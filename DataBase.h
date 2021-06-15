#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <exception>
#include <stdexcept>

using namespace std;


class Database{
  map<Date,vector<string>> db;
public:
  int checkEvent(const vector<string>& list, const string& arg);

  void AddEvent(const Date& date, const string& event);

  bool DeleteEvent(const Date& date, const string& event)l

  int  DeleteDate(const Date& date);

  vector<string> Find(const Date& date) const;

  void Print() const;

  int size();
};

#endif
