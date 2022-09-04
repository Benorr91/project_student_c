#include "project_header.h"

void addToTail(Director* list, student_detailes* newStudent_detailesNode)
{

    list->size++;//for update the size

    if (list->head == NULL)
    {
        list->head = list->tail = newStudent_detailesNode;//When the list is empty compare the head and tail to be the new student
        return;
    }

    list->tail->next = newStudent_detailesNode;//The next of the tail will be equal to the new student
    list->tail = newStudent_detailesNode;//Compares the tail to the new student
}
void addToHead(Director* list, student_detailes* newStudent_detailesNode)
{

    list->size++;

    if (list->head == NULL)
    {
        list->head = list->tail = newStudent_detailesNode;
        return;
    }
    newStudent_detailesNode->next = list->head;
    list->head = newStudent_detailesNode;
}



void insert_to_sort_list(Director* list, student_detailes* newStudent_detailesNode) {
    if (list->head == NULL)//if head is null set the head and the tail to be the new student
    {
        list->head = list->tail = newStudent_detailesNode;;
        return;
    }

    if (strcmp(newStudent_detailesNode->last_name, list->head->last_name) <= 0) {//Comparison of the new student's last name with the head of the list Returns a negative number once it is smaller
        addToHead(list, newStudent_detailesNode);
        return;
    }

    if (strcmp(newStudent_detailesNode->last_name, list->tail->last_name) >= 0)//Comparison of the new student's last name with the top tail the list Returns a negative number once it is smaller
    {
        addToTail(list, newStudent_detailesNode);
        return;
    }

    student_detailes* prev = list->head;
    int a;
    while (a = strcmp(newStudent_detailesNode->last_name, prev->next->last_name) > 0)//Move the pointer until before the student we want to insert the new student
    {
        prev = prev->next;
    }

    list->size++;//Increases the size of the list
    newStudent_detailesNode->next = prev->next;//The next new student will point to the next student after the student we stopped in the loop
    prev->next = newStudent_detailesNode;//compares the prev next to the new student

}
void Error_messageAllocation() {
    printf("Allocatin failed , not enough memory\n");

}
//init the list with NUll and 0 for size
Director* creatList() {
    Director* list = (Director*)malloc(sizeof(Director));
    if (list == NULL) {
        Error_messageAllocation();

    }
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}
//Going over all the letters of the string and turning them into capital letters

void toUpperCase(char* str) {

    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }
}
//Going over all the letters of the string and checking that there are only numbers
int IsonlyNum(char* str) {

    while (*str) {
        if (*str < '0' || *str > '9')//check ther only Numbers
        {
            return 0;
        }
        str++;
    }
    return 1;
}

//Checking the integrity of the ID is 9 long and contains only numbers
int check_Valid_ID(student_detailes* newStudent, char* token) {
    if (strlen(token) > 9 || strlen(token) < 9|| !IsonlyNum(token)) {
        char ID[10];
        printf("Not Valid ID Please Enter a valid ID for user %s %s with 9 numbers only !\n",newStudent->first_name,newStudent->last_name);
        char a=scanf("%s", ID);
        a=getchar();
        if(*ID)
            strcpy(newStudent->ID, ID);
        return 0;
    }
    return 1;
}

//void scanfForGrade(student_detailes* newStudent, int index) {
//    int grade;
//    printf("Grade for %s is not valid Please Enter a Valid Grade for user %s %s between 0-100\n", index == 0 ? "C language" : index == 1 ? "Computer_Networks" : "CS Fundamentals", newStudent->first_name, newStudent->ID);
//    char a = scanf("%d", &grade);
//         a= getchar();
//    //checking in witch index and 0 for C_language 1 for newStudent->Computer_Networks 2 newStudent->CS_Fundamentals
//    if (index == 0)
//        newStudent->C_language = grade;
//    else if (index == 1)
//        newStudent->Computer_Networks = grade;
//    else
//        newStudent->CS_Fundamentals = grade;
//}

//init student for each Cours
void initStudentForC(student_detailes* newStudent) {
    newStudent->Computer_Networks = -1;
    newStudent->CS_Fundamentals = -1;
    newStudent->avg = (float)newStudent->C_language;
    newStudent->next = NULL;
}
void initStudentForComputer_Networks(student_detailes* newStudent) {
    newStudent->CS_Fundamentals = -1;
    newStudent->C_language = -1;
    newStudent->avg = (float)newStudent->Computer_Networks;
    newStudent->next = NULL;
}
void initStudentForCS_Fundamentals(student_detailes* newStudent) {
    newStudent->Computer_Networks = -1;
    newStudent->C_language = -1;
    newStudent->avg = (float)newStudent->CS_Fundamentals;
    newStudent->next = NULL;
}

