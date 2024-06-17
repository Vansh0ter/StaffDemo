#include "Employee.h"

Employee::Employee(int _id, std::string _name, int worktime,
    Positions _position) {
    id = _id;
    name = _name;
    position = _position;
    work_time = worktime;
}

int Employee::getId() {
    return id;
}

std::string Employee::getName() {
    return name;
}

Positions Employee::getPosition() {
    return position;
}

std::string Employee::stringPosition() {
    std::string positionToString;
    switch (position) {
    case senior_manager:
        positionToString = "senior_manager";
        break;
    case project_manager:
        positionToString = "project_manager";
        break;
    case team_leader:
        positionToString = "team_leader";
        break;
    case programmer:
        positionToString = "programmer";
        break;
    case tester:
        positionToString = "tester";
        break;
    case driver:
        positionToString = "driver";
        break;
    case cleaner:
        positionToString = "cleaner";
        break;
        return positionToString;
    }

Positions positionByString(std::string _stringPosition) {
    Positions result;
    while (_stringPosition.back() == ' ' || _stringPosition.back() == '\n') {
        _stringPosition.pop_back();
    }
    if (_stringPosition == "senior_manager") {
        result = Positions::senior_manager;
    }
    else if (_stringPosition == "project_manager") {
        result = Positions::project_manager;
    }
    else if (_stringPosition == "team_leader") {
        result = Positions::team_leader;
    }
    else if (_stringPosition == "programmer") {
        result = Positions::programmer;
    }
    else if (_stringPosition == "tester") {
        result = Positions::tester;
    }
    else if (_stringPosition == "driver") {
        result = Positions::driver;
    }
    else if (_stringPosition == "cleaner") {
        result = Positions::cleaner;
    }
    return result;
}


int Employee::getWorktime() {
    return worktime;
}

int Employee::getPayment() {
    return payment;
}