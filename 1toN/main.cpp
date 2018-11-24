#include "pch.h"

void prototype();
void bubble_sort_version();
void list_sort_version();
void treeset_version();
void heap_version();

int main()
{
	try
	{
		//std::cout << "<<프로토타입>>" << std::endl;
		prototype();
		//std::cout << std::endl << std::endl;
		/*
		std::cout << "<<첫번째 개선>>" << std::endl;
		bubble_sort_version();
		std::cout << std::endl << std::endl;

		std::cout << "<<두번째 개선>>" << std::endl;
		list_sort_version();
		std::cout << std::endl << std::endl;

		std::cout << "<<세번째 개선>>" << std::endl;
		treeset_version();
		std::cout << std::endl << std::endl;

		std::cout << "<<네번째 개선>>" << std::endl;
		heap_version();
		std::cout << std::endl << std::endl;*/
	}

	catch (std::exception& e)
	{
		std::cout << "예외 발생 : " << e.what() << std::endl;
	}

	system("pause");
}