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
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 
	LOAD_MODEL_FROM_GEO(MODEL_TARGET, Target_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SHELLDOOR, ShellDoor_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FALLING_STAGE_1, falling_stage_1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_FALLING_STAGE_2, falling_stage_2_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, 1147, 516, -1326, 0, -45, 0, (99 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1989, 2785, -476, 0, 0, 0, (1 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1989, 5331, -505, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_YELLOW_COIN, -2226, 1245, -5276, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_SHELLDOOR, -2522, 4951, 1345, 0, 90, 0, (2 << 16), bhvKeyDoor),
		OBJECT(MODEL_SHELLDOOR, -4642, 5382, 1345, 0, 90, 0, (2 << 16), bhvKeyDoor),
		OBJECT(MODEL_SHELLDOOR, -6504, 5382, -2128, 0, 0, 0, (2 << 16), bhvKeyDoor),
		OBJECT(MODEL_FALLING_STAGE_1, -3557, 5382, 1964, 0, 0, 0, 0x00000000, bhvFallingStage1),
		OBJECT(MODEL_FALLING_STAGE_2, -5900, 5382, 741, 0, 0, 0, (1 << 16), bhvFallingStage2),
		OBJECT(MODEL_HEAVE_HO, -661, 3886, -307, 0, 146, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_BREAKABLE_BOX, -822, 1207, -2747, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -622, 1007, -2747, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -422, 807, -2747, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -222, 607, -2747, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -22, 407, -2747, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BULLET_BILL, -2226, 1404, -5681, 0, 0, 0, 0x00000000, bhvInstantBulletBill),
		OBJECT(MODEL_PURPLE_SWITCH, 26, 407, -4932, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_KOOPA_SHELL, -1996, 4951, 1345, 0, 0, 0, 0x00000000, bhvThrowShell),
		OBJECT(MODEL_SPINDRIFT, -875, 2816, -1345, 0, -127, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_TARGET, -1996, 5162, 3279, 0, -180, 0, 0x00000000, bhvTarget),
		OBJECT(MODEL_TARGET, -8526, 5674, -638, 0, 90, 0, (1 << 16), bhvTarget),
		OBJECT(MODEL_TARGET, -8765, 5674, -638, 0, 90, 0, (1 << 16), bhvTargetFall),
		OBJECT(MODEL_TARGET, -4018, 5598, 3279, 0, -180, 0, 0x00000000, bhvTarget),
		OBJECT(MODEL_NONE, 0, 178, 0, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, 0, 178, 0),
		OBJECT(MODEL_NONE, 0, 358, 0, 0, -180, 0, 0x000B0000, bhvAirborneDeathWarp),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 178, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
