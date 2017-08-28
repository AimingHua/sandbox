#include <linux/kthread.h>
#include <linux/sched.h>

struct task_struct *task;
int data, ret;

int thread_function(void *data)
{
    int var=10;
    printk(KERN_INFO, "in thread function");
    while(!kthread_should_stop()) {
        schedule();
    }
    return var;
}

static int kernel_init(void)
{
    data = 20;
    printk("KERN_INFO", "---------------");
