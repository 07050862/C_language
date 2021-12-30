// ch12-03

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr1,*fptr2;
	const int MAX = 5;
	char ch[MAX];
 	
	fptr1=fopen("ch12-01.txt","r");
	fptr2=fopen("ch12-03.txt","w");
	if(fptr1!=NULL && fptr2!=NULL)
	{
		while (fgets(ch,MAX,fptr1)!=NULL)
		{
			printf("(%s)",ch);
			fputs(ch,fptr2);
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

