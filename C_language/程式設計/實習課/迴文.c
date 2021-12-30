/*
判斷是否迴文
*/ 

#include<stdio.h>

int main(void)
{
    char a[80];
    int end,i;
    gets(a);
    
    for(i=0;a[i]!=0;i++)
    ;
    end = i-1;
    
    for(i=0;a[i]!=0;i++)
    {
        if(a[i]!=a[end-i])
            {
                i=-1;
                break;
            }
    }
    if(i==-1)
        printf("Please enter string: Result: NO\n");
    else
        printf("Please enter string: Result: YES\n");
    
    return 0;
}
