#include<iostream>
using namespace std;

class Time
{
private:
	int hour, minute, second;

public:
	Time();
	Time(int h);
	Time(int h, int m);
	Time(int h, int m, int s);
	Time(const Time &t);

	void display();

	bool operator ==(Time &t);  //时间的比较
	bool operator !=(Time &t);
	bool operator > (Time &t);
	bool operator >=(Time &t);
	bool operator <(Time &t);
	bool operator <=(Time &t);

	Time &operator +=(int s);  //时间增加若干秒
	Time &operator -=(int s);  //时间减少若干秒

	Time operator ++(int);  //时间增加一秒
	Time operator --(int);  //时间减少一秒

	int operator -(Time &t);  //两个时间相差的秒数
};

Time::Time()
{
	hour = minute = second = 0;
}

Time::Time(int h)
{
	hour = h;
	minute = second = 0;
}

Time::Time(int h, int m)
{
	hour = h;
	minute = m;
	second = 0;
}

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

Time::Time(const Time &t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}

void Time::display()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

bool Time::operator ==(Time &t)
{
	if (hour == t.hour && minute == t.minute && second == t.second)
		return true;
	return false;
}

bool Time::operator !=(Time &t)
{
	return !(*this == t);
}

bool Time::operator > (Time &t)
{
	if (hour>t.hour)
		return true;
	else if (hour == t.hour && minute>t.minute)
		return true;
	else if (hour == t.hour && minute == t.minute && second>t.second)
		return true;
	else
		return false;
}

bool Time::operator >=(Time &t)
{
	return *this > t || *this == t;
}

bool Time::operator <(Time &t)
{
	return !(*this >= t);
}

bool Time::operator <=(Time &t)
{
	return !(*this > t);
}

Time &Time::operator +=(int s)
{
	second += s;
	while (second >= 60)
	{
		second -= 60;
		minute++;
	}
	while (minute >= 60)
	{
		minute -= 60;
		hour++;
	}
	while (hour >= 24)
		hour -= 24;
	return *this;
}

Time &Time::operator -=(int s)
{
	second -= s;
	while (second<0)
	{
		second += 60;
		minute--;
	}
	while (minute<0)
	{
		minute += 60;
		hour--;
	}
	while (hour<0)
		hour += 24;
	return *this;
}

Time Time::operator ++(int)     //对Time t，操作为：t++
{
	Time t = *this;
	*this += 1;
	return t;
}

Time Time::operator --(int)
{
	Time t = *this;
	*this -= 1;
	return t;
}

int Time::operator -(Time &t)
{
	int s1 = hour * 3600 + minute * 60 + second;
	int s2 = t.hour * 3600 + t.minute * 60 + t.second;
	return s2 - s1;
}

int main()
{
	Time T(6, 6, 6);
	T += 59;
	T++;
	Time T2(T);
	T2.display();
}
