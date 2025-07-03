#include "game_include/gen_data/gen_player_lanechange.h"

/********************************************************************************************************
 *   THIS FILE WAS GENERATED          DO NOT EDIT!!! 
 *   make changes in custom_tools/lut_gen/gen_object_path.py
 *
 *
 *   AUTHOR: laserbluejay / cxlledjay, 2025
 *******************************************************************************************************/


#define LCS0_CNT_P1		(8u)
#define LCS0_CNT_P2		(8u)

#define LCS1_CNT_P1		(6u)
#define LCS1_CNT_P2		(6u)

#define LCS2_CNT_P1		(4u)
#define LCS2_CNT_P2		(4u)

#define LCS3_CNT_P1		(3u)
#define LCS3_CNT_P2		(2u)

#define LCS4_CNT_P1		(2u)
#define LCS4_CNT_P2		(1u)




const int		 _LCS0_LM_P1[LCS0_CNT_P1] = {-45, -50, -54, -59, -63, -68, -72, -77 };
const int		 _LCS0_LM_P2[LCS0_CNT_P2] = {-9, -13, -18, -22, -27, -31, -36, -41 };
const int		 _LCS0_MR_P1[LCS0_CNT_P1] = {36, 31, 27, 22, 18, 13, 9, 4 };
const int		 _LCS0_MR_P2[LCS0_CNT_P2] = {72, 68, 63, 59, 54, 50, 45, 41 };
const int		 _LCS0_RM_P1[LCS0_CNT_P1] = {45, 50, 54, 59, 63, 68, 72, 77 };
const int		 _LCS0_RM_P2[LCS0_CNT_P2] = {9, 13, 18, 22, 27, 31, 36, 41 };
const int		 _LCS0_ML_P1[LCS0_CNT_P1] = {-36, -31, -27, -22, -18, -13, -9, -4 };
const int		 _LCS0_ML_P2[LCS0_CNT_P2] = {-72, -68, -63, -59, -54, -50, -45, -41 };

const int		 _LCS1_LM_P1[LCS1_CNT_P1] = {-46, -52, -58, -64, -70, -76 };
const int		 _LCS1_LM_P2[LCS1_CNT_P2] = {-11, -17, -23, -29, -35, -41 };
const int		 _LCS1_MR_P1[LCS1_CNT_P1] = {35, 29, 23, 17, 11, 5 };
const int		 _LCS1_MR_P2[LCS1_CNT_P2] = {70, 64, 58, 52, 46, 41 };
const int		 _LCS1_RM_P1[LCS1_CNT_P1] = {46, 52, 58, 64, 70, 76 };
const int		 _LCS1_RM_P2[LCS1_CNT_P2] = {11, 17, 23, 29, 35, 41 };
const int		 _LCS1_ML_P1[LCS1_CNT_P1] = {-35, -29, -23, -17, -11, -5 };
const int		 _LCS1_ML_P2[LCS1_CNT_P2] = {-70, -64, -58, -52, -46, -41 };

const int		 _LCS2_LM_P1[LCS2_CNT_P1] = {-49, -57, -65, -73 };
const int		 _LCS2_LM_P2[LCS2_CNT_P2] = {-16, -24, -32, -41 };
const int		 _LCS2_MR_P1[LCS2_CNT_P1] = {32, 24, 16, 8 };
const int		 _LCS2_MR_P2[LCS2_CNT_P2] = {65, 57, 49, 41 };
const int		 _LCS2_RM_P1[LCS2_CNT_P1] = {49, 57, 65, 73 };
const int		 _LCS2_RM_P2[LCS2_CNT_P2] = {16, 24, 32, 41 };
const int		 _LCS2_ML_P1[LCS2_CNT_P1] = {-32, -24, -16, -8 };
const int		 _LCS2_ML_P2[LCS2_CNT_P2] = {-65, -57, -49, -41 };

const int		 _LCS3_LM_P1[LCS3_CNT_P1] = {-46, -58, -70 };
const int		 _LCS3_LM_P2[LCS3_CNT_P2] = {-23, -35 };
const int		 _LCS3_MR_P1[LCS3_CNT_P1] = {35, 23, 11 };
const int		 _LCS3_MR_P2[LCS3_CNT_P2] = {58, 46 };
const int		 _LCS3_RM_P1[LCS3_CNT_P1] = {46, 58, 70 };
const int		 _LCS3_RM_P2[LCS3_CNT_P2] = {23, 35 };
const int		 _LCS3_ML_P1[LCS3_CNT_P1] = {-35, -23, -11 };
const int		 _LCS3_ML_P2[LCS3_CNT_P2] = {-58, -46 };

