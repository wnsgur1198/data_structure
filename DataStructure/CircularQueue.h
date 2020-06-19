// CircularQueue.h : ���α׷� 8.5 ����� �����͸� �����ϴ� Ŭ����
#include "BinaryNode.h"
#include <stdlib.h>

inline void error(const char* str) {
	fprintf_s(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue {
	int front;		// ù ��° ��� ���� ��ġ
	int rear;		// ������ ��� ��ġ
	//BinaryNode* data[MAX_QUEUE_SIZE];
	int data[MAX_QUEUE_SIZE];

public:
	CircularQueue() { front = rear = 0; }
	
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }

	// ť�� ���� ------------------------------------------
	/*void enqueue(BinaryNode* n) {
		if (isFull()) error("Error: ť�� ��ȭ�����Դϴ�.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}*/

	// 11�� ��������� �̿��� �׷����� �ʺ�켱Ž�� ����
	void enqueue(int n) {
		if (isFull()) error("Error: ť�� ��ȭ�����Դϴ�.\n");
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}

	// ù �׸��� ť���� ���� ��ȯ ---------------------
	/*BinaryNode* dequeue() {
		if (isEmpty()) error("Error: ť�� ��������Դϴ�.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}*/

	// 11�� ��������� �̿��� �׷����� �ʺ�켱Ž�� ����
	int dequeue() {
		if (isEmpty()) error("Error: ť�� ��������Դϴ�.\n");
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}

	// �� ���� ��Ҹ� �������� �ʰ� ��ȯ
	int peek() {
		if (isEmpty()) error("Error: ť�� ��������Դϴ�.\n");
		return data[(front + 1) % MAX_QUEUE_SIZE];
	}
};