void bhv_hidden_cage_loop(void) {
    struct Object *switchObj;
    switch (o->oAction) {
        case BREAKABLE_BOX_ACT_HIDDEN:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            if (o->oHiddenObjectSwitchObj == NULL) {
                o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvFloorSwitchHiddenObjects);
            }
            switchObj = o->oHiddenObjectSwitchObj;
            if ((switchObj != NULL) && (switchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
                o->oAction = BREAKABLE_BOX_ACT_ACTIVE;
                cur_obj_enable_rendering();
                cur_obj_unhide();
            }
            break;
        case BREAKABLE_BOX_ACT_ACTIVE:
            cur_obj_become_tangible();
            if (cur_obj_wait_then_blink(360, 20)) o->oAction = BREAKABLE_BOX_ACT_HIDDEN;
            load_object_collision_model();
            break;
    }
}

void bhv_moving_platform_slip(void) {

    if (gMarioState->floor != NULL) {
        s32 floorType = gMarioState->floor->type;
        f32 dx = o->oPosX - o->oHomeX;
        f32 dz = o->oPosZ - o->oHomeZ;
        f32 distToHome = sqrtf(sqr(dx) + sqr(dz));

        if (floorType == SURFACE_INTERACTION) {
            if (distToHome < 800.0f) {
                o->oPosX += 100.0f;
            }
        }

        if (floorType != SURFACE_INTERACTION) {
            if (distToHome > 0.0f) {
                o->oPosX -= 100.0f;
            }
        }
    }

    load_object_collision_model();
}


void bhv_pushing_wall_slip_init(void) {
    o->oTimer = random_float() * 100.0f;
}

void bhv_pushing_wall_slip_loop(void) {
    s32 floorType = gMarioState->floor->type;
    f32 dx = o->oPosX - o->oHomeX;
    f32 dz = o->oPosZ - o->oHomeZ;
    f32 distToHome = sqrtf(sqr(dx) + sqr(dz));
    switch (o->oAction) {
        case BOMP_ACT_WAIT:
            if (o->oTimer > 100) {
                o->oAction = BOMP_ACT_POKE_OUT;
            }
            break;

        case BOMP_ACT_POKE_OUT:
            if (distToHome <= 120.0f) {
                o->oPosX = (o->oPosX + 25.0f);
            }

            if (o->oTimer == 15) {
                o->oAction = BOMP_ACT_EXTEND;
                cur_obj_play_sound_2(SOUND_OBJ_BOMP_SLIDE);
            }
            break;

        case BOMP_ACT_EXTEND:
            if (distToHome <= 500.0f) {
                o->oPosX = (o->oPosX + ((floorType == SURFACE_INTERACTION) ? 80.0f : 40.0f));
            }

            if (o->oTimer == 60) {
                o->oAction = BOMP_ACT_RETRACT;
                cur_obj_play_sound_2(SOUND_OBJ_BOMP_SLIDE);
            }
            break;

        case BOMP_ACT_RETRACT:
            if (o->oPosX > o->oHomeX) {
                o->oPosX = (o->oPosX - 10.0f);
            }

            if (o->oTimer == 90) {
                o->oAction = BOMP_ACT_POKE_OUT;
            }
            break;
        
        case BOMP_ACT_LAUNCH:
            o->oPosX = (o->oPosX + 100.0f);

            if (distToHome >= 3000.0f) {
                struct Object *explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                explosion->oGraphYOffset += 100.0f;

                obj_mark_for_deletion(o);
            }
            break;
    }

    if (gMarioState->floor != NULL) {

        if ((floorType == SURFACE_INTERACTION) && (o->oAction != BOMP_ACT_LAUNCH)) {
            o->oTimer = 15;
            o->oAction = BOMP_ACT_EXTEND;

        }

        if (floorType == SURFACE_INTERACTION2) {
            o->oTimer = 0;
            o->oAction = BOMP_ACT_LAUNCH;

        }
    }

}

void bhv_door_key_loop(void) {
//    o->oFaceAngleRoll += 0x200;
    o->oFaceAngleYaw -= 0x400;
    cur_obj_scale(2.0f);

    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        cur_obj_disable_rendering();
        cur_obj_become_intangible();

        spawn_object(o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);
        play_sound(SOUND_MENU_STAR_SOUND, gMarioState->marioObj->header.gfx.cameraToObject);
        if (gMarioState->numKeys == -1) {
            gMarioState->numKeys = (gMarioState->numKeys + 1);
        }
        gMarioState->numKeys = (gMarioState->numKeys + 1);
    }


    if (gMarioState->numKeys == -1) {
        cur_obj_enable_rendering();
        cur_obj_unhide();
        cur_obj_become_tangible();
    }

}

void bhv_key_door_loop(void) {
//    o->oFaceAngleRoll += 0x200;
    o->oDistanceToMario = dist_between_objects(o, gMarioObject);

    if ((o->oDistanceToMario <= 500.0f) && (gMarioState->numKeys >= 1) && (o->oAction == DOOR_IDLE)) {
        cur_obj_disable_rendering();
        cur_obj_become_intangible();

        spawn_object(o, MODEL_NONE, bhvStarKeyCollectionPuffSpawner);

        gMarioState->numKeys = (gMarioState->numKeys - 1);

        o->oAction = DOOR_OPEN;
    }

    if (gMarioState->numKeys == -1) {
        cur_obj_enable_rendering();
        cur_obj_unhide();
        cur_obj_become_tangible();
        load_object_collision_model();
        o->oAction = DOOR_IDLE;
    }
}