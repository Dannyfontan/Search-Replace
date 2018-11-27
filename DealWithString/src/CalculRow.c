#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"

int CalculRow(FILE *fpr, char line[]) {		//计算总行数
	int count = 0; 
	while(fgets(line,100,fpr) != NULL) {
		count++;
	}
	fseek(fpr,0,SEEK_SET);
	return count;
}
