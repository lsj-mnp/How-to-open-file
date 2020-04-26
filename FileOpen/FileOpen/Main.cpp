#include "TextFile.h"

int main()
{
	TextFile textFile{};

	//문자열 안에 백슬래시(\)를 쓰고 싶으면 백슬래시를 두 번 쓰거나(\\) 슬래시를 쓰면 됨(/)
	//flag라서 비트 연산자로 섞어서 쓸 수 있다.
	//file은 수정 중 다른 프로그램이 수정할 수 없다.
	textFile.openAndRead("C:/Users/munop/OneDrive/바탕 화면/TestA.txt");

	textFile.openAndRead("C:/Users/munop/OneDrive/바탕 화면/TestA.txt");

	//배열이 포인터가 되는 순간 배열의 사이즈의 정보가 사라짐.(퇴화함. decay)
	textFile.display();

	return 0;
}