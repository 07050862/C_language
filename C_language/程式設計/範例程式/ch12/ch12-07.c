// ch12-07

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f1,*f2;
	int people,i;
	int money[10];
 	
 	printf("Enter number of people: ");
 	scanf("%d",&people);
 	
 	for (i=0;i<people;i++)
 	{
		printf("Enter money of people %d: ",i);
		scanf("%d",&money[i]);
	}
	
	f2=fopen("ch12-07.dat","wb");
	if(f2 != NULL)
	{
		fwrite(&people,sizeof(int),1,f2);
		fwrite(money,sizeof(int),people,f2);
		close(f2);
	}
	else
	{
		printf("WRITE FAILED!\n");
	}
	
	f1 = fopen("ch12-07.dat","rb");
	if (f1 != NULL)
	{
		fread(&people,sizeof(int),1,f1);
		fread(money,sizeof(int),people,f1);
		
		printf("Number of people = %d\n",people);
		for (i=0;i<people;i++)
		{
			printf("Money of people %d = %d\n",i,money[i]);
		}
		close(f1);
	}
	else
	{
		printf("READ FAILED!\n");
	}
	
   
	system("PAUSE");
	return 0;
}

