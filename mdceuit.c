#include"header.h"

int main()
{
	int (*compressionptr)();
	compressionptr=compression;      
	int (*decompressionptr)();
	decompressionptr=decompression;   
	int (*displaymenuptr)();  
	displaymenuptr=displaymenu; 
	int fd,sel;
	char choice;
		int (*selection[])()={compression,decompression,down};	

   while(1)
	{
		choice=displaymenuptr();
		if((choice=='c') || (choice=='C'))
			sel=0;
		else if((choice=='d') || (choice=='D'))
			sel=1;
		else 
			sel=2;
			
		(*selection[sel])();
	/*		switch(choice)
		{	
		case 'c':
			compressionptr();
			break;
		case 'd':
			decompressionptr();
			break;
		case 'e':
			printf("Exit sucessflly\n");
			exit(EXIT_SUCCESS);
		}	*/
	
	}
return 0;
}
