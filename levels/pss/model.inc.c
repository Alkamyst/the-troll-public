Lights1 pss_dl_f3dlite_material_001_lights = gdSPDefLights1(
	0x7F, 0x21, 0x23,
	0xFF, 0x4B, 0x50, 0x28, 0x28, 0x28);

Lights1 pss_dl_f3dlite_material_004_lights = gdSPDefLights1(
	0x2E, 0x5E, 0x7F,
	0x63, 0xBF, 0xFF, 0x28, 0x28, 0x28);

Lights1 pss_dl_f3dlite_material_003_lights = gdSPDefLights1(
	0x5B, 0x24, 0x7F,
	0xBA, 0x51, 0xFF, 0x28, 0x28, 0x28);

Lights1 pss_dl_f3dlite_material_002_lights = gdSPDefLights1(
	0x7F, 0x5B, 0x12,
	0xFF, 0xB9, 0x2F, 0x28, 0x28, 0x28);

Lights1 pss_dl_f3dlite_material_lights = gdSPDefLights1(
	0x65, 0x7F, 0x2B,
	0xCC, 0xFF, 0x5F, 0x28, 0x28, 0x28);

Vtx pss_dl_Cube_mesh_layer_1_vtx_0[4] = {
	{{ {-1371, -867, 1371}, 0, {370, 1079}, {127, 0, 0, 255} }},
	{{ {-1371, -867, -1371}, 0, {370, 681}, {127, 0, 0, 255} }},
	{{ {-1371, 1875, -1371}, 0, {768, 681}, {127, 0, 0, 255} }},
	{{ {-1371, 1875, 1371}, 0, {768, 1079}, {127, 0, 0, 255} }},
};

Gfx pss_dl_Cube_mesh_layer_1_tri_0[] = {
	gsSPVertex(pss_dl_Cube_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx pss_dl_Cube_mesh_layer_1_vtx_1[4] = {
	{{ {-1371, -867, -1371}, 0, {370, 823}, {0, 0, 127, 255} }},
	{{ {1371, -867, -1371}, 0, {370, 425}, {0, 0, 127, 255} }},
	{{ {1371, 1875, -1371}, 0, {768, 425}, {0, 0, 127, 255} }},
	{{ {-1371, 1875, -1371}, 0, {768, 823}, {0, 0, 127, 255} }},
};

Gfx pss_dl_Cube_mesh_layer_1_tri_1[] = {
	gsSPVertex(pss_dl_Cube_mesh_layer_1_vtx_1 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx pss_dl_Cube_mesh_layer_1_vtx_2[4] = {
	{{ {1371, -867, -1371}, 0, {370, 567}, {129, 0, 0, 255} }},
	{{ {1371, -867, 1371}, 0, {370, 169}, {129, 0, 0, 255} }},
	{{ {1371, 1875, 1371}, 0, {768, 169}, {129, 0, 0, 255} }},
	{{ {1371, 1875, -1371}, 0, {768, 567}, {129, 0, 0, 255} }},
};

Gfx pss_dl_Cube_mesh_layer_1_tri_2[] = {
	gsSPVertex(pss_dl_Cube_mesh_layer_1_vtx_2 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx pss_dl_Cube_mesh_layer_1_vtx_3[4] = {
	{{ {1371, -867, 1371}, 0, {370, 311}, {0, 0, 129, 255} }},
	{{ {-1371, -867, 1371}, 0, {370, -87}, {0, 0, 129, 255} }},
	{{ {-1371, 1875, 1371}, 0, {768, -87}, {0, 0, 129, 255} }},
	{{ {1371, 1875, 1371}, 0, {768, 311}, {0, 0, 129, 255} }},
};

Gfx pss_dl_Cube_mesh_layer_1_tri_3[] = {
	gsSPVertex(pss_dl_Cube_mesh_layer_1_vtx_3 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx pss_dl_Cube_mesh_layer_1_vtx_4[8] = {
	{{ {-1371, -867, -1371}, 0, {41, 567}, {0, 127, 0, 255} }},
	{{ {-1371, -867, 1371}, 0, {41, 169}, {0, 127, 0, 255} }},
	{{ {1371, -867, 1371}, 0, {439, 169}, {0, 127, 0, 255} }},
	{{ {1371, -867, -1371}, 0, {439, 567}, {0, 127, 0, 255} }},
	{{ {1371, 1875, -1371}, 0, {553, 567}, {0, 129, 0, 255} }},
	{{ {1371, 1875, 1371}, 0, {553, 169}, {0, 129, 0, 255} }},
	{{ {-1371, 1875, 1371}, 0, {951, 169}, {0, 129, 0, 255} }},
	{{ {-1371, 1875, -1371}, 0, {951, 567}, {0, 129, 0, 255} }},
};

Gfx pss_dl_Cube_mesh_layer_1_tri_4[] = {
	gsSPVertex(pss_dl_Cube_mesh_layer_1_vtx_4 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Gfx mat_pss_dl_f3dlite_material_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(pss_dl_f3dlite_material_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_pss_dl_f3dlite_material_004[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(pss_dl_f3dlite_material_004_lights),
	gsSPEndDisplayList(),
};

Gfx mat_pss_dl_f3dlite_material_003[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(pss_dl_f3dlite_material_003_lights),
	gsSPEndDisplayList(),
};

Gfx mat_pss_dl_f3dlite_material_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(pss_dl_f3dlite_material_002_lights),
	gsSPEndDisplayList(),
};

Gfx mat_pss_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(pss_dl_f3dlite_material_lights),
	gsSPEndDisplayList(),
};

Gfx pss_dl_Cube_mesh_layer_1[] = {
	gsSPDisplayList(mat_pss_dl_f3dlite_material_001),
	gsSPDisplayList(pss_dl_Cube_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_pss_dl_f3dlite_material_004),
	gsSPDisplayList(pss_dl_Cube_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_pss_dl_f3dlite_material_003),
	gsSPDisplayList(pss_dl_Cube_mesh_layer_1_tri_2),
	gsSPDisplayList(mat_pss_dl_f3dlite_material_002),
	gsSPDisplayList(pss_dl_Cube_mesh_layer_1_tri_3),
	gsSPDisplayList(mat_pss_dl_f3dlite_material),
	gsSPDisplayList(pss_dl_Cube_mesh_layer_1_tri_4),
	gsSPEndDisplayList(),
};

Gfx pss_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

