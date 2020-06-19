// 6장-LinkedList.cpp : 단순 연결 리스트 클래스 테스트 프로그램
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

	//// 리스트 객체1
	//LinkedList list1;

	//list1.insert(0, new Node(20));
	//list1.insert(1, new Node(60));
	//list1.insert(2, new Node(30));
	//list1.insert(3, new Node(10));
	//list1.insert(4, new Node(50));
	//list1.insert(5, new Node(40));

	//printf("------ 리스트1의 현재 데이터 ------\n");
	//list1.display();
	//printf("\n");

	////// 최대값 노드만 삭제
	//list1.remove_max();
	//printf("------ 리스트1의 현재 데이터 ------\n");
	//list1.display();
	//printf("\n");	


	//// 홀수번째만 삭제
	//list1.remove_odd();
	//printf("------ 리스트1의 현재 데이터 ------\n");
	//list1.display();
	//printf("\n");


	//// reverse 연산 수행
	//printf("------ 리스트1의 reverse 연산 후 결과 ------\n");
	//list1.reverse();
	//list1.display();
	//printf("\n");


	//// 리스트 객체2
	//LinkedList list2;

	//list2.insert(0, new Node(40));
	//list2.insert(1, new Node(50));
	//list2.insert(2, new Node(60));

	//printf("------ 리스트2의 현재 데이터 -------\n");
	//list2.display();
	//printf("\n");


	//// merge 연산 수행
	//printf("------ 리스트1와 리스트2의 merge 연산 후 결과 ------\n");
	//list1.merge(&list2);
	//list1.display();
	//printf("\n");

	//printf("------ merge 연산 후 리스트2의 현재 데이터 -------\n");
	//list2.display();
}