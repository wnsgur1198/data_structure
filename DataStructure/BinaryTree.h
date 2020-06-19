// BinaryTree.h : ���α׷� 8.2 ����Ʈ�� Ŭ���� ����
#include "CircularQueue.h"
#include <cmath>		// �ŵ����� ���(pow)�� ���� �߰�

class BinaryTree {

	BinaryNode* root;

public:
	BinaryTree() : root(NULL) { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }


	// 8�� ���α׷��� ������Ʈ (1) 

	// ��ȭ����Ʈ�� �˻� --------------------
	bool isFull() {
		
		int height = getHeight();
		int maxCnt = (int)pow(2, height) - 1;
		int cnt = getCount();

		if(cnt < maxCnt)  
			return false;

		return true;		
	}

	// ��������Ʈ�� �˻� --------------------
	bool isComplete() {

		if (isFull())
			return true;
		else {
			if (!isEmpty()) {
				CircularQueue q;

				q.enqueue(root);

				while (!q.isEmpty()) {
					BinaryNode* n = q.dequeue();

					if (n != NULL) {
						
						// ���� ��尡 �������� �ʰ�, ������ ��常 �����ϸ� ��������Ʈ���� �ƴ�
						if (n->getLeft() == NULL && n->getRight() != NULL)
							return false;

						q.enqueue(n->getLeft());
						q.enqueue(n->getRight());
					}
				}
			}
			return true;
		}
	}


	// 8�� ���α׷��� ������Ʈ (2) 

	// ����Ʈ������ ������ ����� ���� ��� ---------------------------------------
	int level(BinaryNode* node) {

		int maxHeight = getHeight(root);
		int nodeHeight = getHeight(node);

		return maxHeight - nodeHeight + 1;
	}


	// 8�� ���α׷��� ������Ʈ (3)

	// ����Ʈ���� �������� �ִ��� �˻� ---------------------------
	bool isBalanced() { return isEmpty() ? 0 : isBalanced(root); }

	bool isBalanced(BinaryNode* node) {

		if (node == NULL) return true;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		if ( (hLeft - hRight) < 2 && (hLeft - hRight) > -2
			&& isBalanced(node->getLeft()) && isBalanced(node->getRight()) )
			return true;

		return false;
	}


	// 8�� ���α׷��� ������Ʈ (4)

