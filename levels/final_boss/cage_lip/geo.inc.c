#include "src/game/envfx_snow.h"

const GeoLayout cage_lip_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cage_lip_Cage_Lip_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cage_lip_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
