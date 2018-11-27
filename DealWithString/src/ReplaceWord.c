#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/GetSingleLine.h"
#include "../include/Matching.h"
#include "./include/ReplaceOneLine.h"

Status ReplaceWord(FILE *fpr, char *target, char *newword, char line[], char address[]) { 
	FILE *fpw;
	fpw = fopen("./temp.txt","w+");
	while(OK == GetSingleLine(line,fpr)) {								//��ȡһ�гɹ�
		if(OK == Matching(line,target)) {								//����������Ҫ�滻�ĵ���
			if(OK == ReplaceOneLine(target,line,newword)) {				//�滻�ɹ�
				fputs(line,fpw);										//д����ʱ�ļ�
			}else {
				printf("ERROR in Replace!\n");
				return ERROR;
			}		
		}else {
			fputs(line,fpw);											//д����ʱ�ļ�
		}	
	}
	remove(address);												//ɾ���ɵ�text�ļ�
	fseek(fpw,0,SEEK_SET);
	fpr = fopen(address,"w+");										//�����µ�text�ļ�
	while(OK == GetSingleLine(line,fpw)) {
		fputs(line,fpr);
	}
	remove("./temp.txt");												//ɾ����ʱ�ļ�
	fclose(fpw);
	printf("SUC!\n");
	return OK;
}