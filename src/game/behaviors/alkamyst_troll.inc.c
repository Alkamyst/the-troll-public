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

// keys

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
    
    if (o->oAction == DOOR_IDLE) {
        cur_obj_enable_rendering();
        cur_obj_unhide();
        cur_obj_become_tangible();
        load_object_collision_model();
    }

    if (gMarioState->numKeys == -1) {
        o->oAction = DOOR_IDLE;
    }
}

// final boss

static struct ObjectHitbox sFinalBossHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 3,
    /* numLootCoins:      */ 1,
    /* radius:            */ 200,
    /* height:            */ 200,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_troll_final_boss_init(void) {
    obj_set_hitbox(o, &sFinalBossHitbox);
}

void bhv_troll_final_boss_loop(void) {
    struct Object *shellObj;

    shellObj = cur_obj_nearest_object_with_behavior(bhvThrowShell);

    switch (o->oAction) {
        case 0:
            o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x150);
            o->oPosY = approach_f32_symmetric(o->oPosY, gMarioObject->oPosY, 0x8);
            
            if ((shellObj != NULL) && (dist_between_objects(o, shellObj) < 400.0f)) {
                shellObj->oInteractStatus |= INT_STATUS_HIT_MINE;
                o->oHealth--;
                o->oAction = 1;
            }

            break;

        case 1:

            if (o->oHealth <= 0) {

                o->oPosY = approach_f32_symmetric(o->oPosY, o->oHomeY, 0x5);

                if (o->oPosY == o->oHomeY) {

                    seq_player_lower_volume(SEQ_PLAYER_LEVEL, 60, 40);
                    o->oBreakableBoxSmallFramesSinceReleased = 0;
                    cur_obj_become_tangible();
                    cur_obj_enable_rendering();
                    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

                        if (cur_obj_update_dialog_with_cutscene(MARIO_DIALOG_LOOK_UP,
                            DIALOG_FLAG_NONE, CUTSCENE_DIALOG, DIALOG_163)) {
                            spawn_object_relative(0, 0, 500, 1000, o, MODEL_BETA_BOO_KEY, bhvDoorKey);
                            seq_player_unlower_volume(SEQ_PLAYER_LEVEL, 60);
                            seq_player_fade_out(SEQ_PLAYER_LEVEL, 1);
                            o->oAction = 2;
                    }
                }
            }

            o->oBreakableBoxSmallFramesSinceReleased++;

            if (o->oBreakableBoxSmallFramesSinceReleased < 90) {
                COND_BIT((o->oBreakableBoxSmallFramesSinceReleased & 0x2), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
            }

            if (o->oBreakableBoxSmallFramesSinceReleased >= 90) {
                o->oBreakableBoxSmallFramesSinceReleased = 0;
                cur_obj_become_tangible();
                cur_obj_enable_rendering();
                o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                o->oAction = 0;
            }

            break;

        case 2:

            if (gMarioState->numKeys == 1) {
                struct Object *explosion = spawn_object(o, MODEL_EXPLOSION, bhvExplosion);
                explosion->oGraphYOffset += 100.0f;
                o->oAction = 3;
            }

            break;

        case 3:

            obj_mark_for_deletion(o);

            break;
    }

    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        o->oInteractStatus = INT_STATUS_NONE;
    }

}

// final boss bullet bill

void final_boss_bullet_bill_act_0(void) {


    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = OBJ_MOVE_NONE;
    cur_obj_set_pos_to_home();
    o->oAction = 1;
}

void final_boss_bullet_bill_act_1(void) {
    s16 sp1E = abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw);
    if (sp1E < 0x2000 && 400.0f < o->oDistanceToMario && o->oDistanceToMario < 1500.0f) {
        o->oAction = 2;
    }
}

void final_boss_bullet_bill_act_2(void) {
    if (o->oTimer < 50) {
        if (o->oTimer % 2) {
            o->oForwardVel = 3.0f;
        } else {
            o->oForwardVel = -3.0f;
        }
    } else {
        if (o->oTimer > 70) {
            cur_obj_update_floor_and_walls();
        }

        spawn_object(o, MODEL_SMOKE, bhvWhitePuffSmoke);
        o->oForwardVel = 50.0f;

        if (o->oDistanceToMario > 300.0f) {
            cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x50);
        }

        if (o->oTimer == 50) {
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
        }

        if (o->oTimer > 150 || o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
            o->oAction = 3;
            spawn_mist_particles();
        }

    }
}

void final_boss_bullet_bill_act_3(void) {
    o->oAction = 0;
}

void final_boss_bullet_bill_act_4(void) {
    if (o->oTimer == 0) {
        o->oForwardVel = -30.0f;
        cur_obj_become_intangible();
    }

    o->oFaceAnglePitch += 0x1000;
    o->oFaceAngleRoll += 0x1000;
    o->oPosY += 20.0f;

    if (o->oTimer > 90) {
        o->oAction = 0;
    }
}

