#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/sched.h>

struct task_struct *task;
int data, ret;

int thread_function(void *data)
{
    int var=10;
    printk(KERN_INFO "in thread function");
    while(!kthread_should_stop()) {
        schedule();
    }
    return var;
}

static int __init kernel_init(void)
{
    data = 20;
    printk(KERN_INFO "---------------");
    task = kthread_run(&thread_function, (void *)data, "aiming");
    printk(KERN_INFO "kernel thread: %s", task->comm);
    return 0;
}

static void __exit kernel_exit(void)
{
    kthread_stop(task);
}

module_init(kernel_init);
module_exit(kernel_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hua Aiming <ussthamcn@sina.com>");
MODULE_DESCRIPTION("create a kernel thread");
MODULE_SUPPORTED_DEVICE("test device")
