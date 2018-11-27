#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/CalculRow.h"
#include "../include/GetSingleLine.h"
#include "../include/MatchForLine.h"
#include "../include/Matching.h"

typedef int Status;

#define My_API extern

#define OVERFLOW   (-1)
#define ERROR		(0)
#define OK          (1)

int CalculRow(FILE *fpr,char line[]) {		//计算总行数
	int count = 0; 
	while(fgets(line,100,fpr) != NULL) {
		count++;
	}
	fseek(fpr,0,SEEK_SET);
	return count;
}

Status GetSingleLine(char line[], FILE *fpr) {		//从文件中获取一行,并赋给line数组
	char *p = NULL;
	if(fgets(line,100,fpr) != NULL) {
		return OK;
	}
}

Status Matching(char *src, char *target) { 
	int i = 0;
	int j = 0;
	int src_len = strlen(src);
	int target_len = strlen(target);
	while((i < src_len) && (j < target_len)) {
		if(src[i] == target[j]) {				
			i++;
			j++;
		}else {
			i = i-j+1;
			j = 0;
		}
	}
	if(j == target_len) {		
		
		if( ( (src[i]-0>=65)&&(src[i]-0<=90) ) || ( (src[i]-0>=97)&&(src[i]-0<=122) ) ) { 
			return ERROR;
		}else if( ( (src[i-j-1]-0>=65)&&(src[i-j-1]-0<=90) ) || ((src[i-j-1]-0>=97)&&(src[i-j-1]-0<=122) )) { 
			return ERROR;
		}else {
			return OK;
		}
	
	}else {
		return ERROR;
	}
}

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
		printf("Matching!\n");
		return OK;
	}else {
		printf("No Matching!\n");
		return ERROR;
	}
}