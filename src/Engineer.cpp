#include "Engineer.h"

Engineer::Engineer(int _id, std::string _name, int work_time,
    Positions _position, int _salary,
    Project* _project)
    : Personal(_id, _name,work_time, _position, _salary), project(_project) {
}

void Engineer::calc() {
    payment = calc_base_salary(salary, worktime) +
        calcBudgetPart(project->calcPart(position), project->budget) +
        calcProAdditions();
}

int Engineer::calcBudgetPart(float _part,
    int _budget) {
    return static_cast <int> (_part * _budget);
}

Project* Engineer::getProject() {
    return project;
}

Tester::Tester(int _id, std::string _name,
    Positions _position, int _salary,
    Project* _project)
    : Engineer(_id, _name,
        _position, _salary, _project) {
}

int Tester::calcProAdditions() {
    int add = 0;
    add = calcBudgetPart(0.005, project->budget);
    return add;
}

Programmer::Programmer(int _id, std::string _name,
    Positions _position, int _salary,
    Project* _project)
    : Engineer(_id, _name,
        _position, _salary, _project) {
}

int Programmer::calcProAdditions() {
    int add = 0;
    int bonusTime = work_time > 40 ? work_time - 40 : 0;
    float part = bonusTime * 0.002;
    add = calcBudgetPart(part, project->budget);
    return add;
}

TeamLeader::TeamLeader(int _id, std::string _name,int work_time,
    Positions _position, int _salary,
    Project* _project)
    : Programmer(_id, _name, work_time,
        _position, _salary, _project) {
}

int TeamLeader::calcHeads() {
    unsigned int people = 0;
    people += project->testers + project->programmers;
    return people * 5;
}

void TeamLeader::calc() {
    payment = calc_base_salary(salary, work_time) +
        calcBudgetPart(project->calcPart(position), project->budget) +
        calcProAdditions() + calcHeads();
}