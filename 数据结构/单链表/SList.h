#ifndef __SLIST_H_
#define __SLIST_H_

#include <stdio.h>
#include <stdlib.h>
typedef int SLTDataType;

typedef struct SListNode 
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

void SListInit(SListNode** phead);
void SListDestory(SListNode** phead);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SListNode** phead, SLTDataType x);
void SListPopFront(SListNode** phead);
SListNode* SListFind(SListNode** phead, SLTDataType x);
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos);
void SListRemove(SListNode** phead, SLTDataType x);
void SListRemoveAll(SListNode** phead, SLTDataType x);
void SListPrint(SListNode* plist);

void SListReverse(SListNode** phead);
void SListReverse2(SListNode** phead);
void TestSList();
int Palind(SListNode* phead);


#endif