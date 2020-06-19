//// 큐를 이용한 피보나치 수열 구현
//#include <cstdio>
//#include "CircularQueue.h"
//
//int fib_queue(int n) {
//
//	CircularQueue q;
//
//	if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else {
//		int first, second, sum = 0;
//		q.enqueue(0);
//		q.enqueue(1);
//
//		for (int i = 0; i < n; i++) {
//			first = q.dequeue();
//			second = q.dequeue();						
//			sum = first + second;
//
//			q.enqueue(second);
//			q.enqueue(sum);
//		}
//
//		return q.peek();
//	}
//}
//
//int main() {
//	printf("fib: %d",fib_queue(5));
//}