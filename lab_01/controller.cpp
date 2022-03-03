#include "controller.h"


rc_type controller(myscene_t scene, rc_type action_number, action_t action)
{
    static figure_t fig = init_fig();
    rc_type rc = OK;
    switch (action_number)
    {
        case DOWNLOAD:
            rc = download_model(fig, action);
        case MOVE:
            rc = move_fig(fig, action);
        case ROTATE:
            rc = rotation_fig(fig, action);
        case SCALE:
            rc = scale_fig(fig, action);
        case DELETE_NUM:
            clear_fig(fig);
        case DRAW:
            draw_fig(fig, scene);
        default:
            rc = ERR_PARAMETR;
    }
    return rc;
}
