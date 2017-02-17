/* file name: compile_steps.c 
 * description: detail steps gcc compile code 
 * step1. preprocess/precompile: 
 *        function: handle all "#" start commands, e.g. #include, #define, #if, #ifdef, delete comments, add line number
 *        how: gcc -E compile_steps.c -o compile_steps.i or cpp compile_steps.c > compile_steps.i 
 * step2. compile: 
 *        function: precompliation result -> lexical analysis -> syntax analysis -> semantic analysis -> optimize -> assemble code
 *        how: gcc -S compile_steps.i -o compile_steps.s
 * step3. assemble: 
 *        function: assembler translator assemble code to object code
 *        how: gcc -c compile_steps.s|compile_steps.c -o compile_steps.o or as compile_steps.s -o compile_steps.o
 * step4. link: */ 

//handle by precompile
//the comments will deleted by precompiler 
/*the comments will deleted by precompiler*/
//add line number and file name used by debug and warring infomation
#include <stdio.h>
#define pi 3.14
#ifdef pi
float r = 2;
#else
float r = 4;
#endif


int main()
{
    float a = pi*2*2;
    printf("hello world\r\n");
    return 0;
}
