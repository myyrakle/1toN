// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일입니다. 성공하려면 컴파일이 필요합니다.

#include "pch.h"



void Timer::start()
{
	start_point = chrono::system_clock::now();
}

void Timer::stop()
{
	stop_point = chrono::system_clock::now();
}

void Timer::clear()
{
	start_point = chrono::time_point<chrono::system_clock>::min();
	stop_point = chrono::time_point<chrono::system_clock>::min();
}

long long Timer::get_nano() const
{
	return get_time<chrono::nanoseconds>();
}

long long Timer::get_micro() const
{
	return get_time<chrono::microseconds>();
}

long long Timer::get_milli() const
{
	return get_time<chrono::milliseconds>();
}

long long Timer::get_seconds() const
{
	return get_time<chrono::seconds>();
}

long long Timer::get_minutes() const
{
	return get_time<chrono::minutes>();
}

long long Timer::get_hours() const
{
	return get_time<chrono::hours>();
}