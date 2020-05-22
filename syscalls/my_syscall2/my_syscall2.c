/*
 * Custom syscall: my_syscall2
 * Takes an input character pointer, replaces all 'o' with '0', returns the number of replacements made
 */

#include <asm/current.h>
#include <linux/syscalls.h>
#include <linux/string.h>

/* Define the syscall */
SYSCALL_DEFINE1(my_syscall2, char *, s) {

	int sz = strlen(s);

	// check for size > 128
	if (sz > 128) {
		printk(KERN_INFO "my_syscall2: calling pid %d, input <large string>, output %d", current->pid, -1);
		return -1;
	}

	char ss[129];
	strcpy(ss, s);

	// do replacement(s)
	int replCnt = 0;
	int i;
	for (i = 0; i < sz; ++i) {
		if (ss[i] == 'o') {
			ss[i] = '0';
			replCnt++;
		}
	}

	printk(KERN_INFO "my_syscall2: calling pid %d, input %s, output %s", current->pid, s, ss);
	return replCnt;

}
