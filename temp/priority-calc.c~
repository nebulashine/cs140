#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "fixed_point.h"

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
	return fix_2_int(PRI_MAX_FIX - fix_divide_int(recent_cpu, 4) - int_multiply_int(nice, 2));
}

/*
  recent_cpu: fix
  load_avg: fix
  nice: int
*/
int recent_cpu_calc (int load_avg, int nice, int recent_cpu) {
	int a = fix_multiply_int(load_avg, 2); // a: fix
	int c = fix_divide_fix(a, a + int_2_fix(1)); // c: fix
	return fix_multiply_fix(c, recent_cpu) + int_2_fix(nice);
}

/*
  load_avg: fix
  n_ready_threads: int
*/
int load_avg_calc (int load_avg, int n_ready_threads) {
	return fix_multiply_fix(LOAD_AVG_C1_FIX, load_avg) + LOAD_AVG_C2_FIX * n_ready_threads;
}



int main(int argc, char *argv[]){

int load_avg = load_avg_calc(LOAD_AVG_C1_FIX, 100);
int recent_cpu_= recent_cpu_calc(load_avg, 20, 2*LOAD_AVG_C1_FIX);
int priority_ = priority_calc(recent_cpu_, 20);
printf("%d \n", load_avg);
printf("%d \n", recent_cpu_);
printf("%d \n", priority_);


/*
printf("fix_2_int: %d, %d\n", 59, fix_2_int (59));
printf("int_2_fix: %d, %d\n", 59, int_2_fix (59));
printf("fix_add_int: %d+%d --  %d\n", 59, 60, fix_add_int(59, 60));
printf("fix_minus_int: %d-%d -- %d\n", 60, 59, fix_minus_int(60, 59));
printf("fix_multiply_fix: %d*%d, %d\n", 59, 60, fix_multiply_fix (59, 60));
printf("fix_multiply_int: %d*%d, %d\n", 59, 60, fix_multiply_int (59, 60));
printf("fix_divide_fix: %d divide %d, %d\n", 966656, 57, fix_divide_fix (966656, 57));
printf("fix_divide_int: %d divide %d, %d\n", 966656, 57, fix_divide_int (966656, 57));
*/
	return 0;
}
