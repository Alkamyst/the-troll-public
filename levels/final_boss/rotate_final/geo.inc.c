#include "src/game/envfx_snow.h"

const GeoLayout rotate_final_geo[] = {
	GEO_CULLING_RADIUS(4000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rotate_final_Rotate_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rotate_final_Rotate_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rotate_final_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rotate_final_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
