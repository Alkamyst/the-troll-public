#include "src/game/envfx_snow.h"

const GeoLayout breakable_wall_geo[] = {
	GEO_CULLING_RADIUS(2000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, breakable_wall_Breakable_Wall_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, breakable_wall_Breakable_Wall_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, breakable_wall_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, breakable_wall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
