/*16進位轉10進位

設計程式達成以下要求:

設計一個程式讀入至多8位元的16進位數字(假設英文字母可為大寫或小寫)，判斷所讀入的字元是否為16進位的數字，如果是，轉換為10進位的數值；如果否，顯示非16進位數字的位置。
=== 範例執行結果(1) ===

FFFF1234 <-- 從鍵盤輸入
FFFF1234=4294906420
=== 範例執行結果(2) ===
BcDf2K5 <-- 從鍵盤輸入
BcDf2K5
     ^Error*/ 
#include <stdio.h>
#include <conio.h>
int afunc(char ch[],int i);


int main(){
    char c1, c2,ch[8],ans=0;
    int i=0;
    for(i=0;i<8;i++)//輸入8個字
    {
    	if(c1==13)//13是enter鍵
    	{
    		i=i-1;
    		break;
		}
        c1 = getche();
        ch[i]=c1;
    }
    
    
    ans = afunc(ch,i);//判斷是否是為16進位數字，如果不是，則回傳第幾個字不是 
	
	if(ans == -1 )//是16進位
	{
		bfunc(ch,i);
	}
	else//不是16進位
	{
		printf("\n");
		for(i=0;i<ans;i++)
		    printf(" ");
	    printf("^Error");
	} 
    printf("\n\n");
   
    system("pause");
    return 0;
}
int afunc(char ch[],int i)
{
	int j=0,total=0;
	for(j=0;j<i;j++)
	{
	    if('0'<=ch[j]&&ch[j]<='9')
	    ;
        else if ('A'<=ch[j]&&ch[j]<='F')
        ;
        else if ('a'<=ch[j]&&ch[j]<='f')
        ;
	    else
	    {	
	        return j;
	    }	
	}
	return -1;   
}
int bfunc(char ch[],int i)
{
	int j=0,count=0;
    unsigned long n=0;
	for(j=i-1;j>=0;j--)
    {
    	if('0'<=ch[j]&&ch[j]<='9')
	        n =  n + (ch[j] - '0') * power(count);
	    else
	        n =  n + (ch[j] - 'A'+10) * power(count);
    	count++;
	}  
    printf("\n%llu",n);
    
}
int power(int count)
{
	int i=1,ans=1;
	for(i=1;i<=count;i++)
    {
    	ans =  ans * 16;
	}
    return ans;
}
