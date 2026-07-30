/*
 * LIB_Atan2.c
 *
 *  Created on: 2017-2-24
 *     
 */


#include "Platform_Types.h"
/*
 **********************************************************************************************************************
 * CmnLib_Atan2_r32r32_u16
 *
 * arctan2-calculation
 *
 * Calculates the angle of a sine and a cosine value
 * The result is in the range 0..65535 which equates to [0?.360°[ or [0..2Pi[
 *
 * \param   float32  y                Operand 1, float32 (sine value / y-coordinate)
 * \param   float32  x                Operand 2, float32 (cosine value / x-coordinate)
 * \return  uint16   arctan2(y, x)    Result,    unsigned 16-bit
 **********************************************************************************************************************
 */
uint16 CmnLib_Atan2_r32r32_u16_Inl(float32 y, float32 x)
{
	float32 yAbs, tanTmp, tanTmpSqd, agOffs, agResFloat;
	uint16 agRes;
	uint32 yIntgrAbs;

	yIntgrAbs = (*(uint32*)((void*)&y)) & 0x7FFFFFFFul; /*// get absoulute value of float value*/
	yAbs = (*(float32*)((void*)&yIntgrAbs)) + 0.000001f; /*// add small value to prevent from division by 0*/
           
    /*
	// cos(x) - sin(x) = sqrt(2) * cos(x+45? = -sqrt(2) * sin(x-45?
	// cos(x) + sin(x) = sqrt(2) * sin(x+45? = sqrt(2) * cos(x-45?
	//
	// => (cos(x) - sin(x))/(cos(x) + sin(x)) = -tan(x - 45?
*/
	if (x >= 0) {
		tanTmp = (x - yAbs) / (x + yAbs);
		agOffs = 8192.5f; /*// 45.5? add 0.5 for correct rounding to integer*/
	} else {
		tanTmp = (x + yAbs) / (yAbs - x);
		agOffs = 24576.5f;/* // 135.5? add 0.5 for correct rounding to integer*/
	}
	tanTmpSqd = tanTmp * tanTmp;
	agResFloat = agOffs + tanTmp * (-10422.1870340246f + tanTmpSqd * (3349.99555759015f + tanTmpSqd * (-1525.57116063464f + tanTmpSqd * (406.609454309193f ))));
	agRes = (uint16)agResFloat;

	if (y < 0) {
		agRes = (uint16)-agRes;
	}
	return agRes;
}


