//
// Created by Yusuf Pisan on 4/2/18.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

  // add
  TimeSpan operator+(const TimeSpan &ts) const;

  // subtract
  TimeSpan operator-(const TimeSpan &ts) const;

  // check equality
  bool operator==(const TimeSpan &ts) const;

  // check if not equal
  bool operator!=(const TimeSpan &ts) const;

  // multiply timespan by an unsigned number
  TimeSpan operator*(unsigned int number) const;

  // TODO(student)
  // to add operator+=, operator-=, operator<, operator>, operator<=, operator>=

  TimeSpan operator+=(const TimeSpan &ts);

  TimeSpan operator-=(const TimeSpan &ts);

  TimeSpan operator*=(unsigned int number);

  bool operator<(const TimeSpan &ts) const;

  bool operator>(const TimeSpan &ts) const;

  bool operator<=(const TimeSpan &ts) const;
 
  bool operator>=(const TimeSpan &ts) const;

  // hour component of timespan
  int getHour() const;

  // minute component of timespan
  int getMinute() const;

  // second component of timespan
  int getSecond() const;

  // true if timespan is 0 or larger
  bool isPositive() const;

private:
  int hours;
  int mins;
  int secs;
  bool positive;

  int deConstructHelp(const TimeSpan &ts) const;
  int deConstructSelf() const;
  void reConstructSelf(int intTime);
};

#endif // ASS2_TIMESPAN_H
