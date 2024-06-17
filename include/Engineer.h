#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include <iostream>
#include "Personal.h"
#include "Interfaces.h"
#include "Manager.h"


class Project;

class Engineer : public Personal, public ProjectBudget {
protected:
    Project* project;

public:
    Engineer(int _id, std::string _name,
        Positions _position, int _salary,
        Project* _project);
    int calcBudgetPart(float _part,
        int _budget);
    void calc();
    Project* getProject();
};


class Programmer : public Engineer {
public:
    Programmer(int _id, std::string _name,
        Positions _position, int _salary,
        Project* _project);
    int calcProAdditions();
};

class Tester : public Engineer {
public:
    Tester(int _id, std::string _name,
        Positions _position, int _salary,
        Project* _project);
    int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(int _id, std::string _name, int work_time,
        Positions _position, int _salary,
        Project* _project);
    void calc();
    int calcHeads();
};


#endif  //  INCLUDE_ENGINEER_H_