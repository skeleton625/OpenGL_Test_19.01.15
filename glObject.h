
class glObject {
private:
	float x, y, z;
	unsigned int tex_id;
	const float tex[4][2] = {
		{0,0},
		{0,1},
		{1,1},
		{1,0}
	};
	const float plane[4][3] = {
		{1,0,1},{1,0,-1},
		{-1,0,-1},{-1,0,1}
	};
	const float cube[6][4][3] = {
		{ {-1, -1, 1}, {-1, 1, 1}, {1, 1, 1}, {1, -1, 1} },
		{ {-1, -1, -1}, {-1, 1, -1}, {1, 1, -1}, {1, -1, -1} },
		{ {-1, -1, 1}, {-1, -1, -1}, {-1, 1, -1}, {-1, 1, 1} },
		{ {1, -1, 1}, {1, -1, -1}, {1, 1, -1}, {1, 1, 1} },
		{ {-1, -1, 1}, {1, -1, 1}, {1, -1, -1}, {-1, -1, -1} },
		{ {-1, 1, 1}, {1, 1, 1}, {1, 1, -1}, {-1, 1, -1} }
	};
public:
	void set_texID(unsigned int tex_id);
	float getX(); float getY(); float getZ();
	void setX(float x); void setY(float y); void set(float z);
	void glObject_create_plane(float size[3]);
	void glObject_create_cube(float size[3]);
	void glObject_create_sphere(float size[3]);
	void glObject_create_cylinder(float size[3]);
};