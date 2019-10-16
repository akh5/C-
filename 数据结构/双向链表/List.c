#include "List.h"

void ListInit(List* plist){
	plist->head = (ListNode*)malloc(sizeof(ListNode));
	//plist = NULL;
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}

void ListInsert(ListNode* pos, LTDataType x){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = x;

	temp->prev = pos;
	temp->next = pos->next;
	pos->next->prev = temp;
	pos->next = temp;
	
}

void ListErase(ListNode* pos){
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);

}

void ListPrint(List* plist){
	ListNode* cur;
	printf("head->");
	for (cur = plist->head->next; cur != plist->head; cur = cur->next){
		printf("%d->", cur->data);
	}
	printf("head\n");
}

void ListPushBack(List* plist, LTDataType x){
	ListInsert(plist->head->prev, x);
}

void ListPushFront(List* plist, LTDataType x){
	ListInsert(plist->head, x);
}

void ListPopBack(List* plist){
	ListErase(plist->head->prev);
}

void ListPopFront(List* plist){
	ListErase(plist->head->next);
}

ListNode* ListFind(List* plist, LTDataType x){
	ListNode* cur;
	for (cur = plist->head->next; cur != plist->head; cur = cur->next){
		if (cur->data == x){
			return cur;
		}
	}
	return NULL;
}

void ListRemove(List* plist, LTDataType x){
	ListNode* cur;
	cur = ListFind(plist,x);
	ListErase(cur);
}


void SortAs(List* plist, LTDataType x){

	ListNode* cur = ListFind(plist, x);
	ListNode* temp;
	ListNode* point;
	ListNode* last = plist->head->prev;
	ListNode* first = plist->head->next;
	int flag = 0;
	for (point = plist->head->next; point != plist->head;){
		temp = point;
		if (temp == cur){
			point = point->next;
			continue;
		}
		if (temp->data > cur->data){
			/*if (flag > 0){
				point = point->next;
			}*/
			
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			temp->next = cur->next;
			cur->next->prev = temp;
			temp->prev = cur;
			cur->next = temp;
			ListPrint(plist);
			flag++;
		}
		else{
			/*if (flag < 0){
				point = point->next;
			}*/
			point = point->next;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			temp->next = cur;
			cur->prev->next = temp;
			temp->prev = cur->prev;
			cur->prev = temp;
			ListPrint(plist);
			flag--;
			
		}

	}

}

void ListDetect(List* plist){
	ListNode* temp;
	for (temp = plist->head->next; temp->next != plist->head; temp = temp->next){
		if (temp->data == temp->next->data){
			ListErase(temp->next);
			temp = temp->prev;
		}
	}
}

void ListMerge(List* plist1, List* plist2){
	ListNode* temp1 = plist1->head->next;
	ListNode* temp2 = plist2->head->next;

	ListNode* point1;
	ListNode* point2;
	//1为主要表
	while (temp1!=plist1->head&&temp2!=plist2->head)
	{
		if (temp1->data > temp2->data){
			point1 = temp1->prev;
			point2 = temp2->next;

			temp2->prev->next = temp2->next;
			temp2->next->prev = temp2->prev;
			temp2->next = temp1;
			temp2->prev = temp1->prev;
			temp1->prev->next = temp2;
			temp1->prev = temp2;

			temp2 = point2;
		}
		else{
			temp1 = temp1->next;
		}

	}
	if (temp1 == plist1->head){
		point2 = plist2->head->prev;
		
		temp1->prev = point2;
		temp1->prev->next = temp2;
		temp2->prev = temp1->prev;
		point2->next = temp1;

	}
	free(plist2->head);
}