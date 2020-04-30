#include "TextFile.h"
#include <fstream>

TextFile::TextFile()
{
}

TextFile::~TextFile()
{
}

void TextFile::load(const char* fileName)
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
			//배열이 포인터가 되는 순간 배열의 사이즈의 정보가 사라짐.(퇴화함. decay)
			ifs.getline(buffer, 5000);

			_data += buffer;
			_data += "\n";
		}
	}

	//open을 한 번만 한다면 ifs가 소멸될 때 알아서 close를 호출 해주므로 안 호출해도 되긴 함.
	ifs.close();
}

void TextFile::save(const char* fileName)
{
	std::ofstream ofs{};

	ofs.open(fileName, std::ios_base::out);

	if (ofs.is_open() == true)
	{
		ofs.write(_data.c_str(), _data.size());

		printf("file을 성공적으로 save했습니다.\n");

		ofs.close();
	}
	else
	{
		printf("file이 열리지 않았습니다: %s\n", fileName);
	}
}

void TextFile::clear()
{
	_data.clear();
}

void TextFile::write(const char* data)
{
	_data += data;
}

void TextFile::display() const
{
	printf("%s\n", _data.c_str());
}

