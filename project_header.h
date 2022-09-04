#pragma once
#ifndef HEADER_FILE
#define HEADER_FILE
#define _CRT_SECURE_NO_WARNINGS
//include for libaries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>//For linux System 'strdup' without  _ 
//macros 
//#define FILENAME "student_grades_test3.csv" 
#define FILENAME2 "student_grades.csv" 

#define CHUNK 10

//struct && typedef && enum
typedef enum 
{
	true = 1,
	false = 0
}bool;
enum COURSES {
	C_language = 0,
	Computer_Networks = 1,
	CS_Fundamentals = 2

};

typedef struct student_detailes
{
	char ID[10];
	char* first_name;
	char* last_name;
	char CS_Fundamentals ;
	char Computer_Networks ;
	char C_language ;
	float avg;
	struct student_detailes* next;

}student_detailes;

typedef struct student_detailes_err
{
	char ID[10];
	char* first_name;
	char* last_name;
	char CS_Fundamentals;
	char Computer_Networks;
	char C_language;
	float avg;
	struct student_detailes_err* next;
	bool fix;
}student_detailes_err;

typedef struct Director
{
	student_detailes* head;
	student_detailes* tail;
	int size;


}Director;

//statement of functions
void addToTail(Director* list, student_detailes* newStudent_detailesNode);
void addToHead(Director* list, student_detailes* newStudent_detailesNode);
void insert_to_sort_list(Director* list, student_detailes* newStudent_detailesNode);
void Error_messageAllocation();
Director* creatList();
void toUpperCase(char* str);
int IsonlyNum(char* str);
int check_Valid_ID(student_detailes* newStudent, char* token);
int check_Valid_Grade(student_detailes* newStudent, char* token, int index);
void copy_struct_to_struct_err(student_detailes* newStudent, student_detailes_err* err_student);
student_detailes_err* creat_err_struct();
void add_to_error_list(student_detailes_err** head, student_detailes_err* err);
int check_valid_student(student_detailes* newStudent,int index);
student_detailes* creat_struct_student(char* line, int index, student_detailes_err** head);
void enter_avg(student_detailes* newStudent);
void printHeader();
int confirm(char* str);
Director* read_from_file(student_detailes_err** head);
int is_valid_token(char* token);
void change_last_name(student_detailes* ptr, student_detailes* student_for_search, int* flag);
void del_student(student_detailes** head);
student_detailes* search_Student_in_list(student_detailes* ptr, student_detailes* student_for_search, int* flag);
int is_valid_name(char* str);
int is_valid_ID(char* str);
int checkCours(char* line);
void initStudentForC(student_detailes* newStudent);
void initStudentForComputer_Networks(student_detailes* newStudent);
void initStudentForCS_Fundamentals(student_detailes* newStudent);
student_detailes* free_student(student_detailes* newStudent);
char* del_spaces(char* str);
student_detailes* creatStudentFromUser(char* line);
void printStudent(student_detailes* ptr);
void print_studentEror_specific(student_detailes_err* err);
void print_studentEror(student_detailes_err* err);
void exeQueryForEqoual(char* token, char* subject, student_detailes* ptr);
void exeQueryForSmaller(char* token, char* subject, student_detailes* ptr);
void exeQueryForBigger(char* token, char* subject, student_detailes* ptr);
void exeQueryForNotEqoual(char* token, char* subject, student_detailes* ptr);
void printExample();
void selectQeury(Director* list, char* query);
char* check_query(char* input);
void freelistError(student_detailes_err** head_err);
void print_menu(Director* list, student_detailes_err* head_err);
void printList(student_detailes* ptr);
char* read_input_no_limit(FILE* fp, int stdinS);
void readlistToFile(student_detailes* new_student);
void freelist(Director* list);

#endif

/*
MEIR,COHEN,654987321,Computer Networks,56
MEIR,COHEN,654987321,CS Fundamentals,23
SHALOM,DAN,503654987,C language,100
SHIMON,HAIMON,052359873,Computer Networks,85
BEN OR,LEVI,302999987,C language,78
BEN OR,LEVI,302999987,CS Fundamentals,98
BEN,LEVI,302205987,C language,98
ARIE,MEIR,897654321,C language,78
BEN,RADAN,302541987,C language,98
BEN OR,RDAN,302546987,C language,100
BEN OR,RDAN,302546987,Computer Networks,95
HANA,SHALOM,305879312,CS Fundamentals,90
BEN ZTION,SHOVAL,066879654,C language,94
OR,YONA,159785643,C language,57
OR,YONA,159785643,Computer Networks,98
OR,YONA,159785643,CS Fundamentals,78
*/