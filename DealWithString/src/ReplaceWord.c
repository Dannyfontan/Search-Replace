#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/GetSingleLine.h"
#include "../include/Matching.h"
#include "./include/ReplaceOneLine.h"

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