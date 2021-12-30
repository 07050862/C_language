/* 
 * ch11-06.c
 * µ²ºc»P¨ç¼Æ 
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

void show_stu(struct stu_rec stu);
void set_stu_birth(struct stu_rec *p,struct birth_rec d);
void set_stu_id(struct stu_rec s[],int y[]);

int main(void)
{
	struct stu_rec stu[2] = {
		{0,"Barack Obama",'M'},
		{0,"George Bush",'M'}
		};
	struct birth_rec day[2] = {{1961,8,4},{1947,6,6}};
	int id[2] = {2008,2004};

	struct stu_rec *p1 = stu;

	int i;
	
	set_stu_id(stu,id);
		
	for (i=0;i<2;i++)
		set_stu_birth(p1+i,day[i]);
	
	for (i=0;i<2;i++)
		show_stu(stu[i]);
	
	p1 = stu;
	for (i=0;i<2;i++)
	{
		show_stu(*p1);
		p1++;
	}
	
	system("pause");
	return 0;
}

void show_stu(struct stu_rec stu)
{
	printf("=== Student %d ===\n",stu.id);
	printf("Name: %s\n",stu.name);
	printf("Gender: %c\n",stu.sex);
	printf("Birth: %d/%d/%d\n",
		stu.birth.year,stu.birth.month,stu.birth.day);
}

void set_stu_id(struct stu_rec s[],int y[])
{
	int i;
	for (i=0;i<2;i++)
		s[i].id = y[i];
}

void set_stu_birth(struct stu_rec *p,struct birth_rec d)
{
	p->birth = d;
}
