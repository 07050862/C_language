/*祘Αい块 5 计㊣ㄧΑт 5 计い程籔程
ㄤ程程のㄢ计搭挡狦*/ 
#include <stdio.h>

int main(void)
{  
    int max=0,min=0,a[5],i;
    
    for(i=0;i<=4;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=4;i++)
    {
        if(a[max]<a[i])
            max = i;
        else if(a[i]<a[min])
            min = i;
    }
   
    printf("程%d\n",a[max]);
    printf("程%d\n",a[min]);
    printf("ㄢ计畉%d",a[max]-a[min]);
    return 0;
}
