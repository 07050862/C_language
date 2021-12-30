#include <stdio.h>
int main(void){
	int n,i,j;
	
	printf("N*N的乘法表\n");
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		
        for(j=1;j<=n;j++){
        	
        	if(i>=10)
        	{
        	printf("%d*%d=%-4d",i,j,i*j);	
			}
			else		
			printf("%d*%d=%-5d",i,j,i*j);
		}
		
		    printf("\n\n");	
  
		}
	return 0;
} 
