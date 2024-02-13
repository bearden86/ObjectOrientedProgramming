#include <iostream>
using std::string;
using namespace std;

class abstractEmployee { //abstraction demonstration
	virtual void askForPromotion() = 0; //void = return type, virtual makes it obligatory function

};

class Employee: abstractEmployee { //add abstraction method to take effect
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
		if(age >= 18) //special rules... check/validation rule to only allow 18+ for age
		Age = age;
	}
	int getAge() {
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
	void askForPromotion() { //must provide implementation
		if (Age > 30) //rule that any employee over 30 gets a promotion
			cout << Name << " got promoted!" << endl;
		else
			cout << Name << ", sorry, NO promotion for you!" << endl;
	}
};

class Developer: Employee { //creating derived (child) class, which will inherit all properties of Employee (parent)
public:
	string faveProgramLanguage;
	Developer(string name, string company, int age, string faveProgramLanguage) {} //constructor inherits properties from Employee AND Developer classes
		:Employee(name, company, age) {
		FaveProgramLanguage = faveProgramLanguage;
	}
};

int main() {
	Employee employee1 = Employee("Matt", "LM", 37);
	employee1.introduceYourself(); // invokes the class method

	Employee employee2("John", "Amazon", 29);
	employee2.introduceYourself();

	employee1.setAge(15); //this change won't be applied due to the validation rule on line 26
	cout << employee1.getName() << " is " << employee1.getAge() << " years old" << endl;

	employee1.askForPromotion(); //calls the abstraction to determine if employee1 should be promoted
	employee2.askForPromotion();

	Developer d = Developer("Jared", "AWS", 28, "C++");
}