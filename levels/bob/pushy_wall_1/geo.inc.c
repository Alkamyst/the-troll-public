#include "src/game/envfx_snow.h"

const GeoLayout pushy_wall_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pushy_wall_1_Cube_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, pushy_wall_1_Cube_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pushy_wall_1_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, pushy_wall_1_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
