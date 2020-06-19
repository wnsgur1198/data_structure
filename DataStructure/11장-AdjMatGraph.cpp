//// 11장-AdjMatGraph.cpp : 프로그램 11.2 그래프 클래스 테스트
////#include "AdjMatGraph.h"
////#include "SrchAMGraph.h"
//#include "ConnectedComponentGraph.h"
//
//int factorial(int n) {
//	//printf("Factorial(%d)\n", n);
//
//	if (n == 1)
//		return 1;
//	else
//		return (n * factorial(n - 1));
//}
//
//void main() {
//
//	// 인접행렬로 표현한 그래프 테스트 -----------------------------------
//	//for (int i = 0; i < 4; i++)
//	//	g.insertVertex('A' + i);
//	//g.insertEdge(0, 1);
//	//g.insertEdge(0, 3);
//	////g.insertEdge(1, 0);
//	//g.insertEdge(1, 2);
//	//g.insertEdge(1, 3);
//	//g.insertEdge(2, 3);
//
//	//printf("인접행렬로 표현한 그래프\n");
//	//g.display();
//
//	/*g.store("graph.txt");
//	g.reset();*/
//
//	/*g.load("graph.txt");
//	printf("인접행렬로 표현한 그래프2\n");
//	g.display();*/
//
//
//	// (1) 인접행렬로 표현한 무작위 그래프 테스트 -----------------------------------
//	//// 랜덤함수 시드값 생성을 위해..
//	//srand((unsigned)time(NULL));
//
//	//AdjMatGraph g;
//
//	//int numVtx = 0, numEdge = 0;
//
//	//printf("정점의 개수를 입력하시오 : ");
//	//scanf("%d", &numVtx);
//
//	//while (true) {
//	//	printf("간선의 개수를 입력하시오 : ");
//	//	scanf("%d", &numEdge);
//
//	//	int tmp = factorial(numVtx - 1);
//
//	//	if (tmp > numEdge)
//	//		break;
//	//	else
//	//		printf("허용할 수 있는 간선 개수를 초과하였습니다!\n");
//	//}
//	//
//
//	//g.randomGraph(numVtx, numEdge);
//
//	//printf("\n--- 인접행렬로 표현한 무작위 그래프 ---\n");
//	//g.display();
//	//g.store("random_graph.txt");
//
//
//	//// 깊이 우선 탐색 테스트 -----------------------------------
//	//SrchAMGraph g;
//	//g.load("random_graph.txt");
//	//printf("그래프(random_graph.txt)\n");
//	//g.display();
//
//	//printf("DFS ==> ");
//	//g.resetVisited();
//	//g.DFS(0);			// 0번째 정점, A에서 탐색 시작
//	//printf("\n");
//
//
//	//// (2) 무작위 그래프에 대해 연결성분탐색 테스트 --------------------
//	//ConnectedComponentGraph g;	
//
//	//printf("--- 그래프(random_graph.txt) ---\n");
//	//g.load("random_graph.txt");
//	//g.display();
//	//g.resetVisited();
//	//g.findConnectedComponent();
//
//
//	// (3) 모든 정점이 연결된 연결그래프를 무작위로 발생시키는 함수 테스트 ---------
//	ConnectedComponentGraph g;	
//
//	srand((unsigned)time(NULL));
//
//	int numVtx = 0;
//
//	printf("정점의 개수를 입력하시오 : ");
//	scanf("%d", &numVtx);
//
//	printf("\n--- 모든정점이 연결된 무작위 그래프 ---\n");
//	g.randomConnectedGraph(numVtx);
//	g.display();
//
//	g.resetVisited();
//	g.findConnectedComponent();
//}