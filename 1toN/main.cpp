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
		std::cout << "<<������Ÿ��>>" << std::endl;
		prototype();
		std::cout << std::endl << std::endl;
		
		std::cout << "<<ù��° ����>>" << std::endl;
		first();
		std::cout << std::endl << std::endl;

		std::cout << "<<�ι�° ����>>" << std::endl;
		second();
		std::cout << std::endl << std::endl;

		std::cout << "<<����° ����>>" << std::endl;
		third();
		std::cout << std::endl << std::endl;

		std::cout << "<<�׹�° ����>>" << std::endl;
		fourth();
		std::cout << std::endl << std::endl;
	}

	catch (std::exception& e)
	{
		std::cout << "���� �߻� : " << e.what() << std::endl;
	}
}