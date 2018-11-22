#include "pch.h"

//������ �Ź� �����ϴ°ͺ��� �ڵ����� ������ �Ǵ� Ʈ���� ����غô�.
//set�� �⺻������ �����Ʈ���� ������ �����̴�.

#include <set> //Ʈ����

//Ʈ�� ���Ŀ� ��Ŭ����
struct Comparer
{
	constexpr bool operator()(const int* lhs, const int* rhs)
	{
		//if ((*rhs) == 0) //0�̸� ������ �ڷ� �о����
		//	return true;
		//if (*lhs == 0)
		//	return false;

		return (*lhs) < (*rhs);
	}
};

void third()
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

	//�ε����� Ʈ�� ����
	std::set<int*,Comparer> indexing_set;

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

			//�ϴ� �ʱ�ȭ
			for (auto& arr : interface_array)
				for (auto& e : arr)
				{
					indexing_set.insert(&e);
				}

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
timer.start();
			//���� �������̽����� ���� ������ ã���ϴ�.
			auto min_pos_iter = indexing_set.begin();
			while (**min_pos_iter == 0) min_pos_iter++;
			auto min_pos = *min_pos_iter;
timer.stop();
search_time += timer.get_nano();

			//std::cout << "�ּҰ�: " << *min_pos<< std::endl << std::endl << std::endl;

			//���� ������� �� ����
			indexing_set.erase(indexing_set.begin()); //������ ���ؼ� ���ٰ�

			//���迭�� ���� MAX���� ū ��� 0 ����
			if (wating_array[i] > MAX)
				*min_pos = 0;
			
			//���迭�� ���� MAX�Ʒ��� ��쿡�� �������̽��� �� ����
			else
				*min_pos = wating_array[i]; //������� �� ����

			indexing_set.insert(min_pos); //������ ���ؼ� �ٽ� ����

			//show_interface(interface_array);
		}
	}

all_timer.stop();
long long all_time = all_timer.get_nano();

	std::cout << "�ּҰ� Ž���ð� ���� : " << search_time << std::endl;
	std::cout << "��ü ����ð� : " << all_time << std::endl;
}