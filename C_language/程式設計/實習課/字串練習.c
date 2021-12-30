/*
字串練習：輸入一字串後，輸入欲刪除的類型(1-小寫字母，2-大
寫字母，3-數字，4-符號)，根據輸入的類型，刪除字串內對應的內
容。(未使用字串者不給分)。
*/
#include <stdio.h>

int main(void)
{
    int n,i,j=0;
    char a[80],b[80];
	
	printf("請輸入字串：\n");
	
	gets(a);
	
	printf("請輸入欲刪除之類型(1-小寫字母，2-大寫字母，3-數字，4-符號：\n"); 
	
	scanf("%d",&n);
	
    for(i=0;a[i]!=0;i++)
	{    
	    if(n==1)
	    {
	        if('a'<=a[i]&&a[i]<='z')
	        ;
	        else
	        b[j++] = a[i];
	    }
	    else if(n==2)
	    {
	        if('A'<=a[i]&&a[i]<='Z')
	        ;
	        else
	        b[j++] = a[i];
	    }
	    else if(n==3)
	    {
	        if('0'<=a[i]&&a[i]<='9')
	        ;
	        else
	        b[j++] = a[i];
	    }
	    else
	    {
	        if('a'<=a[i]&&a[i]<='z'||'A'<=a[i]&&a[i]<='Z'||'0'<=a[i]&&a[i]<='9')
	        b[j++] = a[i];
	    }
	     
    }
    b[j] = 0;
    puts(b);
    return 0;
}
