#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define f 16384 // f = 2**14

int fix_2_int (int x){
	return x > 0 ? (x+f/2)/f : (x-f/2)/f;
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

int main(int argc, char *argv[]){


printf("fix_2_int: %d, %d\n", 59, fix_2_int (59));
printf("int_2_fix: %d, %d\n", 59, int_2_fix (59));
printf("fix_add_int: %d+%d --  %d\n", 59, 60, fix_add_int(59, 60));
printf("fix_minus_int: %d-%d -- %d\n", 60, 59, fix_minus_int(60, 59));
printf("fix_multiply_fix: %d*%d, %d\n", 59, 60, fix_multiply_fix (59, 60));
printf("fix_multiply_int: %d*%d, %d\n", 59, 60, fix_multiply_int (59, 60));
printf("fix_divide_fix: %d divide %d, %d\n", 966656, 57, fix_divide_fix (966656, 57));
printf("fix_divide_int: %d divide %d, %d\n", 966656, 57, fix_divide_int (966656, 57));

	return 0;
}
