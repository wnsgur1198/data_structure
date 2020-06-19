//// 03장-CheckMathching.cpp : 프로그램 3.6 괄호 검사 프로그램
//# include "ArrayStack.h"    // 프로그램 3.1의 ArrayStack 클래스 코드 사용
//
//
//// 주어진 파일을 읽어 괄호 매칭을 검사하고 결과를 출력하는 함수
//bool checkMatching(const char* filename) {
//
//	// fopen()는 취약점 문제로 인해 fopen_s()를 대신 사용할 것을 권장함
//	// 단, 전처리기 정의 설정을 변경하거나 경고무시 설정을 하면 fopen()를 사용할 수도 있음
//	FILE* fp;
//	errno_t err = fopen_s(&fp, filename, "r");    
//
//	// 파일이 존재하지 않으면 NULL 반환, 에러 출력 후 종료
//	if (fp == NULL)
//		error("Error : 파일이 존재하지 않습니다.\n");
//
//	int nLine = 1;    // 읽은 라인 개수
//	int nChar = 0;    // 읽은 문자 개수
//
//	ArrayStack stack;    // 스택 객체
//	char ch;
//
//	bool quote = false;		// (1) 작은따옴표 감지
//	bool quoteBig = false;		// (3) 큰따옴표 감지
//	bool annotation = false;		// (4) 주석1 감지
//	char tmp = NULL;				// (4) 주석2 감지를 위한 임시 문자형 변수
//	bool anno2 = false;				// (4) 주석2 감지
//
//	while ((ch = getc(fp)) != EOF) {	// 파일의 끝(End Of File)이 나타날 때까지 반복, getc()는 문자입력함수
//
//		// (4) 주석 시작 감지1
//		if (ch == '\/' && annotation == false && quote == false) {		// 작은 따옴표 내의 주석문자를 인식시키기 위해 quote를 사용함
//			annotation = true;
//		}	
//
//		// (4) 주석 끝 감지1
//		if (ch == '\n') {
//			annotation = false;
//			nLine++;				// 입력문자가 개행문자이면 라인 수 증가
//		}
//		nChar++;					// getc() 호출할 때마다 문자 수 증가
//
//		// (4) 주석 감지2
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
//		// (1) 처음 작은 따옴표 감지
//		if (ch == '\'' && quote == false)
//			quote = true;
//		// (1) 마지막 작은 따옴표 감지
//		else if (ch == '\'')
//			quote = false;
//
//		// (3) 처음 큰 따옴표 감지
//		if (ch == '\"' && quoteBig == false)
//			quoteBig = true;
//		// (3) 마지막 큰 따옴표 감지
//		else if (ch == '\"')
//			quoteBig = false;
//
//
//		// 열리는 괄호이고, 작은/큰 따옴표, 주석 내에 있지 않다면 스택 저장
//		if ((ch == '[' || ch == '(' || ch == '{') && quote == false && quoteBig == false && annotation == false && anno2 == false)
//			stack.push(ch);
//
//		// 닫히는 괄호이고, 작은/큰 따옴표, 주석 내에 있지 않다면 스택에서 꺼내 비교
//		else if ((ch == ']' || ch == ')' || ch == '}') && quote == false && quoteBig == false && annotation == false && anno2 == false) {
//			int prev = stack.pop();
//
//			// 맞지 않은 괄호이면 반복문 종료
//			if (   (ch == ']' && prev != '[')
//				|| (ch == ')' && prev != '(')
//				|| (ch == '}' && prev != '{'))
//				break;
//		}
//
//	}
//
//	fclose(fp);
//	printf("[%s] 파일 검사 결과 :\n", filename);
//
//	// 결과 출력
//	if (!stack.isEmpty())
//		printf("Error : 문제발견! (라인 수=%d, 문자 수=%d)\n\n", nLine, nChar);
//	else
//		printf("OK : 정상 (라인 수=%d, 문자 수=%d)\n\n", nLine, nChar);
//	return stack.isEmpty();
//}
//
//
//// 주 함수 : ArrayStack.h, 03장-CheckMatching.cpp 두 파일 검사
//int main() {
//	checkMatching("ArrayStack.h");
//	checkMatching("03장-CheckMatching.cpp");
//
//	// (3) 테스트용
//	//printf("------------------------\n");
//	//printf(" 왼쪽 괄호 = (((((( \n");
//	//printf(" 오른쪽 괄호 = }}}}}} \n");
//	//printf("------------------------\n");
//
//	// (4) 테스트용
//	printf("------------------------\n");
//	printf(" 왼쪽 괄호 = ( \n");      // 왼쪽 괄호 ( 설명
//	printf(" 오른쪽 괄호 = } \n");    /* 오른쪽 괄호 } 설명 */
//	printf("------------------------\n");
//
//	/*
//	{{{	[[[
//	(( {{
//	*/
//}