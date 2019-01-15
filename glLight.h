
class glLight {
private:
	float light_ambi[4] = { 0.8, 0.8, 0.8, 1.0 };
	float light_diff[4] = { 0.5, 0.5, 0.5, 1.0 };
	float light_spec[4] = { 0.2, 0.2, 0.2, 1.0 };
	float light_emi[4] = { 1.0, 1.0, 1.0, 1.0 };
	float light_format[4] = { 0, 0, 0, 1.0 };
public:
	void glLight_init();
	void glLight_create_light(float light_pos[3]);
	void glLight_set_object_light(float ambi[4], float diff[4], float spec[4]);
	void glLight_set_light_format();
	void glLight_set_object_emi(float emi[4]);
	void glLight_set_emission_format();
};