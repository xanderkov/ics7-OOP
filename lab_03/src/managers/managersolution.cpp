#include "managersolution.h"


std::shared_ptr<LoadManager> ManagerSolution::get_load_manager()
{
	return LoadManagerCreator().get_manager();
}

std::shared_ptr<SceneManager> ManagerSolution::get_scene_manager()
{
	return SceneManagerCreator().get_manager();
}

std::shared_ptr<DrawManager> ManagerSolution::get_draw_manager()
{
	return DrawManagerCreator().get_manager();
}

std::shared_ptr<ConfigManager> ManagerSolution::get_config_manager()
{
	return ConfigManagerCreator().get_manager();
}