// ch12-05

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int f1;
	const int MAX = 10;
	char ch[MAX+1];
	int bytes;
 	
	f1=open("ch12-01.txt",O_RDONLY|O_TEXT);
	if(f1 != -1)
	{
		while (!eof(f1))
		{
			bytes = read(f1,ch,MAX);
			ch[bytes] = 0;
			printf("(%s)",ch);
		}
		close(f1);
	}
	else
	{
		printf("OPEN FAILED!\n");
	}
   
	system("PAUSE");
	return 0;
}

