int printf(const char* format, ...);
int global_init_var =84;
static int global_uninit_var; //gcc don't put it on .bss section
//static int global_uninit_var;   //gcc put it on on .bss section
void func1(int i)
{
    printf("i=%d\n", i);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;
    int a = 1;
    int b;
    func1(static_var+static_var2+a+b);
    return a;
}
