#include "src/game/envfx_snow.h"

const GeoLayout red_coin_bars_geo[] = {
	GEO_CULLING_RADIUS(2000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, red_coin_bars_Bars_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, red_coin_bars_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
