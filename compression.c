#include"header.h"
int compression()
{
	char* (*creatMarrayptr)(int);
	int (*codelengthptr)(int);
/*	int (*compress2ptr)(int,char *);
	int (*compress3ptr)(int,char *);
	int (*compress4ptr)(int,char *);
	int (*compress5ptr)(int,char *);
	int (*compress6ptr)(int,char *);
	int (*compress7ptr)(int,char *);*/
	int (*openfileptr)(char *);
	creatMarrayptr=creatMarray;
	codelengthptr=codelength;
/*	compress2ptr=compress2;
	compress3ptr=compress3;
	compress4ptr=compress4;
	compress5ptr=compress5;
	compress6ptr=compress6;
	compress7ptr=compress7;*/
	openfileptr=openfile;
	int (*compress[])(int,char *)={compress2,compress3,compress4,compress5,compress6,compress7};
	
	printf("%s: compression begins\n",__func__);
	int fd,ndc,cl;
	char *ma;
	printf("\n");
	fd=openfileptr("O_RDONLY");
	printf("\n");
	ma=creatMarrayptr(fd);
	printf("Unique array elements are:\n");
	printf("%s\n",ma);
	ndc=strlen(ma);
	printf("Number of data characters are %d\n",ndc);
	cl=codelengthptr(ndc);
	printf("value of codelength is %d\n",cl);
	lseek(fd,0,SEEK_SET);	

/*	switch(cl)
	{
		case 2:
			compress2ptr(fd,ma);
			break;
		case 3:
			compress3ptr(fd,ma);
			break;
		case 4:
			compress4ptr(fd,ma);
			break;
		case 5:
			compress5ptr(fd,ma);
			break;
		case 6:
			compress6ptr(fd,ma);
			break;
		case 7:
			compress7ptr(fd,ma);
			break;
	}*/
	(*compress[cl-2])(fd,ma);
	printf("%s: compression ends\n",__func__);
	return fd;
}

