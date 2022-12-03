#include "src/game/envfx_snow.h"

const GeoLayout maple_tree_geo[] = {
	GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 400),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, maple_tree_Tree_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, maple_tree_Tree_001_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, maple_tree_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, maple_tree_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
