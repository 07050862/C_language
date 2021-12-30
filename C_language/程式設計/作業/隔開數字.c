/*將數字每三個以逗號隔開*/
#include<stdio.h>

void afunc(int n,char ans[]);
int main(void)
{
    int n=0;
    char ans[80]={0};
    scanf("%d",&n);   
    afunc(n,ans);
    printf("="); 
    puts(ans);
    return 0;
}
void afunc(int n,char ans[])
{
    int i=0,count=1,ori;
    ori = n;
 
    for(i=0;n>0;i++)   
 	    n/=10;
 	
    i = (i-1) + (i-1)/3;
    
    for(i;i>=0;i--,count++) 
    {    
 	    if(count%4==0)          
            ans[i]  =  ',';
        else
        {
    	    ans[i]  = (ori %10) +'0'; 
            ori /=10;
	    }
    }
}
