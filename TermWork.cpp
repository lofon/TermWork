////////////////////////TermWork.cpp///////////////////////
/*This is a program named TermWork
It could record setudent's information
and output the order of students*/

#include <stdio.h>
#include <conio.h> //to use function getch()
#include<string.h>
#include "Student.h"

#define _for(i, a, b) for(int i = (a); i<(b); i++)

int input (void);
int total(int);
void outputbyorder(int);
void outputbyID(int);

//main function
int main()
{
	int num; //to record the num of students input
	printf("欢迎使用\n班级学期成绩单\n[版本 2.0.1]\n");
loop1:	printf("------------------------------------------------------------------\n");
	printf("按“1”录入学生信息，按“2”按成绩顺序输出，按“3”按学号输出，按“0”退出\n");

	switch (getch())
	{
	case '1': num = input(); goto loop1;
	case '2': outputbyorder(num); goto loop1;
	case '3':outputbyID(num); goto loop1;
	case '0': goto loop2;
	default:printf("输入有误，请按照提示重新操作......"); goto loop1;
   }
loop2:	return 0;
}//end function main

int input(void)
{
	       int i = 0;
loop3: printf("\n请输入学生学号：");
		   scanf("%d", &stu[i].ID);
		   printf("\n请输入学生姓名：");
		   scanf("%s", stu[i].name);
		   printf("\n请输入语文成绩：");
		   scanf("%d", &stu[i].subject.chinese);
		   printf("\n请输入数学成绩：");
		   scanf("%d", &stu[i].subject.math);
		   printf("\n请输入英语成绩：");
		   scanf("%d", &stu[i].subject.english);
		   printf("\n请输入音乐成绩：");
		   scanf("%d", &stu[i].subject.music);
		   printf("\n请输入美术成绩：");
		   scanf("%d", &stu[i].subject.art);
		   i++;

	printf("----------------------------------------------------------\n继续输入按“1”，否则退出\n\n");
	if (getch() == '1')
		goto loop3; //do loop
	else
		return i; //return the num of students
}//end function input

//return total score
int total(int i)
{
	return (stu[i].subject.chinese + stu[i].subject.math + 
	stu[i].subject.english + stu[i].subject.music + stu[i].subject.art);
}//end function total

//print the students' score in order
void outputbyorder(int sum)
{
	int arr[] = { NULL }; //initialize
	int temp;

	_for(i, 0, sum)
		arr[i] = total(i);

	_for(i, 0, sum)
		_for(j, i + 1, sum)
		if (arr[i] < arr[j])
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			strcpy(stu[29].name, stu[i].name);
			strcpy(stu[i].name, stu[j].name);
			strcpy(stu[j].name, stu[29].name);
		}

	_for(i, 0, sum)
	{
		printf("第%d名：%s，学号：%6d\n总分：%d---语文：%3d---数学：%3d", i+1, stu[i].name, stu[i].ID, arr[i], stu[i].subject.chinese, stu[i].subject.math);
		printf("---英语：%3d---音乐：%3d---美术：%3d\n\n\n", stu[i].subject.english, stu[i].subject.music, stu[i].subject.art);
	} 
		
}

void outputbyID(int num)
{
	_for(i, 0, num)
	{
		printf("学号：%6d---姓名：%6s---语文：%3d---数学：%3d", stu[i].ID, stu[i].name, stu[i].subject.chinese, stu[i].subject.math);
		printf("---英语：%3d---音乐：%3d---美术：%3d\n", stu[i].subject.english, stu[i].subject.music, stu[i].subject.art);
	}
}

