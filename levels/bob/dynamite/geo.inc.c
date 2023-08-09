#include "src/game/envfx_snow.h"

const GeoLayout dynamite_geo[] = {
	GEO_CULLING_RADIUS(2000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dynamite_TNT_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dynamite_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};