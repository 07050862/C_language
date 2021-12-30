/* 
 * ch11-02.c
 * 結構變數初值給定 
 */
 
#include <stdio.h> 
#include <stdlib.h>

struct stu_rec 
{
	int id;
	char name[40];
	char sex;
};

int main(void)
{
	struct stu_rec stu1 = {2008,"Barack Obama",'M'};	//初值給定 
	struct stu_rec stu2;   
	
	printf("Student ID: %d\n",stu1.id);
	printf("Student Name: %s\n",stu1.name);
	printf("Student Gender: %c\n",stu1.sex);
	
	stu2 = stu1;	//指定運算元 
	printf("Student ID: %d\n",stu2.id);
	
	system("pause");
	return 0;
}
