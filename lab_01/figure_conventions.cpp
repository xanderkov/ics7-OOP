#include "figure_conventions.h"


rc_type download_model(figure_t &fig, action_t action)
{
    const char *filename = get_filename(action);
    file_adress file;
    rc_type rc = open_file(file, filename);
    if (!rc)
    {
        rc = read_from_file(fig, file);
        close_file(file);
    }
    return rc;
}

void move(struct point &a, double dx, double dy, double dz)
{
    double x = get_point_x(a) + dx;
    double y = get_point_y(a) + dy;
    double z = get_point_z(a) + dz;
    set_point_x(a, x);
    set_point_y(a, y);
    set_point_z(a, z);
}

rc_type move_fig(figure_t &fig, action_t action)
{
    if (is_empty(fig))
        return ERR_EMPTY;
    double dx = get_deltax(action);
    double dy = get_deltay(action);
    double dz = get_deltaz(action);
    for (size_t i = 0; i < get_fig_n(fig); i++)
        move(get_point(fig, i), dx, dy, dz);
    return OK;
}

void rotation_ax(struct point &a, struct point center, double ax)
{
    double yc = get_point_y(center);
    double zc = get_point_z(center);
    double ya = get_point_y(a);
    double za = get_point_z(a);
    double alpha = ax * M_PI / 180;
    double cosa = cos(alpha);
    double sina = sin(alpha);
    double z = zc + (za- zc) * cosa + (ya - yc) * sina;
    double y = yc - (za - zc) * sina + (ya - yc) * cosa;
    set_point_z(a,z);
    set_point_y(a,y);
}

void rotation_ay(struct point &a, struct point center, double ay)
{

    double xc = get_point_x(center);
    double zc = get_point_z(center);
    double xa = get_point_x(a);
    double za = get_point_z(a);
    double alpha = ay * M_PI / 180;
    double cosa = cos(alpha);
    double sina = sin(alpha);
    double x = xc + (xa- xc) * cosa + (za - zc) * sina;
    double z = zc - (xa - xc) * sina + (za - zc) * cosa;
    set_point_x(a,x);
    set_point_z(a,z);
}

void rotation_az(struct point &a, struct point center, double az)
{
    double xc = get_point_x(center);
    double yc = get_point_y(center);
    double xa = get_point_x(a);
    double ya = get_point_y(a);
    double alpha = az * M_PI / 180;
    double cosaz = cos(alpha);
    double sinaz = sin(alpha);

    double x = xc + (xa - xc) * cosaz + (ya - yc) * sinaz;
    double y = yc - (xa - xc) * sinaz + (ya - yc) * cosaz;
    set_point_x(a, x);
    set_point_y(a, y);
}

void rotation(struct point &a, struct point c, alpha_t alpha)
{
    double ax = get_alphax(alpha);
    double ay = get_alphay(alpha);
    double az = get_alphaz(alpha);
    if (az != 0)
    {
         rotation_az(a,c,az);
    }
    if (ax != 0)
    {
         rotation_ax(a,c,ax);
    }
    if (ay != 0)
    {
         rotation_ay(a,c,ay);
    }
}

rc_type rotation_fig(figure_t &fig, action_t act)
{
    if (is_empty(fig))
        return ERR_EMPTY;
    alpha_t alpha = get_alpha(act);
    struct point center;
    set_point(center, 0, 0, 0, 0);
    for (size_t i = 0; i < get_fig_n(fig); i++)
        rotation(get_point(fig, i), center, alpha);
    return OK;
}

rc_type scale_fig(figure_t &fig, action_t act)
{
    if (is_empty(fig))
        return ERR_EMPTY;
    double k = get_k(act);
    struct point center;
    set_point(center, 0, 0, 0, 0);
    for (size_t i = 0; i < get_fig_n(fig); i++)
        scale(get_point(fig, i), center, k);
    return OK;
}

void clear_fig(figure_t &fig)
{
    free_fig(fig);
}

void draw_fig(figure_t &fig, myscene_t scene)
{
    clear_scene(scene);
    draw_model(fig, scene);
}

void scale(struct point &a, struct point center, double k)
{
    double xc = get_point_x(center);
    double yc = get_point_y(center);
    double zc = get_point_z(center);

    double x = xc + k * (get_point_x(a) - xc);
    double y = yc + k * (get_point_y(a) - yc);
    double z = zc + k * (get_point_z(a) - zc);
    set_point_x(a, x);
    set_point_y(a, y);
    set_point_z(a, z);
}

void draw_model(figure_t fig, myscene_t scene)
{
    if (is_empty(fig))
        return;
    for (size_t i = 0; i < get_fig_n(fig); i++)
        draw_point_scene(scene, get_point(fig, i));
    for (size_t i = 0; i < get_fig_n(fig); i++)
        for(size_t j = 0; j < i + 1; j++)
            if (get_matrix_el(fig, i, j))
                draw_line_scene(scene, get_point(fig, i), get_point(fig, j));
}
