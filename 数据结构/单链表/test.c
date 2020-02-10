#include "SList.h"
#include <Windows.h>

int main(){
	SListNode *head;
	SListInit(&head);
	SListPushFront(&head, 6);
	SListPushFront(&head, 5);
	SListPushFront(&head, 4);
	SListPushFront(&head, 3);
	SListPushFront(&head, 2);
	SListPushFront(&head, 1);
	
	//printf("%d", Palind(head));

	//SListNode* temp = SListFind(&head, 3);
	//SListInsertAfter(SListFind(&head, 3), 10);
	//SListEraseAfter(SListFind(&head, 10));
	//SListRemove(&head, 8);
	//SListRemoveAll(&head, 8);
	//SListPrint(head);
	//SListDestory(&head);
	SListPrint(head);
	SListReverse(&head);
	SListPrint(head);
	system("pause");
	return 0;
}