/*************************************************************************
	> File Name: mkstemp.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 日  1/22 15:39:57 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
void make_temp(char *template);

int main (void) {
	char good_template[] = "/tmp/dirXXXXXX";
	char *bad_template = "/tmp/dirXXXXXX";

	printf("trying to create first temp file...\n");
	make_temp(good_template);
	printf("trying to create second temp file...\n");
	make_temp(bad_template);
	return 0;
}

void make_temp(char *template) {
	int fd;
	struct stat buf;

	if ((fd = mkstemp(template)) < 0) {
		printf("can`t create temp file");
	}
	printf("temp name = %s\n", template);
	close(fd);
	if (stat(template, &buf) < 0) {
		if (errno == ENOENT) {
			printf("file doesn`t exist\n");
		} else {
			printf("stat failed");
		}
	} else {
		printf("file exists\n");
		unlink(template);
	}
}
