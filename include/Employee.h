#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>

enum Positions {
    programmer,
    team_leader,
    project_manager,
    senior_manager,
    cleaner,
    driver,
    tester,
};

class Project {
 public:
    Project(int _id, int _budget, int number_of_employees);
    int get_num_of_employees() const;
    int get_budget() const;
    int id;
    int budget;
    int number_of_employees;
};

class Employee {
 public:
    Employee(int _id, std::string _name,
             int worktime, Positions _position);
    int getId();
    std::string getName();
    Positions getPosition();
    std::string stringPosition();
    int getWorktime();
    int getPayment();
    virtual int calc_salary() = 0;
    virtual void print_info() = 0;

 private:
    int id;
 protected:
    Positions position;
    int payment;
    int work_time;
    std::string name;
    std::vector<std::string> enum_print = {"programmer",
                                           "team_leader",
                                           "project_manager",
                                           "senior_manager",
                                           "cleaner",
                                           "driver",
                                           "tester"};
};
Positions positionByString(std::string _stringPosition);

#endif  // INCLUDE_EMPLOYEE_H_
