#include "pch.h"

#include <list>

//버블소트가 너무 느려서 내장 정렬함수인 std::sort 사용.
//빈 공간의 유연한 처리를 위해, 배열 대신 list 사용

//std::sort는 퀵소트, 힙소트, 삽입소트의 혼합이다.
//std::sort는 기본적으로 퀵소트를 쓰다가, 퀵소트가 너무 느린 경우라면 힙소트를 쓴다.
//그리고 대부분이 정렬되어있을 경우에는 삽입소트로 마무리한다.
//그래서 웬만하면 n log n의 복잡도를 보여준다.

void second()
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

	//인덱스용 배열
	std::list<int*> indexing_list;

	//일단 초기화
	for (auto& arr : interface_array)
		for (auto& e : arr)
			indexing_list.push_back(&e);

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

			//최초 정렬
			indexing_list.sort(
				[](int* lhs, int* rhs) {return (*lhs) < (*rhs); }
			);

			//show_interface(interface_array);
		}

		//대기배열에 25개를 넣습니다.
		//2, 26-50
		//3, 51-75
		//4. 76-100 ...
		std::iota(wating_array.begin(), wating_array.end(), n);

		//그 25개의 대기배열을 섞습니다.
		std::shuffle(wating_array.begin(), wating_array.end(), std::random_device{});

		//25번 반복해서 확인하고 넣고...
		for (int i = 0; i < InterfaceSize; i++)
		{
timer.start();
			//현재 인터페이스에서 제일 작은걸 찾습니다. 물론 0 빼고요
			int* min_pos = indexing_list.front();
timer.stop();
search_time += timer.get_nano();
			//빼고 대기중인 값 삽입

			//std::cout << "최소값: " << *min_pos << std::endl << std::endl << std::endl;

			//대기배열의 값이 MAX보다 큰 경우 0 삽입
			if (wating_array[i] > MAX)
			{
				*min_pos = 0;
				indexing_list.pop_front();
			}
			//대기배열의 값이 MAX아래일 경우에만 인터페이스의 값 변경
			else
				*min_pos = wating_array[i]; //대기중인 값 저장


			//저장했으니까 정렬
timer.start();
			indexing_list.sort(
				[](int* lhs, int* rhs)
			{
				return (*lhs) < (*rhs);
			});
timer.stop();
sort_time += timer.get_nano();

			//show_interface(interface_array);
		}
	}

all_timer.stop();
long long all_time = all_timer.get_nano();

	std::cout << "최소값 탐색시간 총합 : " << search_time << std::endl;
	std::cout << "정렬시간 총합 : " << sort_time << std::endl;
	std::cout << "전체 수행시간 : " << all_time << std::endl;
}