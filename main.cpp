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
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:

  Date(int new_year=1,int new_month=1,int new_day=1){
    if(new_month < 1 || new_month > 12)
      throw runtime_error("Month value is invalid: " + to_string(new_month));
    else if(new_day < 1 || new_day > 31)
      throw runtime_error("Day value is invalid: " + to_string(new_day));

    year = new_year;
    month = new_month;
    day = new_day;
  }

  int GetYear() const{return year;}
  int GetMonth() const{return month;}
  int GetDay() const{return day;}

private:
  int year;
  int month;
  int day;
};

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

ostream& operator<<(ostream& stream,const Date& date){
  stream << setw(4) << setfill('0') << date.GetYear()
         << '-' << setw(2) << setfill('0') << date.GetMonth()
         << '-' << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

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

class Database {
public:
  int checkEvent(const vector<string>& list, const string& arg){
    for(int i(0);i<list.size();i++)
      if(list[i] == arg)
        return i;
    return -1;
  }

  void AddEvent(const Date& date, const string& event){
    if(checkEvent(db[date],event) == -1){
      db[date].push_back(event);
      sort(db[date].begin(),db[date].end());
    }

  }

  bool DeleteEvent(const Date& date, const string& event){
    int ce = checkEvent(db[date],event);
    if(ce == -1)
      throw runtime_error("Event not found");

    db[date].erase(db[date].begin()+ce);
    return true;
  }

  int  DeleteDate(const Date& date){
    int N = 0;
    if(db.count(date) != 0){
      N = db[date].size();
      db.erase(date);
    }
    return N;
  }

  vector<string> Find(const Date& date) const{
    if(db.count(date) != 0)
      return db.at(date);
    else
      return vector<string>();
  }

  void Print() const{
    for(const auto& i: db){
      for(const string& j: i.second)
        cout << i.first << " " << j << endl;
    }
  }

  int size(){
    return db.size();
  }
private:
  map<Date,vector<string>> db;
};

int main() {
  Database db;

  string command;
  string c;
  string event;
  Date date;

  while (getline(cin, command)) {
    stringstream ss;
    try{
      event = "";
      c = "";
      ss << command;
      ss >> c;

      if(c == "Add"){
        ss >> date >> event;
        db.AddEvent(date,event);
      }
      else if(c == "Del"){
        ss >> date;
        ss >> event;
        if(event != ""){
          db.DeleteEvent(date,event);
          cout << "Deleted successfully" << endl;
        }
        else
          cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
        }
        else if(c == "Find"){
          ss >> date;

          if(db.Find(date).size() != 0)
            for(const auto& iter: db.Find(date))
              cout << iter << endl;
        }
        else if(c == "Print"){
          db.Print();
        }
        else if(c != "")
          cout << "Unknown command: " << c << endl;
      }catch(const exception& ex){
        cout << ex.what() << endl;
      }

  }
  return 0;
}
