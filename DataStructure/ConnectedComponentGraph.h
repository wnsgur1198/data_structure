// ConnectedComponentGraph.h : ���α׷� 11.13 ��������� �̿��� �׷����� ���Ἲ��Ž��
#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph {
	int label[MAX_VTXS];

public:

	// ���̿켱Ž��
	void labelDFS(int v, int color) {
		visited[v] = true;
		label[v] = color;

		for (int i = 0; i < size; i++)
			if (isLinked(v, i) && visited[i] == false)
				labelDFS(i, color);
	}

	// �׷����� ���� ���� ���� ------------------------
	void findConnectedComponent() {
		int cnt = 0;

		for (int i = 0; i < size; i++)
			if (visited[i] == false)
				labelDFS(i, ++cnt);

		printf("�׷��� ���Ἲ�� ���� == %d\n", cnt);
		for (int i = 0; i < size; i++)
			printf(" %c=%d ", getVertex(i), label[i]);
		printf("\n");
	}
};