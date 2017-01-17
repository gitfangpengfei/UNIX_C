/*************************************************************************
	> File Name: getpwd.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 二  1/17 17:52:53 2017
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 64

int main (int argc, char *argv[]) {
	char *ptr;
	if (argc != 2) {
		printf("param error!\n");
		exit(1);
	}
	if (chdir(argv[1]) < 0) {
		printf("chdir error!\n");
		exit(1);
	}
	ptr = malloc(SIZE);
	if (getcwd(ptr, SIZE) < 0) {
		printf("getcwd error!\n");
		exit(1);
	}
	printf("cwd = %s\n", ptr);
	return 0;
}
