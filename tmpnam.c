/*************************************************************************
	> File Name: tmpnam.c
	> Author: gushiboy
	> Mail: puvtmqb@sina.com 
	> Created Time: 日  1/22 15:26:11 2017
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024

int main (void) {
	char name[L_tmpnam], line[MAXLINE], *return_name;
	FILE *fp;
	printf("%d\n", mkstemp(NULL));

	mkstemp(name);
	printf("%s\n", name);

	if ((fp = tmpfile()) == NULL) {
		printf("tmpfile error!\n");
		exit(1);
	}
	fputs("one line of output\n", fp);
	rewind(fp);
	if (fgets(line, sizeof(line), fp) == NULL) {
		printf("fgets error");
	}
	fputs(line, stdout);
	return 0;
}
