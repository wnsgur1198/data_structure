// ArrayStack.h : 프로그램 3.1 C++ 배열로 구현한 int 스택 클래스
#include <cstdio>    // C 헤더파일의 <stdio.h>을 포함하는 것과 동일
#include <cstdlib>    // C 헤더파일의 <stdlib.h>을 포함하는 것과 동일


// 오류 처리 함수 - 오류 발생 시 오류메시지 출력 후 종료
inline void error(const char* message) {  // const 키워드를 덧붙이지 않으면 문자열을 전달받을 수 없음
	printf("%s\n", message);
	exit(1);
}


const int MAX_STACK_SIZE = 20;    // 스택의 최대 크기 설정 - #define을 이용한 매크로 방식도 가능

class ArrayStack {
// class에서는 접근지정자를 설정하지 않으면 기본적으로 private
	int top;                     // 요소의 개수
	int data[MAX_STACK_SIZE];    // 요소의 배열

public:
	// 스택 생성자 - 새로운 객체가 생성되면 자동 호출, 멤버변수 초기화
	ArrayStack() { top = -1;  *data = NULL; }    // 생성자에서 data 변수를 초기화하지 않으면 컴파일이 안 되는 것은 아니지만 경고가 출력됨
	
	// 스택 소멸자 - 아무 일도 안하면 생략가능
	// ~ArrayStack() {}

	// 스택의 공백 상태 검사
	bool isEmpty() { return top == -1; }

	// 스택의 포화 상태 검사
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	// 맨 위에 요소 삽입
	void push(int e) {
		if (isFull()) error("스택 포화 에러");
		data[++top] = e;
	}

	// 맨 위의 요소를 삭제하고 반환
	int pop() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top--];
	}

	// 맨 위의 요소를 삭제하지 않고 반환
	int peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];    // top 변수의 변화없음
	}

	// 스택 내용을 출력
	void display() {
		printf("[스택 항목 수 : %2d] ==> ", top + 1);
		
		for (int i = 0; i <= top; i++) {	// 반복문의 종료조건(i<=top)에 유의
			printf("<%2d>", data[i]);
		}

		printf("\n");
	}
};