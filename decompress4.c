#include"header.h"

int decompress4(int cfd,char *ekey)
{
	int (*openfileptr)(char *);
	printf("%s: begins\n",__func__);
	unsigned char ch,c,byt;
	int dfd,i;
	printf("%s: open file for decompression\n",__func__);
	openfileptr=openfile;
	dfd=(*openfileptr)("O_WRONLY");
	while(1)
	{
		i ^=i;
		if(read(cfd,&ch,1)==0)
			break;

		byt ^=byt;
		c=ch;
		printf("character is: %d\n",ch);
		c >>=4;
		if(c==0x0F)
			break;
		i=(int)c;
		printf("index is: %d\n",i);
		byt=*(ekey+i);
		write(dfd,&byt,1);				

		byt ^=byt;
		c=ch;
		c <<=4;
		c >>=4;
		if(c==0x0F)
			break;
		i=(int)c;
		printf("index is2: %d\n",i);
		byt=*(ekey+i);
		write(dfd,&byt,1);

	}
	close(dfd);
	printf("%s: ends\n",__func__);
}
