/* 除錯練習 
   Author：李柏賢（07050862）
   Purpose：費氏數列程式除錯練習，輸入一整數值，算出該向費氏數列之值，將下列程式碼的語法、邏輯錯誤全部修正之。
*/
# include <stdlib.h>
# include <stdio.h>
 
int main() {
    int n, i, n_2=0, n_1=1, fib;
    
    printf("The 0th number is 0, and the first number is 1\n");
    printf("ex : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233 ...\n\n");
    printf("Please input an integer to show the last value of Fibonacci Sequence :");
    scanf("%d", &n);

    if (n == 0)
        fib = n_2;
     else if (n == 1)
        fib = n_1;
     else{
         for (i=1; i<=n-1; i++) {
            fib = n_2 + n_1;
            n_2 = n_1;
            n_1 = fib;
        }
    }
     printf("The %dth Fibonacci number is %d\n\n", n, fib);

    return 0;
}

