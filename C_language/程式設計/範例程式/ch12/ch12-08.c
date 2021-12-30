// ch12-08

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
/*
#include <io.h>
#include <sys/stat.h>
*/

struct st_date
{
	int year;
	int month;
	int day;
};

int main(void)
{
	int f1,f2;
	int date_cnt,i;
	struct st_date date[10];
 	
 	printf("Number of dates: ");
 	scanf("%d",&date_cnt);
 	fflush(stdin);
 	
 	for (i=0;i<date_cnt;i++)
 	{
		printf("Date %d = ",i+1);
		scanf("%d/%d/%d",&date[i].year,&date[i].month,&date[i].day);
	}
 	
	f2=open("ch12-08.dat",O_WRONLY|O_CREAT);
	if(f2 != -1)
	{
		write(f2,&date_cnt,1);
		for (i=0;i<date_cnt;i++)
			write(f2,&date[i],sizeof(struct st_date));
		close(f2);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}
  
	f1=open("ch12-08.dat",O_RDONLY);
	if(f1 != -1)
	{
		read(f1,&date_cnt,1);
		for (i=0;i<date_cnt;i++)
			read(f1,&date[i],sizeof(struct st_date));
		close(f1);
		
		printf("Number of dates = %d\n",date_cnt);
		for (i=0;i<date_cnt;i++)
			printf("Day %d = %d/%d/%d\n",i+1,date[i].year,date[i].month,date[i].day);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}  
   
	system("PAUSE");
	return 0;
}

