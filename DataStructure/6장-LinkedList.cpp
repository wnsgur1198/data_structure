// 6��-LinkedList.cpp : �ܼ� ���� ����Ʈ Ŭ���� �׽�Ʈ ���α׷�
#include "LinkedList.h"
#include <iostream>
using namespace std;

int recursive(int n) {
	printf("%d\n", n);
	if (n < 1) return -1;
	else return (recursive(n - 3) + 1);
}

//void asterisk(int i) {
//	if (i > 1) {
//		asterisk(i / 2);
//		asterisk(i / 2);
//	}
//	printf(" * ");
//}

void main() {

	printf("%d",recursive(10));
	//asterisk(9);

	//// ����Ʈ ��ü1
	//LinkedList list1;

	//list1.insert(0, new Node(20));
	//list1.insert(1, new Node(60));
	//list1.insert(2, new Node(30));
	//list1.insert(3, new Node(10));
	//list1.insert(4, new Node(50));
	//list1.insert(5, new Node(40));

	//printf("------ ����Ʈ1�� ���� ������ ------\n");
	//list1.display();
	//printf("\n");

	////// �ִ밪 ��常 ����
	//list1.remove_max();
	//printf("------ ����Ʈ1�� ���� ������ ------\n");
	//list1.display();
	//printf("\n");	


	//// Ȧ����°�� ����
	//list1.remove_odd();
	//printf("------ ����Ʈ1�� ���� ������ ------\n");
	//list1.display();
	//printf("\n");


	//// reverse ���� ����
	//printf("------ ����Ʈ1�� reverse ���� �� ��� ------\n");
	//list1.reverse();
	//list1.display();
	//printf("\n");


	//// ����Ʈ ��ü2
	//LinkedList list2;

	//list2.insert(0, new Node(40));
	//list2.insert(1, new Node(50));
	//list2.insert(2, new Node(60));

	//printf("------ ����Ʈ2�� ���� ������ -------\n");
	//list2.display();
	//printf("\n");


	//// merge ���� ����
	//printf("------ ����Ʈ1�� ����Ʈ2�� merge ���� �� ��� ------\n");
	//list1.merge(&list2);
	//list1.display();
	//printf("\n");

	//printf("------ merge ���� �� ����Ʈ2�� ���� ������ -------\n");
	//list2.display();
}