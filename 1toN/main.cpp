#include "pch.h"

int prototype();
int first();
int second();
int third();

int main()
{
	std::cout << "<<프로토타입>>" << std::endl;
	prototype();
	std::cout << std::endl << std::endl;

	std::cout << "<<첫번째 개선>>" << std::endl;
	first();
	std::cout << std::endl << std::endl;

	std::cout << "<<두번째 개선>>" << std::endl;
	second();
	std::cout << std::endl << std::endl;

	std::cout << "<<세번째 개선>>" << std::endl;
	third();
	std::cout << std::endl << std::endl;
}