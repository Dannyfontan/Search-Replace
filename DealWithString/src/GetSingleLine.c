#include <stdio.h>
#include <string.h>
#include "../include/MyTypes.h"

Status GetSingleLine(char line[], FILE *fpr) {		//从文件中获取一行,并赋给line数组
	char *p = NULL;
	if(fgets(line,100,fpr) != NULL) {
		return OK;
	}
}
