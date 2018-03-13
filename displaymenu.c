#include"header.h"
 
int nocbreak();
int displaymenu()
{
	nocbreak();
   	 char choice;

	printf("\n%s: ******Hello*****\n",__func__);
	printf("%s: Press 'c or C' for compression\n",__func__);
	printf("%s: Press 'd or D' for decompression\n",__func__);
	printf("%s: 3. Press any alphabet except d and c for exit\n",__func__);


	printf("Enter your choice:\n");
	do
	{
		choice=getchar();
	}while(choice=='\n');
	cbreak();
	return choice;
}
