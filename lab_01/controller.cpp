#include "controller.h"
#include "constants.h"
#include "figure_conventions.h"

rc_type controller(myscene_t scene, rc_type action_number, action_t action)
{
    static figure_t figure = init_fig();
    rc_type rc = OK;
    switch (action_number)
    {
        case DOWNLOAD:
            rc = download_model(figure, action);
        case MOVE:
            rc = move_fig(figure, action);
        case ROTATE:
            rc = rotation_fig(figure, action);
        case SCALE:
            rc = scale_fig(figure, action);
        case DELETE:
            rc = clear_fig(figure);
        case DRAW:
            rc = draw_fig(figure, scene);
        default:
            rc = ERR_PARAMETR;
    }
    return rc;
}
