// Leaf Pile Behavior

void bhv_luigiman_leaf_pile_init() {
    if (o->oBehParams2ndByte == 0) {
        o->oNumLootCoins = 0;
    }
    if (o->oBehParams2ndByte == 1) {
        o->oNumLootCoins = 3;
    }
    if (o->oBehParams2ndByte == 2) {
        o->oNumLootCoins = 5;
    }
}

// extern const Collision luigiman_rings_collision[];
void bhv_luigiman_leaf_pile_loop(void) {
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        obj_spawn_loot_yellow_coins(o, o->oNumLootCoins, 20.0f);
        obj_mark_for_deletion(o);
        spawn_mist_particles_variable(0, 0, 46.0f);
        o->oInteractType = INTERACT_COIN;
        // obj_explode_and_spawn_coins(46.0f, COIN_TYPE_YELLOW);
    }
}

// Chestnuts Behavior

static struct ObjectHitbox sChestnutHitbox = {
    /* interactType:      */ INTERACT_DAMAGE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 150,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void bhv_luigiman_chestnut_init(void) {
    // o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
    o->oGravity = 5.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;
    if (o->oBehParams2ndByte == 1) {
        cur_obj_scale(3.0f);
    }
}

void luigiman_chestnut_act_0(void) {
    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = OBJ_MOVE_NONE;
    cur_obj_set_pos_to_home();
    obj_set_hitbox(o, &sChestnutHitbox);
    if (o->oBehParams2ndByte == 0) {
        o->oGraphYOffset = 100.0f;
    }
    if (o->oBehParams2ndByte == 1) {
        o->oGraphYOffset = 250.0f;
    }
    o->oAction = 1;
}

void luigiman_chestnut_act_1(void) {
    if (o->oTimer < 10) {
        o->oForwardVel = 2.0f;
        
    } else if (o->oTimer < 20) {
        if (o->oTimer % 2) {
            o->oForwardVel = 2.0f;
        } else {
            o->oForwardVel = -2.0f;
        }
    } else {
        if (o->oTimer > 40) {
            cur_obj_update_floor_and_walls();
        }

        o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f));
        o->oForwardVel = 15.0f;

        if (o->oTimer > 20) {
            object_step_without_floor_orient();
            // o->oMoveAnglePitch -= 0x4F;
            // o->oFaceAngleYaw = o->oMoveAngleYaw;
        }

        o->parentObj = cur_obj_nearest_object_with_behavior(bhvPushableMetalBox);

        if (dist_between_objects(o, o->parentObj) < 400.0f) {
            o->oAction = 0;
            spawn_mist_particles();
        }

        if (o->oDistanceToMario >= 3500.0f) {
            o->oAction = 0;
        }

        if (o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
            o->oAction = 2;
            spawn_mist_particles();
        }
    }
}

void luigiman_chestnut_act_2(void) {
    // o->oMoveAngleYaw == 0x0;
    // o->oMoveAngleYaw += 0x9000;
    cur_obj_rotate_yaw_toward(0x0, 0x8000);
    o->oAction = 0;
}

void luigiman_chestnut_act_3(void) {
    spawn_mist_particles();
    o->oAction = 0;
}

ObjActionFunc sluigimanChustnutActions[] = {
    luigiman_chestnut_act_0,
    luigiman_chestnut_act_1,
    luigiman_chestnut_act_2,
    luigiman_chestnut_act_3,
};

void bhv_luigiman_chestnut_loop(void) {
    cur_obj_call_action_function(sluigimanChustnutActions);
    if (cur_obj_check_interacted()) {
        o->oAction = 3;
    }
}

// Golden Chestnuts Behavior

void bhv_luigiman_golden_chestnut_init(void) {
    o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
    o->oGravity = 5.0f;
    o->oFriction = 0.999f;
    o->oBuoyancy = 2.0f;
}

void luigiman_golden_chestnut_act_0(void) {
    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = OBJ_MOVE_NONE;
    cur_obj_set_pos_to_home();
    obj_set_hitbox(o, &sChestnutHitbox);
    o->oGraphYOffset = 100.0f;
    o->oAction = 1;
}

void luigiman_golden_chestnut_act_1(void) {
    struct Object *sparkleObj = spawn_object(o, MODEL_SPARKLES_ANIMATION, bhvSparkle);
    obj_translate_xyz_random(sparkleObj, 270.0f);
    obj_scale_random(sparkleObj, 2.0f, 0.0f);

    cur_obj_update_floor_and_walls();

    o->oFaceAnglePitch += (s16)(o->oForwardVel * (100.0f));
    o->oForwardVel = 10.0f;
    o->oAngleToMario = cur_obj_angle_to_home();
    cur_obj_rotate_yaw_toward(o->oAngleToMario, 0x200);

    object_step_without_floor_orient();

    o->parentObj = cur_obj_nearest_object_with_behavior(bhvPushableMetalBox);

    if (dist_between_objects(o, o->parentObj) < 400.0f) {
        spawn_mist_particles();
        obj_mark_for_deletion(o);
        spawn_default_star(0, 300.0f, 0);
    }
}

ObjActionFunc sluigimanGoldenChustnutActions[] = {
    luigiman_golden_chestnut_act_0,
    luigiman_golden_chestnut_act_1,
};

void bhv_luigiman_golden_chestnut_loop(void) {
    cur_obj_call_action_function(sluigimanGoldenChustnutActions);
    if (cur_obj_check_interacted()) {
        obj_set_hitbox(o, &sChestnutHitbox);
    }
}