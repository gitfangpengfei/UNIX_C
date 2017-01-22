/*************************************************************************
	> File Name: fgets.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 日  1/22 11:35:25 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

int main (void) {
	char buf[MAXLINE];
	while ((fgets(buf, MAXLINE, stdin)) != NULL) {
		if (fputs(buf, stdout) == EOF) {
			printf("input error!\n");
		}
	}
	if (ferror(stdin)) {
		printf("ferror error!\n");
		exit(1);
	}
	return 0;
}
