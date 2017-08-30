#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 500002

struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node heap[MAX];
int heap_idx = 2;

Node* head;
Node* tail;

inline Node* getEmptyNode()
{
	return &heap[++heap_idx];
}

inline bool checkLastRemainNode()
{
	if (head->next == tail->prev)
		return true;
	else
		return false;
}


inline void removeTopNode()
{
	if (checkLastRemainNode())
		return;
	Node* TopNode = head->next;
	head->next = TopNode->next;
	TopNode->next->prev = head;

	cout << TopNode->data << " ";
}

inline void NodeTopToBottom()
{
	Node* TopNode = head->next;
	head->next = TopNode->next;
	TopNode->next->prev = head;

	Node* BottomNode = tail->prev;
	BottomNode->next = TopNode;
	TopNode->prev = BottomNode;
	TopNode->next = tail;
	tail->prev = TopNode;
	
}

inline void insertNNode(int n)
{
	for (int i = 1; i <= n; i++)
	{
		Node* addOne = getEmptyNode();
		Node* lastOne = tail->prev;

		lastOne->next = addOne;
		addOne->data = i;
		addOne->prev = lastOne;
		addOne->next = tail;
		tail->prev = addOne;
	}
}

inline void LinkedListHeadAndTailSetting()
{
	head = &heap[0];
	tail = &heap[1];

	head->data = -987654321;
	head->next = tail;
	head->prev = nullptr;

	tail->data = 987654321;
	tail->next = nullptr;
	tail->prev = head;
}


int main()
{
	std::ios::sync_with_stdio(false);
	freopen("Text.txt", "r", stdin);

	int N;
	cin >> N;
	LinkedListHeadAndTailSetting();
	insertNNode(N);

	while (1) {
		removeTopNode();

		if (checkLastRemainNode()) {
			cout << head->next->data << endl;
			break;
		}

		NodeTopToBottom();
	}

	return 0;
}
