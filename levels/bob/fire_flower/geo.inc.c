#include "src/game/envfx_snow.h"

const GeoLayout fire_flow_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_9_VERTS, 0xB4, 75),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fire_flower_Circle_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fire_flower_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
