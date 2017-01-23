/*************************************************************************
	> File Name: fmemopen.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 日  1/22 16:03:04 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BSZ 48

int main (void) {
	FILE *fp;
	char buf[BSZ];

	memset(buf, 'a', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	if ((fp = fmemopen(buf, BSZ, "w+")) == NULL) {
		printf("fmemopen failed!\n");
		exit(1);
	}
	printf("initial buffer contents: %s\n", buf);
	fprintf(fp, "hello, word");
	printf("before flush: %s\n", buf);
	fflush(fp);
	printf("after fflush: %s\n", buf);
	printf("len of string in buf = %ld\n", (long)strlen(buf));

	memset(buf, 'b', BSZ-2);
	buf[BSZ-2] = '\0';
	buf[BSZ-1] = 'X';
	fprintf
}
