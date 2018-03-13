#include"header.h"

int findindex(char ch,char *ma)
{
	printf("%s: begins\n",__func__);
	int len,i;
	len=strlen(ma);
	for(i=0;i<len;i++)
	{ 
		if(*(ma+i)==ch)
		return i;
	}
	printf("%s: ends\n",__func__);
}
