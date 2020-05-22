/**
* Tests the custom system calls: my_syscall, my_syscall2
*/

#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>

#define __NR_my_syscall 332
#define __NR_my_syscall2 333

long my_syscall_syscall(int a, int b) {
	return syscall(__NR_my_syscall, a, b);
}

long my_syscall2_syscall(char * s) {
	return syscall(__NR_my_syscall2, s);
}

int main() {
	printf("Name : Bobby Georgiou\n");
	printf("PID  : %d\n", getpid());

	// call my_syscall
	printf("\nCall : my_syscall(6, 7)\n");
	long int a = my_syscall_syscall(6, 7);
	printf("my_syscall returned: %ld\n", a);

	// call my_syscall2 with a small string
	printf("\nCall : my_syscall2('trololol')\n");
	long int b = my_syscall2_syscall("trololol");
	printf("my_syscall2 returned: %ld\n", b);

	// call my_syscall2 with a large string
	char * str_size_256 = (char *) malloc(256*sizeof(char));
	memset(str_size_256, 'a', 256*sizeof(char));
	printf("\nCall : my_syscall2(str_size_256)\n");
	long int c = my_syscall2_syscall(str_size_256);
	printf("my_syscall2 returned: %ld\n", c);
	free(str_size_256);

	return 0;
}
