#include <vector>
#include <random>
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
    StaffFactory factory;
    std::vector<Employee*> staff =
        factory.makeStaff("../data/Projects.txt", "../data/Employees.txt");
    for (auto e : staff) {
        e->calc_salary();
        //  calculating income for every employee
    }
    return 0;
}