/* 
 * ch10-05.c
 * 函數使用指標傳遞陣列 
 */
 
#include <stdio.h> 
#include <stdlib.h>

char* max_char(char* p);	//傳入指標且傳回指標 

int main(void)
{
	// char a[] = "That is a key";
	// char *p1 = a;
	
	char *p1 = "That is a key";	//令p1指向一個字串(字元陣列且結束為0) 
	char *p2;

	p2 = max_char(p1);			//傳回字串中最大字元所在的位址 
	
	printf("The MAX character in \"%s\" is %c.\n",p1,*p2);
	
	system("pause");
	return 0;
}

char* max_char(char* p)
{
	char* t;
	
	t = p;
	for (;*p!=0;p++)			//當p所指的字元不是0，則繼續檢查下一個字元 
		if (*t<*p)				//比較t所指的字元是否為最大字元 
			t = p;
	return t;
}
