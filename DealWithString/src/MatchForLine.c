#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/func.h"

Status MatchForLine(char line[], FILE *fpr, char *target,int list[]) {	//按行匹配，若存在target，将其行数存入list数组
	int linecount = 0;
	int count = CalculRow(fpr,line);
	int templist[count],i,j,flag = 0;
	
	for(i = 0; i < count; i++) {
		++linecount;
		if(OK == GetSingleLine(line,fpr)) {
			if(OK == Matching(line,target)) {
				flag = 1;
				templist[linecount] = 1;
			}else{
				templist[linecount] = 0;
			}	
		}	
	}
	
	i = 0;
	for(j = 1; j <= count; j++) {
		if(templist[j] == 1) {
			list[i++] = j;
		}
	}
	
	if(flag == 1) {
		return OK;
	}else {
		return ERROR;
	}
}
