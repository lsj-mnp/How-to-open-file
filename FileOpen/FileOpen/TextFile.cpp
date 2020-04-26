#include "TextFile.h"
#include <fstream>

TextFile::TextFile()
{
}

TextFile::~TextFile()
{
}

void TextFile::openAndRead(const char* fileName)
{
	std::ifstream ifs{};

	ifs.open(fileName, std::ios_base::in);

	if (ifs.is_open())
	{
		_data.clear();

		char buffer[5000]{};

		//현재위치가 파일의 끝인지 알려주는 함수.
		while (!ifs.eof())
		{
			ifs.getline(buffer, 5000);

			_data += buffer;
			_data += "\n";
		}
	}

	//open을 한 번만 한다면 ifs가 소멸될 때 알아서 close를 호출 해주므로 안 호출해도 되긴 함.
	ifs.close();
}

void TextFile::display() const
{
	printf("%s\n", _data.c_str());
}

