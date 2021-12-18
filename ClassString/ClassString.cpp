// ClassString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Str.h"

int main()
{
    std::cout << "Hello World!\n";
    char inputLine[1024] = "";
    char inputLineV2[1024] = "";
    int length = 0;

    std::cin >> inputLine;
    std::cin >> inputLineV2;

    Str line = Str(inputLine);
    Str lineV2 = Str(inputLineV2);

    Str result;

    length = line.getLength(inputLine);
    std::cout << length;

    line += lineV2;

    result = line.copy(3,2);
}

