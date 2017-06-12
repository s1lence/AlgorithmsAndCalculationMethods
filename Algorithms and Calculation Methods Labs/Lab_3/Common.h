/***
*file:"Common.h"
*synopsis:common defines
*author: R. Neshta
*written: -/-/- ~ date lost
*last modified: 12/06/17
****/

#ifndef _COMMON_H
#define _COMMON_H

#include <math.h>

#define LINES 4
#define COLUMNS 5

#define MATRIX {3,19,11,8,149, 9,31,3,18,257, 11,7,32,13,143, 12,19,12,5,144}

//about transforming matrix:
/*
 matrix:
 3,  19, 11,  8, 149, {1} max=2
 9,  31,  3, 18, 257, {2} max=2
11,   7, 32, 13, 143, {3} max=3
12,  19, 12,  5, 144  {4} max=2

2nd & 3rd I'm leaving on their own places
1st = {4} - {1}
4th = {2} + {3} - {4} - {1}:
	20 38 35 31 400 | = {2} + {3}
	 8 19 23 26 256 | = {2} + {3} - {4}
	 5  0 12 18 107 | = {2} + {3} - {4} - {1}

transformed matrix:
 9,   0,   1,  -3,  -5,  {4} - {1} 
 9,  31,   3,  18, 257,  {2}
11,   7,  32,  13, 143,  {3} 
 5,   0,  12,  18, 107   {2} + {3} - {4} - {1}


*/

#define TRANSFORMED {9,0,1,-3,-5, 9,31,3,18,257, 11,7,32,13,143, 5,0,12,18,107}

#endif