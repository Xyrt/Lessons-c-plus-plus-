#include "Time.h"
#include <cstdio>
#include <iostream>
#include <iomanip>

Time::Time():
	Time(0, 0, 0)
{
}

Time::Time(int hours, int minutes, int seconds)
{
	m_hours = hours;
	m_minutes = minutes;
	m_seconds = seconds;
	Chek();
}

Time::Time(const char* time)
{
	if(sscanf(time, "%02i:%02i:%02i", &m_hours, &m_minutes, &m_seconds) != 3);
	{
		m_hours = 0;
		m_minutes = 0;
		m_seconds = 0;
		std::cout << "All fields = 0, because wrong input =)" << std::endl;
	}
}

Time::Time(Time const& time) : m_hours(time.m_hours), m_minutes(time.m_minutes), m_seconds(time.m_seconds)
{

}

Time& Time::operator = (Time const& time)
{
	if (this != &time)
	{
		m_hours = time.m_hours;
		m_minutes = time.m_minutes;
		m_seconds = time.m_seconds;
	}
	return *this;
}

int Time::GetHours() const
{
	return m_hours;
}

int Time::GetMinutes() const
{
	return m_minutes;

}

int Time::GetSeconds() const
{
	return m_seconds;
}

void Time::Set(int hours, int minutes, int seconds)
{
	m_hours = hours;
	m_minutes = minutes;
	m_seconds = seconds;
}

void Time::Check()
{
	while (m_seconds >= 60)
	{
		m_minutes++;
		m_seconds -= 60;
	}
	
	while (m_minutes >= 60)
	{
		m_hours++;
		m_minutes -= 60;
	}
	
	while (m_hours >= 24)
	{
		m_hours -= 24;
	}
}

void Time::AddSec(int value)
{
	m_seconds += value;
	Check();
}

void Time::AddMin(int value)
{
	m_minutes += value;
	Check();
}

void Time::AddHour(int value)
{
	m_seconds += value;
	Check();
}

void Time::Print() const
{
	std::cout << std::setw(2) << std::setfill('0') << m_hours << ":"
		<< std::setw(2) << std::setfill('0') << m_minutes << ":"
		<< std::setw(2) << std::setfill('0') << m_seconds;
}

bool Time::IsAm() const
{
	return(m_hours < 12);
}

int Time::GetSecondsFromMidnight() const
{
	return m_hours * 3600 + m_minutes * 60 + m_seconds;
}

bool Time::operator == (Time const& time) const
{
	return (m_hours == time.m_hours) && (m_minutes == time.m_minutes) && (m_seconds == time.m_seconds);
}

Time& Time::operator++()
{
	++m_seconds;
	Check();
	return *this;
}

Time Time::operator++(int)
{
	Time result = *this;
	m_seconds++;
	Check();
	return result;
}

bool Time::operator < (Time const& time) const
{
	return GetSecondsFromMidnight() < time.GetSecondsFromMidnight();
}

bool Time::operator >= (Time const& time) const
{
	return !(*this < time);
}

Time operator + (Time const& time1, Time const& time2)
{
	Time newTime(time1.GetHours() + time2.GetHours(),
		time1.GetMinutes() + time2.GetMinutes(),
		time1.GetSeconds() + time2.GetSeconds());
	return newTime;
}
