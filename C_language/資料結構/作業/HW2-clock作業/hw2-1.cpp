#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1001
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void sort(int[], int);  /*選擇排序*/

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n; i++) {
		min = i;
		for (j = i; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}

int main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;

	/*根據n = 0, 10, …, 100, 200, …, 1000來計時 */
	printf("    n    repetitions      time\n");
	for (n = 0; n <= 1000; n += step)
	{ /*根據n的大小得到時間 */
		long repetitions = 0;
		clock_t start = clock();
		do
		{
			repetitions++;
			/* 初始最差情況的資料 */
			for (i = 0; i < n; i++)
				a[i] = n - i;
			sort(a, n);
		} while (clock() - start < 1000);
		/* 重複這個迴圈直到已經用掉了足夠的時間 */

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;
		printf("%6d  %9d  %f\n", n, repetitions, duration);
		if (n == 100) step = 100;
	}
}
