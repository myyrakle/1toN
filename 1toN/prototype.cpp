#include "pch.h"

//#define _PRINT_MODE //��� ���θ� �����մϴ�.


int main()
{
	constexpr auto side = 5; //�������̽� �� ���� ����
	constexpr auto MAX = 100; //�ִ� �Է°� ����
	constexpr auto InterfaceSize = side*side; //�������̽��� �� ũ��
	
Timer timer;
int time=0;

	//�������̽� 5x5 �迭
	std::array<std::array<int, side>, side> interface_array;

	int n = 1; //���� ��

	//���� �迭
	std::array<int, InterfaceSize> wating_array{ 0, }; //0���� �ʱ�ȭ

	bool on_first = true;

	//4��. : 100/25 = 4
	for (; n <= MAX + InterfaceSize; n += InterfaceSize)
	{
		if (on_first) //�ѹ��� ����˴ϴ�.
		{
			on_first = false;

			std::iota(wating_array.begin(), wating_array.end(), n); //1~25 ����

			n += InterfaceSize;

			//�� 25���� �迭�� �����ϴ�.
			std::shuffle(wating_array.begin(), wating_array.end(), std::random_device{});

			/*������ �������̽��� ���Դ� �׽��ϴ�.*/
			int i = 0;
			for (auto& arr : interface_array)
			{
				for (auto& e : arr)
				{
					e = wating_array[i];
					//std::cout << e <<" ";
					i++;
				}
				#ifdef _PRINT_MODE 
					std::cout << std::endl; 
				#endif
			}
		}

		//25���� �ֽ��ϴ�.
		//2, 26-50
		//3, 51-75
		//4. 76-100
		std::iota(wating_array.begin(), wating_array.end(), n);

		//�� 25���� �迭�� �����ϴ�.
		std::shuffle(wating_array.begin(), wating_array.end(), std::random_device{});

		//25�� �ݺ��ؼ� Ȯ���ϰ� �ְ�...
		for (int i = 0; i < InterfaceSize; i++)
		{			
			auto min_pos = &(interface_array[0][0]);
			
			while (*min_pos == 0) {
				min_pos++;
			}
			//�������̽� �ּҰ��� ��ġ�� ����� �������Դϴ�.

			/*�ּҰ��� �����ɴϴ�.*/
timer.start();
			//���� �������̽����� ���� ������ ã���ϴ�.
			for (auto& arr : interface_array)
			{
				for (auto& e : arr)
				{
					if (e != 0)
						if ((*min_pos) > e) //�� ������ ������ ��� ���
							min_pos = &e;
				}
			}
timer.stop();
time += timer.get_nano();
			//���� ������� �� ����

			//���迭�� ���� MAX���� ū ��� 0 ����
			if (wating_array[i] > MAX)
				*min_pos = 0;
			//���迭�� ���� MAX�Ʒ��� ��쿡�� �������̽��� �� ����
			else
				*min_pos = wating_array[i]; //������� �� ����
			
			#ifdef _PRINT_MODE
				std::cout << std::endl;
			#endif

			//show_interface(interface_array);
		}
	}

	std::cout << "�ּҰ� Ž���ð� ���� : " << time << std::endl;

	return 0;
}

