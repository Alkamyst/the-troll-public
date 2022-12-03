#include "src/game/envfx_snow.h"

const GeoLayout chestnut_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 400),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chestnut_Sphere_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chestnut_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
