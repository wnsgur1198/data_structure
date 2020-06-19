// AdjMatGraph.h : ���α׷� 11.1 ��������� �̿��� �׷��� Ŭ����
#include <cstdio>
#define MAX_VTXS 256
#include <cstdlib>		// �����Լ� ��� ����
#include <ctime>		// ����ð��� �����Լ��� �õ�� �����ϱ� ����

class AdjMatGraph {
protected:
	int size;
	char vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];

public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }

	bool isEmpty() { return size == 0; }
	bool isFull() { return size >= MAX_VTXS; }

	void reset() {
		size = 0;

		for (int i = 0; i < MAX_VTXS; i++)
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
	}

	void insertVertex(char name) {
		if (!isFull())
			vertices[size++] = name;
		else
			printf("Error: �׷��� ���� ���� �ʰ�\n");
	}

	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void display(FILE* fp = stdout) {
		fprintf(fp, "%d\n", size);

		for (int i = 0; i < size; i++) {
			fprintf(fp, "%c  ", getVertex(i));

			for (int j = 0; j < size; j++)
				fprintf(fp, " %3d", getEdge(i, j));
			fprintf(fp, "\n");
		}
	}

	void load(const char* filename) {
		FILE* fp = fopen(filename, "r");

		if (fp != NULL) {
			int n;
			fscanf(fp, "%d", &n);

			for (int i = 0; i < n; i++) {
				char str[80];
				fscanf(fp, "%s", str);
				insertVertex(str[0]);

				for (int j = 0; j < n; j++) {
					int val;
					fscanf(fp, "%d", &val);

					if (val != 0)
						insertEdge(i, j);
				}
			}
			fclose(fp);
		}
	}

	void store(const char* filename) {
		FILE* fp = fopen(filename, "w");

		if (fp != NULL) {
			display(fp);
			fclose(fp);
		}
	}

	// (1) �������� �׷����� �߻���Ű�� �Լ� --------------------------
	void randomGraph(int numVtx, int numEdge) {
		for (int i = 0; i < numVtx; i++)
			insertVertex('A' + i);

		for (int i = 0; i < numEdge; i++) {
			bool flag = true;
			
			while (flag) {
				int vtx1 = rand() % numVtx;
				//printf("vtx1: %d\n", vtx1);
				int vtx2 = rand() % numVtx;

				while (vtx1 == vtx2)
					vtx2 = rand() % numVtx;

				//printf("vtx2: %d\n", vtx2);

				if (adj[vtx1][vtx2] == 0) {  
					insertEdge(vtx1, vtx2);
					flag = false;			// �Ȱ��� ��ġ�� ������ �ߺ��Ǵ� ���� ���� ����
				}					
			}
			
		}
	}

	// (3) ��� ������ ����� ����׷����� �������� �߻���Ű�� �Լ�
	void randomConnectedGraph(int numVtx) {
		for (int i = 0; i < numVtx; i++)
			insertVertex('A' + i);

		for (int i = 0; i < numVtx; i++)
			for (int j = 0; j < numVtx; j++)
				if (i != j)
					insertEdge(i, j);
	}

};