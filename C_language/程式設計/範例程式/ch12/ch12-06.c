// ch12-06

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
/*
#include <io.h>
#include <sys/stat.h>
*/

int main(void)
{
	int f2;
	const int MAX = 60;
	char ch[MAX];
	int bytes;
 	
 	printf("Nickname: ");
 	gets(ch);
	f2=open("ch12-06.txt",O_WRONLY|O_CREAT|O_TEXT);
//	f2=open("ch12-06.txt",O_WRONLY|O_TEXT);
	if(f2 != -1)
	{
		write(f2,ch,strlen(ch));
		printf("%s\n",ch);
		close(f2);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}
   
	system("PAUSE");
	return 0;
}

