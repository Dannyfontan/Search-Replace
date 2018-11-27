#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/MyTypes.h"
#include "./include/ReplaceWord.h"

int main(void) {
	FILE *fpr;
	char target[10];
	char newword[10];
	char address[20] = "./text.txt";				//文件路径
	printf("input target:\n");
	scanf("%s",target);
	printf("input newword:\n");
	scanf("%s",newword);
	char line[100];
	fpr = fopen("./text.txt","r+");
	if(OK == ReplaceWord(fpr,target,newword,line,address)) {
			fclose(fpr);
	}
	return 0;
}

