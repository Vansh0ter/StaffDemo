#include "Personal.h"

Personal::Personal(int _id, std::string _name, int work_time, 
    Positions _position, int _salary) : Employee(_id, _name, work_time, _position), salary(_salary) {
}

void Personal::calc() {
    payment = calc_base_salary(salary, work_time) + calc_bonus_salary();
}
 int Personal::calc_base_salary(int _salary,
    int work_time_salary) {
    return work_time_salary * _salary;
}


Driver::Driver(int _id, std::string _name,int work_time,
    Positions _position, int _salary) : Personal(_id, _name, work_time, _position, _salary) {
}

Cleaner::Cleaner(int _id, std::string _name,
    Positions _position, int work_time, int _salary) : Personal(_id, _name, work_time,  _position, _salary) {
}