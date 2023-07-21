void scroll_jrb_dl_Main_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 39;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Main_mesh_layer_1_vtx_5);

	deltaY = (int)(1.399999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_Main_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 19;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Main_mesh_layer_1_vtx_6);

	deltaY = (int)(1.399999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_Main_mesh_layer_1_vtx_9() {
	int i = 0;
	int count = 8;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Main_mesh_layer_1_vtx_9);

	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_Main_mesh_layer_1_vtx_20() {
	int i = 0;
	int count = 56;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Main_mesh_layer_1_vtx_20);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_jrb() {
	scroll_jrb_dl_Main_mesh_layer_1_vtx_5();
	scroll_jrb_dl_Main_mesh_layer_1_vtx_6();
	scroll_jrb_dl_Main_mesh_layer_1_vtx_9();
	scroll_jrb_dl_Main_mesh_layer_1_vtx_20();
}
