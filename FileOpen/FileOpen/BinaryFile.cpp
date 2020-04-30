#include "BinaryFile.h"
#include <fstream>
#include <Windows.h>
#include <cassert>

BinaryFile::BinaryFile()
{
}

BinaryFile::~BinaryFile()
{
}

void BinaryFile::load(const char* fileName)
{
	std::ifstream ifs{};

	ifs.open(fileName, std::ios_base::in | std::ios_base::binary);

	if (ifs.is_open() == true)
	{
		printf("file을 성공적으로 open했습니다.");

		while (ifs.eof() == false)
		{
			_vData.emplace_back(ifs.get());
		}
		//DebugBreak();
	}
	else
	{
		printf("file이 열리지 않았습니다: %s\n", fileName);
	}
}

void BinaryFile::save(const char* fileName)
{
	std::ofstream ofs{};

	ofs.open(fileName, std::ios_base::out | std::ios_base::binary);

	if (ofs.is_open() == true)
	{
		printf("file을 성공적으로 open했습니다.");

		for (const auto& ch : _vData)
		{
			ofs.put(ch);
		}
	}
	else
	{
		printf("file이 열리지 않았습니다: %s\n", fileName);
	}
}

void BinaryFile::clear()
{
	_vData.clear();
}

void BinaryFile::write(int32 value)
{
	const size_t size{ sizeof(value) };
	union Conv
	{
		decltype(value) val;
		byte b[size]{};
	};
	Conv conv{ value };
	
	for (size_t i = 0; i < size; ++i)
	{
		_vData.emplace_back(conv.b[i]);
	}
}

void BinaryFile::write(char value)
{
	const size_t size{ sizeof(value) };
	union Conv
	{
		decltype(value) val;
		byte b[size]{};
	};
	Conv conv{ value };

	for (size_t i = 0; i < size; ++i)
	{
		_vData.emplace_back(conv.b[i]);
	}
}

bool BinaryFile::canRead(uint32 count) const
{
	if (_at + count > _vData.size())
	{
		return false;
	}

	return true;
}

int32 BinaryFile::readInt32() const
{
	int32 result{};
	size_t size{ sizeof(result) };

	assert(canRead(size) == true);

	memcpy(&result, &_vData[_at], size);
	
	_at += size;

	return result;
}

char BinaryFile::readChar() const
{
	char result{};
	size_t size{ sizeof(result) };

	assert(canRead(size) == true);

	memcpy(&result, &_vData[_at], size);

	_at += size;

	return result;
}