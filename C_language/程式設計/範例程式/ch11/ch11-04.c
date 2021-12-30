/* 
 * ch11-04.c
 * µ²ºc°}¦C 
 */
 
#include <stdio.h> 
#include <stdlib.h>

struct birth_rec
{
	int year;
	int month;
	int day;
};

struct stu_rec 
{
	int id;
	char name[40];
	char sex;
	struct birth_rec birth;
};

int main(void)
{
	struct stu_rec stu[2] = {
		{2008,"Barack Obama",'M',{1961,8,4}},
		{2004,"George Bush",'M',{1947,6,6}}
		}; 
	int i;
	
	for (i=0;i<2;i++)
	{
		printf("=== Student %d ===\n",stu[i].id);
		printf("Name: %s\n",stu[i].name);
		printf("Gender: %c\n",stu[i].sex);
		printf("Birth: %d/%d/%d\n",
			stu[i].birth.year,stu[i].birth.month,stu[i].birth.day);
	}
	
	system("pause");
	return 0;
}
