#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/MyTypes.h"
#include "../include/Matching.h"

Status ReplaceOneLine(char *target, char line[], char *newword) {		
	int len = strlen(line);
	int front_len = (int)(strstr(line,target)-line);
	line[front_len] = '\0';	

	int newword_len = strlen(newword);
	int target_len = strlen(target);

	int temp_size = len-front_len-target_len;
	char *temp = (char *)malloc(sizeof(char)*100);
	strncpy(temp,line+front_len+target_len,100);		
	strncat(line,newword,newword_len);	
	strncat(line,temp,strlen(temp));
	free(temp);	
	if(OK == Matching(line,target)) {			
		if(OK == ReplaceOneLine(target,line,newword)) {
			return OK;
		}
	}else {
		return OK;
	}
}
