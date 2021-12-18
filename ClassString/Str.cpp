#include "Str.h"
#include <iostream>
using std::istream;
using std::ostream;

int Str::getLength(const char* inputLine)
{
	int i = 0;

	for (; ; i++)
		if (inputLine[i] == '\0') break;

	return i;
}

int Str::getLength(char* inputLine)
{
	int i = 0;

	for (; ; i++)
		if (inputLine[i] == '\0') break;

	return i;
}

int Str::getLength() 
{
	return this->len;
}

Str::Str() //Реализация конструктора без параметров.
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
}

Str::Str(const char* line) //Реализация конструктора с парметром из заголовка.
{
	int i = 0;
	
	for (; ; i++)
		if (line[i] == '\0') break;

	str = new char[i + 1];

	len = i;

	for (i = 0; i < len; i++)
		str[i] = line[i];
}

Str& Str::operator=(const Str& refStr) 
{
	if (this == &refStr)
		return *this;

	delete[] str; // this->str Аналогично this.str;

	len = refStr.len;
	str = new char[len + 1];

	for (int i = 0; i < len; i++)
		str[i] = refStr.str[i];

	return *this;
}

Str& Str::operator=(const char* inputLine) 
{
	delete[] str;

	len = getLength(inputLine);
	str = new char[len + 1];

	for (int i = 0; i < len; i++)
		str[i] = inputLine[i];

	return *this;
}

Str& Str::operator+=(const Str& refStr) // Ex: newLine ("Hello") += line ("Word");
										// newLine - this object. line - refStr.
{
	int sizeL = this->getLength();
	int newSize = sizeL + refStr.len;
	char* line = new char[newSize + 1];

	int i = 0;
	for (; i < sizeL; i++)
		line[i] = this->str[i];

	for (int j = 0; j < refStr.len; i++, j++)
		line[i] = refStr.str[j];

	delete this->str;

	this->str = line;
	this->len = newSize;

	/*int newSize = this->getLength() + refStr.len;
	int currentSize = this->getLength();
	
	for (int i = currentSize, j = 0; i < newSize; i++, j++)
		this->str[i] = refStr.str[j];

	this->str[newSize] = '\0';
	this->len = newSize;*/

	return *this;
}

char& Str::operator[](int index)
{
	return str[index];
}

Str& operator+(const Str& refrStrL, const Str& refStrR)
{
	Str* str = new Str;
	*str = refrStrL;

	return *str += refStrR;
}

ostream& operator<< (ostream& outputStream, const Str& refStr)
{
	outputStream << refStr.str;
	return outputStream;
}

istream& operator>> (istream& inputStream, Str& refStr)
{
	char temp[80];
	inputStream.get(temp, 80);

	if (inputStream)
		refStr = temp;

	while (inputStream && inputStream.get() != '\n')
		continue;

	return inputStream;
}

Str& Str::copy(int startIndex, int length)
{
	Str* line = new Str();

	if (length > 0)
	{
		startIndex = startIndex < 0 ? 0 : startIndex;

		for (int i = startIndex, j = 0; i < startIndex + length; i++, j++)
			line->str[j] = this->str[i];

		line->str[length] = '\0';
		line->len = length;
	}

	return *line;
}


Str::~Str() //Реализация деструктора.
{
	delete str;
}

