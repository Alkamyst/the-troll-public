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