#include <QFileDialog>
//#include <qdebug>
#include "../../implementation/commands/scene/render/render_scene.hpp"
#include "../../implementation/commands/model/load/load_model.hpp"
#include "../../implementation/commands/model/add/add_model.hpp"
#include "../../implementation/commands/model/remove/remove_model.hpp"
#include "../../implementation/commands/camera/load/load_camera.hpp"
#include "../../implementation/commands/camera/add/add_camera.hpp"
#include "../../implementation/commands/camera/remove/remove_camera.hpp"
#include "../../implementation/commands/camera/set/set_camera.hpp"
#include "../../implementation/commands/camera/move/move_camera.hpp"
#include "../../implementation/commands/model/move/move_model.hpp"
#include "../../implementation/commands/model/scale/scale_model.hpp"
#include "../../implementation/commands/model/rotate/rotate_model.hpp"
#include "../../implementation/commands/camera/count/count_cameras.hpp"
#include "../../implementation/commands/model/count/count_models.hpp"
#include "../../implementation/commands/scene/get_main_camera/get_main_camera.hpp"
#include "../../implementation/commands/scene/get_scene/get_scene.hpp"
#include "../../implementation/commands/scene/get_object/get_object.hpp"

#include "../../implementation/objects/camera/camera.hpp"
#include "../../implementation/objects/model/wireframe_model/wireframe_model.hpp"

#include "../../implementation/exceptions/base_exception.hpp"

#include "mainwindow.h"

#include "drawer/factory/qt_drawer_factory.hpp"

#define CAM_SHIFT 10

using namespace std;


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    this->ui->setupUi(this);
    this->setupScene();

    this->facade = std::make_shared<Facade>(Facade());

    
    connect(&*this->ui->display, SIGNAL(moveSignal(double, double, double)), 
        &*this, SLOT(mouseMoveSlot(double, double, double)));

    connect(&*this->ui->display, SIGNAL(rotateSignal(double, double, double)),
        &*this, SLOT(mouseRotateSlot(double, double, double)));
}

void MainWindow::setupScene() {
    this->scene = std::make_shared<QGraphicsScene>(this);
    ui->display->setScene(this->scene.get());
    ui->display->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->display->setInteractive(true);

    this->scene->setSceneRect(0, 0, ui->display->width(), ui->display->height());

    decltype(auto) solution = std::make_shared<SolutionDrawerFactory>();
    solution->registration<QtDrawerFactory>("QtDrawer", this->scene);

    decltype(auto) factory = solution->createFactory("QtDrawer");

    //decltype(auto) factory = new QtDrawerFactory(this->scene);
    this->drawer = factory->createDrawer();

}

