#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <sstream>

using namespace std;

class Date{
  int year;
  int month;
  int day;
public:
  Date(int new_year=1,int new_month=1,int new_day=1);

  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;
};

istream& operator>>(istream& stream,Date& date);

ostream& operator<<(ostream& stream,const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

#endif
