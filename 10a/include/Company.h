#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;

public:
    Employee(const std::string& name, const std::string& position, double salary)
        : name(name), position(position), salary(salary) {}

    const std::string& getName() const {
        return name;
    }

    const std::string& getPosition() const {
        return position;
    }

    double getSalary() const {
        return salary;
    }

    void display() const {
        std::cout << name << " - " << salary << " PLN" << std::endl;
    }
};

class Company {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(const std::string& name, const std::string& position, double salary) {
        employees.emplace_back(name, position, salary);
    }

    void displayEmployees() const {
        for (const auto& employee : employees) {
            employee.display();
        }
    }

    void sortEmployees(const std::function<bool(const Employee&, const Employee&)>& compareFunc) {
        std::sort(employees.begin(), employees.end(), compareFunc);
    }

    void removeEmployees(const std::function<bool(const Employee&)>& removeFunc) {
        employees.erase(std::remove_if(employees.begin(), employees.end(), removeFunc), employees.end());
    }
};
