#include "DataBase.h"

int Database::checkEvent(const vector<string>& list, const string& arg){
  for(int i(0);i<list.size();i++)
    if(list[i] == arg)
      return i;
  return -1;
}

void Database::AddEvent(const Date& date, const string& event){
  if(checkEvent(db[date],event) == -1){
    db[date].push_back(event);
    sort(db[date].begin(),db[date].end());
  }
}

bool Database::DeleteEvent(const Date& date, const string& event){
  int ce = checkEvent(db[date],event);
  if(ce == -1)
    throw runtime_error("Event not found");

  db[date].erase(db[date].begin()+ce);
  return true;
}

int  Database::DeleteDate(const Date& date){
  int N = 0;
  if(db.count(date) != 0){
    N = db[date].size();
    db.erase(date);
  }
  return N;
}

vector<string> Database::Find(const Date& date) const{
  if(db.count(date) != 0)
    return db.at(date);
  else
    return vector<string>();
}

void Database::Print() const{
  for(const auto& i: db){
    for(const string& j: i.second)
      cout << i.first << " " << j << endl;
  }
}

int Database::size(){
  return db.size();
}
