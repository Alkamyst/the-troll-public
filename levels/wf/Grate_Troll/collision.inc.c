const Collision Grate_Troll_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-333, 703, 0),
	COL_VERTEX(-333, 0, 0),
	COL_VERTEX(333, 0, 0),
	COL_VERTEX(333, 703, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 4),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(0, 3, 2),
	COL_TRI(0, 2, 1),
	COL_TRI_STOP(),
	COL_END()
};
