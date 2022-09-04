#include "project_header.h"


int main(){

	printHeader();
	student_detailes_err* head_err = NULL;
	Director* list= read_from_file(&head_err);
	if (head_err) {
		printf("Error List : \n");
		print_studentEror(head_err);
	}
	if (list) {
		printList(list->head);
		print_menu(list, head_err);
	}
	else {
		Error_messageAllocation();

	}
	freelist(list);
	freelistError(&head_err);

	return 0;

}