#include <string>
#include <iostream>
#include "helper.h"

struct Person {
private:
	std::string first_name;
	std::string last_name;
	int age;
	char invalidChars[13] = ":'[]*&^%$#@!";
	
	void validateAge(int a) {
		if (a > 0 && a < 150)
			this->age = a;
		else throw InvalidAge();
	}

	void validateName(std::string fn, std::string ln) {
		for (int i = 0; i < 13; ++i)
			if (containsChar(fn, invalidChars[i]) || containsChar(ln, invalidChars[i]))
				throw InvalidName(); 
			else {
				this->first_name = fn;
				this->last_name = ln;
			}
	}

public:
	struct InvalidName {};
	struct InvalidAge {};

	Person(std::string fn = "fn", std::string ln = "ln", int a = 1) {
		validateAge(a);
		validateName(fn,ln);
	}

	std::string getName() const {
		return first_name + " " + last_name;
	}

	int getAge() const {
		return age;
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << "Person named: " << p.getName() << ", " << p.getAge() << " years old." << std::endl;
}

Person operator>>(std::istream& is, Person& p) {
	std::cout << "First name: ";
	std::string fname;
	is >> fname;
	std::cout << "Last name: ";
	std::string lname;
	is >> lname;
	std::cout << "Age: ";
	int age = 0;
	is >> age;
	p = Person(fname,lname, age);
	return p;
}