#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"
#include "../include/func.h"

Status ReplaceWord(FILE *fpr, FILE *fpw, char *target, char *newword,char line[]) { 
	while(OK == GetSingleLine(line,fpr)) {								//��ȡһ�гɹ�
		if(OK == Matching(line,target)) {								//����������Ҫ�滻�ĵ���
			if(OK == ReplaceOneLine(target,line,newword)) {				//�滻�ɹ�
				fputs(line,fpw);										//д����ʱ�ļ�
			}		
		}else {
			fputs(line,fpw);											//д����ʱ�ļ�
		}	
	}
	remove("./text.txt");												//ɾ���ɵ�text�ļ�
	fseek(fpw,0,SEEK_SET);
	fpr = fopen("./text.txt","w+");										//�����µ�text�ļ�
	while(OK == GetSingleLine(line,fpw)) {
		fputs(line,fpr);
	}
	remove("./temp.txt");												//ɾ����ʱ�ļ�
	return OK;
}
