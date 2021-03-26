#include <string>
#include <iostream>

class Person {
	std::string name;
	int age;
public:
	Person(std::string n = "someone", int a = 0) {
		if (a > 0 && a < 150)
			this->age = a;
		else error("Invalid age input.");
		
		this->name = n;
	}

	std::string getName() const {
		return name;
	}

	int getAge() const {
		return age;
	}

	friend std::istream& operator>>(std::istream& is, Person& p);
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << "Person named: " << p.getName() << ", is " << p.getAge() << " years old." << std::endl;
}

std::istream& operator>>(std::istream& is, Person& p) {
	cout << "Name: ";
	is >> p.name;
	cout << "Age: ";
	is >> p.age;
	return is;
}