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
#include "levels/maple_treewway/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_maple_treewway_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _maple_treewway_segment_7SegmentRomStart, _maple_treewway_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEAF_PILE, leaf_pile_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CHESTNUT, chestnut_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GOLDEN_CHESTNUT, golden_chestnut_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, maple_treewway_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CHESTNUT, -1313, 446, -1108, 0, 0, 0, (0 << 16), bhvLuigimanChestnut),
		OBJECT(MODEL_CHESTNUT, -749, 446, -1108, 0, 0, 0, (1 << 16), bhvLuigimanChestnut),
		OBJECT(MODEL_GOLDEN_CHESTNUT, -6, 100, -3250, 0, 0, 0, (0 << 16), bhvLuigimanGoldenChestnut),
		OBJECT(MODEL_LEAF_PILE, 1104, 100, 14, 0, 0, 0, (1 << 16), bhvLuigimanLeafPile),
		OBJECT(MODEL_LEAF_PILE, 1104, 100, -484, 0, 0, 0, (0 << 16), bhvLuigimanLeafPile),
		OBJECT(MODEL_LEAF_PILE, 1104, 100, 511, 0, 0, 0, (2 << 16), bhvLuigimanLeafPile),
		OBJECT(MODEL_METAL_BOX, 910, 100, -3250, 0, 0, 0, (0 << 16), bhvPushableMetalBox),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(maple_treewway_area_1_collision),
		MACRO_OBJECTS(maple_treewway_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
