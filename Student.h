//Student.h
//designed by lofone at 05/10

#ifndef STUDENT_H
#define STUDENT_H

//define five subjects
struct Subject 
{
	int chinese;
	int math;
	int english;
	int music;
	int art;
};//end function Subject

//define Student whose function is record message
struct Student
{
	unsigned int ID; //It's a number
	char name[12];
	struct Subject subject;
};//end seruct Student

//typedef struct Subject SUB;
typedef struct Student STU;
STU stu[30] = { NULL }; //default construct 30 students

#endif
