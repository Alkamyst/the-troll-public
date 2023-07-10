#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/troll_test/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_troll_test_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _troll_test_segment_7SegmentRomStart, _troll_test_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_CAGE, cage_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, troll_test_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_TROLL_TEST, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_TROLL_TEST, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, 1201, 441, -11991, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 1201, 441, -12578, 0, 0, 0, (99 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 1201, 441, -13182, 0, 0, 0, (4 << 16), bhvExclamationBox),
		OBJECT(MODEL_BETA_BOO_KEY, 2865, 321, -7353, 0, 0, 0, 0x00000000, bhvDoorKey),
		OBJECT(MODEL_BETA_BOO_KEY, 2410, 321, -7353, 0, 0, 0, 0x00000000, bhvDoorKey),
		OBJECT(MODEL_BETA_BOO_KEY, 1973, 321, -7353, 0, 0, 0, 0x00000000, bhvDoorKey),
		OBJECT(MODEL_BETA_BOO_KEY, 2865, 321, -8036, 0, 0, 0, 0x00000000, bhvDoorKey),
		OBJECT(MODEL_BETA_BOO_KEY, 2410, 321, -8036, 0, 0, 0, 0x00000000, bhvDoorKey),
		OBJECT(MODEL_BETA_BOO_KEY, 1973, 321, -8036, 0, 0, 0, 0x00000000, bhvDoorKey),
		OBJECT(MODEL_CAGE, -886, 100, -12348, 0, 0, 0, 0x00000000, bhvHiddenCage),
		OBJECT(MODEL_METAL_BOX, -1021, 100, -8197, 0, -180, 0, 0x00000000, bhvKeyDoor),
		OBJECT(MODEL_METAL_BOX, -1021, 100, -7423, 0, -180, 0, 0x00000000, bhvKeyDoor),
		OBJECT(MODEL_METAL_BOX, -1021, 100, -6340, 0, -180, 0, 0x00000000, bhvMovingPlatformSlip1),
		OBJECT(MODEL_METAL_BOX, -1, 100, -6890, 0, -180, 0, 0x00000000, bhvPushingWallSlip1),
		OBJECT(MODEL_PURPLE_SWITCH, -886, 100, -12348, 0, -180, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_THE_TROLL, 357, 100, -12876, 0, -138, 0, 0x00000000, bhvTrollInteract),
		OBJECT(MODEL_NONE, 0, 200, -13463, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, -13463),
		OBJECT(MODEL_NONE, 0, 492, -13463, 0, 0, 0, 0x00320000, bhvAirborneDeathWarp),
		TERRAIN(troll_test_area_1_collision),
		MACRO_OBJECTS(troll_test_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x23, SEQ_PIZZA_DELUXE),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, -13463),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
