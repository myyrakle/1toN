//#define _PRINT_MODE //��� ���θ� �����մϴ�.

#include "pch.h"

//�����ϴ°� �ʹ� ������ �����Ѵ��� �� ���� ���� �������� �ߴ�.

template <class Array>
void bubble_sort(Array& arr)
{
	for (int unsorted_until = arr.size() - 1;
		unsorted_until != 0; unsorted_until--)
	{
		//0�� ����������.. ����
		for (int i = 1; i <= unsorted_until && *(arr[i]) != 0; i++) 
			if (*(arr[i]) < *(arr[i - 1]))
				std::swap(arr[i], arr[i - 1]);
	}
}

void bubble_sort_version()
{
Timer timer;
Timer all_timer;
long long time = 0;
long long sort_time = 0;

all_timer.start();

	//�������̽� 5x5 �迭
	std::array<std::array<int, side>, side> interface_array;

	int n = 1; //���� ��

	//���� �迭
	std::array<int, InterfaceSize> wating_array{ 0, }; //0���� �ʱ�ȭ

	//�ε����� �迭
	std::array<int*, InterfaceSize> indexing_array{ nullptr, };

	//�ϴ� �ʱ�ȭ
	int i = 0;
	for(auto& arr : interface_array)
		for (auto& e : arr)
		{
			indexing_array[i] = &e;
			i++;
		}

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
					i++;
				}
			}

			//�����Ѵ�.
			bubble_sort(indexing_array);

			//show_interface(interface_array);
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
			//�������̽� �ּҰ��� ��ġ�� ����� �������Դϴ�.
			int* min_pos = indexing_array[0];

			/*�ּҰ��� �����ɴϴ�.*/
timer.start();
			//���� �������̽����� ���� ������ ã���ϴ�.
			min_pos = indexing_array[0];
timer.stop(); 
time += timer.get_nano();
			//���� ������� �� ����

			//std::cout << "�ּҰ�: " << *min_pos << std::endl << std::endl << std::endl;

			//���迭�� ���� MAX���� ū ��� 0 ����
			if (wating_array[i] > MAX)
				*min_pos = 0;
			//���迭�� ���� MAX�Ʒ��� ��쿡�� �������̽��� �� ����
			else
				*min_pos = wating_array[i]; //������� �� ����

			
			//���������ϱ� ����
timer.start();
			std::rotate(indexing_array.begin(), //�� ���� 0�� �����ϱ� ��ĭ ������ �б�
				indexing_array.begin() + 1,
				indexing_array.end());
			bubble_sort(indexing_array);
timer.stop(); 
sort_time += timer.get_nano();

			//show_interface(interface_array);
		}
	}

all_timer.stop();
long long all_time = all_timer.get_nano();

	std::cout << "�ּҰ� Ž���ð� ���� : " << time << std::endl;
	std::cout << "���Ľð� ���� : " << sort_time << std::endl;
	std::cout << "��ü ����ð� : " << all_time << std::endl;
}

