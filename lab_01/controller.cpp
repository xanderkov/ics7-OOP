#include "controller.h"


rc_type controller(myscene_t scene, rc_type action_number, data action)
{
    static figure_t fig = init_fig();
    rc_type rc = OK;
    switch (action_number)
    {
        case DOWNLOAD:
            rc = download_model(fig, action);
            break;
        case MOVE:
            rc = move_fig(fig, action);
            break;
        case ROTATE:
            rc = rotation_fig(fig, action);
            break;
        case SCALE:
            rc = scale_fig(fig, action);
            break;
        case DELETE_NUM:
            clear_fig(fig);
            break;
        case DRAW:
            draw_fig(fig, scene);
            break;
        default:
            rc = ERR_PARAMETR;
            break;
    }
    return rc;
}
