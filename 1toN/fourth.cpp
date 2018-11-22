#include "pch.h"

//트리 정렬용 비교클래스
struct Comparer2
{
	constexpr bool operator()(const int* lhs, const int* rhs)
	{
		//if ((*rhs) == 0) //0이면 무조건 뒤로 밀어버림
		//	return true;
		//if (*lhs == 0)
		//	return false;

		return (*lhs) > (*rhs);
	}
};

void fourth()
{
Timer timer;
Timer all_timer;
long long search_time = 0;
long long sort_time = 0;

all_timer.start();

	//인터페이스 5x5 배열
	std::array<std::array<int, side>, side> interface_array;

	int n = 1; //현재 값

	//대기용 배열
	std::array<int, InterfaceSize> wating_array{ 0, }; //0으로 초기화

	//인덱스용 트리 집합
	std::vector<int*> indexing_heap;

	//일단 초기화
	for (auto& arr : interface_array)
		for (auto& e : arr)
		{
			indexing_heap.push_back(&e);
		}

	bool on_first = true;

	//4번. : 100/25 = 4
	for (; n <= MAX + InterfaceSize; n += InterfaceSize)
	{
		if (on_first) //한번만 수행됩니다.
		{
			on_first = false;

			std::iota(wating_array.begin(), wating_array.end(), n); //1~25 저장

			n += InterfaceSize;

			//그 25개의 배열을 섞습니다.
			std::shuffle(wating_array.begin(), wating_array.end(), std::random_device{});

			/*섞은걸 인터페이스에 들입다 붓습니다.*/
			int i = 0;
			for (auto& arr : interface_array)
			{
				for (auto& e : arr)
				{
					e = wating_array[i];
					i++;
				}
			}

			//힙으로 만들기
			std::make_heap(indexing_heap.begin(), indexing_heap.end(),
				Comparer2());

			//show_interface(interface_array);
		}

		//25개를 넣습니다.
		//2, 26-50
		//3, 51-75
		//4. 76-100
		std::iota(wating_array.begin(), wating_array.end(), n);

		//그 25개의 배열을 섞습니다.
		std::shuffle(wating_array.begin(), wating_array.end(), std::random_device{});


		//25번 반복해서 확인하고 넣고...
		for (int i = 0; i < InterfaceSize; i++)
		{
			int zero_count = 0;

timer.start();
			//현재 인터페이스에서 제일 작은걸 찾습니다.
			auto min_pos = indexing_heap[0];
timer.stop();
search_time += timer.get_nano();

			//std::cout << "최소값: " << *min_pos << std::endl << std::endl << std::endl;

			std::pop_heap(indexing_heap.begin(), indexing_heap.end(), Comparer2()); //정렬을 위해 뺐다가
			indexing_heap.pop_back();

			//대기배열의 값이 MAX보다 큰 경우 0 삽입
			if (wating_array[i] > MAX)
			{
				*min_pos = 0;
			}

			//대기배열에 값이 MAX아래일 경우에만 인터페이스에 값 변경
			else
			{
				*min_pos = wating_array[i]; //대기중인 값 저장
				indexing_heap.push_back(min_pos); //다시 집어넣고 정렬
				std::push_heap(indexing_heap.begin(), indexing_heap.end(), Comparer2());
			}

			//show_interface(interface_array);
		}
	}

	all_timer.stop();
	long long all_time = all_timer.get_nano();

	std::cout << "최소값 탐색시간 총합 : " << search_time << std::endl;
	std::cout << "전체 수행시간 : " << all_time << std::endl;
}