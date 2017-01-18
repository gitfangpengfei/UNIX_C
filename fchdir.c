/*************************************************************************
	> File Name: fchdir.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 三  1/18 10:37:02 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#define SIZE 64
int show_current_path(char *ptr);
static int fp;

int main (int argc, char *argv[]) {
	char *ptr;
	int fp;
	if ((ptr = (char *)malloc(SIZE)) == NULL) {
		printf("malloc() error!\n");
		exit(1);
	}
	if (argc != 2) {
		printf("param error!\n");
		exit(1);
	}
	fp = show_current_path(ptr);
	if (chdir(argv[1]) < 0) {
		printf("chdir error!\n");
		exit(1);
	}
	show_current_path(ptr);
	if (fchdir(fp) < 0) {
		printf("fchdir() error!\n");
		exit(1);
	}
	show_current_path(ptr);
	return 0;
}

int show_current_path(char *ptr) {
	int fp;
	if ((fp = open(".", O_RDONLY)) < 0) {
		printf("open error!\n");
		exit(1);
	} else {
		if (getcwd(ptr, SIZE) < 0) {
			printf("getcwd() error!\n");
			exit(1);
		} else {
			printf("current path is %s\n", ptr);
		}
		
	}
	return fp;
}

