#include"List.h"
#include <Windows.h>


int main(){

	List head;
	List head2;

	ListInit(&head);

	ListPushBack(&head, 8);
	ListPushBack(&head, 9);
	ListPushFront(&head, 3);
	ListPushFront(&head, 2);
	ListPushFront(&head, 2);
	ListPushFront(&head, 2);
	ListPushFront(&head, 1);
	ListPushFront(&head, 4);
	ListPushFront(&head, 6);
	ListPushFront(&head, 5);

	ListInit(&head2);
	ListPushFront(&head2, 10);
	ListPushFront(&head2, 1);
	ListPushFront(&head2, 7);
	ListPushFront(&head2, 4);
	
	//ListPopFront(&head);
	ListPrint(&head);
	//SortAs(&head, 4);
	//ListDetect(&head);

	ListMerge(&head, &head2);

	ListPrint(&head);

	system("pause");
	return 0;
}