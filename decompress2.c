#include"header.h"

int decompress2(int cfd,char *ekey)
{
	printf("%s: begins\n",__func__);
        int (*openfileptr)(char *);
        openfileptr=openfile;
        unsigned char ch,c,chd,byt;
        int dfd,i;
        printf("%s: open file for decompression\n",__func__);
        dfd=(*openfileptr)("O_WRONLY");

        while(1)
        {
                i ^=i;
                if(read(cfd,&ch,1)==0)
                        break;
		
                byt ^=byt;
                c=ch;
                c >>=6;
                if(c==0x03)
                        break;
                i=(int)c;
                printf("\t\t%d\n",i);
                byt=*(ekey+i);
                write(dfd,&byt,1);

                byt ^=byt;
                c=ch;
                c <<=2;
                c >>=6;
                if(c==0x03)
                        break;
                i=(int)c;
                printf("\t\t%d\n",i);
                byt=*(ekey+i);
                write(dfd,&byt,1);

                byt ^=byt;
                c=ch;
                c <<=4;
                c >>=6;
                if(c==0x03)
                        break;
                i=(int)c;
                printf("\t\t%d\n",i);
                byt=*(ekey+i);
                write(dfd,&byt,1);

		
                byt ^=byt;
                c=ch;
                c <<=6;
                c >>=6;
                if(c==0x03)
                        break;
                i=(int)c;
                printf("\t\t%d\n",i);
                byt=*(ekey+i);
                write(dfd,&byt,1);
	}
	printf("%s: ends\n",__func__);
}
