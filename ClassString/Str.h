#pragma once

#include <iostream>
using std::ostream;
using std::istream;

class Str
{
public:

	Str(); //�����������.
	Str(const char* line);
	~Str(); //����������.

	// ������������� ����� ���������� ������ ������.
	int getLength(const char* inputLine);
	int getLength(char* inputLine);
	int getLength();

	Str& copy(int, int);
	Str& remove(int, int);

	// ������������� ����� ������� ���������.
	Str& insert(Str&, int);
	Str& insert(char*, int);

	// ������������� ����� ������ ������� ���������.
	int indexOf(Str&);
	int indexOf(char*);

	// ������� ������� ���������. 
	//�������� �����, ��� � �������. (a = b, a+=b)
	Str& operator=(const Str&);
	Str& operator=(const char*);
	Str& operator+=(const Str&);

	char& operator[](int);

	// �������� �������� �������� ���� �����.
	friend Str& operator+(const Str&, const Str&);

	// ��������� ������������� ������.
	friend ostream& operator<<(std::ostream&, const Str&);
	friend istream& operator>>(std::istream&, Str&);

private:
	char* str;
	int len;

};

