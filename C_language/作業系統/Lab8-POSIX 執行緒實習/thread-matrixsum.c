#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define M 5
#define N 4
int A[M][N]= {  
        {1,2,3,4},
        {2,4,6,8},
        {3,6,9,12},
        {4,8,12,16},
        {5,10,15,20}};

pthread_t tid[M];  //儲存每個工作執行緒id
int row[M];        //儲存每個工作執行緒要計算的列編號
int rowsum[M] = {0}; //儲存每列之總和

void *summationThread(void *param);
void printMatrix(int *mat, int row, int col);

int main(int argc, char *argv[])
{   
    int i, matrixSum=0;
    int *result;  //用來接收工作執行緒傳回值
    
    //Create working threads to compute the sum of each row
    for(i = 0; i < M; i++)
    {
        row[i] = i;
        pthread_create(...);
    }

    for(i = 0; i < M; i++)
    {
        pthread_join(...);
        ... 
    }

    //Dispaly Matrix A
    printf("\nMatrix A=\n");
    printMatrix((int *)A, M, N);

    //Dispaly result of matrix summation
    printf("\nTotal sum =%d\n", matrixSum);
    return 0;
}

void printMatrix(int *mat, int row, int col)
{
    int i,j;

    for (i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%4d\t", *((mat + i * col) + j));
        }
        printf("\n");
    }
}

void *summationThread(void * param)
{
    int row = *(int *) param;
    int i, sum=0;

    //Perform the matrix summation
    ...
    pthread_exit(...);
}

