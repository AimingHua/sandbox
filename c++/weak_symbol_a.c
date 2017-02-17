#include <stdio.h>
/*1. before c programer ofen forget "extern" before declare variable, 
 * so compiler and linker using "COMMON" to process global uninitial variable
 *2. readelf -s weak_symbol_a.o to get symbol information 
 *3. gcc -fno-common */
//int global_init_var = 1; //strong symbol
int global_uninit_var;   //weak symbol 
//int global_uninit_var __attribute__((nocommon)); //strong symbol 
