#include "src/game/envfx_snow.h"

const GeoLayout checkpoint_mario_geo[] = {
	GEO_CULLING_RADIUS(2000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, checkpoint_mario_Checkpoint_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, checkpoint_mario_Checkpoint_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, checkpoint_mario_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, checkpoint_mario_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
