// BinaryTree.h : 프로그램 8.2 이진트리 클래스 구현
#include "CircularQueue.h"
#include <cmath>		// 거듭제곱 계산(pow)을 위해 추가

class BinaryTree {

	BinaryNode* root;

public:
	BinaryTree() : root(NULL) { }

	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }


	// 8장 프로그래밍 프로젝트 (1) 

	// 포화이진트리 검사 --------------------
	bool isFull() {
		
		int height = getHeight();
		int maxCnt = (int)pow(2, height) - 1;
		int cnt = getCount();

		if(cnt < maxCnt)  
			return false;

		return true;		
	}

	// 완전이진트리 검사 --------------------
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
						
						// 왼쪽 노드가 존재하지 않고, 오른쪽 노드만 존재하면 완전이진트리가 아님
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


	// 8장 프로그래밍 프로젝트 (2) 

	// 이진트리에서 임의의 노드의 레벨 계산 ---------------------------------------
	int level(BinaryNode* node) {

		int maxHeight = getHeight(root);
		int nodeHeight = getHeight(node);

		return maxHeight - nodeHeight + 1;
	}


	// 8장 프로그래밍 프로젝트 (3)

	// 이진트리가 균형잡혀 있는지 검사 ---------------------------
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


	// 8장 프로그래밍 프로젝트 (4)

	// 경로의 길이의 합을 구하는 연산 --------------------
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


	// 8장 프로그래밍 프로젝트 (5)

	// 이진트리를 좌우로 대칭시키는 연산 --------------------
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


	// 8장 프로그래밍 프로젝트 (6)

	// 두 트리의 분리 여부 검사 --------------------	
	// 두 트리의 분리 여부 검사 - 반복문으로 구현
	//bool isDisjointFrom(BinaryTree that) {

	//	int root_data = 0;
	//	int that_data = 0;

	//	if (!isEmpty()) {

	//		// root 트리의 노드 탐색
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

	//			// that 트리의 노드 탐색
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

	//				// root 내의 노드와 that의 노드가 일치하므로 두 트리는 분리되어 있지 않음
	//				if (root_data == that_data) return false;
	//			}
	//		}

	//	}

	//	return true;
	//}

	// 순환호출에 의한 트리의 분리 여부 검사
	bool isDisjointFrom(BinaryTree that) {
		return isEmpty() ? 0 : isDisjointFrom(root, that.getRoot());
	}

	bool isDisjointFrom(BinaryNode* node, BinaryNode* that) {

		// 두 트리의 노드들이 NULL이 될 때까지 
		// 함수가 종료되지 않으면(같은 노드가 없다면) 두 트리는 분리되어 있음
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


	// 8장 프로그래밍 프로젝트 (7)

	// 모든 서브트리의 분리 여부 검사 --------------------
	bool isVaild() {
		return isDisjointFrom(root->getLeft(), root->getRight()) ? true : false;	
	}


	// 이진트리의 순회 연산 8.4~8.5
	
	// 중위순회 -----------------------
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

	// 전위순회 -----------------------
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

	// 후위순회 -----------------------
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

	// 레벨순회 -----------------------
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


	// 이진트리의 추가 연산 8.6~8.8

	// 트리의 노드 개수 구하기 -----------------------
	int getCount() { return isEmpty() ? 0 : getCount(root); }

	// 순환호출에 의해 node를 루트로 하는 서브트리의 노드 개수 계산
	int getCount(BinaryNode* node) {
		if (node == NULL) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}

	// 단말 노드 개수 구하기 -----------------------
	int getLeafCount() { return isEmpty() ? 0 : getLeafCount(root); }

	// 순환호출에 의해 node를 루트로 하는 서브트리의 단말 노드 개수 계산
	int getLeafCount(BinaryNode* node) {
		if (node == NULL) 
			return 0;

		if (node->isLeaf())
			return 1;
		else 
			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}

	// 트리의 높이 구하기 -----------------------
	int getHeight() { return isEmpty() ? 0 : getHeight(root); }

	// 순환호출에 의해 node를 루트로 하는 서브트리의 단말 노드 개수 계산
	int getHeight(BinaryNode* node) {
		if (node == NULL) return 0;

		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());

		return (hLeft > hRight) ? hLeft+1 : hRight+1;
	}
};