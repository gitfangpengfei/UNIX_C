/*************************************************************************
	> File Name: getc.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 日  1/22 11:28:38 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
	int n;
	char c;
	while ((c = getc(stdin)) != EOF) {
		if(putc(c, stdout) == EOF) {
			printf("putc error!\n");
		}
	}
	if (ferror(stdin)) {
		printf("input error!\n");
		exit(1);
	}
	return 0;
}
