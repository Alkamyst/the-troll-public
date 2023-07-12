void scroll_final_boss_dl_Main_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 40;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(final_boss_dl_Main_mesh_layer_1_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_final_boss() {
	scroll_final_boss_dl_Main_mesh_layer_1_vtx_0();
}
