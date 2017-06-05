#pragma once

class Time
{
public:
	Time();
	Time(int hours, int minutes, int seconds);
	//~Time();
	Time(const char* time);
	Time(Time const& time);

	Time& operator=(Time const& time);

	int GetHours() const;
	int GetMinutes() const;
	int GetSeconds() const;

	void Set(int hours, int minutes, int seconds);
	
	void AddSec(int value);
	void AddMin(int value);
	void AddHour(int value);

	void Print() const;
	bool IsAm() const;

	int GetSecondsFromMidnight() const;
	bool operator == (Time const& time) const;

	Time& operator++();
	Time operator++(int);

	bool operator < (Time const& time) const;
	bool operator >= (Time const& time) const;

private:
	int m_hours;
	int m_minutes;
	int m_seconds;

	void Check();
};
