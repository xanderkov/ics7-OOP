#include "myscene.h"
#include "math.h"
#include <iostream>

void draw_line_scene(myscene_t scene, point_t p1, point_t p2)
{
    double z1 = sqrt(2)/2 * get_point_z(p1);
    double z2 = sqrt(2)/2 * get_point_z(p2);
    scene.scene->addLine(get_point_x(p1) - z1, - get_point_y(p1) + z1,
                         get_point_x(p2) - z2, - get_point_y(p2) + z2);
}

void draw_point_scene(myscene_t scene, point_t p1)
{
    double z1 = sqrt(2)/2 * get_point_z(p1);
    scene.scene->addEllipse(get_point_x(p1) - z1, - get_point_y(p1) + z1, 1, 1);
}

void clear_scene(myscene_t scene)
{
    scene.scene->clear();
}
