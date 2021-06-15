#include "Date.h"

Date::Date(int new_year=1,int new_month=1,int new_day=1){
  if(new_month < 1 || new_month > 12)
    throw runtime_error("Month value is invalid: " + to_string(new_month));
  else if(new_day < 1 || new_day > 31)
    throw runtime_error("Day value is invalid: " + to_string(new_day));

  year = new_year;
  month = new_month;
  day = new_day;
}

int Date::GetYear() const{return year;}
int Date::GetMonth() const{return month;}
int Date::GetDay() const{return day;}

private:
  int year;
  int month;
  int day;
};

// overloading the operator>> for class Date
// now we can input Date from std in like YYYY-MM-DD
istream& operator>>(istream& stream,Date& date){
  int new_year = 1;
  char div1,div2;
  string div3;
  string check;
  int new_month = 1;
  int new_day = 1;
  string str;

  if(stream){
    stream >> str;
    stringstream input(str);
    input >> new_year >> div1;
    input >> new_month >> div2;
    input >> new_day;
    if(input.rdbuf()->in_avail())
      input >> div3;
    if(input && div1 == '-' && div2 == '-' && div3 == "" && str.size() >= 5)
      date = Date(new_year,new_month,new_day);
    else
      throw runtime_error("Wrong date format: " + str);
  }
  return stream;
}

// now we can put Date to std out like YYYY-MM-DD
ostream& operator<<(ostream& stream,const Date& date){
  stream << setw(4) << setfill('0') << date.GetYear()
         << '-' << setw(2) << setfill('0') << date.GetMonth()
         << '-' << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

// comparison of two Dates
bool operator<(const Date& lhs, const Date& rhs){
  if(lhs.GetYear() < rhs.GetYear())
    return true;
  else if(lhs.GetYear() > rhs.GetYear())
    return false;
  else
    if(lhs.GetMonth() < rhs.GetMonth())
      return true;
    else if(lhs.GetMonth() > rhs.GetMonth())
      return false;
    else
      if(lhs.GetDay() < rhs.GetDay())
        return true;
      else
        return false;
}
