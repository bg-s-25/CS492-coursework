/*
 * Custom syscall: my_syscall
 * Takes two input integers, prints sum in kernel log, returns sum
 */

#include <asm/current.h>
#include <linux/syscalls.h>

/* Define the syscall */
SYSCALL_DEFINE2(my_syscall, int, a, int, b) {

	int out = a + b;
	printk(KERN_INFO "my_syscall: calling pid %d, input %d+%d, output %d\n", current->pid, a, b, out);
	return out;

}
