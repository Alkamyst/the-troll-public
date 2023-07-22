
/**
 * Behavior for bhvFloorSwitchHardcodedModel, bhvFloorSwitchGrills, and
 * bhvFloorSwitchAnimatesObject.
 *
 * This controls the purple switches that Mario can step on to affect parts of
 * the environment.
 */

void bhv_purple_switch_loop(void) {
    s32 switch_bparam1 = GET_BPARAM1(o->oBehParams);
    
    switch (o->oAction) {
        /**
         * Set the switch's model and scale. If Mario is standing near the
         * switch's middle section, transition to the pressed state.
         */
        case PURPLE_SWITCH_ACT_IDLE:
            cur_obj_enable_rendering();
            cur_obj_unhide();
            cur_obj_become_tangible();
            load_object_collision_model();

            cur_obj_set_model(MODEL_PURPLE_SWITCH);
            cur_obj_scale(1.5f);
            if (
                gMarioObject->platform == o
                && !(gMarioStates[0].action & MARIO_NO_PURPLE_SWITCH)
                && lateral_dist_between_objects(o, gMarioObject) < 127.5f
            ) {
                o->oAction = PURPLE_SWITCH_ACT_PRESSED;
            }
            break;

        /**
         * Collapse the switch downward, play a sound, and shake the screen.
         * Immediately transition to the ticking state.
         */
        case PURPLE_SWITCH_ACT_PRESSED:

        if (switch_bparam1 == 1) {
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 1.5f, 8.0f);
        } else {
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 1.5f, 0.2f);
        }
            if (o->oTimer == 3) {
                if (switch_bparam1 == 1) {
                    obj_mark_for_deletion(o);
                }
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = PURPLE_SWITCH_ACT_TICKING;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
#if ENABLE_RUMBLE
                queue_rumble_data(5, 80);
#endif
            }
            break;

        /**
         * Play a continuous ticking sound that gets faster when time is almost
         * up. When time is up, move to a waiting-while-pressed state.
         */
        case PURPLE_SWITCH_ACT_TICKING:
            if (o->oBehParams2ndByte != 0) {
                if (o->oBehParams2ndByte == 1 && gMarioObject->platform != o) {
                    o->oAction++;
                } else {
                    if (o->oTimer < 360) {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                    } else {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                    }
                    if (o->oTimer > 400) {
                        o->oAction = PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF;
                    }
                }
            }

            if (switch_bparam1 == 2) {
                if (o->oTimer == 0) {
                    cur_obj_wait_then_blink(360, 20);
                }
                cur_obj_disable_rendering();
                cur_obj_hide();
                cur_obj_become_intangible();
            }

            break;

        /**
         * Make the switch look unpressed again, and transition back to the
         * idle state.
         */
        case PURPLE_SWITCH_ACT_UNPRESSED:
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_ACT_IDLE;
            }
            break;

        /**
         * Mario is standing on the switch, but time has expired. Wait for
         * him to get off the switch, and when he does so, transition to the
         * unpressed state.
         */
        case PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF:
            if (!cur_obj_is_mario_on_platform()) {
                o->oAction = PURPLE_SWITCH_ACT_UNPRESSED;
            }
            break;
    }
}
