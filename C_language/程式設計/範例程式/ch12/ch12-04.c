// ch12-04

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr1,*fptr2;
	const int MAX = 5;
	char ch[MAX+1];
	int bytes = 0;
	
 	fptr1=fopen("ch12-01.txt","r");
	fptr2=fopen("ch12-04.txt","w");
	if(fptr1!=NULL && fptr2!=NULL)
	{
		while (!feof(fptr1))
		{
			bytes = fread(ch,sizeof(char),MAX,fptr1);
			fwrite(ch,sizeof(char),bytes,fptr2);
			if (bytes <= MAX)
				ch[bytes] = 0;
			printf("%s",ch);
		} 
		fclose(fptr2);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}
   
	system("PAUSE");
	return 0;
}

