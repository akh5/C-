#include "SList.h"

void SListInit(SListNode** phead){
	*phead = (SListNode*)malloc(sizeof(SListNode));
	*phead = NULL;
}

SListNode* BuySListNode(SLTDataType x){
	SListNode* temp = (SListNode*)malloc(sizeof(SListNode));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void SListPushFront(SListNode** phead, SLTDataType x){
	SListNode* temp = BuySListNode(x);
	temp->next = *phead;
	*phead = temp;

}

void SListPrint(SListNode* plist){
	SListNode* temp = plist;
	for (; temp; temp = temp->next){
		printf("%d->", temp->data);
	}
	printf("NULL\n");
}

void SListPopFront(SListNode** phead){
	SListNode* temp = (*phead)->next;
	free(*phead);
	*phead = temp;
}

SListNode* SListFind(SListNode** phead, SLTDataType x){
	SListNode* temp = *phead;
	for (; temp; temp = temp->next){
		if (temp->data == x){
			return temp;
		}
	}
	return NULL;
	
}

void SListInsertAfter(SListNode* pos, SLTDataType x){
	SListNode* temp = BuySListNode(x);
	//temp->data = x;
	temp->next = pos->next;
	pos->next = temp;

}
void SListEraseAfter(SListNode* pos){
	SListNode* temp = pos ->next;
	if (temp->next == NULL){
		return;
	}
	pos->next = temp->next;
	free(temp); 
	
}
void SListRemove(SListNode** phead, SLTDataType x){
	if ((*phead)->data == x){
		SListPopFront(phead);
	}
	SListNode* temp = *phead;
	for (; temp->next; temp = temp->next){
		if (temp->next->data == x){
			SListEraseAfter(temp);
			return;
		}
	}
}

void SListRemoveAll(SListNode** phead, SLTDataType x){
	SListNode* temp = *phead;
	if (*phead == NULL){
		return;
	}
	if ((*phead)->data == x){
		SListPopFront(phead);
	}
	for (; temp->next; ){
		if (temp->next->data == x){
			SListEraseAfter(temp);
		}
		else{
			temp = temp->next;
		}
	}
	return;
}

void SListReverse(SListNode** phead){
	SListNode *head = *phead;
	SListNode *temp = head->next;
	SListNode *oldh = *phead;

	while (temp){
		oldh->next = temp->next;
		temp->next = head;
		head = temp;
		temp = oldh->next;
	}
	*phead = head;

}

void SListDestory(SListNode** phead){
	while ((*phead)->next){
		SListEraseAfter((*phead)->next);
	}
}

void SListReverse2(SListNode** phead){


}

int Palind(SListNode* phead){  //判断是否是回文，只需要零时定义一个链表，让零时的链表反转与原链表相比
	SListNode* temp = phead;
	SListNode* rtemp;
	SListInit(&rtemp);
	for (; temp; temp = temp->next){
		SListPushFront(&rtemp, (*temp).data);
		//rtemp->data = temp->data;
		//rtemp = rtemp->next;
	}
	//SListReverse(&rtemp);
	temp = phead;
	for (; temp; temp = temp->next,rtemp=rtemp->next){
		if (temp->data != rtemp->data){
			return 0;
		}
	}
	return 1;
}

int IsRing(SListNode* phead){
	SListNode* pre = phead;
	SListNode* last = phead;
	pre = pre->next;
	for (; last; last = last->next){
		for (; pre; pre = pre->next){
			if (last == pre){
				return 1;
			}
		}
	}
	return 0;
}

SListNode* getIntersectionNode(SListNode *heada, SListNode *headb){

}

