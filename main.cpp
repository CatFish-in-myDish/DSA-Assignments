#include <iostream>
#include <string>
#include <sstream>
#include "Schedule.h"

using namespace std;

int main() {
  int n;
  string line;
  getline(cin, line);
  n = stoi(line);

  Schedule taskList;

  for (int i = 0; i < n; i++) {
    getline(cin, line);

    if (line.empty()) {
      continue;
    }

    stringstream ss(line);
    string op;
    ss >> op;

    if (op == "A") {
      string id, name, type;
      ss >> id >> name >> type;

      if (id.empty() || name.empty() || type.empty()) {
        cout << "Invalid input for Add operation." << endl;
        continue;
      }

      taskList.addTask(id, name, type);

    } else if (op == "R") {
      string id;
      ss >> id;

      if (id.empty()) {
        cout << "Invalid input for Remove operation." << endl;
        continue;
      }

      taskList.removeTask(id);

    } else if (op == "P") {
      taskList.print();

    } else if (op == "REV") {
      taskList.printReverse();

    } else {
      cout << "Invalid operation." << endl;
    }
  }

  return 0;
}

int main2() {
  int n;
  string line;
  getline(cin, line);
  
}