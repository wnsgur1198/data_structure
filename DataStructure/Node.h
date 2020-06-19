// Node.h : 프로그램 6.5 단순 연결 리스트를 위한 Node 클래스 + 프로그램 11.5 인접리스트를 이용한 그래프를 위한 Node 클래스
#include <cstdio>

class Node {
	Node* link;		// 다음 노드를 가리키는 포인터 변수
	int data;		// 노드의 데이터 필드
	//int id;			// 정점의 id

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

	// 자신의 다음에 새로운 노드 n을 삽입하는 함수-------
	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}

	// 자신의 다음 노드를 리스트에서 삭제하는 함수-------
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) 
			link = removed->link;
		
		return removed;
	}

};