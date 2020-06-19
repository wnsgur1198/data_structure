// LinkedList.h : ���α׷� 6.6 �ܼ� ���� ����Ʈ Ŭ����
#include "Node.h"

class LinkedList {
	Node org;		// ��� ���

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() {
		while (!isEmpty())
			delete remove(0);
	}

	bool isEmpty() { return getHead() == NULL; }
	Node* getHead() { return org.getLink(); }

	// pos��° �׸��� ��ȯ-----------------------
	Node* getEntry(int pos) {
		Node* n = &org;

		for (int i = -1; i < pos; i++, n = n->getLink())

			if (n == NULL)
				break;

		return n;
	}

	// ����Ʈ�� � ��ġ�� �׸� ����------------
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
			prev->insertNext(n);
	}

	// ����Ʈ�� � ��ġ�� �׸� ����-----------
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);

		return prev->removeNext();
	}

	// Ž�� �Լ�-------------------------------
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())

			if (p->hasData(val))
				return p;

		return NULL;
	}

	// ����Ʈ�� pos��° ��带 �ٸ� ���� ��ü------------
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);

		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	// ����Ʈ �׸� ������ ��ȯ------------------------
	int size() {
		int count = 0;

		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;

		return count;
	}

	// ȭ�鿡 ���� ���� ���-----------------------------
	void display() {
		printf("[��ü �׸� �� = %2d] : ", size());

		for (Node* p = getHead(); p != NULL; p = p->getLink()) 
			p->display();

		printf("\n");
	}

	// ���Ḯ��Ʈ�� ��� ����� ������ �ݴ�� �ٲٴ� ����---------------
	void reverse() {
		int pos = 0;

		for (int i = 0; i < size(); i++) {
			Node* p = remove(size() - 1);		// ������ ��ġ�� ��� ���� �� �� ���� p�� ����
			insert(pos, p);						// ó�� ��ġ���� p�� ����

			pos++;
		}

	}

	//�ٸ� ����Ʈ ��ü�� ��� ������ ���� ����Ʈ�� �����ϴ� ����------------
	void merge(LinkedList* that) {

		while (!that->isEmpty()) {				// that�� ������� ������ �ݺ��� ����
			Node* p = that->remove(0);			// that�� ó�� ��ġ�� �����͸� ���� �� �� ���� p�� ����
			insert(size(), p);					// ������ ��ġ���� p�� ����
		}

	}
	
	// Ȧ����° ��带 �����ϴ� ���� ---------------
	void remove_odd() {
		for (int i = 1; i < size(); i++) 
			remove(i);
	}

	// �ܼ� ���� ����Ʈ�� ������������ ����Ǿ� ���� ��, �ִ밪�� ������ ��带 �����ϴ� ���� --------
	void remove_max() {
		Node* tmpNode;
		int tmp = 0, max = 0;
		int max_pos = 0;

		for (int i = 0; i < size(); i++) {
			tmpNode = getEntry(i);
			tmp = tmpNode->getData();

			if (tmp > max) {
				max = tmp;
				max_pos = i;
			}				
		}

		remove(max_pos);
	}

};