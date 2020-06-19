// Node.h : ���α׷� 6.5 �ܼ� ���� ����Ʈ�� ���� Node Ŭ���� + ���α׷� 11.5 ��������Ʈ�� �̿��� �׷����� ���� Node Ŭ����
#include <cstdio>

class Node {
	Node* link;		// ���� ��带 ����Ű�� ������ ����
	int data;		// ����� ������ �ʵ�
	//int id;			// ������ id

public:
	Node(int val=0) : data(val), link(NULL) { }

	//Node(int i, Node* l = NULL) : id(i), link(l) { }
	//~Node() {
	//	if (link != NULL)
	//		delete link;
	//}

	//int getId() { return id; }

	int getData() { return data; }
	
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }

	void display() { printf("<%2d>", data); }
	bool hasData(int val) { return data == val; }

	// �ڽ��� ������ ���ο� ��� n�� �����ϴ� �Լ�-------
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	// �ڽ��� ���� ��带 ����Ʈ���� �����ϴ� �Լ�-------
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) 
			link = removed->link;
		
		return removed;
	}

};