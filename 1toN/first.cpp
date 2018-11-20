//#define _PRINT_MODE //출력 여부를 결정합니다.

#include "pch.h"


template <class Array>
void bubble_sort(Array& arr)
{
	for (int unsorted_until = arr.size() - 1;
		unsorted_until != 0; unsorted_until--)
	{
		//0이 찍혀있으면.. 무시
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

	//인터페이스 5x5 배열
	std::array<std::array<int, side>, side> interface_array;

	int n = 1; //현재 값

	//대기용 배열
	std::array<int, InterfaceSize> wating_array{ 0, }; //0으로 초기화

	//인덱스용 배열
	std::array<int*, InterfaceSize> indexing_array{ nullptr, };

	//일단 초기화
	int i = 0;
	for(auto& arr : interface_array)
		for (auto& e : arr)
		{
			indexing_array[i] = &e;
			i++;
		}

	//정렬한다.
	bubble_sort(indexing_array);

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
					//std::cout << e << " ";
					i++;
				}
			}
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
			auto min_pos = &(interface_array[0][0]);

			while (*min_pos == 0) {
				min_pos++;
			}
			//인터페이스 최소값의 위치를 기억할 포인터입니다.

			/*최소값을 가져옵니다.*/
timer.start();
			//현재 인터페이스에서 제일 작은걸 찾습니다.
			min_pos = indexing_array[0];
timer.stop(); 
time += timer.get_nano();
			//빼고 대기중인 값 삽입

#ifdef _PRINT_MODE
			std::cout << *min_pos << std::endl;
#endif

			//대기배열에 값이 MAX보다 큰 경우 0 삽입
			if (wating_array[i] > MAX)
				*min_pos = 0;
			//대기배열에 값이 MAX아래일 경우에만 인터페이스에 값 변경
			else
				*min_pos = wating_array[i]; //대기중인 값 저장

			//저장했으니까 정렬
timer.start();
			std::rotate(indexing_array.begin(), //맨 앞이 0이 됐으니까 한칸 앞으로 밀기
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

	std::cout << "최소값 탐색시간 총합 : " << time << std::endl;
	std::cout << "정렬시간 총합 : " << sort_time << std::endl;

	return 0;
}

