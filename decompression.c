#include"header.h"

int decompression()
{
	int (*openfileptr)(char *);
	int (*decompressptr2)(int,char *);
	int (*decompressptr3)(int,char *);
	int (*decompressptr4)(int,char *);
	int (*decompressptr5)(int,char *);
	int (*decompressptr6)(int,char *);
	int (*decompressptr7)(int,char *);
	decompressptr2=decompress2;
	decompressptr3=decompress3;
	decompressptr4=decompress4;
	decompressptr5=decompress5;
	decompressptr6=decompress6;
	decompressptr7=decompress7;
	int (*decompress[])(int,char *)={decompress2,decompress3,decompress4,decompress5,decompress6,decompress7};
	
	printf("%s: decompression begins",__func__);
	int cfd,efd,ndc,cl,ret,i=0;
	char ch,*ekey;
	ekey=(char *)malloc(sizeof(char)*14);
	printf("\n%s: Compressed File is opened\n",__func__);
	openfileptr=openfile;
	cfd=(*openfileptr)("O_RDONLY");
	printf("\n%s: Encrypted File is opened\n",__func__);
	efd=(*openfileptr)("O_RDONLY");
	//ekey=creatMarray(efd);
		ret=read(efd,ekey,100);
		*(ekey+ret+1)='\0';
		printf("%d\n",ret);

	printf("%s: ekey::%s\n",__func__,ekey);
	ndc=strlen(ekey);
	printf("%s: length of string is %d\n",__func__,ndc);
	cl=codelength(ndc);
	printf("%s: codelength is %d\n",__func__,cl);
	(*decompress[cl-2])(cfd,ekey);

/*	switch(cl)
	{
		case 2:
			(*decompressptr2)(cfd,ekey);
			break;
		case 3:
			(*decompressptr3)(cfd,ekey);
			break;
		case 4:
			(*decompressptr4)(cfd,ekey);
			break;
		case 5:
			(*decompressptr5)(cfd,ekey);
			break;
		case 6:
			(*decompressptr6)(cfd,ekey);
			break;
		case 7:
			(*decompressptr7)(cfd,ekey);
			break;
	}*/
	printf("%s: decompression ends",__func__);
}
