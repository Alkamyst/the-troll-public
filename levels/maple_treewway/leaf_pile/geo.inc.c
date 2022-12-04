#include "src/game/envfx_snow.h"

const GeoLayout leaf_pile_geo[] = {
	GEO_CULLING_RADIUS(800),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, leaf_pile_Circle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, leaf_pile_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
