#include "Manager.h"

Project::Project(int _id, int _budget, int number_of_employees) : id(_id), budget(_budget), employees(number_of_employees) {
}

float Project::calcPart(Positions _position) {
    int weightSum = 5 * Project::number_of_employees; ///????? not working
        + 6 * people + 10 + 18 + 20;
    //  10 teamleader, 18 projectmanager, 20 seniormanager
    float part;
    switch (_position) {
    case senior_manager:
        part = static_cast<float> (20.0 / weightSum);
        break;
    case project_manager:
        part = static_cast<float> (18.0 / weightSum);
        break;
    case team_leader:
        part = static_cast<float> (10.0 / weightSum);
        break;
    case programmer:
        part = static_cast<float> (6.0 / weightSum);
        break;
    case tester:
        part = static_cast<float> (5.0 / weightSum);
        break;
    }
    return part * 0.8;
}

ProjectManager::ProjectManager(unsigned int _id, std::string _name,
    Positions _position, std::vector <Project*> _projects) : Employee(_id, _name, _position) {
    projects = _projects;
}

void ProjectManager::calc() {
    for (auto p : projects) {
        payment += calcBudgetPart(p->calc_part(position), p->budget);
    }
    payment += calcProAdditions() + calcHeads();
}

int ProjectManager::calcHeads() {
    int people = 0;
    for (auto p : projects) {
        people += p->number_of_employees;
    }
    return people * 15;
}

int ProjectManager::calcBudgetPart(float _part,
    int _budget) {
    return static_cast <int> (_part * _budget);
}

int ProjectManager::calcProAdditions() {
    unsigned int add = 0;
    for (auto p : projects)
        add += static_cast <unsigned int> (calcBudgetPart(0.07, p->budget));
    return add;
}

std::vector<Project*> ProjectManager::getProjects() {
    return projects;
}

SeniorManager::SeniorManager(int _id, std::string _name, Positions _positon,
    std::vector<Project*> _projects) : ProjectManager(_id, _name, _position, _projects) {}