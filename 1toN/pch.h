// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가

#include <iostream>
#include <array>
#include <algorithm> 
#include <random> //random_device
#include <numeric> //iota

#include <chrono>

//대기 배열을 전부 출력합니다.
template <class Array>
void show_wating(const Array& array);

//인터페이스 내용을 전부 출력합니다.
template <class InterfaceArray>
void show_interface(const InterfaceArray&);

//인터페이스 내용을 전부 출력합니다.
template <class InterfaceArray>
void show_interface(const InterfaceArray& array2)
{
	for (auto& arr : array2)
	{
		for (auto& e : arr)
			std::wcout << e << ' ';
		std::wcout << '\n';
	}
}

//대기 배열을 전부 출력합니다.
template <class Array>
void show_wating(const Array& array)
{
	for (auto& e : array)
	{
		std::wcout << e << ' ';
	}
}

namespace chrono = std::chrono;

//시간 측정용 클래스입니다.
class Timer
{
public:
	void start(); //타이머를 가동합니다.
	void stop(); //타이머를 중단합니다.
	void clear(); //값을 초기화합니다.
public:
	template<class seconds_t>
	long long get_time() const; //측정 메서드의 템플릿입니다.
	long long get_nano() const; //나노세컨드 단위입니다.
	long long get_micro() const; //마이크로세컨드 단위입니다.
	long long get_milli() const; //밀리세컨드 단위입니다.
	long long get_seconds() const; //세컨드 단위입니다.
	long long get_minutes() const; //분 단위입니다.
	long long get_hours() const; //시간 단위입니다.
private:
	chrono::time_point<chrono::system_clock> start_point; //시작지점입니다.
	chrono::time_point<chrono::system_clock> stop_point; //중단지점입니다.
public:
	Timer() = default;
	Timer(const Timer&) = default;
	Timer(Timer&&) = default;
	Timer& operator= (const Timer&) = default;
	Timer& operator= (Timer&&) = default;
	virtual ~Timer() = default;
};

template<class seconds_t>
inline long long Timer::get_time() const
{
	return chrono::duration_cast<seconds_t>(stop_point - start_point).count();
	return 0;
}

#endif //PCH_H
