#ifndef FIXED_POINT_H
#define FIXED_POINT_H
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#define f 16384 // f = 2**14
#define SHIFT 14

int fix_2_int (int x){
	//return x > 0 ? (x+f/2)/f : (x-f/2)/f; // round to nearest , KAI
	//return x > 0 ? (x+f/2)>>SHIFT : (x-f/2)>>SHIFT; // round to nearest , KAI
	return x/f; // round to zero
	//return x>>SHIFT; // round to zero
}

int fix_2_int_nearest(int x){
	return x > 0 ? (x+f/2)/f : (x-f/2)/f;
}

int int_2_fix (int x){
	return (x*f);
	//return (x << SHIFT);
}

int fix_add_int(int x, int n){
	return (x+n*f);
	//return (x + (n << SHIFT));
}

int fix_minus_int(int x, int n){
	return (x-n*f);
	//return (x-(n << SHIFT));
}

int fix_multiply_fix (int x, int y){
	return ((int64_t)x)*y/f;
	//return (((int64_t)x)*y) >> SHIFT;
}

int int_multiply_int (int x, int y){
	return ((int64_t)x)*y*f;
	//return (((int64_t)x)*y) << SHIFT;
}

int fix_multiply_int (int x, int n){
	return x*n;
}

int fix_divide_fix (int x, int y){
	return ((int64_t)x)*f/y;
	//return (((int64_t)x) << SHIFT) /y;
}

int fix_divide_int (int x, int n){
	return (x/n);
}

int int_divide_int (int x, int y){
	return ((int64_t)x)*f/y;
	//return (((int64_t)x) << SHIFT) /y;
}
#endif
/** Begin fixed_point function **/


/** Begin priority-cal function **/

// #define PRI_MIN 0                       /* Lowest priority. */
// #define PRI_DEFAULT 31                  /* Default priority. */
// #define PRI_MAX 63                      /* Highest priority. */

# define PRI_MAX_FIX 1032192 // fix-point value of 63
# define LOAD_AVG_C1_FIX 16110 // fix-point value 59/60
# define LOAD_AVG_C2_FIX 273 // fix-point value 1/60

/*
  priority: int (0 ~ 63)
  recent_cpu: fix
  nice: int
  PRI_MAX_FIX: int
*/
int priority_calc (int recent_cpu, int nice) {
	int res = fix_2_int(PRI_MAX_FIX - fix_divide_int(recent_cpu, 4) - int_multiply_int(nice, 2));
	//res = (res+40) * 63 / 143;
	
	// clamp to [0,63] KAI
	if (res<0) res=0;
	else if (res >63) res = 63;

	return res;
	//int temp_1 = recent_cpu / 4;
	//int temp_2 = nice * 2 + temp_1;
	//return 63-temp_2;
}

/*
  recent_cpu: fix
  load_avg: fix
  nice: int
*/
int recent_cpu_calc (int load_avg, int nice, int recent_cpu) {
	int a = fix_multiply_int(load_avg, 2); // a: fix
	int c = fix_divide_fix(a, a + f); // c: fix
	return fix_multiply_fix(c, recent_cpu) + int_2_fix(nice);
}

/*
  load_avg: fix
  n_ready_threads: int
*/
int load_avg_calc (int load_avg, int n_ready_threads) {
	return fix_multiply_fix(LOAD_AVG_C1_FIX, load_avg) + fix_multiply_int(LOAD_AVG_C2_FIX, n_ready_threads);
}

/** End priority-cal function **/


