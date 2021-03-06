#include "pch.h"

//#define _PRINT_MODE //출력 여부를 결정합니다.


void prototype()
{
Timer timer;
Timer all_timer;

long long all_time = 0;
long long search_time=0;

all_timer.start();

	int n = 1; //현재 값

	//인터페이스 5x5 배열
	std::array<std::array<int, side>, side> interface_array;

	//대기용 배열
	std::array<int, InterfaceSize> wating_array{ 0, }; //0으로 초기화

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
					//std::cout << e <<" ";
					i++;
				}
			}

			show_interface(interface_array);
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
			
			while (*min_pos == 0) 
				min_pos++;
			
			//인터페이스 최소값의 위치를 기억할 포인터입니다.

			/*최소값을 가져옵니다.*/
timer.start();
			//현재 인터페이스에서 제일 작은걸 찾습니다.
			for (auto& arr : interface_array)
			{
				for (auto& e : arr)
				{
					if (e != 0)
						if ((*min_pos) > e) //더 작은게 있으면 장소 기억
							min_pos = &e;
				}
			}
timer.stop();
search_time += timer.get_nano();
			std::cout << "최소값: " << *min_pos << std::endl << std::endl << std::endl;

			

			//빼고 대기중인 값 삽입			

			//대기배열에 값이 MAX보다 큰 경우 0 삽입
			if (wating_array[i] > MAX)
				*min_pos = 0;
			//대기배열에 값이 MAX아래일 경우에만 인터페이스에 값 변경
			else
				*min_pos = wating_array[i]; //대기중인 값 저장

			show_interface(interface_array);
		}
	}

all_timer.stop();
all_time = all_timer.get_nano();

	std::cout << "최소값 탐색시간 총합 : " << search_time << std::endl;
	std::cout << "전체 수행시간 : " << all_time << std::endl;
}

