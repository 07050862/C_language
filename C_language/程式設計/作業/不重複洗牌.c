#include <stdio.h> 
#include <stdbool.h>
/* 不重複的撲克洗牌 */
int main()
 {
 	int poker[52] = {0};

        bool isRepeat;
        int m_rand,i,j;
        for (i = 0; i < 52; i++) {
            do {
            	int min = 0;
                int max = 51;

                /* 產生 [min , max] 的整數亂數 */
               m_rand = rand() % (max - min + 1) + min;
                

                //檢查機制
                isRepeat = false;
                for (j = 0; j < i; j++) {
                    if (m_rand == poker[j]) {
                        isRepeat = true;
                        break;
                    }
                }
            }while(isRepeat);

            poker[i] = m_rand;

            // poker[i] = rand;
        }
        for (i = 0; i < 52; i++)
		printf("poker[%d] = %d\n", i, poker[i]);
    }
 
      