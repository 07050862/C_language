/* 
 * ch11-05.c
 * µ²ºc«ü¼Ð 
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
		{0,"Barack Obama",'M',{1961,8,4}},
		{2004,"George Bush",'M'}
		};
	int y1 = 2008;
	struct birth_rec day1 = {1947,6,6};

	struct stu_rec *p1 = stu, *p2;
	struct birth_rec *p3 = &day1;

	(*p1).id = y1;	
	p1++;
	p1->birth = *p3;
	
	int i;
	
	p2 = p1 = stu;
	for (i=0;i<2;i++)
	{
		printf("=== Student %d ===\n",(*p1).id);
		printf("Name: %s\n",p1->name);
		printf("Gender: %c\n",(p2+i)->sex);
		printf("Birth: %d/%d/%d\n",
			p1->birth.year,p1->birth.month,p1->birth.day);
		p1++;
	}
	
	system("pause");
	return 0;
}
