#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <string>
#include <vector>
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"

class ProjectManager : public Employee,
    public Heading, public ProjectBudget {
protected:
    std::vector<Project*> projects;

public:
    ProjectManager(int _id, std::string _name,
        Positions _position, std::vector<Project*> _projects);
    void calc();
    virtual int calcBudgetPart(float _part, int _budget);
    virtual int calcProAdditions();
    virtual int calcHeads();
    std::vector<Project*> getProjects();
};

class SeniorManager : public ProjectManager {
public:
    SeniorManager(int _id, std::string _name,
        Positions _position, std::vector<Project*> _projects);
};

#endif  //  INCLUDE_MANAGER_H_