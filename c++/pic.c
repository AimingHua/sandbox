static int a;
extern int b;
extern void ext();

void bar()
{
    a=1;
    b=1;
}

void foo()
{
    bar();
    ext();
}
