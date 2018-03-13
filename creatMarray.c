#include"header.h"

char* creatMarray(int fd)
{
	printf("%s:  begins\n",__func__);
	int i,j,k,flag,ret;
	char ch;
	char *ma;
	ma=NULL;
	i=flag=0;
	ret=lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	for(k=0;k<ret;k++)
	{	
	     	if(read(fd,&ch,1)==0)
		break;
						//printf("%s: characters are %c\n",__func__,ch);
			for(j=0;j<i;j++)
			{
				if(*(ma+j)==ch)
				flag=1;
			}	
		
		if(flag==0)
		{
			ma=(char *)realloc(ma,i+1);
			if(!ma)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			*(ma+i)=ch;
			i++;
		}
		flag=0;
               
	}	
		ma=(char *)realloc(ma,i+1);
		if(!ma)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		*(ma+i)='\0';
			
	printf("%s: ends\n",__func__);
		return ma;
}

