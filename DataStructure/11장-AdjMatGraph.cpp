//// 11��-AdjMatGraph.cpp : ���α׷� 11.2 �׷��� Ŭ���� �׽�Ʈ
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
//	// ������ķ� ǥ���� �׷��� �׽�Ʈ -----------------------------------
//	//for (int i = 0; i < 4; i++)
//	//	g.insertVertex('A' + i);
//	//g.insertEdge(0, 1);
//	//g.insertEdge(0, 3);
//	////g.insertEdge(1, 0);
//	//g.insertEdge(1, 2);
//	//g.insertEdge(1, 3);
//	//g.insertEdge(2, 3);
//
//	//printf("������ķ� ǥ���� �׷���\n");
//	//g.display();
//
//	/*g.store("graph.txt");
//	g.reset();*/
//
//	/*g.load("graph.txt");
//	printf("������ķ� ǥ���� �׷���2\n");
//	g.display();*/
//
//
//	// (1) ������ķ� ǥ���� ������ �׷��� �׽�Ʈ -----------------------------------
//	//// �����Լ� �õ尪 ������ ����..
//	//srand((unsigned)time(NULL));
//
//	//AdjMatGraph g;
//
//	//int numVtx = 0, numEdge = 0;
//
//	//printf("������ ������ �Է��Ͻÿ� : ");
//	//scanf("%d", &numVtx);
//
//	//while (true) {
//	//	printf("������ ������ �Է��Ͻÿ� : ");
//	//	scanf("%d", &numEdge);
//
//	//	int tmp = factorial(numVtx - 1);
//
//	//	if (tmp > numEdge)
//	//		break;
//	//	else
//	//		printf("����� �� �ִ� ���� ������ �ʰ��Ͽ����ϴ�!\n");
//	//}
//	//
//
//	//g.randomGraph(numVtx, numEdge);
//
//	//printf("\n--- ������ķ� ǥ���� ������ �׷��� ---\n");
//	//g.display();
//	//g.store("random_graph.txt");
//
//
//	//// ���� �켱 Ž�� �׽�Ʈ -----------------------------------
//	//SrchAMGraph g;
//	//g.load("random_graph.txt");
//	//printf("�׷���(random_graph.txt)\n");
//	//g.display();
//
//	//printf("DFS ==> ");
//	//g.resetVisited();
//	//g.DFS(0);			// 0��° ����, A���� Ž�� ����
//	//printf("\n");
//
//
//	//// (2) ������ �׷����� ���� ���Ἲ��Ž�� �׽�Ʈ --------------------
//	//ConnectedComponentGraph g;	
//
//	//printf("--- �׷���(random_graph.txt) ---\n");
//	//g.load("random_graph.txt");
//	//g.display();
//	//g.resetVisited();
//	//g.findConnectedComponent();
//
//
//	// (3) ��� ������ ����� ����׷����� �������� �߻���Ű�� �Լ� �׽�Ʈ ---------
//	ConnectedComponentGraph g;	
//
//	srand((unsigned)time(NULL));
//
//	int numVtx = 0;
//
//	printf("������ ������ �Է��Ͻÿ� : ");
//	scanf("%d", &numVtx);
//
//	printf("\n--- ��������� ����� ������ �׷��� ---\n");
//	g.randomConnectedGraph(numVtx);
//	g.display();
//
//	g.resetVisited();
//	g.findConnectedComponent();
//}