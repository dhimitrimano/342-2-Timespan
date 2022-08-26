#include <cassert>
#include <iostream>
#include <sstream>

#include "timespan.h"

using namespace std;

// testing constructor
void test1() {
  TimeSpan ts(1, 20, 30);
  stringstream ss;
  ss << ts;
  assert(ss.str() == "1:20:30");

  TimeSpan ts2(4, -20, -90);
  ss.str("");
  ss << ts2;
  assert(ss.str() == "3:38:30");

  TimeSpan ts3(1.5, 30.5, -90);
  ss.str("");
  ss << ts3;
  assert(ss.str() == "1:59:00");

  TimeSpan ts4(0, 0.07, 0);
  ss.str("");
  ss << ts4;
  assert(ss.str() == "0:00:04");
  cout << "test1 complete" << endl;
}

// testing equality, addition, subtraction, multiplication
void test2() {
  TimeSpan ts(1, 20, 30);
  TimeSpan ts2(1, 20, 30);
  TimeSpan ts3(0, 0, 0);
  assert(ts == ts2);
  assert(!(ts != ts2));
  assert(ts != ts3);
  assert((ts + ts + ts) == (ts2 * 3));
  assert((ts * 5) == (ts2 * 4) + ts2);
  assert((ts * 5) == (ts2 * 6) - ts2);
  assert((ts + ts - ts) == ((ts2 * 2) - ts));
  assert((ts - ts2) == ts3);
  assert((ts3 * 5) == ts3);
  cout << "test2 complete" << endl;
}

void test3() {
  TimeSpan ts0(0, 0, 0);
  TimeSpan ts1(0, 0, 10);
  TimeSpan ts2 = ts0 - ts1;
  assert(ts1.isPositive() && !ts2.isPositive());
  stringstream ss;
  ss << ts2;
  assert(ss.str() == "-0:00:10");
  cout << "test3 complete" << endl;
}

void test4() {
  TimeSpan ts1(10, 20, 30);
  TimeSpan ts2(40, 50, 60);
  TimeSpan ts3(51, 11, 30);
  assert(ts1 < ts2);
  assert(ts3 > ts1);
  assert(ts2 <= ts2);
  assert(ts2 <= ts3);
  assert(ts3 >= ts3);
  assert(ts3 >= ts2);
  ts1 += ts2;
  stringstream ss;
  ss << ts1;
  assert(ts1 == ts3);
  ts3 -= ts2;
  assert(ts3 != ts1);
  TimeSpan ts4(0, -2, -3);
  TimeSpan ts5(0, -2, -4);
  TimeSpan ts6(0, 2, -3);
  assert(ts4 != ts5);
  assert(ts4 != ts6);
  ss.str("");
  ss << ts4;
  assert(ss.str() == "-0:02:03");
  ss.str("");
  ss << ts6;
  assert(ss.str() == "0:01:57");
  ts4 += ts5;
  ts6 += ts4;
  assert(ts6 >= ts4);
  TimeSpan ts7(-1.5, 10, -93);
  ss.str("");
  ss << ts7;
  assert(ss.str() == "-1:21:33");
  TimeSpan ts8(1.5, -10, 93.4);
  ts2 = ts4;
  ts4 += ts7;
  ts4 -= ts8;
  assert(ts4 + (ts8 * 2) == ts2);
  ts1 = ts5;
  ts1 *= 7;
  assert(ts1 == (ts5 * 7));
  TimeSpan ts9(0, -3, 0);
  ts9 -= ts9;
  TimeSpan ts0(0, 0, 0);
  assert(ts9 == ts0);
  TimeSpan ts10(0, 0, -60);
  ss.str("");
  ss << ts10;
  assert(ss.str() == "-0:01:00");
  TimeSpan ts11(0, -60);
  ss.str("");
  ss << ts11;
  assert(ss.str() == "-1:00:00");
  cout << "test4 complete" << endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  cout << "Done." << std::endl;
  return 0;
}