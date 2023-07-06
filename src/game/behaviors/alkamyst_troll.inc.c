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