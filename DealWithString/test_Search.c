#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/MyTypes.h"
#include "./include/ReplaceWord.h"

int main(void) {
	FILE *fpr;
	char target[10];
	printf("input target:\n");
	scanf("%s",target);
	char line[100];
	int list[100] = {0};
	fpr = fopen("./text.txt","r+");
	if(OK == MatchForLine(line,fpr,target,list)) {
			for(int i = 0; list[i]; i++) {
				printf("%d ",list[i]);
			}
			fclose(fpr);
	}
	return 0;
}