	// ����� ������ ���� ���ϴ� ���� --------------------
	int pathLength() {

		int sum = 0;

		if (!isEmpty()) {
			CircularQueue q;

			q.enqueue(root);

			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();

				sum += level(n) - 1; 

				if (n != NULL) {
					if (n->getLeft())  q.enqueue(n->getLeft());
					if (n->getRight())  q.enqueue(n->getRight());
				}
			}
		}
		return sum;
	}


	// 8�� ���α׷��� ������Ʈ (5)

	// ����Ʈ���� �¿�� ��Ī��Ű�� ���� --------------------
	bool reverse() { return isEmpty() ? 0 : reverse(root); }

	bool reverse(BinaryNode* node) {
		if (node == NULL) return false;

		else {
			reverse(node->getLeft());
			reverse(node->getRight());

			BinaryNode* tmp = node->getLeft();
			node->setLeft(node->getRight());
			node->setRight(tmp);
		}
		return true;
	}


	// 8�� ���α׷��� ������Ʈ (6)

	// �� Ʈ���� �и� ���� �˻� --------------------	
	// �� Ʈ���� �и� ���� �˻� - �ݺ������� ����
	//bool isDisjointFrom(BinaryTree that) {

	//	int root_data = 0;
	//	int that_data = 0;

	//	if (!isEmpty()) {

	//		// root Ʈ���� ��� Ž��
	//		CircularQueue q;

	//		q.enqueue(root);

	//		while (!q.isEmpty()) {
	//			BinaryNode* n = q.dequeue();

	//			if (n != NULL) {
	//				//printf("root: [%c] ", n->getData());
	//				root_data = n->getData();
	//				q.enqueue(n->getLeft());
	//				q.enqueue(n->getRight());
	//			}

	//			// that Ʈ���� ��� Ž��
	//			CircularQueue q2;

	//			q2.enqueue(that.getRoot());

	//			while (!q2.isEmpty()) {
	//				BinaryNode* n2 = q2.dequeue();

	//				if (n2 != NULL) {
	//					//printf("that: [%c] ", n2->getData());
	//					that_data = n2->getData();
	//						
	//					q2.enqueue(n2->getLeft());
	//					q2.enqueue(n2->getRight());
	//				}

	//				// root ���� ���� that�� ��尡 ��ġ�ϹǷ� �� Ʈ���� �и��Ǿ� ���� ����
	//				if (root_data == that_data) return false;
	//			}
	//		}

	//	}

	//	return true;
	//}

	// ��ȯȣ�⿡ ���� Ʈ���� �и� ���� �˻�
	bool isDisjointFrom(BinaryTree that) {
		return isEmpty() ? 0 : isDisjointFrom(root, that.getRoot());
	}

	bool isDisjointFrom(BinaryNode* node, BinaryNode* that) {

		// �� Ʈ���� ������ NULL�� �� ������ 
		// �Լ��� ������� ������(���� ��尡 ���ٸ�) �� Ʈ���� �и��Ǿ� ����
		if (node == NULL || that == NULL)	return true;

		for (BinaryNode* n = that; n != NULL; n = n->getLeft()) {

			//printf("root Node : [%c], that Node : [%c]\n", node->getData(), n->getData());

			if (n == node)	return false;

			if (node->getLeft() != NULL) 
				if (!isDisjointFrom(that, node->getLeft()))
					return false;
			
			if (node->getRight() != NULL) 
				if (!isDisjointFrom(that, node->getRight()))
					return false;			
		}

		for (BinaryNode* n = that; n != NULL; n = n->getRight()) {

			//printf("root Node : [%c], that Node : [%c]\n", node->getData(), n->getData());

			if (n == node)	return false;

			if (node->getLeft() != NULL) 
				if (!isDisjointFrom(that, node->getLeft()))		
					return false;			

			if (node->getRight() != NULL) 
				if (!isDisjointFrom(that, node->getRight()))	
					return false;			
		}
		return true;
	}


	// 8�� ���α׷��� ������Ʈ (7)

	// ��� ����Ʈ���� �и� ���� �˻� --------------------
	bool isVaild() {
		return isDisjointFrom(root->getLeft(), root->getRight()) ? true : false;	
	}


	// ����Ʈ���� ��ȸ ���� 8.4~8.5
	
	// ������ȸ -----------------------
	void inorder() { 
		printf("\n  inorder: "); 
		inorder(root);
	}

	void inorder(BinaryNode* node) {
		if (node != NULL) {
			inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			inorder(node->getRight());
		}
	}

	// ������ȸ -----------------------
	void preorder() {
		printf("\n  preorder: ");
		preorder(root);
	}

	void preorder(BinaryNode* node) {
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}

	// ������ȸ -----------------------
	void postorder() {
		printf("\n  postorder: ");
		postorder(root);
	}

	void postorder(BinaryNode* node) {
		if (node != NULL) {
			postorder(node->getLeft());
			postorder(node->getRight());
			printf(" [%c] ", node->getData());
		}
	}

	// ������ȸ -----------------------
	void levelorder() {
		printf("\n levelorder: ");

		if (!isEmpty()) {
			CircularQueue q;

			q.enqueue(root);

			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();

				if (n != NULL) {
					printf(" [%c] ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}


	// ����Ʈ���� �߰� ���� 8.6~8.8

	// Ʈ���� ��� ���� ���ϱ� -----------------------
	int getCount() { return isEmpty() ? 0 : getCount(root); }

	// ��ȯȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� ��� ���� ���
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// �ܸ� ��� ���� ���ϱ� -----------------------
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }

	// ��ȯȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� �ܸ� ��� ���� ���
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) 
			return 0;

		if (node->isLeaf())
			return 1;
		else 
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// Ʈ���� ���� ���ϱ� -----------------------
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }

	// ��ȯȣ�⿡ ���� node�� ��Ʈ�� �ϴ� ����Ʈ���� �ܸ� ��� ���� ���
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		return (hLeft > hRight) ? hLeft+1 : hRight+1;
	}
};