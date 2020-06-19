//// 8��-BinaryTree.cpp : ���α׷� 8.3 ����Ʈ�� �׽�Ʈ
//#include "BinaryTree.h"
//
//int main() {
//	BinaryTree tree;
//
//	// ���� ����Ʈ��
//	BinaryNode* d = new BinaryNode('D', NULL, NULL);
//	BinaryNode* c = new BinaryNode('C', NULL, NULL);
//	BinaryNode* b = new BinaryNode('B', c, d);
//
//
//	// ������ ����Ʈ��
//	//BinaryNode* g = new BinaryNode('G', NULL, NULL);	// Ʈ���� �ұ����� ���� ���
//	//BinaryNode* f = new BinaryNode('F', NULL, g);		// Ʈ���� �ұ����� ���� ���
//	BinaryNode* f = new BinaryNode('F', NULL, NULL);
//	BinaryNode* e = new BinaryNode('E', NULL, f);
//	//BinaryNode* e = new BinaryNode('E', f, NULL);	// ��������Ʈ�� ����
//
//	
//	// ��Ʈ ���
//	BinaryNode* a = new BinaryNode('A', b, e);
//
//	tree.setRoot(a);
//
//
//	//// ������ȸ
//	//tree.inorder();
//
//	//// ������ȸ
//	//tree.preorder();
//
//	//// ������ȸ
//	//tree.postorder();
//
//	//// ������ȸ
//	//tree.levelorder();
//
//	//printf("\n");
//
//	//printf("����� ���� = %d\n", tree.getCount());
//	//printf("�ܸ��� ���� = %d\n", tree.getLeafCount());
//	//printf("Ʈ���� ���� = %d\n", tree.getHeight());
//
//
//	// ��ȭ����Ʈ�� �˻�
//	//if (tree.isFull())
//	//	printf("��ȭ����Ʈ���̴�.\n");
//	//else
//	//	printf("��ȭ����Ʈ���� �ƴϴ�.\n");
//
//	//// ��������Ʈ�� �˻�
//	//if (tree.isComplete())
//	//	printf("��������Ʈ���̴�.\n");
//	//else
//	//	printf("��������Ʈ���� �ƴϴ�.\n");
//
//
//	//// ������ ��� ���� ���
//	//printf("������ ��� ���� = %d\n", tree.level(a));	// 1
//	//printf("������ ��� ���� = %d\n", tree.level(b));	// 2
//	//printf("������ ��� ���� = %d\n", tree.level(c));	// 3
//	//printf("������ ��� ���� = %d\n", tree.level(d));	// 3
//	//printf("������ ��� ���� = %d\n", tree.level(e));	// 2
//	//printf("������ ��� ���� = %d\n", tree.level(f));	// 3
//
//
//	//// ����Ʈ�� ���� �˻�
//	//if (tree.isBalanced()) {
//	//	printf("���� ���� �ִ�.\n");
//	//}
//	//else {
//	//	printf("���� ���� ���� �ʴ�.\n");
//	//}
//
//
//	//// ����� ������ ���� ���ϴ� ����
//	//printf("����� ���� �� = %d\n", tree.pathLength());
//
//
//	//// ����Ʈ���� �¿�� ��Ī��Ű�� ����
//	//printf("�¿��Ī �� Ʈ���� ������ȸ..");
//	//tree.inorder();
//	//printf("\n\n");
//	//tree.reverse();
//	//printf("�¿��Ī �� Ʈ���� ������ȸ..");
//	//tree.inorder();
//
//
//	//// ������ Ʈ�� ����
//	//BinaryTree that;
//
//	//BinaryNode* z = new BinaryNode('Z', NULL, NULL);
//	//BinaryNode* y = new BinaryNode('Y', NULL, NULL);
//	//BinaryNode* x = new BinaryNode('X', y, z);
//
//	////that.setRoot(x);
//	//that.setRoot(b);
//
//	//tree.inorder();		// root Ʈ���� ������ȸ
//	//that.inorder();		// that Ʈ���� ������ȸ
//
//	//printf("\n\n");
//
//	//// �� Ʈ���� �и� ���� �˻�
//	//if(tree.isDisjointFrom(that))
//	//	printf("�� Ʈ���� �и��Ǿ��ִ�.\n");
//	//else
//	//	printf("�� Ʈ���� �и��Ǿ����� �ʴ�.\n");
//
//
//	//that.setRoot(x);
//	//tree.inorder();		// root Ʈ���� ������ȸ
//	//that.inorder();		// that Ʈ���� ������ȸ
//
//	//printf("\n\n");
//
//	//if (tree.isDisjointFrom(that))
//	//	printf("�� Ʈ���� �и��Ǿ��ִ�.\n");
//	//else
//	//	printf("�� Ʈ���� �и��Ǿ����� �ʴ�.\n");
//
//
//	// ��� ����Ʈ���� �и� ���� �˻�
//
//	tree.inorder();		// root Ʈ���� ������ȸ
//	printf("\n\n");
//
//	if(tree.isVaild())
//		printf("��ȿ�ϴ�.\n");
//	else
//		printf("��ȿ���� �ʴ�.\n");
//}