#include <stdio.h>
void afunc(char a1[],char a2[],char a3[]); 
int main(void) 
{ 
    char a1[80],a2[80],a3[80]; 
     
    gets(a1); 
    gets(a2); 
     
    afunc(a1,a2,a3); 
    printf("%s",a3); 
         
    return 0; 
}
void afunc(char a1[],char a2[],char a3[])
{
	int i,j,k,carry=0;
	
	for(i=0;a1[i]!=0;i++)
	;
	for(j=i-1;j>=0;j--)
	{
		k = (a1[j]-'0'+ a2[j] -'0')+carry;
		a3[j] = (k%2)+'0';
	    carry = k/2;
	}
	 a3[i] = 0;
}
