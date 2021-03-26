#include "Person.h"
#include <std_lib_facilities.h>

int main() {
	try {
		Person someone("Goofy"," with LastName", 63);
		std::cout << someone;

		Person otherone;
		std::cout << "\nNew person data request:\n";
		std::cin >> otherone;
		std::cout << otherone;

		int request = 3;
		vector<Person> personVec;

		for (int i = 0; i < request; ++i) {
			Person p;
			std::cout << "\nNew person data request:\n";
			std::cin >> p;
			personVec.push_back(p);
		}
		std::cout << "\nRequested members' data:\n";
		for (int i = 0; i < personVec.size(); ++i)
			std::cout << personVec[i];

		return 0;
	}
	catch (Person::InvalidAge) {
		std::cout << "Invalid age input!";
		return 1;
	}
	catch (Person::InvalidName) {
		std::cout << "Invalid name input!";
		return 2;
	}
};