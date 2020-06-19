//// 03��-CheckMathching.cpp : ���α׷� 3.6 ��ȣ �˻� ���α׷�
//# include "ArrayStack.h"    // ���α׷� 3.1�� ArrayStack Ŭ���� �ڵ� ���
//
//
//// �־��� ������ �о� ��ȣ ��Ī�� �˻��ϰ� ����� ����ϴ� �Լ�
//bool checkMatching(const char* filename) {
//
//	// fopen()�� ����� ������ ���� fopen_s()�� ��� ����� ���� ������
//	// ��, ��ó���� ���� ������ �����ϰų� ����� ������ �ϸ� fopen()�� ����� ���� ����
//	FILE* fp;
//	errno_t err = fopen_s(&fp, filename, "r");    
//
//	// ������ �������� ������ NULL ��ȯ, ���� ��� �� ����
//	if (fp == NULL)
//		error("Error : ������ �������� �ʽ��ϴ�.\n");
//
//	int nLine = 1;    // ���� ���� ����
//	int nChar = 0;    // ���� ���� ����
//
//	ArrayStack stack;    // ���� ��ü
//	char ch;
//
//	bool quote = false;		// (1) ��������ǥ ����
//	bool quoteBig = false;		// (3) ū����ǥ ����
//	bool annotation = false;		// (4) �ּ�1 ����
//	char tmp = NULL;				// (4) �ּ�2 ������ ���� �ӽ� ������ ����
//	bool anno2 = false;				// (4) �ּ�2 ����
//
//	while ((ch = getc(fp)) != EOF) {	// ������ ��(End Of File)�� ��Ÿ�� ������ �ݺ�, getc()�� �����Է��Լ�
//
//		// (4) �ּ� ���� ����1
//		if (ch == '\/' && annotation == false && quote == false) {		// ���� ����ǥ ���� �ּ����ڸ� �νĽ�Ű�� ���� quote�� �����
//			annotation = true;
//		}	
//
//		// (4) �ּ� �� ����1
//		if (ch == '\n') {
//			annotation = false;
//			nLine++;				// �Է¹��ڰ� ���๮���̸� ���� �� ����
//		}
//		nChar++;					// getc() ȣ���� ������ ���� �� ����
//
//		// (4) �ּ� ����2
//		if (ch == '\/' && anno2 == false) {
//			tmp = '\/';
//		}
//		else if (ch == '*' && tmp == '\/') {
//			anno2 = true;
//			tmp = NULL;
//		}
//
//		if (ch == '*' && anno2 == true) {
//			tmp = '*';
//		}
//		else if (tmp == '*' && ch == '\/') {
//			anno2 = false;
//			tmp = NULL;
//		}
//
//		// (1) ó�� ���� ����ǥ ����
//		if (ch == '\'' && quote == false)
//			quote = true;
//		// (1) ������ ���� ����ǥ ����
//		else if (ch == '\'')
//			quote = false;
//
//		// (3) ó�� ū ����ǥ ����
//		if (ch == '\"' && quoteBig == false)
//			quoteBig = true;
//		// (3) ������ ū ����ǥ ����
//		else if (ch == '\"')
//			quoteBig = false;
//
//
//		// ������ ��ȣ�̰�, ����/ū ����ǥ, �ּ� ���� ���� �ʴٸ� ���� ����
//		if ((ch == '[' || ch == '(' || ch == '{') && quote == false && quoteBig == false && annotation == false && anno2 == false)
//			stack.push(ch);
//
//		// ������ ��ȣ�̰�, ����/ū ����ǥ, �ּ� ���� ���� �ʴٸ� ���ÿ��� ���� ��
//		else if ((ch == ']' || ch == ')' || ch == '}') && quote == false && quoteBig == false && annotation == false && anno2 == false) {
//			int prev = stack.pop();
//
//			// ���� ���� ��ȣ�̸� �ݺ��� ����
//			if (   (ch == ']' && prev != '[')
//				|| (ch == ')' && prev != '(')
//				|| (ch == '}' && prev != '{'))
//				break;
//		}
//
//	}
//
//	fclose(fp);
//	printf("[%s] ���� �˻� ��� :\n", filename);
//
//	// ��� ���
//	if (!stack.isEmpty())
//		printf("Error : �����߰�! (���� ��=%d, ���� ��=%d)\n\n", nLine, nChar);
//	else
//		printf("OK : ���� (���� ��=%d, ���� ��=%d)\n\n", nLine, nChar);
//	return stack.isEmpty();
//}
//
//
//// �� �Լ� : ArrayStack.h, 03��-CheckMatching.cpp �� ���� �˻�
//int main() {
//	checkMatching("ArrayStack.h");
//	checkMatching("03��-CheckMatching.cpp");
//
//	// (3) �׽�Ʈ��
//	//printf("------------------------\n");
//	//printf(" ���� ��ȣ = (((((( \n");
//	//printf(" ������ ��ȣ = }}}}}} \n");
//	//printf("------------------------\n");
//
//	// (4) �׽�Ʈ��
//	printf("------------------------\n");
//	printf(" ���� ��ȣ = ( \n");      // ���� ��ȣ ( ����
//	printf(" ������ ��ȣ = } \n");    /* ������ ��ȣ } ���� */
//	printf("------------------------\n");
//
//	/*
//	{{{	[[[
//	(( {{
//	*/
//}