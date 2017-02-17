#include <stdio.h>
/*function level linking: only link the functions that used by other compile modules
 * 1. gcc -ffunction-sections -fdata-sections 
 * 2. each function and data will be put in a section 
 * 3. readelf -S function_level_link_a.o */
int global_init_a = 1;
int global_init_b = 1;
int global_init_c = 1;
int global_init_d = 1;
