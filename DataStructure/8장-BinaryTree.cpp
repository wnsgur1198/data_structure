//// 8장-BinaryTree.cpp : 프로그램 8.3 이진트리 테스트
//#include "BinaryTree.h"
//
//int main() {
//	BinaryTree tree;
//
//	// 왼쪽 서브트리
//	BinaryNode* d = new BinaryNode('D', NULL, NULL);
//	BinaryNode* c = new BinaryNode('C', NULL, NULL);
//	BinaryNode* b = new BinaryNode('B', c, d);
//
//
//	// 오른쪽 서브트리
//	//BinaryNode* g = new BinaryNode('G', NULL, NULL);	// 트리의 불균형을 위한 노드
//	//BinaryNode* f = new BinaryNode('F', NULL, g);		// 트리의 불균형을 위한 노드
//	BinaryNode* f = new BinaryNode('F', NULL, NULL);
//	BinaryNode* e = new BinaryNode('E', NULL, f);
//	//BinaryNode* e = new BinaryNode('E', f, NULL);	// 완전이진트리 버전
//
//	
//	// 루트 노드
//	BinaryNode* a = new BinaryNode('A', b, e);
//
//	tree.setRoot(a);
//
//
//	//// 중위순회
//	//tree.inorder();
//
//	//// 전위순회
//	//tree.preorder();
//
//	//// 후위순회
//	//tree.postorder();
//
//	//// 레벨순회
//	//tree.levelorder();
//
//	//printf("\n");
//
//	//printf("노드의 개수 = %d\n", tree.getCount());
//	//printf("단말의 개수 = %d\n", tree.getLeafCount());
//	//printf("트리의 개수 = %d\n", tree.getHeight());
//
//
//	// 포화이진트리 검사
//	//if (tree.isFull())
//	//	printf("포화이진트리이다.\n");
//	//else
//	//	printf("포화이진트리가 아니다.\n");
//
//	//// 완전이진트리 검사
//	//if (tree.isComplete())
//	//	printf("완전이진트리이다.\n");
//	//else
//	//	printf("완전이진트리가 아니다.\n");
//
//
//	//// 임의의 노드 레벨 계산
//	//printf("임의의 노드 레벨 = %d\n", tree.level(a));	// 1
//	//printf("임의의 노드 레벨 = %d\n", tree.level(b));	// 2
//	//printf("임의의 노드 레벨 = %d\n", tree.level(c));	// 3
//	//printf("임의의 노드 레벨 = %d\n", tree.level(d));	// 3
//	//printf("임의의 노드 레벨 = %d\n", tree.level(e));	// 2
//	//printf("임의의 노드 레벨 = %d\n", tree.level(f));	// 3
//
//
//	//// 이진트리 균형 검사
//	//if (tree.isBalanced()) {
//	//	printf("균형 잡혀 있다.\n");
//	//}
//	//else {
//	//	printf("균형 잡혀 있지 않다.\n");
//	//}
//
//
//	//// 경로의 길이의 합을 구하는 연산
//	//printf("경로의 길이 합 = %d\n", tree.pathLength());
//
//
//	//// 이진트리를 좌우로 대칭시키는 연산
//	//printf("좌우대칭 전 트리의 중위순회..");
//	//tree.inorder();
//	//printf("\n\n");
//	//tree.reverse();
//	//printf("좌우대칭 후 트리의 중위순회..");
//	//tree.inorder();
//
//
//	//// 임의의 트리 생성
//	//BinaryTree that;
//
//	//BinaryNode* z = new BinaryNode('Z', NULL, NULL);
//	//BinaryNode* y = new BinaryNode('Y', NULL, NULL);
//	//BinaryNode* x = new BinaryNode('X', y, z);
//
//	////that.setRoot(x);
//	//that.setRoot(b);
//
//	//tree.inorder();		// root 트리의 중위순회
//	//that.inorder();		// that 트리의 중위순회
//
//	//printf("\n\n");
//
//	//// 두 트리의 분리 여부 검사
//	//if(tree.isDisjointFrom(that))
//	//	printf("두 트리는 분리되어있다.\n");
//	//else
//	//	printf("두 트리는 분리되어있지 않다.\n");
//
//
//	//that.setRoot(x);
//	//tree.inorder();		// root 트리의 중위순회
//	//that.inorder();		// that 트리의 중위순회
//
//	//printf("\n\n");
//
//	//if (tree.isDisjointFrom(that))
//	//	printf("두 트리는 분리되어있다.\n");
//	//else
//	//	printf("두 트리는 분리되어있지 않다.\n");
//
//
//	// 모든 서브트리의 분리 여부 검사
//
//	tree.inorder();		// root 트리의 중위순회
//	printf("\n\n");
//
//	if(tree.isVaild())
//		printf("유효하다.\n");
//	else
//		printf("유효하지 않다.\n");
//}