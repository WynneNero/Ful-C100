#ifndef APA_LM_ULTRA_H
#define APA_LM_ULTRA_H

extern float ultra_C_point[2];
//extern float ultra_B_point[2];
extern float ultra_left_kb[2];
extern float ultra_right_kb[2];

extern float ultra_left_point[2];
extern float ultra_right_point[2];
extern float ultra_left_point1[2];
extern float ultra_left_point2[2];
extern float ultra_left_point3[2];
extern float ultra_right_point1[2];
extern float ultra_right_point2[2];
extern float ultra_right_point3[2];

//extern float SRRML_obstacle_out[3];
//extern float SRRMR_obstacle_out[3];

extern float ultra_final_num[2];

extern void UltraScanMapGenerate(int i_gear_state, int current_step,int total_step,float vehicle_pos_x, float vehicle_pos_y, float vehicle_yaw,float *m_d_ultrasonic_distance);

//extern void InitUltraScan(int parking_type,float f_tracking_end_x, float f_tracking_end_y, float f_tracking_end_yaw,float A_x, float A_y, float B_x, float B_y, float C_x, float C_y, float D_x, float D_y);
#endif
