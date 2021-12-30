/* 
 * ch11-03.c
 * ±_ª¬µ²ºc 
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
	struct birth_rec birthday;
};

int main(void)
{
	struct stu_rec stu1 = {2008,"Barack Obama",'M',{1961,8,4}};//ªì­Èµ¹©w 
	struct stu_rec stu2;   
	
	printf("=== Student %d ===\n",stu1.id);
	printf("Name: %s\n",stu1.name);
	printf("Gender: %c\n",stu1.sex);
	printf("Birth: %d/%d/%d\n",
		stu1.birthday.year,stu1.birthday.month,stu1.birthday.day);
		
	system("pause");
	return 0;
}
