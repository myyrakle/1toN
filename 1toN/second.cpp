#include "pch.h"

//�����Ʈ�� �ʹ� ������ ���� �����Լ��� std::sort ���.

//std::sort�� ����Ʈ, ����Ʈ, ���Լ�Ʈ�� ȥ���̴�.
//std::sort�� �⺻������ ����Ʈ�� ���ٰ�, ����Ʈ�� �ʹ� ���� ����� ����Ʈ�� ����.
//�׸��� ��κ��� ���ĵǾ����� ��쿡�� ���Լ�Ʈ�� �������Ѵ�.
//�׷��� �����ϸ� n log n�� ���⵵�� �����ش�.

int second()
{
Timer timer;
Timer all_timer;
long long search_time = 0;
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
	for (auto& arr : interface_array)
		for (auto& e : arr)
		{
			indexing_array[i] = &e;
			i++;
		}

	//�����Ѵ�.
	std::sort(indexing_array.begin(),indexing_array.end(),
		[](int* lhs, int* rhs) {return (*lhs) < (*rhs); }
		);

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
			int blank_count = 0; //��� �迭�� 0�� ���ִ� ��

			auto min_pos = &(interface_array[0][0]);

			while (*min_pos == 0) 
			{
				min_pos++;
			}
			//�������̽� �ּҰ��� ��ġ�� ����� �������Դϴ�.

			/*�ּҰ��� �����ɴϴ�.*/
timer.start();
			//���� �������̽����� ���� ������ ã���ϴ�.
			min_pos = indexing_array[0];
timer.stop();
search_time += timer.get_nano();
			//���� ������� �� ����

#ifdef _PRINT_MODE
			std::cout << *min_pos << std::endl;
#endif

			//���迭�� ���� MAX���� ū ��� 0 ����
			if (wating_array[i] > MAX)
			{
				*min_pos = 0;
				blank_count++;
			}
			//���迭�� ���� MAX�Ʒ��� ��쿡�� �������̽��� �� ����
			else
				*min_pos = wating_array[i]; //������� �� ����

			//���������ϱ� ����
timer.start();
			std::rotate(indexing_array.begin(), //�� ���� 0�� �����ϱ� ��ĭ ������ �б�
				indexing_array.begin() + 1,
				indexing_array.end());
			std::sort(indexing_array.begin(), indexing_array.end()-blank_count,
				[](int* lhs, int* rhs) {return (*lhs) < (*rhs); });
timer.stop();
sort_time += timer.get_nano();

			//show_interface(interface_array);
			//std::cout << std::endl;
		}
	}

	all_timer.stop();
	long long all_time = all_timer.get_nano();

	std::cout << "�ּҰ� Ž���ð� ���� : " << search_time << std::endl;
	std::cout << "���Ľð� ���� : " << sort_time << std::endl;
	std::cout << "��ü ����ð� : " << all_time << std::endl;

	return 0;
}