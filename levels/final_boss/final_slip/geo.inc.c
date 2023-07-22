#include "src/game/envfx_snow.h"

const GeoLayout final_slip_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, final_slip_Final_Slip_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, final_slip_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