//func get 3 patametrs for checkin the the new student for valid graed return 0 if not valid else return 1
int check_Valid_Grade(student_detailes* newStudent, char* token, int index) {
  
    if ((atoi(token) > 100 || atoi(token) < 0)&&atoi(token)!=-1) {
        return 0;
    }
    return 1;


}
//func check int num that valid grade return 0 if not valid else return 1
int is_valid_grade(int num) {
    if ((num > 100 || num < 0)&&num!=-1)  {
        return 0;
    }
    return 1;
}
//finc gets id in parameter and return 0 if not valid else return 1
int is_valid_ID(char * ID) {
    if (ID[strlen(ID) - 1] == ',') {
        ID[strlen(ID) - 1] = 0;
    }
    if (strlen(ID) != 9 || !IsonlyNum(ID)) {
        return 0;
    }
    return 1;
}
//func gets new student and index in his parameter for know which cours and check if not valid return 0 else return 1
int check_valid_student(student_detailes* newStudent,int index) {
    if (!is_valid_name(newStudent->first_name)|| !is_valid_name(newStudent->last_name)||!is_valid_ID(newStudent->ID)) {
        return 0;
    }
    if(!is_valid_grade(newStudent->C_language)|| !is_valid_grade(newStudent->CS_Fundamentals)|| !is_valid_grade(newStudent->Computer_Networks))
        return 0;

    return 1;
}
//A function that adds to the top of the error list - Gets the head of the error list and the new error
void add_to_error_list(student_detailes_err** head , student_detailes_err* err) {
    if (*head == NULL)
    {
        *head = err;
        return;
    }
    err->next =*head;
    *head = err;
}
//A function that creates a structure of student_detailes_err* with null and return student_detailes_err* 
student_detailes_err* creat_err_struct() {
    student_detailes_err* err  = (student_detailes_err*) calloc(sizeof(student_detailes_err),1);
    if (err == NULL) {
        Error_messageAllocation();
        return NULL;
    }
    return err;

}

//A function that copies the student with the error to the error's structure 
void copy_struct_to_struct_err( student_detailes* newStudent, student_detailes_err* err_student) {
    err_student->first_name = _strdup(newStudent->first_name);
    err_student->last_name = _strdup(newStudent->last_name);
    strcpy(err_student->ID, newStudent->ID);
    err_student->avg = newStudent->avg;
    err_student->Computer_Networks = newStudent->Computer_Networks;
    err_student->CS_Fundamentals = newStudent->CS_Fundamentals;
    err_student->C_language = newStudent->C_language;

}



//func gets line and index to know which student to creat return the new student 
student_detailes* creat_struct_student(char* line, int index, student_detailes_err** head) {
    toUpperCase(line);
    char* token = strtok(line, ","); 
    /*student_detailes_err* head= NULL;*/
    student_detailes_err* err_student=NULL;
    student_detailes* newStudent = (student_detailes*)malloc(sizeof(student_detailes));
    if (newStudent == NULL) {
        Error_messageAllocation();
        return free_student(newStudent);
    }
            //For linux System strdup without _
       
         newStudent->first_name = _strdup(token);
         token = strtok(NULL, ",");
         newStudent->last_name = _strdup(token);
         token = strtok(NULL, ",");
         //check for valid ID if less than 9 return 1 if is valid else asking the user for new ID 
         strcpy(newStudent->ID, token);
         token = strtok(NULL, ",");
         token = strtok(NULL, "\0");

             switch (index)
             {
             case 0:

                 newStudent->C_language = atoi(token);
                 initStudentForC(newStudent);
                 if (check_valid_student(newStudent, 0)) {

                    return newStudent;
                 }
                 else
                 {
                     err_student = creat_err_struct();
                     copy_struct_to_struct_err(newStudent,err_student);
                     add_to_error_list(head, err_student);
                     return NULL;
                 }

             case 1:
                 newStudent->Computer_Networks = atoi(token);
                 initStudentForComputer_Networks(newStudent);
                 if (check_valid_student(newStudent, 0)) {

                     return newStudent;
                 }
                 else
                 {
                     err_student = creat_err_struct();
                     copy_struct_to_struct_err(newStudent, err_student);
                     add_to_error_list(head, err_student);
                     return NULL;
                 }
             case 2:
                 newStudent->CS_Fundamentals = atoi(token);
                 initStudentForCS_Fundamentals(newStudent);
                 if (check_valid_student(newStudent, 0)) {

                     return newStudent;
                 }
                 else
                 {
                     err_student = creat_err_struct();
                     copy_struct_to_struct_err(newStudent, err_student);
                     add_to_error_list(head, err_student);
                  
                     return NULL;
                 }
                 // operator doesn't match any case constant 0, 1, 2, /
             default:
                 printf("Error! index  is not correct");
                 return NULL;
             }
         
         return NULL;


    
}
//A function that receives a pointer to a file and reads a line from it, no matter how long it is

