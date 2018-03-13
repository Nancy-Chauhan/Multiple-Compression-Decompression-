#include"header.h"

int openfile(char *mode)
{
	int fd;
	char *file;
	printf("%s: Begins\n",__func__);
	file=(char *)malloc(sizeof(char)*20);
	if(!file)
	{
		perror("malloc");
		exit(EXIT_SUCCESS);
	}
	printf("Enter the filename\n");
	scanf("%s",file);
	if(strncmp("O_WRONLY",mode,8)==0)
	{
	fd=open(file,O_WRONLY|O_CREAT);
		if(fd==-1)
		{
			perror("open");
			exit(EXIT_FAILURE);		
		}
	}
	else if(strncmp("O_RDONLY",mode,8)==0)
	{
	fd=open(file,O_RDONLY);
		if(fd==-1)
		{
			perror("open");
			exit(EXIT_FAILURE);		
		}
	}
	else
	{
		printf("The mode you entered is invalid\n");
		exit(EXIT_FAILURE);
	}
	printf("%s:file opened successfully\n",__func__);
	printf("%s: Ends\n",__func__);
	return fd;
}
