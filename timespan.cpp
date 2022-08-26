//
// Created by Yusuf Pisan on 4/2/18.
//

#include "timespan.h"

int hours;
int mins;
int secs;
bool positive;

ostream &operator<<(ostream &out, const TimeSpan &ts) {
  if (!ts.isPositive()) {
    out << "-";
  }
  out << ts.getHour() << ":";
  if (ts.getMinute() < 10) {
    out << 0;
  }
  out << ts.getMinute() << ":";
  if (ts.getSecond() < 10) {
    out << 0;
  }
  out << ts.getSecond();
  return out;
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
  double doubleTime = (hour * 3600) + (minute * 60) + second;
  positive = doubleTime >= 0;
  if (!positive) {
    doubleTime *= -1;
  }
  if (doubleTime > 0.0) {
    doubleTime += .5;
  } else {
    doubleTime -= .5;
  }
  int intTime = static_cast<int>(doubleTime);
  hours = intTime / 3600;
  intTime -= hours * 3600;
  mins = intTime / 60;
  intTime -= mins * 60;
  secs = intTime;
}

void TimeSpan::reConstructSelf(int intTime) {
  positive = intTime >= 0;
  if (!positive) {
    intTime *= -1;
  }
  hours = intTime / 3600;
  intTime -= hours * 3600;
  mins = intTime / 60;
  intTime -= mins * 60;
  secs = intTime;
}

int TimeSpan::deConstructHelp(const TimeSpan &ts) const {
  if (ts.isPositive()) {
    return (ts.getHour() * 3600) + ts.getMinute() * 60 + ts.getSecond();
  }
  return 0 - ((ts.getHour() * 3600) + ts.getMinute() * 60 + ts.getSecond());
}

int TimeSpan::deConstructSelf() const {
  if (positive) {
    return (hours * 3600) + mins * 60 + secs;
  }
  return 0 - ((hours * 3600) + mins * 60 + secs);
}

// hour component
int TimeSpan::getHour() const { return this->hours; }

// minute component
int TimeSpan::getMinute() const { return this->mins; }

// second component
int TimeSpan::getSecond() const { return this->secs; }

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const { return this->positive; }

// add
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  TimeSpan tsSum(0, 0, deConstructSelf() + deConstructHelp(ts));
  return tsSum;
}

// subtract
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  TimeSpan tsSub(0, 0, deConstructSelf() - deConstructHelp(ts));
  return tsSub;
}

// multiply with an integer
TimeSpan TimeSpan::operator*(unsigned int number) const {
  TimeSpan tsLarg(0, 0, deConstructSelf() * static_cast<int>(number));
  return tsLarg;
}

TimeSpan TimeSpan::operator+=(const TimeSpan &ts) {
  reConstructSelf(deConstructSelf() + deConstructHelp(ts));
  return *this;
}

TimeSpan TimeSpan::operator-=(const TimeSpan &ts) {
  reConstructSelf(deConstructSelf() - deConstructHelp(ts));
  return *this;
}

TimeSpan TimeSpan::operator*=(unsigned int number) {
  reConstructSelf(deConstructSelf() * number);
  return *this;
}

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const {
  return deConstructSelf() == deConstructHelp(ts);
}

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  return deConstructSelf() != deConstructHelp(ts);
}

bool TimeSpan::operator<(const TimeSpan &ts) const {
  return deConstructSelf() < deConstructHelp(ts);
}

bool TimeSpan::operator>(const TimeSpan &ts) const {
  return deConstructSelf() > deConstructHelp(ts);
}

bool TimeSpan::operator<=(const TimeSpan &ts) const {
  return deConstructSelf() <= deConstructHelp(ts);
}

bool TimeSpan::operator>=(const TimeSpan &ts) const {
  return deConstructSelf() >= deConstructHelp(ts);
}