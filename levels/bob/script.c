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

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_MUSHROOM_1, mushroom_troll_1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PUSHYWALL1, pushy_wall_1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CAGE, hidden_cage_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DYNAMITE, dynamite_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_DYNAMITE_ROPE, dynamite_rope_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BREAKABLE_WALL, breakable_wall_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOBOMB_BUDDY, -88, 313, 5254, 0, 157, 0, (1 << 16), bhvBobomb),
		OBJECT(MODEL_YELLOW_COIN, 356, 313, -908, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 356, 313, -796, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 356, 313, -676, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 356, 313, -553, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 356, 313, -441, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_DYNAMITE, 7590, 705, 3474, 0, 55, 0, 0x00000000, bhvDynamite),
		OBJECT(MODEL_DYNAMITE_ROPE, 7590, 705, 3474, 0, 0, 0, 0x00000000, bhvDynamiteTrail),
		OBJECT(MODEL_BREAKABLE_WALL, 7737, 705, 3267, 0, -126, 0, 0x00000000, bhvDynamiteWall),
		OBJECT(MODEL_RED_FLAME, 6259, 917, 5212, 0, -124, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_CAGE, -519, 313, -1454, 0, 0, 0, 0x00000000, bhvHiddenCage),
		OBJECT(MODEL_PUSHYWALL1, 2556, 313, 3588, 0, 0, 0, 0x00000000, bhvPushingWallSlip1),
		OBJECT(MODEL_MUSHROOM_1, 283, -2645, -4066, 0, 0, 0, 0x00000000, bhvMovingPlatformSlip1),
		OBJECT(MODEL_PURPLE_SWITCH, -519, 313, -1454, 0, -180, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_NONE, 0, 200, -7319, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, -7319),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, -7319),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
