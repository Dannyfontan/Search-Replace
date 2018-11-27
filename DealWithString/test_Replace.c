#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/MyTypes.h"
#include "./include/ReplaceWord.h"

int main(void) {
	FILE *fpr;
	FILE *fpw;
	char target[10];
	char newword[10];
	printf("input target:\n");
	scanf("%s",target);
	printf("input newword:\n");
	scanf("%s",newword);
	char line[100];
	fpr = fopen("./text.txt","r+");
	fpw = fopen("./temp.txt","w+");
	if(OK == ReplaceWord(fpr,fpw,target,newword,line)) {
			fclose(fpr);
			fclose(fpw);
	}
	return 0;
}