void MainWindow::updateScene() {
    auto scene = std::make_shared<Scene>();
    auto mainCamera = std::make_shared<Camera>();

    auto get_scene_cmd = std::make_shared<GetScene>(scene);
    auto get_camera_cmd = std::make_shared<GetMainCamera>(mainCamera);
    this->facade->execute(get_scene_cmd);
    this->facade->execute(get_camera_cmd);

    auto render_scene_cmd = std::make_shared<RenderScene>(scene, this->drawer, mainCamera);

    try
    {
        this->facade->execute(render_scene_cmd);
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

size_t MainWindow::getCamerasCount() const {
    auto cameras_count = std::make_shared<size_t>(0);
    auto cameras_count_cmd = std::make_shared<CountCameras>(cameras_count);
    this->facade->execute(cameras_count_cmd);

    return *cameras_count;
}

size_t MainWindow::getModelsCount() const {
    auto models_count = std::make_shared<size_t>(0);
    auto models_count_cmd = std::make_shared<CountModels>(models_count);
    this->facade->execute(models_count_cmd);

    return *models_count;
}

void MainWindow::on_move_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> model = make_shared<WireframeModel>();
    auto get_model_cmd = make_shared<GetSceneObject>(model, this->getCurrModelID());
    this->facade->execute(get_model_cmd);

    auto move_model_cmd = make_shared<MoveModel>(model, this->ui->dx_box->value(),
                                                 this->ui->dy_box->value(), this->ui->dz_box->value());
    try
    {
        this->facade->execute(move_model_cmd);
        this->updateScene();
    } catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_scale_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> model = make_shared<WireframeModel>();
    auto get_model_cmd = make_shared<GetSceneObject>(model, this->getCurrModelID());
    this->facade->execute(get_model_cmd);

    auto scale_model_cmd = std::make_shared<ScaleModel>(model, this->ui->kx_box->value(),this->ui->ky_box->value(),  this->ui->kz_box->value());
    try
    {
        this->facade->execute(scale_model_cmd);
        //this->updateScene();
    } catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_rotate_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> model = make_shared<WireframeModel>();
    auto get_model_cmd = make_shared<GetSceneObject>(model, this->getCurrModelID());
    this->facade->execute(get_model_cmd);

    auto rotate_model_cmd = std::make_shared<RotateModel>(model, this->ui->ax_box->value(),
                                                          this->ui->ay_box->value(), this->ui->az_box->value());
    try
    {
        this->facade->execute(rotate_model_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_load_model_btn_clicked() {
    if (!this->cameraSelected())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру");
        return;
    }

    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;

    shared_ptr<Object> model = make_shared<WireframeModel>();
    auto load_model_cmd = std::make_shared<LoadModel>(model, filename.toUtf8().data());
    try
    {
        this->facade->execute(load_model_cmd);
    }
    catch (const BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto add_model_cmd = std::make_shared<AddModel>(model);
    this->facade->execute(add_model_cmd);
    this->updateScene();
    this->ui->objects_list->addItem(QString("model_") + QString::number(++this->last_mod_id));

    auto obj_list = this->ui->objects_list;
    this->ui->curr_model_lbl->setText(obj_list->item(obj_list->count() - 1)->text());
}

void MainWindow::on_clear_scene_btn_clicked() {
    auto obj_list = this->ui->objects_list;
    if (!obj_list->count())
    {
        QMessageBox::information(nullptr, "OK!", "Сцена уже очищена");
        return;
    }

    std::shared_ptr<Command> remove_cmd;

    this->resetModel();
    for (int i = obj_list->count() - 1; i >= 0; --i)
        if (obj_list->item(i)->text().contains("model"))
        {
            remove_cmd = std::make_shared<RemoveModel>(i);
            this->facade->execute(remove_cmd);
            obj_list->takeItem(i);
        }

    if (this->cameraSelected()) this->updateScene();

    this->resetCamera();
    for (int i = obj_list->count() - 1; i >= 0; --i)
        if (obj_list->item(i)->text().contains("camera"))
        {
            remove_cmd = std::make_shared<RemoveCamera>(i);
            this->facade->execute(remove_cmd);
            obj_list->takeItem(i);
        }
}

void MainWindow::on_load_camera_btn_clicked() {
    auto filename = QFileDialog::getOpenFileName();
    if (filename.isNull()) return;

    shared_ptr<Object> camera = make_shared<Camera>();
    auto load_camera_cmd = std::make_shared<LoadCamera>(camera, filename.toUtf8().data());
    try
    {
        this->facade->execute(load_camera_cmd);
        this->ui->objects_list->addItem(QString("camera_") + QString::number(++this->last_cam_id));
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto add_camera_cmd = std::make_shared<AddCamera>(camera);
    this->facade->execute(add_camera_cmd);

    auto obj_list = this->ui->objects_list;
    this->ui->curr_camera_lbl->setText(obj_list->item(obj_list->count() - 1)->text());
}

void MainWindow::on_add_camera_btn_clicked() {
    auto r_content = ui->display->contentsRect();
    auto add_camera_cmd = std::make_shared<AddCamera>(-r_content.width() / 2.0, -r_content.height() / 2.0, 0.0);

    try
    {
        this->facade->execute(add_camera_cmd);
        this->ui->objects_list->addItem(QString("camera_") + QString::number(++this->last_cam_id));
    }
    catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }

    auto obj_list = this->ui->objects_list;
    
    qDebug() << this->ui->objects_list->currentRow();
    auto camera_set_cmd = std::make_shared<SetCamera>(0);
    this->facade->execute(camera_set_cmd);
    this->ui->curr_camera_lbl->setText(obj_list->item(obj_list->count() - 1)->text());

    this->updateScene();
}

void MainWindow::on_change_model_btn_clicked() {
    if (this->ui->objects_list->currentRow() < 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите модель, которую хотите сделать текущей");
        return;
    }

    auto curr_item = this->ui->objects_list->currentItem();

    if (curr_item->text().contains("model"))
        this->ui->curr_model_lbl->setText(curr_item->text());
    else
        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную модель");
}


void MainWindow::on_change_camera_btn_clicked() {
    if (this->ui->objects_list->currentRow() < 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите камеру, которую хотите сделать текущей");
        return;
    }

    auto curr_item = this->ui->objects_list->currentItem();
    if (!curr_item->text().contains("camera"))
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите корректную камеру");
        return;
    }

    auto camera_set_cmd = std::make_shared<SetCamera>(this->ui->objects_list->currentRow());

    try
    {
        this->facade->execute(camera_set_cmd);
        this->updateScene();
        this->ui->curr_camera_lbl->setText(curr_item->text());
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}

bool MainWindow::canRemoveModel(const size_t id) {
    if (!this->getModelsCount())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять модель, добавьте хотя бы одну.");
        return false;
    }

    return true;
}

bool MainWindow::canRemoveCamera(const size_t id) {
    if (!this->getCamerasCount())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Прежде чем удалять камеру, добавьте хотя бы одну.");
        return false;
    }

    if (this->getCamerasCount() == 1 && this->getModelsCount())
    {
        QMessageBox::critical(nullptr, "Ошибка",
                              "Прежде чем удалять последнюю камеру, необходимо удалить оставшиеся модели.");
        return false;
    }

    if (this->getCamerasCount() > 1 &&
        this->ui->objects_list->currentItem()->text() == this->ui->curr_camera_lbl->text())
    {
        QMessageBox::critical(nullptr, "Ошибка",
                              "Прежде чем удалить данную камеру, выберите другую в качестве текущей");
        return false;
    }

    return true;
}

void MainWindow::resetCamera() { this->ui->curr_camera_lbl->setText("None"); }

void MainWindow::resetModel() { this->ui->curr_model_lbl->setText("None"); }

bool MainWindow::cameraSelected() { return this->ui->curr_camera_lbl->text() != QString("None"); }

bool MainWindow::modelSelected() { return this->ui->curr_model_lbl->text() != QString("None"); }

void MainWindow::on_remove_object_btn_clicked() {
    auto curr_row = this->ui->objects_list->currentRow();
    if (curr_row < 0)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Выберите объект, который хотите удалить");
        return;
    }

    std::shared_ptr<Command> remove_cmd;

    auto text_item = this->ui->objects_list->currentItem()->text();
    if (text_item.contains("camera"))
    {
        if (!this->canRemoveCamera(curr_row)) return;

        auto cam_lbl = this->ui->curr_camera_lbl;
        if (text_item == cam_lbl->text()) this->resetCamera();

        remove_cmd = std::make_shared<RemoveCamera>(curr_row);
    }
    else
    {
        if (!this->canRemoveModel(curr_row)) return;

        auto mod_lbl = this->ui->curr_model_lbl;
        if (text_item == mod_lbl->text()) this->resetModel();

        remove_cmd = std::make_shared<RemoveModel>(curr_row);
    }

    try
    {
        this->facade->execute(remove_cmd);
        this->ui->objects_list->takeItem(curr_row);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
        return;
    }
}

size_t MainWindow::getCurrCameraID() {
    auto item = this->ui->objects_list->findItems(this->ui->curr_camera_lbl->text(), Qt::MatchExactly)[0];
    return this->ui->objects_list->row(item);
}

size_t MainWindow::getCurrModelID() {
    auto item = this->ui->objects_list->findItems(this->ui->curr_model_lbl->text(), Qt::MatchExactly)[0];
    return this->ui->objects_list->row(item);
}

void MainWindow::on_right_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> camera = make_shared<Camera>();
    qDebug() << this->getCurrCameraID();
    auto get_camera_cmd = make_shared<GetSceneObject>(camera, this->getCurrCameraID());
    this->facade->execute(get_camera_cmd);

    auto camera_move_cmd = std::make_shared<MoveCamera>(camera, CAM_SHIFT, 0);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_up_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> camera = make_shared<Camera>();
    auto get_camera_cmd = make_shared<GetSceneObject>(camera, this->getCurrCameraID());
    this->facade->execute(get_camera_cmd);

    auto camera_move_cmd = std::make_shared<MoveCamera>(camera, 0, -CAM_SHIFT);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_down_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> camera = make_shared<Camera>();
    auto get_camera_cmd = make_shared<GetSceneObject>(camera, this->getCurrCameraID());
    this->facade->execute(get_camera_cmd);

    auto camera_move_cmd = std::make_shared<MoveCamera>(camera, 0, CAM_SHIFT);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::on_left_btn_clicked() {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> camera = make_shared<Camera>();
    auto get_camera_cmd = make_shared<GetSceneObject>(camera, this->getCurrCameraID());
    this->facade->execute(get_camera_cmd);

    auto camera_move_cmd = std::make_shared<MoveCamera>(camera, -CAM_SHIFT, 0);
    try
    {
        this->facade->execute(camera_move_cmd);
        this->updateScene();
    } catch (BaseException &ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::mouseMoveSlot(double dx, double dy, double dz) {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> model = make_shared<WireframeModel>();
    auto get_model_cmd = make_shared<GetSceneObject>(model, this->getCurrModelID());
    this->facade->execute(get_model_cmd);

    auto move_model_cmd = make_shared<MoveModel>(model, dx, dy, dz);
    try
    {
        this->facade->execute(move_model_cmd);
        this->updateScene();
    }
    catch (const BaseException& ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::mouseRotateSlot(double dx, double dy, double dz) {
    if (!this->checkCamAndModel()) return;

    shared_ptr<Object> model = make_shared<WireframeModel>();
    auto get_model_cmd = make_shared<GetSceneObject>(model, this->getCurrModelID());
    this->facade->execute(get_model_cmd);

    auto rotate_model_cmd = std::make_shared<RotateModel>(model, dx*0.3, dy*0.3, dz*0.3);
    try
    {
        this->facade->execute(rotate_model_cmd);
        this->updateScene();
    }
    catch (BaseException& ex)
    {
        QMessageBox::warning(this, "Error", QString(ex.what()));
    }
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);

    this->scene->setSceneRect(0, 0, ui->display->width(), ui->display->height());

    auto r_content = ui->display->contentsRect();
    this->scene->setSceneRect(0, 0, r_content.width(), r_content.height());
}

bool MainWindow::checkCamAndModel() {
    if (!this->cameraSelected() || !this->modelSelected())
    {
        QMessageBox::critical(nullptr, "Ошибка", "Сначала выберите камеру и модель");
        return false;
    }

    return true;
}

MainWindow::~MainWindow() { delete ui; scene.~shared_ptr(); }

