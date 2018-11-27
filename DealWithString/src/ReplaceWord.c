#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/func.h"

Status ReplaceWord(FILE *fpr, FILE *fpw, char *target, char *newword,char line[]) { 
	while(OK == GetSingleLine(line,fpr)) {								//读取一行成功
		if(OK == Matching(line,target)) {								//此行中有需要替换的单词
			if(OK == ReplaceOneLine(target,line,newword)) {				//替换成功
				fputs(line,fpw);										//写入临时文件
			}		
		}else {
			fputs(line,fpw);											//写入临时文件
		}	
	}
	remove("./text.txt");												//删除旧的text文件
	fseek(fpw,0,SEEK_SET);
	fpr = fopen("./text.txt","w+");										//创建新的text文件
	while(OK == GetSingleLine(line,fpw)) {
		fputs(line,fpr);
	}
	remove("./temp.txt");												//删除临时文件
	return OK;
}
