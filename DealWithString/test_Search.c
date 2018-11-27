#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/MyTypes.h"
#include "./include/MatchForLine.h"

int main(void) {
	FILE *fpr;
	char target[10];
	char address[20] = "./text.txt";
	printf("input target:\n");
	scanf("%s",target);
	char line[100];
	int list[100] = {0};
	fpr = fopen(address,"r+");
	if(OK == MatchForLine(line,fpr,target,list)) {
			for(int i = 0; list[i]; i++) {
				printf("%d ",list[i]);
			}
			fclose(fpr);
	}
	return 0;
}

