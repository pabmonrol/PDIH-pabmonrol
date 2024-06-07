/**
 * @file    greeting.c
 * @author  Pablo Montero Rollán
 * @date    7 June 2024
 * @version 0.1
 * @brief   Loadable kernel module (LKM).
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");         ///< The license type
MODULE_AUTHOR("Pablo");      ///< The author
MODULE_DESCRIPTION("A simple Linux driver."); ///< Description
MODULE_VERSION("0.1");         ///< The version of the module

static char *name = "darkness";
module_param(name, charp, S_IRUGO);  
MODULE_PARM_DESC(name, "The name to display in log"); 

static int __init greeting_init(void){
   printk(KERN_INFO "Hello %s, my old friend\n", name);
   return 0;
}

static void __exit greeting_exit(void){
   printk(KERN_INFO "Goodbye %s, my old friend\n", name);
}

module_init(greeting_init);
module_exit(greeting_exit);
