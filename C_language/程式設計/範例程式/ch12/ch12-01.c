// ch12-01

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	char ch;
 	
	fptr=fopen("ch12-01.txt","r");
	if(fptr!=NULL)
	{
		while((ch=fgetc(fptr)) != EOF)
			printf("%c",ch);
		fclose(fptr);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}
   
	system("PAUSE");
	return 0;
}

