#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int hello_data __initdata = 3;
static int __init hello_init(void)
{
    printk(KERN_INFO "hello world 3\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "goodbye world 3\n");
}

module_init(hello_init);
module_exit(hello_exit);