char* read_input_no_limit(FILE* fp, int stdinS)
{
  
    char* input = NULL;
    char tempbuf[CHUNK];
    size_t inputlen = 0, templen = 0;
    if (stdinS == 0) {
        do {//We will divide our string into segments and when we reach the last segment that has a \n or the length of the string is greater than less than the amount of the segment, we will return the line
            fgets(tempbuf, 10, fp);
            templen = strlen(tempbuf);
            unsigned char* tmp = (char*)realloc(input, inputlen + templen + 1);
            if (tmp == NULL)
            {
                Error_messageAllocation();
                return input;
            }
            else
                input = tmp;
                
            
                strcpy(input + inputlen, tempbuf);//Moving the pointer to the end of the string to copy the new string there
                inputlen += templen;//The length scheme of the strings to allocate appropriate memory


        } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');
    }
    else {
        do {//We will divide our string into segments and when we reach the last segment that has a \n or the length of the string is greater than less than the amount of the segment, we will return the line
            fgets(tempbuf, 10, stdin);//for the user 
            templen = strlen(tempbuf);
            unsigned char* tmp = (char*)realloc(input, inputlen + templen + 1);
            if (tmp == NULL)
            {
                Error_messageAllocation();
                return input;
            }
            else
                input = tmp;
            strcpy(input + inputlen, tempbuf);//Moving the pointer to the end of the string to copy the new string there
            inputlen += templen;//The length scheme of the strings to allocate appropriate memory


        } while (templen == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');
    }

    if(input[strlen(input) - 1]=='\n')
        input[strlen(input) - 1] = '\0';


    return input;
}


//A function to print the header
void printHeader() {

    printf("Welcome To Student's DB\n");
    printf("You can get information about a student by set and select queries\n");
    printf("You can print your student list if you Enter \"print\" and the Error list with \"print error\"\n");
    printf("Enter \"quit\" for exit! \n");
    printf("Student with -1 in is grade means that he didn't tested in this Cours\n");
    printf("For Example select average>50 OR set first name =Avi(Only letters!),  last name= Yakov (Only letters!), ID= 958478321 (9 numbers only! ), C language= 95 ( Between 0-100 ) \n\n");

}
//A function to print the Error students
void print_studentEror_specific(student_detailes_err* err) {
    fprintf(stdout, " First name = %s , Last name = %s , ID = %s , C language = %-3d ,Computer Networks = %-3d ,CS Fundamentals = %-3d ,  is not valid! please fix it !\n\n", err->first_name, err->last_name, err->ID, err->C_language, err->Computer_Networks, err->CS_Fundamentals);
}
void print_studentEror(student_detailes_err* err ) {
    while (err)
    {
        if (!err->fix)
            print_studentEror_specific(err);
        err = err->next;
    }
}



//A function that reads from the file and produces the structure receives a double pointer to the list of errors so that it can be updated and returns the list
Director* read_from_file(student_detailes_err** head ) {
    Director* list = creatList();
    
    char flag = 0;
    int a;
    char file_name_temp[100]={0};
    FILE* fp = fopen(FILENAME2, "r");
    //case file not open asking the user to enter valid file
    while (fp == NULL)
    {
        printf("Error! Could not open file, check if the file exsits  \n");
        a=scanf("%s", file_name_temp);
        a= getchar();
        fp= fopen(file_name_temp, "r");
    }


    char* line = NULL;
    student_detailes* new_student = NULL;
    //run all over the file and insert to my list
    int index=0;
    int i = 0;
    while (1)
    {
      
        i++;
        line = read_input_no_limit(fp, 0);
        if (*line == -52) break;

        if (!checkCours) 
                  continue;
        
        if (strstr(line, "C language")) {
            index = 0;
            new_student = creat_struct_student(line, index,head );
            if (new_student) {
                new_student = search_Student_in_list(list->head, new_student, &index);
                    flag = 0;
            }
            else {
                flag = 1;

            }
         }
        else if (strstr(line, "Computer Networks")) {
            index = 1;
            new_student = creat_struct_student(line, index, head);
            if (new_student) {
                new_student = search_Student_in_list(list->head, new_student, &index);
                flag = 0;
            }
            else 
                flag = 1;
        }
        else if (strstr(line, "CS Fundamentals")) {
            index = 2;
            new_student = creat_struct_student(line, index, head);
            if (new_student) {
                new_student = search_Student_in_list(list->head, new_student, &index);
                flag = 0;
            }
            else 
                flag = 1;

            
        }
        if (!flag&&index) {
            insert_to_sort_list(list, new_student);
            
        }
        if(new_student)
            enter_avg(new_student);

    }

    fclose(fp);
   
    return list;
}
//A function that checks if the token is valid and returns 0 if not and 1 if yes
int is_valid_token(char* token) {
    if (token == NULL) {
        printf("Invalid Query ,try again\n");
        return 0;
    }
    return 1;
}
//A function that receives a pointer to the list and a pointer to the new student we want to generate and changes the last name
void change_last_name(student_detailes* ptr, student_detailes* student_for_search, int* flag) {
    ptr->last_name = _strdup(student_for_search->last_name);
    switch (*flag)
    {

    case 0:
    
        ptr->C_language = student_for_search->C_language;
        break;
    case 1:
   
        ptr->Computer_Networks = student_for_search->Computer_Networks;
        break;
    case 2:
   
        ptr->CS_Fundamentals = student_for_search->CS_Fundamentals;
        break;

    default:
        break;
    } 
    *student_for_search = *ptr;
    ptr->last_name = NULL;

}
//A function that receives the head of the list as a parameter and the student to delete and deletes it
void del_student(student_detailes** head) {
    
    student_detailes* ptr = (*head)->next;
    student_detailes* prev = *head;
        if (prev->last_name == NULL) {
            *head = (*head)->next;
            free(prev);
            return;
        }
        while (ptr->last_name != NULL)
        {
            ptr = ptr->next;
            prev = prev->next;
        }
        if (ptr->next)
            prev->next = ptr->next;

        free(ptr);
    


}

//A function that receives the head of the list as a parameter and the student for the search and returns a pointer to it if found, otherwise returns null
student_detailes* search_Student_in_list(student_detailes* ptr, student_detailes* student_for_search, int* flag) {
  
    student_detailes* head = ptr;
    while (ptr)
    {     
        if (strcmp(ptr->ID, student_for_search->ID) == 0) {
           if (strcmp(ptr->first_name, student_for_search->first_name) == 0) {
               if (strcmp(ptr->last_name, student_for_search->last_name)) {
                   printf("You change your last name\n\n");
                   change_last_name(ptr,student_for_search,flag);
                   del_student(&head);
                   *flag = 1;
                   return student_for_search;
               }

               switch (*flag)
               {

               case 0:
                   *flag = 0;
                   ptr->C_language = student_for_search->C_language;
                   break;
               case 1:
                   *flag = 0;
                   ptr->Computer_Networks = student_for_search->Computer_Networks;
                   break;
               case 2:
                   *flag = 0;
                   ptr->CS_Fundamentals = student_for_search->CS_Fundamentals;
                   break;

               default:
                   break;
               }
               return ptr;

            }
           else {
               *flag = 0;
               return NULL;
           }

        }
        ptr = ptr->next;
    }
    *flag = 1;
    return student_for_search;
}
//A function that checks that the name is correct and without errors receives the pointer of the name we want to check
int is_valid_name(char* str) {

    while (*str)
    {
        if ( ( * str < 'A' || *str>'Z') && *str != ' ') {
            return 0;
        }
        str++;
    }
    return 1;
}

//A function that checks for each reception from the user the course we want to pursue and returns the course index and receives the line entered by the user
int checkCours(char* line) {
    if (strstr(line, "CS FUNDAMENTALS"))
        return CS_Fundamentals;
    else if (strstr(line, "C LANGUAGE"))
        return C_language;
    else if (strstr(line, "COMPUTER NETWORKS"))
        return Computer_Networks;
    else
        return -1;

}

//A function to release a student from memory accepts a student for deletion and returns the nal student in case we need it later
student_detailes* free_student(student_detailes* newStudent) {
    free( newStudent->first_name);
    free( newStudent->last_name);
    free(newStudent);
    newStudent = NULL;
    return newStudent;
}


//A function that accepts a string and returns the string without leading and trailing spaces
char* del_spaces(char* str) {
    char* temp = _strdup(str);
    size_t i;
    while (*temp == ' ')temp++;
    size_t length = strlen(temp) - 1;
    for (i = length; temp[i] == ' '; i--);
    temp[i + 1] = 0;
    return temp;
}

//A function that receives a pointer to a line entered from the user and creates the data structure with it and returns the structure and if there is a failure it will return null
student_detailes* creatStudentFromUser(char* line) {
    student_detailes* newStudent = (student_detailes*)malloc(sizeof(student_detailes));
    if (newStudent == NULL) {
        Error_messageAllocation();

        return free_student(newStudent);
       
    }
    int flag=checkCours(line);
    char* token = strtok(line, "=");
    if (token == NULL) {

        return free_student(newStudent);
    }

    token = strtok(NULL, ",");
    token=del_spaces(token);
    if (is_valid_name(token)) {                         
          newStudent->first_name = _strdup(token);        
    }
    else {

        return free_student(newStudent);
    }

    token = strtok(NULL, "=");/*for last name*/
    if (token == NULL) {

        return free_student(newStudent);
      
    }
    token = strtok(NULL, ",");
    token = del_spaces(token);
    if (is_valid_name(token)) {
            newStudent->last_name = _strdup(token);           
        }
    else {

        return free_student(newStudent);
        }

    token = strtok(NULL, "=");//for ID
    if (token == NULL) {

        return free_student(newStudent);
    }
    token = strtok(NULL, ", ");
        if (is_valid_ID(token)) {
            strcpy(newStudent->ID, _strdup(token));
            newStudent->ID[9] = 0;//for delete the cona & sapce
        }
        else {

            return free_student(newStudent);
        }

    token = strtok(NULL, ", ");
    token = strtok(NULL, "=");
    token = strtok(NULL, " ");
    if (token==NULL) {

        return free_student(newStudent);
    }
    switch (flag)
    {
    case C_language:
        if (check_Valid_Grade(newStudent, token, C_language)) {
            newStudent->C_language = atoi(token);
            initStudentForC(newStudent);
            return newStudent;
        }
        else {

            return free_student(newStudent);
        }

    case CS_Fundamentals:
        if (check_Valid_Grade(newStudent, token, CS_Fundamentals)) {

        newStudent->CS_Fundamentals = atoi(token);
        initStudentForCS_Fundamentals(newStudent);
        return newStudent;
        }
        else {

            return free_student(newStudent);
        }
    case Computer_Networks:
        if (check_Valid_Grade(newStudent, token, Computer_Networks)) {
            newStudent->Computer_Networks = atoi(token);
            initStudentForComputer_Networks(newStudent);
            return newStudent;

        }
        else {

            return free_student(newStudent);
        }

    default:

        return free_student(newStudent);
    }
}

//A function that receives a new student and prints it and if there is a lack of a grade it will be noted in the null
void printStudent(student_detailes* new_student) {
    char str[] ="NULL";
    
    printf("%-20s %-10s  %13s ", new_student->first_name, new_student->last_name, new_student->ID);
    if (new_student->C_language != -1)
        printf("%10d", new_student->C_language);
    else printf("%10s", str);
    if (new_student->Computer_Networks != -1)
        printf("%20d", new_student->Computer_Networks);
    else printf("%20s", str);
    if (new_student->CS_Fundamentals != -1)
        printf("%25d",new_student->CS_Fundamentals);
    else printf("%25s", str);
    printf("%25.2f\n", new_student->avg);
}

//Select-related functions that receive a pointer to the top of the list and the token to check and print who it found
void exeQueryForEqoual(char* token, char* subject, student_detailes* ptr) {
    
    while (ptr)
    {//checking query for first name
        if (strcmp(subject, "FIRST") == 0) {

            if (strcmp(ptr->first_name, token) == 0) {
                printStudent(ptr);
            }
        }//checking query for last name
        else if (strcmp(subject, "LAST") == 0)
        {

            if (strcmp(ptr->last_name, token) == 0) {
                printStudent(ptr);
            }
        }//checking query for ID
        else if (strcmp(subject, "ID") == 0)
        {
            if (strcmp(ptr->ID, token) == 0) {
                printStudent(ptr);
            }
        }//checking query for AVG
        else if (strcmp(subject, "AVERAGE") == 0)
        {
            if (ptr->avg == atof(token)) {
                printStudent(ptr);
            }
        }//checking query for CS_Fundamentals
        else if (strcmp(subject, "CS") == 0)
        {
            if (ptr->CS_Fundamentals == atoi(token))
                printStudent(ptr);
               //printf("%-20s\t%-10s %20s \tCS_Fundamentals\t\t %d\n", ptr->first_name, ptr->last_name, ptr->ID, ptr->CS_Fundamentals);

        }//checking query for Computer_Networks
        else if (strcmp(subject, "COMPUTER") == 0)
        {
            if (ptr->Computer_Networks == atoi(token))
                printStudent(ptr);
              /*  printf("%-20s\t%-10s %20s \tComputer_Networks\t %d\n", ptr->first_name, ptr->last_name, ptr->ID, ptr->Computer_Networks);*/

        }//checking query for C_language
        else if (strcmp(subject, "C") == 0)
        {
            if (ptr->C_language == atoi(token))
                printStudent(ptr);

        }

        ptr = ptr->next;
    }

}
void exeQueryForSmaller(char* token, char* subject, student_detailes* ptr) {
    while (*token == ' ')token++;
    while (ptr)
    {
        if (strcmp(subject,"FIRST")==0) {

            if (strcmp(ptr->first_name, token) < 0) {
                printStudent(ptr);

            }
        }
        else if (strcmp(subject, "LAST")==0)
        {

            if (strcmp(ptr->last_name, token) < 0) {
                printStudent(ptr);

            }
        }
        else  if (strcmp(subject, "ID")==0)
        {
            if (strcmp(ptr->ID, token) < 0) {
                printStudent(ptr);
            }
        }
        else if (strcmp(subject, "AVERAGE") == 0)
        {
            if (ptr->avg < atof(token)) {
                printStudent(ptr);
            }
        }//checking query for CS_Fundamentals
        else if (strcmp(subject, "CS") == 0)
        {
            if (ptr->CS_Fundamentals < atoi(token)&& ptr->CS_Fundamentals!=-1)
                printStudent(ptr);
        }
        else if (strcmp(subject, "COMPUTER") == 0)
        {
            if (ptr->Computer_Networks < atoi(token) && ptr->Computer_Networks != -1)
                printStudent(ptr);
                //printf("%-20s\t%-10s %20s \tComputer_Networks\t %d\n", ptr->first_name, ptr->last_name, ptr->ID, ptr->Computer_Networks);

        }
        else if (strcmp(subject, "C") == 0)
        {
            if (ptr->C_language < atoi(token) && ptr->C_language != -1)
                printStudent(ptr);
                //printf("%-20s\t%-10s %20s \tC language\t\t %d\n", ptr->first_name, ptr->last_name, ptr->ID, ptr->C_language);

        }

        ptr = ptr->next;
    }

}

void exeQueryForBigger(char* token, char* subject, student_detailes* ptr) {
    while (*token == ' ')token++;
    while (ptr)
    {
        if (strcmp(subject, "FIRST")==0 ){
        
            if (strcmp(ptr->first_name, token) > 0) {
                printStudent(ptr);
            }
        }
        else if (strcmp(subject, "LAST")==0)
        {
 
            if (strcmp(ptr->last_name, token) > 0) {
                printStudent(ptr);
            }
        }
        else if (strcmp(subject, "ID") == 0)
        {
       
            if (strcmp(ptr->ID, token) > 0) {
                printStudent(ptr);
            }
        }
        else if (strcmp(subject, "AVERAGE") == 0)
        {
            if (ptr->avg > atof(token)) {
                printStudent(ptr);
            }
        }//checking query for CS_Fundamentals
        else if (strcmp(subject, "CS") == 0)
        {
         
            if (ptr->CS_Fundamentals > atoi(token))
                printStudent(ptr);
               
        }
        else if (strcmp(subject, "COMPUTER") == 0)
        {
         
            if (ptr->Computer_Networks > atoi(token))
                printStudent(ptr);


        }
        else  if (strcmp(subject, "C") == 0)
        {
            if (ptr->C_language > atoi(token))
                printStudent(ptr);


        }

        ptr = ptr->next;
    }

}

void exeQueryForNotEqoual(char* token, char* subject, student_detailes* ptr) {
    while (*token == ' ')token++;
    while (ptr)
    {//checking query for first name
        if (strcmp(subject, "FIRST") == 0) {

            if (strcmp(ptr->first_name, token) != 0) {
                printStudent(ptr);

            }
        }//checking query for last name
       else if (strcmp(subject, "LAST") == 0)
        {  

            if (strcmp(ptr->last_name, token) != 0) {
                printStudent(ptr);

            }
        }//checking query for ID
        else if (strcmp(subject, "ID") == 0)
        {
            if (strcmp(ptr->ID, token) != 0) {
                printStudent(ptr);

            }
        }//checking query for avarage
        else if (strcmp(subject, "AVERAGE") == 0)
        {
            if (ptr->avg != atof(token)) {
                printStudent(ptr);
            }
        }//checking query for CS_Fundamentals
        else if (strcmp(subject, "CS") == 0)
        {
            if (ptr->CS_Fundamentals != atoi(token) && ptr->CS_Fundamentals!=-1)
                printStudent(ptr);

        }//checking query for Computer_Networks
        else if (strcmp(subject, "COMPUTER") == 0)
        {
            if (ptr->Computer_Networks != atoi(token) && ptr->Computer_Networks != -1)
                printStudent(ptr);
        }//checking query for C_language
        else if (strcmp(subject, "C") == 0)
        {
            if (ptr->C_language != atoi(token) && ptr->C_language!=-1)
                printStudent(ptr);

        }

        ptr = ptr->next;
    }

}

//A function that prints that there is an error and the example of a valid query
void printExample() {
    printf("Invalid qurey \n");
    printf("For Example select average>50 OR set first name =Avi  last name= Yakov  ID= 958478321, C language= 95 \n\n");
}

//A function that receives the list of students and points to a query, and if the query is correct the function will know how to run the appropriate function
void selectQeury(Director* list, char* query) {

    student_detailes* ptr = list->head;
    char* token = strtok(query, " ");
    token = strtok(NULL, " ");
    //For linux System strdup without _
    char* subject = _strdup(token);
    if (strcmp(subject,"FIRST")!=0&& strcmp(subject, "LAST") != 0 && strcmp(subject, "AVERAGE") != 0 && strcmp(subject, "ID") != 0 && strcmp(subject, "CS") != 0 && strcmp(subject, "COMPUTER") != 0 && strcmp(subject, "C") != 0){
        printExample();
        return;
    }
    token = strtok(NULL, " ");
    if (strcmp(token, ">") != 0 && strcmp(token, "<") != 0 && strcmp(token, "=") != 0 && strcmp(token, "!=") != 0) {  
        if (strcmp(token, "NAME") != 0 && strcmp(token, "NETWORKS") != 0 && strcmp(token, "FUNDAMENTALS") != 0 && strcmp(token, "LANGUAGE") != 0) {
            printExample();
            return;
        }
        token = strtok(NULL, " ");
    }
    //check operator
    switch (*token)
    {
    case '=':
        token = strtok(NULL, "\n");
        token = del_spaces(token);
        exeQueryForEqoual(token, subject, ptr);

        break;
    case '<':
        token = strtok(NULL, "\n");
        token = del_spaces(token);
        exeQueryForSmaller(token, subject, ptr);

        break;
    case '>':
        token = strtok(NULL, "\n");
        token = del_spaces(token);
        exeQueryForBigger(token, subject, ptr);
 
        break;
    case '!':
        token = strtok(NULL, " ");
        token = strtok(NULL, "\n");
        token = del_spaces(token);
        exeQueryForNotEqoual(token, subject, ptr);
        break;
    default:
        printf("Invalid Sign try  =, <, > ,!=  Only!\n\n");
        break;
    }
    free(subject);
}
//The funccia will check the query and create a template with which we can work
char* check_query(char* input) {
    //not valid operator
    if (strstr(input, "=!")) {
        free(input);
        return NULL;
    }
    char* token, * temp;
    char operator[5]={0};
    //For linux System strdup without _
    temp = _strdup(input);
    //check in which qurey you want
    // Checks the first 6 letters if they match
    if (!strncmp(input, "SELECT", 6)) {
        token = strtok(input, "T"); /*Separator until the word select - 1*/
        //Checks which operator appears in the query
        if (strstr(temp, "!=")) {
            strcpy(operator," != ");
        }
        else if (strstr(temp, ">")) {
            strcpy(operator," > ");
        }
        else if (strstr(temp, "<")) {
            strcpy(operator," < ");
        }
        else if (strstr(temp, "=")) {
            strcpy(operator," = ");
        }//separator up to one of the operators
        else {
            free(input);
            return NULL;
        }
        token = strtok(NULL, "=,><!");
        //Connects to the query all the components it needs
        strcpy(temp, "SELECT ");
        strcat(temp + 7, token);
        strcat(temp + strlen(token), operator);
        token = strtok(NULL, "\n");
        strcat(temp + strlen(token), token);

    }
    free(input);
    return temp;

}
//A function that receives a student and calculates the average for him
void enter_avg(student_detailes* newStudent) {
    float sum = 0,count=0;
    if (newStudent->Computer_Networks != -1) {
        sum +=(float) newStudent->Computer_Networks;
        count++;

    }
    if (newStudent->CS_Fundamentals != -1) {
        sum += (float)newStudent->CS_Fundamentals;
        count++;
    }
    if (newStudent->C_language != -1) {
        sum += (float)newStudent->C_language;
        count++;
    }
    //after sum all grades calc avg
    newStudent->avg = sum / count;

}
//A function that accepts a string and returns 0 if the user has not approved or 1 if the user has approved
int confirm(char * str) {
    
        int a = 0;
        char temp = ' ';
        printf("%s?(Y/N)\n",str);
        a = scanf("%c", &temp);
        a = getchar();
        if (temp == 'n' || temp == 'N') {
            return 0;
        }
        return 1;

}
//A function that receives the list of errors and marks it as corrected and returns 1 if it has been corrected or 0 if not
int update_fix_err(student_detailes_err* head_err, student_detailes* newStudent) {
    student_detailes_err* ptr= head_err;
    while (ptr)
    {
        if (!strcmp(ptr->ID, newStudent->ID)) {
            ptr->fix = 1;
            return 1;
        }

            ptr = ptr->next;
    }
    return 0;

}
//A function that adds the list of errors to the end of the list in the file
void read_err_to_file(student_detailes_err* head_err) {
    FILE* fp = fopen(FILENAME2, "a+");
    if (fp == NULL)
    {
        printf("Error! Could not open file, check if the file already open ,and please close it ,and enter the query again ! \n");
        return;

    }
    //goes over the list and print to file
    while (head_err)
    {
        if (head_err->fix == 0) {

        if (head_err->C_language != -1&& head_err->C_language != -2)
            fprintf(fp, "%s,%s,%s,C language,%d\n", head_err->first_name, head_err->last_name, head_err->ID, head_err->C_language);
        if (head_err->Computer_Networks != -1 && head_err->Computer_Networks != -2)
            fprintf(fp, "%s,%s,%s,Computer Networks,%d\n", head_err->first_name, head_err->last_name, head_err->ID, head_err->Computer_Networks);
        if (head_err->CS_Fundamentals != -1&& head_err->CS_Fundamentals != -2)
            fprintf(fp, "%s,%s,%s,CS Fundamentals,%d\n", head_err->first_name, head_err->last_name, head_err->ID, head_err->CS_Fundamentals);
        }

        head_err = head_err->next;
    }
    fclose(fp);

}
//A function that releases the entire error list receives a double pointer to the head of the error list
void freelistError(student_detailes_err** head_err) {

    student_detailes_err* ptr = NULL;
    ptr = *head_err;
    //run all over the list for free each allocation that we used to this list 
    while (ptr)
    {
        
        *head_err = (*head_err)->next;
        free(ptr->first_name);
        free(ptr->last_name);
        free(ptr);
        ptr = *head_err;
    }
    //free(*head_err);

}
//A function that prints the menu that the program has to offer receives the valid student list and the invalid student list
void print_menu(Director* list, student_detailes_err* head_err) {
    //for read_input_no_limit 
    char* input;
    bool flag2 = 0;

    student_detailes* newStudent;
    while (1)
    {
        printf("\n\nPlease Enter Your Query (Enter quit for quit): \n");
        printf("PROMPT--> ");
        input = read_input_no_limit(NULL, 1);//NULL for the first parametr of  read_input_no_limit function
        toUpperCase(input);
        if (strcmp(input, "QUIT") == 0) {

            readlistToFile(list->head);
         
            read_err_to_file(head_err);
            freelist(list);
            freelistError(&head_err);
            free(input);
            printf("Bye Bye ,see you next time");
            exit(1);
        }

        input = check_query(input);
        if (input == NULL) {
            printExample();
            continue;
        }
        int flag = checkCours(input);/*check in which cours the user want*/
        //check if set query or select
        if (strstr(input, "SET")) {
          
            newStudent = creatStudentFromUser(input);
            if (newStudent == NULL) {
                printExample();
                continue;
            }
            if (update_fix_err(head_err, newStudent)) {
                flag2 = 1;
            }
            //check if the user alredy exsits
            newStudent = search_Student_in_list(list->head, newStudent, &flag);
            if (newStudent == NULL) {
                printf("User Invalid ,try again! \n\n");
                continue;
            }
            else if (flag == 1) {
                printf("New Student added or chengh his last name\n\n\n");
                insert_to_sort_list(list, newStudent);

            }
            else
                printf("User : %s ID : %s updated\n\n\n", newStudent->first_name, newStudent->ID);

            if (flag2)
                read_err_to_file(head_err);
         
            //calc avg for student after change deatils or for new user 
            enter_avg(newStudent);


        }
        else if (strstr(input, "SELECT")) {
            printf("First Name         Last Name        ID            C Language           Computer Networks       CS Fundamentals            Average\n");
            printf("----------         -----------      ----------    ----------           -----------------       ----------------        ------------\n\n");
            selectQeury(list, input);

        }
        else if (!strcmp(input, "PRINT")) {
            printList(list->head);
        }
        else if (!strcmp(input, "PRINT ERROR")) {
            printf("ERROR LIST :\n");
            print_studentEror(head_err);
        }
        else {
            printExample();
            continue;
        }

    }
    free(input);
}


//A function that receives a list and prints it to a file when a student is updated or a new one is created
void readlistToFile(student_detailes* new_student) {
    FILE* fp = fopen(FILENAME2, "w+");
    if (fp == NULL)
    {
        printf("Error! Could not open file, check if the file already open ,and please close it ,and enter the query again ! \n");
        return;
      
    }
    //goes over the list and print to file
    while (new_student)
    {   if(new_student->C_language!=-1)
            fprintf(fp, "%s,%s,%s,C language,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->C_language);
        if(new_student->Computer_Networks != -1)
            fprintf(fp, "%s,%s,%s,Computer Networks,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->Computer_Networks);
        if (new_student->CS_Fundamentals != -1)
            fprintf(fp, "%s,%s,%s,CS Fundamentals,%d\n", new_student->first_name, new_student->last_name, new_student->ID, new_student->CS_Fundamentals);

        new_student = new_student->next;
    }
    fclose(fp);

}
//A function that receives the head of the list and goes through it and prints it
void printList(student_detailes* ptr) {

    printf("First Name         Last Name        ID            C Language           Computer Networks       CS Fundamentals            Average\n");
    printf("----------         -----------      ----------    ----------           -----------------       ----------------        ------------\n\n");
    while (ptr)
    {
        printStudent(ptr);
        ptr = ptr->next;

    }
}
//A function that releases the entire valid student list
void freelist(Director* list) {
    student_detailes* ptr = NULL;
    //run all over the list for free each allocation that we used to this list 
    for (int i = 0; i < list->size; i++)
    {
        ptr= list->head;
        list->head = list->head->next;
        free(ptr->first_name);
        free(ptr->last_name);
        free(ptr);
   }
    //free(list);

}
