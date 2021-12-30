/* 
 * ch11-01.c
 * 結構定義與結構變數 
 */
 
#include <stdio.h> 
#include <stdlib.h>

struct stu_rec		//結構定義 
{
	int id;
	char name[40];
	char sex;
};

int main(void)
{
	struct stu_rec stu1,stu2;	//宣告結構變數   
	
	printf("Enter Student ID: ");
	scanf("%d",&stu1.id);
	fflush(stdin);
	
	printf("Enter Student Name: ");
	gets(stu1.name);
	
	printf("Enter Student Gender: ");
	scanf("%c",&stu1.sex);
	
	system("pause");
	return 0;
}
