// ch12-02

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr1,*fptr2;
	char ch;
 	
	fptr1=fopen("ch12-01.txt","r");
	fptr2=fopen("ch12-02.txt","w");
	if(fptr1!=NULL && fptr2!=NULL)
	{
		while((ch=fgetc(fptr1)) != EOF)
		{
			fputc(ch,fptr2);
			printf("%c",ch);
		}
		fclose(fptr2);
		fclose(fptr1);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}
   
	system("PAUSE");
	return 0;
}

