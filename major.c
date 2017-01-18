/*************************************************************************
	> File Name: major.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 三  1/18 14:28:04 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {
	int i;
	struct stat buf;
	if (argc < 2) {
		printf("param error!\n");
		exit(1);
	}
	for (i = 1; i < argc; i++) {
		if (stat(argv[i], &buf) < 0) {
			printf("stat error!\n");
			continue;
		}
		printf("%s is st_dev = %d / %d\n", argv[i], major(buf.st_dev), minor(buf.st_dev));
		if (S_ISREG(buf.st_mode) || S_ISBLK(buf.st_mode)) {
			printf("%s type %s is st_rdev = %d / %d\n", argv[i], (S_ISREG(buf.st_mode) ? "character" : "block"), major(buf.st_rdev), minor(buf.st_rdev));
		}
	}
	return 0;
}
