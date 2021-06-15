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
