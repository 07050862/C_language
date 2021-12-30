/*
=== 範例執行結果(1) ===
0101 <-- 從鍵盤輸入0101[Enter]
0101 = 5

=== 範例執行結果(2) ===
1010 <-- 從鍵盤輸入1010[Enter]
1010 = 10
*/
#include <stdio.h>
int main(void)
{
	int n,i=1,ans=0,ori;
	scanf("%d",&n);
	ori = n;
	
	for(;n>0;)
	{
		ans=ans+(n%10)*i;
		n/=10;
		i*=2;
	}
	printf("%04d = %d",ori,ans);
	return 0;
}
