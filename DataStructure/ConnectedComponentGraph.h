// ConnectedComponentGraph.h : 프로그램 11.13 인접행렬을 이용한 그래프의 연결성분탐색
#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph {
	int label[MAX_VTXS];

public:

	// 깊이우선탐색
	void labelDFS(int v, int color) {
		visited[v] = true;
		label[v] = color;

		for (int i = 0; i < size; i++)
			if (isLinked(v, i) && visited[i] == false)
				labelDFS(i, color);
	}

	// 그래프의 연결 성분 검출 ------------------------
	void findConnectedComponent() {
		int cnt = 0;

		for (int i = 0; i < size; i++)
			if (visited[i] == false)
				labelDFS(i, ++cnt);

		printf("그래프 연결성분 개수 == %d\n", cnt);
		for (int i = 0; i < size; i++)
			printf(" %c=%d ", getVertex(i), label[i]);
		printf("\n");
	}
};