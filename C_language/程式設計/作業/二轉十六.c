/*
檔名: 學號-hw04.c (例如：04051234-hw04.c)

設計程式達成以下要求:
設計一個程式讀入8位元的2進位數字，判斷所讀入是否為2進位的數字，如果是，轉換為16進位的數值；如果否，顯示非2進位。

程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及考試日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果

=== 範例執行結果(1) ===
11001010 <-- 從鍵盤輸入11001010[Enter]
11001010=CA

=== 範例執行結果(2) ===
11110011 <-- 從鍵盤輸入11110011[Enter]
11110011=F3

=== 範例執行結果(3) ===
1234ABCD <-- 從鍵盤輸入1234ABCD[Enter]
1234ABCD=NO
*/
#include <stdio.h>
int main(void)
{
    int n,i=1,ans=0,ori,a[80],end,j=1;
    char b[80];
	
	gets(b);
	for(j=0;b[j]!=0;j++)
	    n = n * 10 + (b[j] - '0');
	ori = n;
	for(;n!=0;)
	{
		ans = ans + (n%10)*i;
		
    	if((n%10)!=1&&(n%10)!=0)
    	    {
    	    	ans = -1;
    	    	break;
			}
		i *= 2;
		n /= 10;
	}
	n = ori;
    if(ans==-1)
        {
        	for(j=0;b[j]!=0;j++)
        	printf("%c",b[j]);
        	printf("=NO");
		}
    else
        {
        	printf("%d=",n);
        	n = ans;
        	for(i=0;;i++)
	        {
		        a[i] = n % 16;
		        if(a[i]>=10)
		            a[i] = a[i] - 10 + 'A';
	     	        n /= 16;
	    	if(n==0)
		        break; 
	        }   
        	end = i;
    	    for(i=end;i>=0;i--)
        	{
		    if(a[i]<10)
		        printf("%d",a[i]);
	    	else
		        printf("%c",a[i]);
	        }
	    }
	
    
	return 0;
}
