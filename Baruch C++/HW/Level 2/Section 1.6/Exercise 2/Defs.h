/*
 * @Objective: Define macros to get the maximum of two or three numbers.
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/05/21
 */

#ifndef MAX2
#define MAX2(x, y) ((x > y) ? x : y)
#endif

#ifndef MAX3
#define MAX3(x, y, z) (MAX2(MAX2(x, y), z))
#endif