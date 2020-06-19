// CircularQueue.h : 프로그램 8.5 노드의 포인터를 저장하는 클래스
#include "BinaryNode.h"
#include <stdlib.h>

inline void error(const char* str) {
	fprintf_s(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue {
	int front;		// 첫 번째 요소 앞의 위치
	int rear;		// 마지막 요소 위치
	//BinaryNode* data[MAX_QUEUE_SIZE];
	int data[MAX_QUEUE_SIZE];

public:
	CircularQueue() { front = rear = 0; }
	
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	// 큐에 삽입 ------------------------------------------
	/*void enqueue(BinaryNode* n) {
		if (isFull()) error("Error: 큐가 포화상태입니다.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}*/

	// 11장 인접행렬을 이용한 그래프의 너비우선탐색 위함
	void enqueue(int n) {
		if (isFull()) error("Error: 큐가 포화상태입니다.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	// 첫 항목을 큐에서 빼서 반환 ---------------------
	/*BinaryNode* dequeue() {
		if (isEmpty()) error("Error: 큐가 공백상태입니다.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}*/

	// 11장 인접행렬을 이용한 그래프의 너비우선탐색 위함
	int dequeue() {
		if (isEmpty()) error("Error: 큐가 공백상태입니다.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	// 맨 위의 요소를 삭제하지 않고 반환
	int peek() {
		if (isEmpty()) error("Error: 큐가 공백상태입니다.\n");
		return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};