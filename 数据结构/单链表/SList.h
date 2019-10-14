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
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SListNode** phead, SLTDataType x);
void SListRemoveAll(SListNode** phead, SLTDataType x);
void SListPrint(SListNode* plist);

void SListReverse(SListNode** phead);
void SListReverse2(SListNode** phead);
void TestSList();
int Palind(SListNode* phead);


#endif