#include"header.h"

int compress4(int fd,char *ma)
{
	int (*openfileptr)(char *); 
	openfileptr=openfile;
	int (*findindexptr)(char,char *);
	findindexptr=findindex;
	unsigned char ch,byt,c,byt1;
	int cfd,efd,i;
	printf("%s: begins\n",__func__);
	printf("\t%s::Give the name for compress file\n",__func__);
	cfd=openfileptr("O_WRONLY");
	printf("%s:compressed file opened successfully\n",__func__);
	
	printf("\n\t%s::Give the name for encrypted file\n",__func__);
	efd=openfileptr("O_WRONLY");
	printf("%s:encrypted file opened successfully\n",__func__);
	while(1)
	{
		byt ^= byt;
		c ^= c;
		if(read(fd,&ch,1)==0)
		break;
		i=findindexptr(ch,ma);
		printf("%s: ch :%c\n",__func__,ch);
		printf("%s: i :%d\n",__func__,i);
		c=(char)i;
		c=c<<4;
		byt |=c;
		byt1=byt;
			
		if(read(fd,&ch,1)==0)
			{
				c=0x0F;
				byt |=c;
				write(cfd,&byt,1);		
				break;
			}
		i=findindexptr(ch,ma);
		printf("%s: ch :%c\n",__func__,ch);
		printf("%s: i :%d\n",__func__,i);
		c=(char)i;
		c <<=4;
		c >>=4;
		byt1 |=c;	
		printf("\t%s: byte at location %d is %c and %d\n",__func__,i,byt1,byt1);	
		write(cfd,&byt1,1);	
	}
	write(efd,ma,strlen(ma));
	close(fd);
	close(cfd);
	close(efd);
	
	printf("%s: ends\n",__func__);
}
