/*************************************************************************
	> File Name: lstat.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 二  1/17 17:04:44 2017
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

static struct stat statbuf;
static mode_t type;

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf("param error!\n");
	}
	if (stat(argv[1], &statbuf) < 0) {
		printf("stat error!\n");
	}
	type = statbuf.st_mode;
	if (S_ISDIR(type)) {
		printf("%s is directory!\n", argv[1]);
	}
	if (S_ISREG(type)) {
		printf("%s is file!\n", argv[1]);
	}
	if (S_ISFIFO(type)) {
		printf("%s is fifo!\n", argv[1]);
	}
	if (S_ISLNK(type)) {
		printf("%s is link file!\n", argv[1]);
	}
	if (S_ISSOCK(type)) {
		printf("%s is sock file!\n", argv[1]);
	}
	return 0;
}