const int		 _LCS4_LM_P1[LCS4_CNT_P1] = {-49, -65 };
const int		 _LCS4_LM_P2[LCS4_CNT_P2] = {-32 };
const int		 _LCS4_MR_P1[LCS4_CNT_P1] = {32, 16 };
const int		 _LCS4_MR_P2[LCS4_CNT_P2] = {49 };
const int		 _LCS4_RM_P1[LCS4_CNT_P1] = {49, 65 };
const int		 _LCS4_RM_P2[LCS4_CNT_P2] = {32 };
const int		 _LCS4_ML_P1[LCS4_CNT_P1] = {-32, -16 };
const int		 _LCS4_ML_P2[LCS4_CNT_P2] = {-49 };

const player_lane_change_t player_lane_change_phase1 =
{
	.FRAME_CNT =
	{
		LCS0_CNT_P1, LCS0_CNT_P1, LCS0_CNT_P1, LCS1_CNT_P1, LCS1_CNT_P1, LCS1_CNT_P1, LCS2_CNT_P1, LCS2_CNT_P1, LCS3_CNT_P1, LCS3_CNT_P1, LCS4_CNT_P1
	},
	.animation_tick = &_player_lanechange_tick_phase1,
	.x_LUT =
	{
		.left_to_mid =
		{
			_LCS0_LM_P1, _LCS0_LM_P1, _LCS0_LM_P1, _LCS1_LM_P1, _LCS1_LM_P1, _LCS1_LM_P1, _LCS2_LM_P1, _LCS2_LM_P1, _LCS3_LM_P1, _LCS3_LM_P1, _LCS4_LM_P1
		},
		.mid_to_right =
		{
			_LCS0_MR_P1, _LCS0_MR_P1, _LCS0_MR_P1, _LCS1_MR_P1, _LCS1_MR_P1, _LCS1_MR_P1, _LCS2_MR_P1, _LCS2_MR_P1, _LCS3_MR_P1, _LCS3_MR_P1, _LCS4_MR_P1
		},
		.right_to_mid =
		{
			_LCS0_RM_P1, _LCS0_RM_P1, _LCS0_RM_P1, _LCS1_RM_P1, _LCS1_RM_P1, _LCS1_RM_P1, _LCS2_RM_P1, _LCS2_RM_P1, _LCS3_RM_P1, _LCS3_RM_P1, _LCS4_RM_P1
		},
		.mid_to_left =
		{
			_LCS0_ML_P1, _LCS0_ML_P1, _LCS0_ML_P1, _LCS1_ML_P1, _LCS1_ML_P1, _LCS1_ML_P1, _LCS2_ML_P1, _LCS2_ML_P1, _LCS3_ML_P1, _LCS3_ML_P1, _LCS4_ML_P1
		}
	}
};

const player_lane_change_t player_lane_change_phase2 =
{
	.FRAME_CNT =
	{
		LCS0_CNT_P2, LCS0_CNT_P2, LCS0_CNT_P2, LCS1_CNT_P2, LCS1_CNT_P2, LCS1_CNT_P2, LCS2_CNT_P2, LCS2_CNT_P2, LCS3_CNT_P2, LCS3_CNT_P2, LCS4_CNT_P2
	},
	.animation_tick = &_player_lanechange_tick_phase2,
	.x_LUT =
	{
		.left_to_mid =
		{
			_LCS0_LM_P2, _LCS0_LM_P2, _LCS0_LM_P2, _LCS1_LM_P2, _LCS1_LM_P2, _LCS1_LM_P2, _LCS2_LM_P2, _LCS2_LM_P2, _LCS3_LM_P2, _LCS3_LM_P2, _LCS4_LM_P2
		},
		.mid_to_right =
		{
			_LCS0_MR_P2, _LCS0_MR_P2, _LCS0_MR_P2, _LCS1_MR_P2, _LCS1_MR_P2, _LCS1_MR_P2, _LCS2_MR_P2, _LCS2_MR_P2, _LCS3_MR_P2, _LCS3_MR_P2, _LCS4_MR_P2
		},
		.right_to_mid =
		{
			_LCS0_RM_P2, _LCS0_RM_P2, _LCS0_RM_P2, _LCS1_RM_P2, _LCS1_RM_P2, _LCS1_RM_P2, _LCS2_RM_P2, _LCS2_RM_P2, _LCS3_RM_P2, _LCS3_RM_P2, _LCS4_RM_P2
		},
		.mid_to_left =
		{
			_LCS0_ML_P2, _LCS0_ML_P2, _LCS0_ML_P2, _LCS1_ML_P2, _LCS1_ML_P2, _LCS1_ML_P2, _LCS2_ML_P2, _LCS2_ML_P2, _LCS3_ML_P2, _LCS3_ML_P2, _LCS4_ML_P2
		}
	}
};

