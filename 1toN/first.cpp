//#define _PRINT_MODE //��� ���θ� �����մϴ�.

#include "pch.h"


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


int main()
{
Timer timer;
int time = 0;
int sort_time = 0;

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

	//�����Ѵ�.
	bubble_sort(indexing_array);

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
					//std::cout << e << " ";
					i++;
				}
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
			min_pos = indexing_array[0];
timer.stop(); 
time += timer.get_nano();
			//���� ������� �� ����

#ifdef _PRINT_MODE
			std::cout << *min_pos << std::endl;
#endif

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
			//std::sort(indexing_array.begin(), indexing_array.end());
timer.stop(); 
sort_time += timer.get_nano();

			//show_interface(interface_array);
			//std::cout << std::endl;
		}
	}

	std::cout << "�ּҰ� Ž���ð� ���� : " << time << std::endl;
	std::cout << "���Ľð� ���� : " << sort_time << std::endl;

	return 0;
}

