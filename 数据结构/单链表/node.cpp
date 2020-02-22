
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}Node;
void create(Node** head)
{
	*head = (Node*)malloc(sizeof(Node));
	*head = NULL;

}
//void push_back(Node* head, int d)
//{
//	Node* oldhead = head;
//	Node* cur = head;
//	Node* temp = (Node*)malloc(sizeof(Node));
//	temp->data = d;
//	temp->next = NULL;
//	while (cur!=NULL)
//	{
//		cur = cur->next;
//	}
//	cur->next = temp;
//	head = oldhead;
//}
void push_front(Node** head, int d)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->next = *head;
	*head = temp;
}

void printlist(Node* head)
{
	Node* pcur = head;
	while (pcur!=NULL)
	{
		printf("%d-->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}
void insert(Node** head, Node* pos, int data)
{
	Node* cur = *head;
	while (cur != pos)
	{
		cur = cur->next;
	}
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = cur->next;
	cur->next = temp;
	
	
}
Node* find(Node* head, int data)
{
	Node* cur = head;
	while (cur->data != data)
	{
		cur = cur->next;
	}
	return cur;
	
}
void erase(Node** head, int data)
{
	Node* cur = *head;
	while (cur->next->data != data)
	{
		cur = cur->next;
	}
	Node* temp = cur->next;
	cur->next = cur->next->next;
	free(temp);
}
void reverse(Node** head)
{
	Node* oldh, *h,*temp;
	oldh = *head;
	h = *head;
	temp = (*head)->next;
	while (temp)
	{
		oldh->next = temp->next;
		temp->next = h;
		h = temp;
		temp = oldh->next;
	}
	*head = h;
}

int main()
{
	Node* list = NULL;
	create(&list);
	/*push_back(list, 1);
	push_back(list, 2);
	push_back(list, 3);
	push_back(list, 4);
	push_back(list, 5);*/
	push_front(&list, 6);
	push_front(&list, 5);
	push_front(&list, 4);
	push_front(&list,3);
	push_front(&list, 2);
	find(list, 4);
	insert(&list, find(list, 4), 1);
	erase(&list, 1);
	reverse(&list);
	printlist(list);
 	return 0;
}