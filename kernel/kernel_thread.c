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
    task = kthread_run(&thread_function, (void *)data, "aiming");
    printk("KERN_INFO", kernel thread: %s\n, task->comm);
    return 0;
}

static void kernel_exit(void)
{
    kthread_stop(task);
}

module_init(kernel_init);
module_exit(kernel_exit);
MODULE_AUTHOR("aiming");
MODULE_LICENSE("GPL");
