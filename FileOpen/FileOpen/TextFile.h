#pragma once
#include <string>

class TextFile
{
public:
	TextFile();
	~TextFile();

public:
	void load(const char* fileName);

	void save(const char* fileName);

	void clear();

	void write(const char* data);

	void display() const;

private:
	std::string _data{};
};
