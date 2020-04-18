#include <stdio.h>
#include <stdlib.h>

typedef struct double_list
{
	int val;
	struct double_list* next;
	struct double_list* pre;
}double_list;

void inite(double_list** head)
{
	*head = (double_list*)malloc(sizeof(double_list));
	(*head)->next = NULL;
	(*head)->pre = NULL;
	
}


void push_back(double_list* head, int val)
{
	double_list* phead = head;
	double_list* node = (double_list*)malloc(sizeof(double_list));
	while (phead->next!= NULL)
	{
		phead = phead->next;
	}
	node->val = val;
	phead->next = node;
	node->next = NULL;
	node->pre = phead;
	
}
void push_front(double_list* head,int val)
{
	double_list* node = (double_list*)malloc(sizeof(double_list));
	node->val = val;
	head->next->pre = node;
	node->next = head->next;
	head->next = node;
	node->pre = head;
}

void pop_back(double_list* head)
{
	double_list* phead = head;
	while (phead->next != NULL)
	{
		phead = phead->next;
	}
	phead->pre->next = NULL;
	free(phead);
	phead = NULL;
}

void pop_front(double_list* head)
{
	double_list* temp = head->next;
	head->next->next->pre = head;
	head->next = head->next->next;
	free(temp);
	temp = NULL;
}

double_list* find(double_list* head, int val)
{
	double_list* phead = head;
	while (phead != NULL)
	{
		if (phead->val == val)
			return phead;
		phead = phead->next;
	}
	return NULL;
}
void erase(double_list* node)
{
	node->next->pre = node->pre;
	node->pre->next = node->next;
	free(node);
	node = NULL;
}

void print_list(double_list* head)
{
	double_list* phead = head->next;
	while (phead->next != NULL)
	{
		printf("%d->", phead->val);
		phead = phead->next;
	}
	printf("%d", phead->val);
}

//void reverse(double_list* head)
//{
//	double_list* phead = head;
//	double_list* prev = head->pre;
//	double_list* temp = NULL;
//	while (phead->next != NULL)
//	{
//		temp = phead->next;
//		phead->next = temp->next;
//		temp->next->pre = phead;
//		temp->next = phead;
//		temp->pre = prev;
//		phead->pre = temp;
//		prev = head->pre;
//		
//	}

}

int main()
{
	double_list* head;
	
	inite(&head);
	push_back(head, 1);
	push_back(head, 2);
	push_back(head, 3);
	/*push_front(head, 0);
	push_back(head, 4);
	push_back(head, 5);
	push_back(head, 6);
	push_back(head, 7);
	push_back(head, 8);
	push_back(head, 9);
	erase(find(head, 5));*/
	reverse(head);
	print_list(head);
	return 0;
}