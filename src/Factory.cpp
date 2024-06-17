#include "Factory.h"


std::vector<Employee*> StaffFactory::makeStaff(std::string _projectsFile,
    std::string _employeesFile) {
    std::ifstream fproj(_projectsFile);
    std::vector <Project*> companyProjects;
    std::string input;
    while (getline(fproj, input)) {
        unsigned int pos = input.find(':');
        unsigned int id = std::stoi(input.substr(0, pos));
        input = input.substr(pos + 1, input.size() - pos - 1);
        unsigned int budget = std::stoi(input);
        Project* project = new Project(id, budget);
        companyProjects.push_back(project);
    }
    fproj.close();
    std::ifstream femp(_employeesFile);
    std::vector <Employee*> staff;
    while (getline(femp, input)) {
        unsigned int pos = input.find(':');
        unsigned int id = std::stoi(input.substr(0, pos));
        input = input.substr(pos + 1, input.size() - pos - 1);
        pos = input.find(':');
        std::string name = input.substr(0, pos);
        input = input.substr(pos + 1, input.size() - pos - 1);
        pos = input.find(':');
        std::string stringPosition = input.substr(0, pos);
        input = input.substr(pos + 1, input.size() - pos - 1);
        Positions position = positionByString(stringPosition);
        pos = input.find(':');
        unsigned int salary;
        Project* project;
        std::vector <Project*> projects;
        if (position == programmer || position == tester ||
            position == team_leader || position == driver || position == cleaner) {
            salary = std::stoi(input.substr(0, pos));
            input = input.substr(pos + 1, input.size() - pos - 1);
            pos = input.find(':');
        }

        if (position == programmer || position == tester ||
            position == team_leader) {
            int projectId = std::stoi(input.substr(0, pos));
            for (auto p : companyProjects) {
                if (projectId == p->id) {
                    project = p;
                }
            }
        }
        else if (position == project_manager || position == senior_manager) {
            while (pos != std::string::npos) {
                int projectId = std::stoi(input.substr(0, pos));
                for (auto p : companyProjects) {
                    if (projectId == p->id) {
                        projects.push_back(p);
                    }
                }
                input = input.substr(pos + 1, input.size() - pos - 1);
                pos = input.find(':');
            }
        }
        if (position == senior_manager) {
            SeniorManager* employee = new SeniorManager(id, name,
                position, projects);
            staff.push_back(employee);
        }
        else if (position == project_manager) {
            ProjectManager* employee = new ProjectManager(id, name,
                position, projects);
            staff.push_back(employee);
        }
        else if (position == team_leader) {
            TeamLeader* employee = new TeamLeader(id, name,
                position, salary, project);
            staff.push_back(employee);
        }
        else if (position == programmer) {
            Programmer* employee = new Programmer(id, name,
                position, salary, project);
            staff.push_back(employee);
            project->number_of_employees++;
        }
        else if (position == tester) {
            Tester* employee = new Tester(id, name,
                position, salary, project);
            staff.push_back(employee);
            project->number_of_employees++;
        }
        else if (position == driver) {
            Driver* employee = new Driver(id, name,
                position, salary);
            staff.push_back(employee);
        }
        else if (position == cleaner) {
            Cleaner* employee = new Cleaner(id, name,
                position, salary);
            staff.push_back(employee);
        }
    }
    femp.close();
    return staff;
}