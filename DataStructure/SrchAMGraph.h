// SrchAMGraph.h : 프로그램 11.8 인접행렬을 이용한 그래프의 탐색 연산
#include "AdjMatGraph.h"
//#include "CircularQueue.h"				// 너비우선탐색 구현을 위함

class SrchAMGraph : public AdjMatGraph {
protected:
	bool visited[MAX_VTXS];

public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	//// 깊이우선탐색 함수 -------------
	//void DFS(int v) {
	//	visited[v] = true;
	//	printf("%c ", getVertex(v));

	//	for (int i = 0; i < size; i++)
	//		if (isLinked(v, i) && visited[i] == false)
	//			DFS(i);
	//}

	//// 너비우선탐색 함수 -------------
	//void BFS(int v) {
	//	visited[v] = true;
	//	printf("%c ", getVertex(v));

	//	CircularQueue q;
	//	q.enqueue(v);

	//	while (!q.isEmpty()) {
	//		int v = q.dequeue();

	//		for(int i=0; i<size; i++)
	//			if (isLinked(v, i) && visited[i] == false) {
	//				visited[i] = true;
	//				printf("%c ", getVertex(i));
	//				q.enqueue(i);
	//			}
	//	}
	//}
};