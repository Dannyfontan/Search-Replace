#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/func.h"

Status Matching(char line[], char *target) { 
	int i = 0;
	int j = 0;
	int line_len = strlen(line);
	int target_len = strlen(target);
	while((i < line_len) && (j < target_len)) {
		if(line[i] == target[j]) {				
			i++;
			j++;
		}else {
			i = i-j+1;
			j = 0;
		}
	}
	if(j == target_len) {		
		
		if( ( (line[i]-0>=65)&&(line[i]-0<=90) ) || ( (line[i]-0>=97)&&(line[i]-0<=122) ) ) { 
			return ERROR;
		}else if( ( (line[i-j-1]-0>=65)&&(line[i-j-1]-0<=90) ) || ((line[i-j-1]-0>=97)&&(line[i-j-1]-0<=122) )) { 
			return ERROR;
		}else {
			return OK;
		}
	
	}else {
		return ERROR;
	}
}
