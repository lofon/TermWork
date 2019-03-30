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
	printf("��ӭʹ��\n�༶ѧ�ڳɼ���\n[�汾 2.0.1]\n");
loop1:	printf("------------------------------------------------------------------\n");
	printf("����1��¼��ѧ����Ϣ������2�����ɼ�˳�����������3����ѧ�����������0���˳�\n");

	switch (getch())
	{
	case '1': num = input(); goto loop1;
	case '2': outputbyorder(num); goto loop1;
	case '3':outputbyID(num); goto loop1;
	case '0': goto loop2;
	default:printf("���������밴����ʾ���²���......"); goto loop1;
   }
loop2:	return 0;
}//end function main

int input(void)
{
	       int i = 0;
loop3: printf("\n������ѧ��ѧ�ţ�");
		   scanf("%d", &stu[i].ID);
		   printf("\n������ѧ��������");
		   scanf("%s", stu[i].name);
		   printf("\n���������ĳɼ���");
		   scanf("%d", &stu[i].subject.chinese);
		   printf("\n��������ѧ�ɼ���");
		   scanf("%d", &stu[i].subject.math);
		   printf("\n������Ӣ��ɼ���");
		   scanf("%d", &stu[i].subject.english);
		   printf("\n���������ֳɼ���");
		   scanf("%d", &stu[i].subject.music);
		   printf("\n�����������ɼ���");
		   scanf("%d", &stu[i].subject.art);
		   i++;

	printf("----------------------------------------------------------\n�������밴��1���������˳�\n\n");
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
		printf("��%d����%s��ѧ�ţ�%6d\n�ܷ֣�%d---���ģ�%3d---��ѧ��%3d", i+1, stu[i].name, stu[i].ID, arr[i], stu[i].subject.chinese, stu[i].subject.math);
		printf("---Ӣ�%3d---���֣�%3d---������%3d\n\n\n", stu[i].subject.english, stu[i].subject.music, stu[i].subject.art);
	} 
		
}

void outputbyID(int num)
{
	_for(i, 0, num)
	{
		printf("ѧ�ţ�%6d---������%6s---���ģ�%3d---��ѧ��%3d", stu[i].ID, stu[i].name, stu[i].subject.chinese, stu[i].subject.math);
		printf("---Ӣ�%3d---���֣�%3d---������%3d\n", stu[i].subject.english, stu[i].subject.music, stu[i].subject.art);
	}
}

