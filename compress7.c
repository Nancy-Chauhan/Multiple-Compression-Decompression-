#include"header.h"

int compress7(int fd,char *ma)
{
	printf("%s: begins\n",__func__);
	int (*openfileptr)(char *);
	openfileptr=openfile;
	int (*findindexptr)(char,char *);
	findindexptr=findindex;
	unsigned char ch,byt,c;
	unsigned int cfd,efd,i;
	printf("%s: begins\n",__func__);
	printf("\t\n");
	printf("%s::Give the name for compress file\n",__func__);
	cfd=openfileptr("O_WRONLY");
	printf("%s:compressed file opened successfully\n",__func__);

	printf("\t\n");
	printf("%s::Give the name for encrypted file\n",__func__);
	efd=openfileptr("O_WRONLY");
	printf("%s:encrypted file opened successfully\n",__func__);

	while(1)
	{
		byt ^= byt;
		c ^= c;
		if(read(fd,&ch,1)==0)
			break;
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c=(char)i;
		c <<=1;
		byt |=c;

		if(read(fd,&ch,1)==0)
		{
			c=0x7F;
			c <<=1;
			c >>=7;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			byt ^= byt;
			c ^= c;
			c=0x7F;
			c <<=2;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=7;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
		c ^= c;
		byt ^= byt;
		c=(char)i;
		c <<=2;
		byt |=c;

		if(read(fd,&ch,1)==0)
		{
			c=0x7F;
			c <<=1;
			c >>=6;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			byt ^= byt;
			c ^= c;
			c=0x7F;
			c <<=3;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=6;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
		byt ^= byt;
		c ^= c;
		c=(char)i;
		c <<=3;
		byt |=c;

		if(read(fd,&ch,1)==0)
		{
			c=0x7F;
			c <<=1;
			c >>=5;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			byt ^= byt;
			c ^= c;
			c=0x7F;
			c <<=4;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=5;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
		byt ^= byt;
		c ^= c;
		c=(char)i;
		c <<=4;
		byt |=c;

		if(read(fd,&ch,1)==0)
		{
			c=0x7F;
			c <<=1;
			c >>=4;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			byt ^= byt;
			c ^= c;
			c=0x7F;
			c <<=5;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=4;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
		byt ^= byt;
		c ^= c;
		c=(char)i;
		c <<=5;
		byt |=c;

		if(read(fd,&ch,1)==0)		
		{
			c=0x7F;
			c <<=1;
			c >>=3;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			byt ^= byt;
			c ^= c;
			c=0x7F;
			c <<=6;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=3;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
		byt ^= byt;
		c ^= c;
		c=(char)i;
		c <<=6;
		byt |=c;

		if(read(fd,&ch,1)==0)
		{
			c=0x7F;
			c <<=1;
			c >>=2;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			byt ^= byt;
			c ^= c;
			c=0x7F;
			c <<=7;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=2;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
		byt ^= byt;
		c ^= c;
		c=(char)i;
		c <<=7;
		byt |=c;

		if(read(fd,&ch,1)==0)
		{
			c=0x7F;
			c <<=1;
			c >>=1;
			byt |=c;
			printf("\t\t%d\n",byt);
			write(cfd,&byt,1);
			break;
		}
		i=findindexptr(ch,ma);
		printf("\t\t%d\n",i);
		printf("\t\t%c\n",ch);
		c ^= c;
		c=(char)i;
		c <<=1;
		c >>=1;
		byt |=c;
		printf("\t\t%d\n",byt);
		write(cfd,&byt,1);
	}
	write(efd,ma,strlen(ma));
	close(cfd);
	close(efd);
	printf("%s: ends\n",__func__);
}
