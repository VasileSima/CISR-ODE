
// *** Warning:
// *** auto-generated file and subjected to be overwritten

// path: ./app_models/classical_washoutfilter/autogenerated/user_template.hpp

// inputs

	// u0	surge_acc
	// u1	pitch_angle

	u(inputs::surge_acc)=...
	u(inputs::pitch_angle)=...

// intermediates

	// m0	surge_input_acc_ref
	// m1	surge_hp_out
	// m2	surge_kin_acc
	// m3	surge_kin_vel
	// m4	surge_kin_pos
	// m5	surge_lp_out
	// m6	tilt_coordination
	// m7	pitch_input_angle_ref
	// m8	pitch_hp_out
	// m9	pitch_angle
	// m10	tilt_force
	// m11	specific_force

	mid(mids::surge_input_acc_ref)=...
	mid(mids::surge_hp_out)=...
	mid(mids::surge_kin_acc)=...
	mid(mids::surge_kin_vel)=...
	mid(mids::surge_kin_pos)=...
	mid(mids::surge_lp_out)=...
	mid(mids::tilt_coordination)=...
	mid(mids::pitch_input_angle_ref)=...
	mid(mids::pitch_hp_out)=...
	mid(mids::pitch_angle)=...
	mid(mids::tilt_force)=...
	mid(mids::specific_force)=...

// states

	// x0	surge_hp_x1
	// x1	surge_hp_x2
	// x2	surge_kin_vel
	// x3	surge_kin_pos
	// x4	surge_lp_x1
	// x5	surge_lp_x2
	// x6	pitch_hp_x1

	x_dot(states::surge_hp_x1)=...
	x_dot(states::surge_hp_x2)=...
	x_dot(states::surge_kin_vel)=...
	x_dot(states::surge_kin_pos)=...
	x_dot(states::surge_lp_x1)=...
	x_dot(states::surge_lp_x2)=...
	x_dot(states::pitch_hp_x1)=...
