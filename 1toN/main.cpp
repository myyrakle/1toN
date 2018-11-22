#include "pch.h"

void prototype();
void first();
void second();
void third();
void fourth();

int main()
{
	try
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

		std::cout << "<<네번째 개선>>" << std::endl;
		fourth();
		std::cout << std::endl << std::endl;
	}

	catch (std::exception& e)
	{
		std::cout << "예외 발생 : " << e.what() << std::endl;
	}
}