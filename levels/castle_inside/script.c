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
#include "levels/castle_inside/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP, castle_geo_000F18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND, castle_geo_001530), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND, castle_geo_001548), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM, castle_geo_001518), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_GRATE_BREAK, grate_break_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SECRET_CRACK, secret_crack_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x02, 0x0C, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1287, 224, 174, 0, -90, 0, (11 << 16), bhvSignOnWall),
		OBJECT(MODEL_NONE, -1247, 206, -414, 0, 90, 0, (10 << 16), bhvSignOnWall),
		OBJECT(MODEL_STAR, 1374, 172, -4407, 0, 90, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_THE_TROLL, 1586, -119, -3833, 0, -157, 0, 0x00000000, bhvTrollEngage),
		OBJECT(MODEL_NONE, 20, 566, 2658, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, 20, 566, 2658),
		OBJECT(MODEL_NONE, 37, 108, 57, 0, 90, 0, (0x0B << 16), bhvWarp),
		OBJECT(MODEL_NONE, 20, 526, 2982, 0, 90, 0, 0x140B0000, bhvWarp),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, castle_inside_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE, 0x02, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_CASTLE, 0x02, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_CASTLE, 0x02, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_CASTLE, 0x02, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0F, LEVEL_FINAL_BOSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x15, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GRATE_BREAK, 5129, 1393, -296, 0, 0, 0, (2 << 16), bhvGrateBreak),
		OBJECT(MODEL_NONE, -1247, 206, -414, 0, 90, 0, (10 << 16), bhvSignOnWall),
		OBJECT(MODEL_NONE, 1287, 224, 174, 0, -90, 0, (11 << 16), bhvSignOnWall),
		OBJECT(MODEL_NONE, -9029, 428, -2691, 0, 0, 0, (12 << 16), bhvSignOnWall),
		OBJECT(MODEL_NONE, -9029, 428, -2891, 0, -180, 0, (12 << 16), bhvSignOnWall),
		OBJECT(MODEL_SECRET_CRACK, 7604, 100, -3136, 0, 0, 0, (2 << 16), bhvSecretCrack),
		OBJECT(MODEL_KOOPA_SHELL, 5583, 751, -4221, 0, 90, 0, 0x00000000, bhvThrowShell),
		OBJECT(MODEL_NONE, 6525, 426, -3232, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 4515, 1115, -430, 0, 90, 0, 0x030B0000, bhvWarp),
		OBJECT(MODEL_NONE, 1719, 1174, 721, 0, -90, 0, 0x030C0000, bhvWarp),
		OBJECT(MODEL_NONE, 8078, 100, -3136, 0, -90, 0, 0x030D0000, bhvWarp),
		OBJECT(MODEL_NONE, -10092, 100, -1209, 0, 90, 0, 0x030E0000, bhvWarp),
		OBJECT(MODEL_NONE, -2187, -307, -6171, 0, -90, 0, 0x140F0000, bhvWarp),
		OBJECT(MODEL_NONE, -1500, -228, -6171, 0, -90, 0, 0x00150000, bhvAirborneDeathWarp),
		TERRAIN(castle_inside_area_2_collision),
		MACRO_OBJECTS(castle_inside_area_2_macro_objs),
		SHOW_DIALOG(/*index*/ 0x00, DIALOG_008),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 20, 566, 2658),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
