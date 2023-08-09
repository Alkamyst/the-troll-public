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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 
	LOAD_MODEL_FROM_GEO(MODEL_WALL_JUMP_SLIP, wall_jump_slip_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_COIN_BARS, red_coin_bars_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CCM, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CCM, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_AMP, -11, 440, 2636, 0, -180, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_NONE, 2925, 727, 915, 0, -180, 0, (1 << 16), bhvCoinFormation),
		OBJECT(MODEL_RED_COIN, -2957, 360, -3152, 0, -180, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_RED_COIN, 1617, 843, -6585, 0, -180, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_RED_COIN, 1441, 229, 1419, 0, -180, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_GOOMBA, 4637, 55, -198, 0, -180, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_BREAKABLE_BOX, 1602, 194, -2660, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -6, 371, -2168, 0, 90, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -496, 448, -2168, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -696, 648, -2168, 0, 90, 0, (0 << 16), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -896, 848, -2168, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1602, 289, -3226, 0, 0, 0, (0 << 16), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1602, 366, -3804, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1602, 458, -4366, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1602, 553, -4932, 0, 0, 0, (0 << 16), bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 1602, 631, -5510, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 577, 305, -2168, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 777, 305, -2168, 0, 90, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_METAL_BOX, 2925, 279, -283, 0, 90, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_PURPLE_SWITCH, 1602, 229, -1776, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, -1487, 229, 1419, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 554, 229, 3883, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5072, 1510, -1565, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1932, 1423, -3150, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -14, 1299, -936, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2925, 1341, 915, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 554, 229, 3883, 0, -180, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN_BARS, -28, 49, -493, 0, 0, 0, 0x00000000, bhvRedCoinBars),
		OBJECT(MODEL_STAR, -7, 358, -1400, 0, -180, 0, 0x00000000, bhvFakeStar),
		OBJECT(MODEL_THE_TROLL, -487, 49, 44, 0, 51, 0, (19 << 16), bhvTrollInteract),
		OBJECT(MODEL_WALL_JUMP_SLIP, -5428, 1386, -882, 0, 0, 0, 0x00000000, bhvWallJumpSlip),
		OBJECT(MODEL_NONE, -7, 136, 315, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, -7, 136, 315),
		OBJECT(MODEL_NONE, -7, 358, 315, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x24, SEQ_NSMBW_CASTLE),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -7, 136, 315),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
