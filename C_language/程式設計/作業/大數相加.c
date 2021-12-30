/*
設計一個程式讀入整數(最長80個數字)，計算出兩個整數相加的結果。

提示：浮點數有精準度的限制，請勿使用浮點數作答。

檔名: 學號-hw08.c (例如：04051234-hw08.c)

程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及考試日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果

=== 範例執行結果(1) ===
12345678987654321
123
=12345678987654444
*/
#include <stdio.h>
void afunc(char a[],char b[],char c[]);
int main(void) 
{ 
    char a[80],b[80],c[80]; 
     
    gets(a); 
    gets(b); 
     
    afunc(a,b,c);  
    printf("=%s",c);  
    return 0; 
}
void afunc(char a[],char b[],char c[])
{
	int i,j,k,carry=0,a_end,b_end,c_end,z,ae,be,end;
	
	for(i=0;a[i]!=0;i++)
	;
	a_end = i;
	ae = i;
	end = i;
	for(i=0;b[i]!=0;i++)
	;
	b_end = i;
	be = i;
	if(a_end>=b_end)
	{
		for(i=a_end;i>=0;i--)
            b[i] = b[b_end--];
	}
	else
	{
		for(i=b_end;i>=0;i--)
            a[i] = a[a_end--];
	}
	if(ae>=be)
	    for(i=ae-be-1;i>=0;i--)
	        b[i] = '0';
	else
	    for(i=be-ae-1;i>=0;i--)
	        a[i] = '0';

	
	for(i=0;a[i]!=0;i++)
	;
	for(j=i-1;j>=0;j--)
	{
		k = (a[j]-'0'+ b[j] -'0')+carry;
		c[j] = (k%10)+'0';
	    carry = k/10;
	}
	 c[i] = 0; 
    
	if(carry==1)
	{
	  for(j=i+1;j>0;j--)
	        c[j]=c[j-1];
	    c[0]='1';
    }
    return;
}
