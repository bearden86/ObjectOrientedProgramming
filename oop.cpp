#include <iostream>
using std::string;
using namespace std;


class Employee {
private:
	string Name;
	string Company;
	int Age;

public: // access modifiers (private, protected, public)
	void setName(string name) { //setter
		Name = name;
	}
	string getName() { //getter
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	void setAge(int age) {
		Age = age;
	}
	string getAge() {
		return Age;
	}

	// class method to define behavior
	void introduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;

	}
	// constructor creates the object by receiving parameters when each employee is declared
	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
};

int main() {
	Employee employee1 = Employee("Matt", "LM", 37);
	employee1.introduceYourself(); // invokes the class method

	Employee employee2("John", "Amazon", 35);
	employee2.introduceYourself();

	employee1.setAge(39);
	cout << employee1.getName() << " is " << employee1.getAge() << " years old" << endl;
}