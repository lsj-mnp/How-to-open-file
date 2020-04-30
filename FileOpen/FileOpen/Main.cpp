#include "TextFile.h"
#include "BinaryFile.h"

int main()
{
	TextFile textFile{};

	//문자열 안에 백슬래시(\)를 쓰고 싶으면 백슬래시를 두 번 쓰거나(\\) 슬래시를 쓰면 됨(/)
	//flag라서 비트 연산자로 섞어서 쓸 수 있다.
	//file은 수정 중 다른 프로그램이 수정할 수 없다.
	//textFile.load("C:/Users/munop/OneDrive/바탕 화면/TestA.txt");
	//textFile.display();

	//textFile.write("마른 하늘을 달려\n나 그대에게 안길수만 있으면\n내 몸 부서진대도 좋아\n");

	/*textFile.write("123456789");

	textFile.save("C:/Users/munop/OneDrive/바탕 화면/TestC.txt");

	textFile.clear();*/

	BinaryFile binaryFile{};

	//binaryFile.load("C:/Users/munop/OneDrive/바탕 화면/TestC.txt");

	/*binaryFile.write('l');
	binaryFile.write('s');
	binaryFile.write('j');

	binaryFile.write(123'456'789);

	binaryFile.save("C:/Users/munop/OneDrive/바탕 화면/TestD.txt");*/
	
	binaryFile.load("C:/Users/munop/OneDrive/바탕 화면/TestD.txt");

	binaryFile.readChar();
	binaryFile.readChar();
	binaryFile.readChar();

	int32 a{ binaryFile.readInt32() };

	return 0;
}