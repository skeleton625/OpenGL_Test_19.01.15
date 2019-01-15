#include "glLight.h"

class glDisplay {
private:
	float cam_pos[3];
	float light_pos[3];
	glLight light;
public:
	void glDis_display();
	void glDis_create_object();
	void glDis_create_background();
	void glDis_get_texID(unsigned int* tex_id);
	void glDis_press_norKey(unsigned char key);
	void glDis_press_specKey(int key);
};