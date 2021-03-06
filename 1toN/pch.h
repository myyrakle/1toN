#pragma once

// TODO: 여기에 미리 컴파일하려는 헤더 추가

#include <iostream>
#include <array>
#include <algorithm> 
#include <random> //random_device
#include <numeric> //iota

#include <chrono>

constexpr auto side = 5; //인터페이스 한 변의 길이
constexpr auto MAX = 100; //최대 입력값 개수
constexpr auto InterfaceSize = side * side; //인터페이스의 총 크기


//인터페이스 내용을 전부 출력합니다.
template <class InterfaceArray>
void show_interface(const InterfaceArray& array2)
{
	for (auto& arr : array2)
	{
		for (auto& e : arr)
		{
			if (e == INT_MAX)
				std::wcout << 0 << ' ';
			else
				std::wcout << e << ' ';
		}
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
}