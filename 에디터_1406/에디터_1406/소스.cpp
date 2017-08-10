#include <stdio.h>
using namespace std;
#define MAX_NODE 1000000

typedef struct listNode
{
	int data;
	struct listNode* prev;
	struct listNode* next;
} ListNode;
typedef struct
{
	int use;
	ListNode node;
} ListNodeHeap;
ListNodeHeap heap[MAX_NODE];

void initHeap(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		heap[i].use = 0;
	}
}
void initListNode(ListNode* node)
{
	node->data = 0;
	node->prev = node;
	node->next = node;
}

int index = -1;
ListNode* getListNode(void)
{
	while(++index<MAX_NODE) {

		if (!heap[index].use)
		{
			heap[index].use = 1;
			initListNode(&heap[index].node);
			return &heap[index].node;
		}
	}
	return NULL;
}
void destroyListNode(ListNode* node)
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
}
ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();
	node->data = data;
	if (list == NULL)
	{
		return node;
	}
	else
	{
		ListNode* last = list->prev;
		last->next = node;
		list->prev = node;
		node->prev = last;
		node->next = list;
		return list;
	}
}
ListNode* removeListNode(ListNode* list, ListNode* node)
{
	if (list == list->next)
	{
		destroyListNode(node);
		return NULL;
	}
	else
	{
		ListNode* prev = node->prev;
		ListNode* next = node->next;
		prev->next = next;
		next->prev = prev;
		destroyListNode(node);
		return (list == node) ? next : list;
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);

	ListNode* list = NULL;
	ListNode* node;
	initHeap();
	list = appendListNode(list, 'S');

	char c;
	while (1) {
		scanf("%c", &c);
		if (c == '\n')
			break;
		list = appendListNode(list, c - '0');
		node = list;


	}

	node = list->prev; // 마지막 노드 가르킴

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		//scanf(" %c", &c); 이거 쓰면 틀림
		getchar();
		c = getchar();

		switch (c)
		{
		case 'L':
			if (node == list) // 처음인 경우
				break;
			else
				node = node->prev;
			break;
		case 'D':
			if (node->next == list) // 마지막인 경우
				break;
			else
				node = node->next;
			break;
		case 'B':
			if (node == list)
				break;
			else {
				ListNode* prenode = node->prev;
				removeListNode(list, node);
				node = prenode;
			}		
			break;
		case 'P':
			char addChar;
			scanf(" %c", &addChar);
			appendListNode(node->next, addChar - '0'); // 처음(list)을 보존시켜줌
			node = node->next;			
			break;

		default:
			break;
		}
	}

	//printf("%c",list->next->data + '0');

	ListNode* tempnode = list;
	while (tempnode->next != list) {
		printf("%c", tempnode->next->data + '0');
		tempnode = tempnode->next;
	}
}