#ifndef __ENH_API_H__
#define __ENH_API_H__

typedef struct {
   kal_uint32 enhance_pars[28];
   kal_uint32 error_flag;
   kal_int32  App_table;
   kal_int32  Fea_Cfg_table;
   kal_int32  PGA_gain;
   kal_int32  sample_rate;
   kal_int32  frame_rate;
   kal_int16  DMNR_cal_data[76];
   kal_int16  Compen_filter[270];
   kal_int16  ne_out[960];
   kal_int16  fe_out[960];
   kal_int16  PCM_buffer[1920];
   kal_int16  EPL_buffer[6080];
} SPH_ENH_ctrl_struct;


kal_int16 ENH_API_Rst( SPH_ENH_ctrl_struct *Sph_Enh_ctrl);
kal_int32 ENH_API_Get_Memory(SPH_ENH_ctrl_struct *Sph_Enh_ctrl);
kal_int16 ENH_API_Alloc(SPH_ENH_ctrl_struct *Sph_Enh_ctrl, kal_int32 *mem_ptr );
void ENH_API_Process( SPH_ENH_ctrl_struct *Sph_Enh_ctrl);
kal_int16  ENH_API_Free( void );

#endif
