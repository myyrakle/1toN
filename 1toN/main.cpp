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
		//std::cout << "<<������Ÿ��>>" << std::endl;
		prototype();
		//std::cout << std::endl << std::endl;
		/*
		std::cout << "<<ù��° ����>>" << std::endl;
		bubble_sort_version();
		std::cout << std::endl << std::endl;

		std::cout << "<<�ι�° ����>>" << std::endl;
		list_sort_version();
		std::cout << std::endl << std::endl;

		std::cout << "<<����° ����>>" << std::endl;
		treeset_version();
		std::cout << std::endl << std::endl;

		std::cout << "<<�׹�° ����>>" << std::endl;
		heap_version();
		std::cout << std::endl << std::endl;*/
	}

	catch (std::exception& e)
	{
		std::cout << "���� �߻� : " << e.what() << std::endl;
	}

	system("pause");
}