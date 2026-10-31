
#include <iostream>
#include <string>

// Represents an employee and its data
class Employee {
public:
    Employee(std::string name, double salary)
        : name(name), salary(salary) {}

    const std::string& getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

private:
    std::string name;
    double salary;
};

// Responsible for salary calculations
class SalaryCalculator {
public:
    double calculate(const Employee& employee) const {
        return employee.getSalary() * 1.10;
    }
};

// Responsible for generating employee reports
class ReportGenerator {
public:
    void generate(const Employee& employee,
                  double calculatedSalary) const {
        std::cout << "\n--- Employee Report ---\n";
        std::cout << "Name: " << employee.getName() << '\n';
        std::cout << "Base salary: " << employee.getSalary() << '\n';
        std::cout << "Calculated salary: " << calculatedSalary << '\n';
    }
};

// Responsible for employee persistence
class EmployeeRepository {
public:
    void save(const Employee& employee) const {
        std::cout << "\nSaving employee: "
                  << employee.getName() << '\n';

        // Database persistence logic would go here
    }
};

int main() {
    Employee employee("Fani", 50000.0);

    SalaryCalculator calculator;
    double salary = calculator.calculate(employee);

    ReportGenerator reportGenerator;
    reportGenerator.generate(employee, salary);

    EmployeeRepository repository;
    repository.save(employee);

    return 0;
}
