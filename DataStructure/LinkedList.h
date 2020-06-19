// LinkedList.h : 프로그램 6.6 단순 연결 리스트 클래스
#include "Node.h"

class LinkedList {
	Node org;		// 헤드 노드

public:
	LinkedList() : org(0) { }
	~LinkedList() { clear(); }

	void clear() {
		while (!isEmpty())
			delete remove(0);
	}

	bool isEmpty() { return getHead() == NULL; }
	Node* getHead() { return org.getLink(); }

	// pos번째 항목을 반환-----------------------
	Node* getEntry(int pos) {
		Node* n = &org;

		for (int i = -1; i < pos; i++, n = n->getLink())

			if (n == NULL)
				break;

		return n;
	}

	// 리스트의 어떤 위치에 항목 삽입------------
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);

		if (prev != NULL)
			prev->insertNext(n);
	}

	// 리스트의 어떤 위치의 항목 삭제-----------
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);

		return prev->removeNext();
	}

	// 탐색 함수-------------------------------
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())

			if (p->hasData(val))
				return p;

		return NULL;
	}

	// 리스트의 pos번째 노드를 다른 노드로 교체------------
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);

		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(n);
		}
	}

	// 리스트 항목 개수를 반환------------------------
	int size() {
		int count = 0;

		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;

		return count;
	}

	// 화면에 보기 좋게 출력-----------------------------
	void display() {
		printf("[전체 항목 수 = %2d] : ", size());

		for (Node* p = getHead(); p != NULL; p = p->getLink()) 
			p->display();

		printf("\n");
	}

	// 연결리스트의 모든 노드의 순서를 반대로 바꾸는 연산---------------
	void reverse() {
		int pos = 0;

		for (int i = 0; i < size(); i++) {
			Node* p = remove(size() - 1);		// 마지막 위치의 노드 삭제 후 그 값을 p에 대입
			insert(pos, p);						// 처음 위치부터 p를 삽입

			pos++;
		}

	}

	//다른 리스트 객체의 노드 정보를 현재 리스트에 병합하는 연산------------
	void merge(LinkedList* that) {

		while (!that->isEmpty()) {				// that이 비어있지 않으면 반복문 수행
			Node* p = that->remove(0);			// that의 처음 위치의 데이터를 삭제 후 그 값을 p에 대입
			insert(size(), p);					// 마지막 위치부터 p를 삽입
		}

	}
	
	// 홀수번째 노드를 삭제하는 연산 ---------------
	void remove_odd() {
		for (int i = 1; i < size(); i++) 
			remove(i);
	}

	// 단순 연결 리스트가 오름차순으로 연결되어 있을 때, 최대값을 가지는 노드를 삭제하는 연산 --------
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