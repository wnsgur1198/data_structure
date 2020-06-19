// BinaryNode.h : ���α׷� 8.1 ����Ʈ���� ���� ��� Ŭ����
#include <cstdio>	

class BinaryNode {

protected:
	int data;			// Ʈ���� ������ ��
	BinaryNode* left;	// ���� �ڽĳ���� ������
	BinaryNode* right;	// ������ �ڽĳ���� ������

public:
	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL) : data(val), left(l), right(r) { }

	void setData(int val) { data = val; }
	void setLeft(BinaryNode* l) { left = l; }
	void setRight(BinaryNode* r) { right = r; }
	
	int getData() { return data; }
	BinaryNode* getLeft() { return left; }
	BinaryNode* getRight() { return right; }

	bool isLeaf() { return left == NULL && right == NULL; }
};