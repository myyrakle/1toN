#include "pch.h"

//#define _PRINT_MODE //��� ���θ� �����մϴ�.


int prototype()
{
Timer timer;
Timer all_timer;
long long all_time = 0;
long long search_time=0;

all_timer.start();

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
			}

			show_interface(interface_array);
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
search_time += timer.get_nano();
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

			show_interface(interface_array);
		}
	}

all_timer.stop();
all_time = all_timer.get_nano();

	std::cout << "�ּҰ� Ž���ð� ���� : " << search_time << std::endl;
	std::cout << "��ü ����ð� : " << all_time << std::endl;

	return 0;
}

