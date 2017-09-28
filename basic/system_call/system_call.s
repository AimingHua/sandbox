;similar syscall vs fun call from programer view, but in fact they are different. system call use register, function call use stack
.section .data
string:
	.ascii "hello world\n"
string_end:
	.equ len, string_end - string

.section .text
.globl main
main:
	#write(1, "hello world\n", 13)
	movl $4, %eax
	movl $1, %ebx
	movl $string, %ecx
	movl $len, %edx
	int  $0x80;

	#exit(0)
    movl $1, %eax
    movl $0, %ebx
    int  $0x80
