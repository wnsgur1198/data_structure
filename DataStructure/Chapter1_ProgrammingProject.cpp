//#include <iostream>
//#include <ctime>
//#define ITERATION 110000000
//using namespace std;
//
//// 알고리즘 A 구현
//int sumAlgorithmA(int n) {
//	int sum = n * (n + 1) / 2;
//	return sum;
//}
//
//// 알고리즘 B 구현
//int sumAlgorithmB(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += i;
//	}
//	return sum;
//}
//
//// 알고리즘 C 구현
//int sumAlgorithmC(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		for (int k = 0; k < i; k++) {
//			sum++;
//		}
//	}
//	return sum;
//}
//
//int main() {
//	
//	clock_t start, finish;
//	double duration;
//	int sum[3];
//
//	// 알고리즘별 실행시간 측정--------------------------------
//	for (int n = 0; n < ITERATION; n += 10000000) {
//		
//		printf("n: %d\n", n);
//
//		// 알고리즘 A 실행시간 측정
//		start = clock();
//
//		sum[0] = sumAlgorithmA(n);
//
//		finish = clock();
//		duration = (double)(finish - start) / CLOCKS_PER_SEC;
//
//		printf("알고리즘 A 계산결과 : %f 초입니다.\n", duration);
//
//
//		// 알고리즘 B 실행시간 측정
//		start = clock();
//
//		sum[1] = sumAlgorithmB(n);
//
//		finish = clock();
//		duration = (double)(finish - start) / CLOCKS_PER_SEC;
//
//		printf("알고리즘 B 계산결과 : %f 초입니다.\n", duration);
//
//
//		//// 알고리즘 C 실행시간 측정
//		//start = clock();
//
//		//sum[2] = sumAlgorithmC(n);
//
//		//finish = clock();
//		//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//
//		//printf("알고리즘 C 계산결과 : %f 초입니다.\n", duration);
//		
//		printf("\n");
//	}
//}