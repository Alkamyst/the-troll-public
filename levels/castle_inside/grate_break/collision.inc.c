const Collision grate_break_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(0, 0, -271),
	COL_VERTEX(0, 0, 0),
	COL_VERTEX(0, -278, 0),
	COL_VERTEX(0, -278, -271),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
