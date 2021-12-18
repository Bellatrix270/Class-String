#pragma once

#include <iostream>
using std::ostream;
using std::istream;

class Str
{
public:

	Str(); //Конструктор.
	Str(const char* line);
	~Str(); //Деструктор.

	// Перегруженный метод вычисления длинны строки.
	int getLength(const char* inputLine);
	int getLength(char* inputLine);
	int getLength();

	Str& copy(int, int);
	Str& remove(int, int);

	// Перегруженный метод вставки подстроки.
	Str& insert(Str&, int);
	Str& insert(char*, int);

	// Перегруженный метод поиска индекса подстроки.
	int indexOf(Str&);
	int indexOf(char*);

	// Обычные унарные операторы. 
	//Работают также, как с числами. (a = b, a+=b)
	Str& operator=(const Str&);
	Str& operator=(const char*);
	Str& operator+=(const Str&);

	char& operator[](int);

	// Бинарный оператор сложения двух строк.
	friend Str& operator+(const Str&, const Str&);

	// Операторы представления данных.
	friend ostream& operator<<(std::ostream&, const Str&);
	friend istream& operator>>(std::istream&, Str&);

private:
	char* str;
	int len;

};

