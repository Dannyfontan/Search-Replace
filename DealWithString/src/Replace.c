#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/MyTypes.h"
#include "../include/GetSingleLine.h"
#include "../include/Matching.h"
#include "../include/ReplaceOneLine.h"
#include "../include/ReplaceWord.h"

Status GetSingleLine(char line[], FILE *fpr) {			//从文件中获取一行,并赋给line数组		
	char *p = NULL;
	if(fgets(line,100,fpr) != NULL) {
		return OK;
	}
}

Status Matching(char *src, char *target) { 				//在一行中搜寻匹配项
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

Status ReplaceOneLine(char *oldword,char line[], char *newword) {		
	int len = strlen(line);
	int front_len = (int)(strstr(line,oldword)-line);
	line[front_len] = '\0';	

	int newword_len = strlen(newword);
	int oldword_len = strlen(oldword);

	int temp_size = len-front_len-oldword_len;
	char *temp = (char *)malloc(sizeof(char)*100);
	strncpy(temp,line+front_len+oldword_len,100);		
	strncat(line,newword,newword_len);	
	strncat(line,temp,strlen(temp));
	free(temp);	
	if(OK == Matching(line,oldword)) {			//此行还有剩余未替换
		if(OK == ReplaceOneLine(oldword,line,newword)) {
			return OK;
		}
	}else {
		return OK;
	}
}

Status ReplaceWord(FILE *fpr, char *target, char *newword, char line[], char address[]) { 
	FILE *fpw;
	fpw = fopen("./temp.txt","w+");
	while(OK == GetSingleLine(line,fpr)) {								//读取一行成功
		if(OK == Matching(line,target)) {								//此行中有需要替换的单词
			if(OK == ReplaceOneLine(target,line,newword)) {				//替换成功
				fputs(line,fpw);										//写入临时文件
			}else {
				printf("ERROR in Replace!\n");
				return ERROR;
			}		
		}else {
			fputs(line,fpw);											//写入临时文件
		}	
	}
	remove(address);												//删除旧的text文件
	fseek(fpw,0,SEEK_SET);
	fpr = fopen(address,"w+");										//创建新的text文件
	while(OK == GetSingleLine(line,fpw)) {
		fputs(line,fpr);
	}
	remove("./temp.txt");												//删除临时文件
	fclose(fpw);
	printf("SUC!\n");
	return OK;
}