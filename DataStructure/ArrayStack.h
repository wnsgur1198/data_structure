// ArrayStack.h : ���α׷� 3.1 C++ �迭�� ������ int ���� Ŭ����
#include <cstdio>    // C ��������� <stdio.h>�� �����ϴ� �Ͱ� ����
#include <cstdlib>    // C ��������� <stdlib.h>�� �����ϴ� �Ͱ� ����


// ���� ó�� �Լ� - ���� �߻� �� �����޽��� ��� �� ����
inline void error(const char* message) {  // const Ű���带 �������� ������ ���ڿ��� ���޹��� �� ����
	printf("%s\n", message);
	exit(1);
}


const int MAX_STACK_SIZE = 20;    // ������ �ִ� ũ�� ���� - #define�� �̿��� ��ũ�� ��ĵ� ����

class ArrayStack {
// class������ ���������ڸ� �������� ������ �⺻������ private
	int top;                     // ����� ����
	int data[MAX_STACK_SIZE];    // ����� �迭

public:
	// ���� ������ - ���ο� ��ü�� �����Ǹ� �ڵ� ȣ��, ������� �ʱ�ȭ
	ArrayStack() { top = -1;  *data = NULL; }    // �����ڿ��� data ������ �ʱ�ȭ���� ������ �������� �� �Ǵ� ���� �ƴ����� ��� ��µ�
	
	// ���� �Ҹ��� - �ƹ� �ϵ� ���ϸ� ��������
	// ~ArrayStack() {}

	// ������ ���� ���� �˻�
	bool isEmpty() { return top == -1; }

	// ������ ��ȭ ���� �˻�
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	// �� ���� ��� ����
	void push(int e) {
		if (isFull()) error("���� ��ȭ ����");
		data[++top] = e;
	}

	// �� ���� ��Ҹ� �����ϰ� ��ȯ
	int pop() {
		if (isEmpty()) error("���� ���� ����");
		return data[top--];
	}

	// �� ���� ��Ҹ� �������� �ʰ� ��ȯ
	int peek() {
		if (isEmpty()) error("���� ���� ����");
		return data[top];    // top ������ ��ȭ����
	}

	// ���� ������ ���
	void display() {
		printf("[���� �׸� �� : %2d] ==> ", top + 1);
		
		for (int i = 0; i <= top; i++) {	// �ݺ����� ��������(i<=top)�� ����
			printf("<%2d>", data[i]);
		}

		printf("\n");
	}
};