ObjActionFunc sFinalBossBulletBillActions[] = {
    final_boss_bullet_bill_act_0,
    final_boss_bullet_bill_act_1,
    final_boss_bullet_bill_act_2,
    final_boss_bullet_bill_act_3,
    final_boss_bullet_bill_act_4,
};

void bhv_final_boss_bullet_bill_loop(void) {
    struct Object *finalBoss;
    finalBoss = cur_obj_nearest_object_with_behavior(bhvFinalBoss);

    cur_obj_call_action_function(sFinalBossBulletBillActions);
    if (cur_obj_check_interacted()) {
        o->oAction = 4;
    }

    if (!((o->oAction == 2) && ((o->oTimer >= 50)))) {
        o->oMoveAngleYaw = finalBoss->oMoveAngleYaw;
        o->oPosY = finalBoss->oPosY;
    }

    o->header.gfx.node.flags = finalBoss->header.gfx.node.flags;

    if (finalBoss->oAction == 2) {
        obj_mark_for_deletion(o);
    }

}

// throw shell

struct ObjectHitbox sThrowShellHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_throw_shell_init(void) {
    obj_set_hitbox(o, &sThrowShellHitbox);
    o->oAnimState = BREAKABLE_BOX_ANIM_STATE_CORK_BOX;
    o->activeFlags |= ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void throw_shell_spawn_dust(void) {
    struct Object *smokeObj = spawn_object(o, MODEL_SMOKE, bhvSmoke);
    smokeObj->oPosX += (s32)(random_float() * 80.0f) - 40;
    smokeObj->oPosZ += (s32)(random_float() * 80.0f) - 40;
}

void throw_shell_act_move(void) {
    s16 collisionFlags = object_step();

    if (collisionFlags == OBJ_COL_FLAG_GROUNDED) {
        cur_obj_play_sound_2(SOUND_GENERAL_SMALL_BOX_LANDING);
    }

    if (collisionFlags & OBJ_COL_FLAG_GROUNDED) {
        if (o->oForwardVel > 20.0f) {
            cur_obj_play_sound_2(SOUND_ENV_SLIDING);
            throw_shell_spawn_dust();
        }
    }

    if (collisionFlags & OBJ_COL_FLAG_HIT_WALL) {
        spawn_mist_particles();
        create_sound_spawner(SOUND_ACTION_BONK);
        o->oForwardVel = 0.0f;
        cur_obj_set_pos_to_home();
    }

    if (o->oInteractStatus & INT_STATUS_HIT_MINE) {
        spawn_mist_particles();
        create_sound_spawner(SOUND_ACTION_METAL_BONK);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }

    obj_check_floor_death(collisionFlags, sObjFloor);
}

void throw_shell_released_loop(void) {
    o->oBreakableBoxSmallFramesSinceReleased++;

    // Begin flashing
    if (o->oBreakableBoxSmallFramesSinceReleased > 810) {
        COND_BIT((o->oBreakableBoxSmallFramesSinceReleased & 0x1), o->header.gfx.node.flags, GRAPH_RENDER_INVISIBLE);
    }

    // Despawn, and create a corkbox respawner
    if (o->oBreakableBoxSmallFramesSinceReleased > 900) {
        create_respawner(MODEL_BREAKABLE_BOX, bhvThrowShell, 3000);
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void throw_shell_idle_loop(void) {
    switch (o->oAction) {
        case BREAKABLE_BOX_SMALL_ACT_MOVE:
            throw_shell_act_move();
            break;

        case OBJ_ACT_LAVA_DEATH:
            obj_lava_death();
            break;

        case OBJ_ACT_DEATH_PLANE_DEATH:
            o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            create_respawner(MODEL_BREAKABLE_BOX, bhvThrowShell, 3000);
            break;
    }
}

void throw_shell_get_dropped(void) {
    cur_obj_become_tangible();
    cur_obj_enable_rendering();
    cur_obj_get_dropped();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oBreakableBoxSmallReleased = TRUE;
    o->oBreakableBoxSmallFramesSinceReleased = 0;
}

void throw_shell_get_thrown(void) {
    cur_obj_become_tangible();

    cur_obj_enable_rendering();
    o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
    o->oHeldState = HELD_FREE;
    o->oFlags &= ~OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW;
    o->oForwardVel = 80.0f;
    o->activeFlags &= ~ACTIVE_FLAG_DESTRUCTIVE_OBJ_DONT_DESTROY;
}

void bhv_throw_shell_loop(void) {
    switch (o->oHeldState) {
        case HELD_FREE:
            throw_shell_idle_loop();
            break;

        case HELD_HELD:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            break;

        case HELD_THROWN:
            throw_shell_get_thrown();
            break;

        case HELD_DROPPED:
            throw_shell_get_dropped();
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}
