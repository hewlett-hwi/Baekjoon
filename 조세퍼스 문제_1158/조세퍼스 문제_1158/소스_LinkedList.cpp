#include <iostream>
using namespace std;

#define MAX_NODE 5010
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

void initHeap(void);
void initListNode(ListNode* node);
ListNode* getListNode(void);
void destroyListNode(ListNode* node);
ListNode* appendListNode(ListNode* list, int data);
ListNode* removeListNode(ListNode* list, ListNode* node);

int listSize=0;

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	initHeap();

	ListNode* list = NULL;
	ListNode* node;

	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= m; i++)
	{
		list = appendListNode(list, i);
	}

	node = list;

	for (int i = 1; i < n; i++)
	{
		node = node->next;
	}

	if (listSize == 1) { // ����Ʈ ������ 1���� ��� ����ó�� : ��ó�� ���ϸ� 97%���� ��Ÿ�ӿ���
		cout << "<" << node->data << ">" << endl;
		return 0;
	}

	cout <<"<"<<node->data <<", ";
	list = removeListNode(list, node);

	while (list != list->next) // �Ѱ� ������ ����
	{
		for (int i = 1; i <= n; i++)
		{
			node = node->next;
		}
		cout << node->data << ", ";
		list = removeListNode(list, node);
	}



	cout << list->data << ">" << endl;
	//cout << node->next->data <<">" << endl;
	//list = removeListNode(list, node);

	return 0;
}


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

ListNode* getListNode(void)
{
	int i;
	for (i = 0; i < MAX_NODE; i++)
	{
		if (!heap[i].use)
		{
			heap[i].use = 1;
			initListNode(&heap[i].node);

			return &heap[i].node;
		}
	}
	return NULL;
}
void destroyListNode(ListNode* node)
{
	ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
	heap_node->use = 0;
	listSize--;
}
ListNode* appendListNode(ListNode* list, int data)
{
	ListNode* node = getListNode();
	node->data = data; 
	listSize++;
	if (list == NULL)
	{
		return node;
	}
	else
	{
		ListNode* last = list->prev; // �̰� �׻� ��������(last�� �������� ���� �� ���)
		last->next = node; // node�� ���� ���� ������(last�� node������ ��)
		list->prev = node; // ó���� ���� �׻� �������� ������
		node->prev = last;
		node->next = list; // �� �������� node�� �������� ó�����
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