#include "Platform_Types.h"
/*
 **********************************************************************************************************************
 * Lib_InvSqrt_r32_r32
 *
 * inverse square-root calculation
 *
 * Calculates the inverse of the square-root of x
 * Restrictions: it has to be ensured that x > 0. Otherwise wrong results are returned
 *
 * \param   float32  x                Operand,  32bit float value, only values >0 are allowed
 * \return  float32  1/sqrt(x)        Result,   32bit float value
 **********************************************************************************************************************
 */
 float32 Lib_InvSqrt_r32_r32(float32 x)
{
	uint32 xIntgr, yIntgr;
	float32 xHalf, y;
	uint8 cntrLoop;

	xHalf = 0.5f * x;
	xIntgr = (*(uint32*)((void*)&x));
	yIntgr = 0x5F375A86 - (xIntgr >>1); /* best guess for 1/sqrt(|x|) by doing an "evil hack"*/
	y = (*(float32*)((void*)&yIntgr));
	for(cntrLoop = 0; cntrLoop <= 1; cntrLoop++) {
		y = y * (1.5f - (xHalf * y * y)); /* steps of newton iteration*/
	}
	return y;
}

/*
 **********************************************************************************************************************
 * Lib_InvSqrt_s32_s32
 *
 * inverse square-root calculation
 *
 * Calculates the inverse of the square-root of x
 * Restrictions: it has to be ensured that x > 0. Otherwise wrong results are returned
 *
 * \param   sint32  x                 Operand,  32bit signed integer value, only values >0 are allowed
 * \return  sint32  1/sqrt(x)         Result,   32bit signed integer value
 **********************************************************************************************************************
 */
 sint32 Lib_InvSqrt_s32_s32(sint32 x)
{
	return (sint32)(1073741824.0f * Lib_InvSqrt_r32_r32((float32)x));
}


/*
 **********************************************************************************************************************
 * Lib_Sqrt_r32_r32
 *
 * square-root calculation
 *
 * Calculates the square-root of x
 * Restrictions: it has to be ensured that x >= 0. Otherwise wrong results are returned
 *
 * \param   float32  x                Operand,  32bit float value, only values >=0 are allowed
 * \return  float32  sqrt(x)          Result,   32bit float value
 **********************************************************************************************************************
 */
 float32 Lib_Sqrt_r32_r32(float32 x)
{
	return x * Lib_InvSqrt_r32_r32(x);
}

/*
 **********************************************************************************************************************
 * Lib_Sqrt_s32_s16
 *
 * square-root calculation
 *
 * Calculates the square-root of x
 * Restrictions: it has to be ensured that x >= 0. Otherwise wrong results are returned
 *
 * \param   sint32  x                 Operand,  32bit signed integer value, only values >=0 are allowed
 * \return  sint16  sqrt(x)           Result,   16bit signed integer value
 **********************************************************************************************************************
 */
 sint16 Lib_Sqrt_s32_s16(sint32 x)
{
	return (sint16)((float32)x * Lib_InvSqrt_r32_r32((float32)x));
}
