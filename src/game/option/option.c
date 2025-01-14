#include "game/option.h"

#include "game/input.h"
#include "game/option/option_compass.h"
#include "game/option/option_control.h"
#include "game/option/option_control_pick.h"
#include "game/option/option_graphics.h"
#include "game/option/option_passport.h"
#include "game/option/option_sound.h"
#include "global/types.h"

static CONTROL_MODE m_ControlMode = CM_PICK;

void Option_Shutdown(INVENTORY_ITEM *inv_item)
{
    switch (inv_item->object_id) {
    case O_PASSPORT_OPTION:
        Option_Passport_Shutdown();
        break;

    case O_MAP_OPTION:
        Option_Compass_Shutdown();
        break;

    case O_DETAIL_OPTION:
        Option_Graphics_Shutdown();
        break;

    case O_SOUND_OPTION:
        Option_Sound_Shutdown();
        break;

    case O_CONTROL_OPTION:
        if (m_ControlMode == CM_PICK) {
            Option_ControlPick_Shutdown();
        } else {
            Option_Control_Shutdown();
        }
        break;

    default:
        break;
    }
}

void Option_DoInventory(INVENTORY_ITEM *inv_item)
{
    switch (inv_item->object_id) {
    case O_PASSPORT_OPTION:
        Option_Passport(inv_item);
        break;

    case O_MAP_OPTION:
        Option_Compass(inv_item);
        break;

    case O_DETAIL_OPTION:
        Option_Graphics(inv_item);
        break;

    case O_SOUND_OPTION:
        Option_Sound(inv_item);
        break;

    case O_CONTROL_OPTION:
        if (m_ControlMode == CM_PICK) {
            m_ControlMode = Option_ControlPick();
        } else {
            m_ControlMode = Option_Control(inv_item, m_ControlMode);
        }
        break;

    case O_GAMMA_OPTION:
        // not implemented in TombATI
        break;

    case O_PISTOL_OPTION:
    case O_SHOTGUN_OPTION:
    case O_MAGNUM_OPTION:
    case O_UZI_OPTION:
    case O_EXPLOSIVE_OPTION:
    case O_MEDI_OPTION:
    case O_BIGMEDI_OPTION:
    case O_PUZZLE_OPTION_1:
    case O_PUZZLE_OPTION_2:
    case O_PUZZLE_OPTION_3:
    case O_PUZZLE_OPTION_4:
    case O_KEY_OPTION_1:
    case O_KEY_OPTION_2:
    case O_KEY_OPTION_3:
    case O_KEY_OPTION_4:
    case O_PICKUP_OPTION_1:
    case O_PICKUP_OPTION_2:
    case O_SCION_OPTION:
        g_InputDB.menu_confirm = 1;
        break;

    case O_PISTOL_AMMO_OPTION:
    case O_SG_AMMO_OPTION:
    case O_MAG_AMMO_OPTION:
    case O_UZI_AMMO_OPTION:
        break;

    default:
        if (g_InputDB.menu_confirm || g_InputDB.menu_back) {
            inv_item->goal_frame = 0;
            inv_item->anim_direction = -1;
        }
        break;
    }
}
