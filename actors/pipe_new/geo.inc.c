#include "src/game/envfx_snow.h"

const GeoLayout pipe_new_geo[] = {
	GEO_CULLING_RADIUS(2000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pipe_new_Pipe_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, pipe_new_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
