//#include <iostream>
//#include <ctime>
//#define ITERATION 110000000
//using namespace std;
//
//// �˰��� A ����
//int sumAlgorithmA(int n) {
//	int sum = n * (n + 1) / 2;
//	return sum;
//}
//
//// �˰��� B ����
//int sumAlgorithmB(int n) {
//	int sum = 0;
//	for (int i = 1; i <= n; i++) {
//		sum += i;
//	}
//	return sum;
//}
//
//// �˰��� C ����
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
//	// �˰��� ����ð� ����--------------------------------
//	for (int n = 0; n < ITERATION; n += 10000000) {
//		
//		printf("n: %d\n", n);
//
//		// �˰��� A ����ð� ����
//		start = clock();
//
//		sum[0] = sumAlgorithmA(n);
//
//		finish = clock();
//		duration = (double)(finish - start) / CLOCKS_PER_SEC;
//
//		printf("�˰��� A ����� : %f ���Դϴ�.\n", duration);
//
//
//		// �˰��� B ����ð� ����
//		start = clock();
//
//		sum[1] = sumAlgorithmB(n);
//
//		finish = clock();
//		duration = (double)(finish - start) / CLOCKS_PER_SEC;
//
//		printf("�˰��� B ����� : %f ���Դϴ�.\n", duration);
//
//
//		//// �˰��� C ����ð� ����
//		//start = clock();
//
//		//sum[2] = sumAlgorithmC(n);
//
//		//finish = clock();
//		//duration = (double)(finish - start) / CLOCKS_PER_SEC;
//
//		//printf("�˰��� C ����� : %f ���Դϴ�.\n", duration);
//		
//		printf("\n");
//	}
//}