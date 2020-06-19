// SrchAMGraph.h : ���α׷� 11.8 ��������� �̿��� �׷����� Ž�� ����
#include "AdjMatGraph.h"
//#include "CircularQueue.h"				// �ʺ�켱Ž�� ������ ����

class SrchAMGraph : public AdjMatGraph {
protected:
	bool visited[MAX_VTXS];

public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}

	bool isLinked(int u, int v) { return getEdge(u, v) != 0; }

	//// ���̿켱Ž�� �Լ� -------------
	//void DFS(int v) {
	//	visited[v] = true;
	//	printf("%c ", getVertex(v));

	//	for (int i = 0; i < size; i++)
	//		if (isLinked(v, i) && visited[i] == false)
	//			DFS(i);
	//}

	//// �ʺ�켱Ž�� �Լ� -------------
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