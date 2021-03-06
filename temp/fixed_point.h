#ifndef FIXED_POINT_H
#define FIXED_POINT_H


#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define f 16384 // f = 2**14

int fix_2_int (int x){
//	return x > 0 ? (x+f/2)/f : (x-f/2)/f; // round to nearest
	return x/f; // round to zero
}

int int_2_fix (int x){
	return (x*f);
}

int fix_add_int(int x, int n){
	return (x+n*f);
}

int fix_minus_int(int x, int n){
	return (x-n*f);
}

int fix_multiply_fix (int x, int y){
	return ((int64_t)x)*y/f;
}

int int_multiply_int (int x, int y){
	return ((int64_t)x)*y*f;
}

int fix_multiply_int (int x, int n){
	return x*n;
}

int fix_divide_fix (int x, int y){
	return ((int64_t)x)*f/y;
}

int fix_divide_int (int x, int n){
	return (x/n);
}

int int_divide_int (int x, int y){
	return ((int64_t)x)*f/y;
}


#endif
