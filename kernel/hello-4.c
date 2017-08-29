#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init init_hello(void)
{
    printk(KERN_INFO "hello, world\n");
    return 0;
}

static void __exit exit_hello(void)
{
    printk(KERN_INFO "goodbye, world\n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("aiming");
MODULE_DESCRIPTION("this is a test");
MODULE_SUPPORTED_DEVICE("test device");
