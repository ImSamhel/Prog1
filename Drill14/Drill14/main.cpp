#include <iostream>

class pureB1 {
public:
	virtual void pvf() = 0;
};

class B1 : public pureB1 {
public:
	virtual void vf() {
		std::cout << "B1::vf()" << std::endl;
	}

	void f() {
		std::cout << "B1::f()" << std::endl;
	}

	void pvf() {
		std::cout << "B1::pvf()" << std::endl;
	}

};

class D1 : public B1 {
public:
	void vf() {
		std::cout << "D1::vf()" << std::endl;
	}

	void f() {
		std::cout << "D1::f()" << std::endl;
	}
};

class D2 : public D1 {
public:
	void pvf() {
		std::cout << "D2::pvf()" << std::endl;
	}
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
	std::string data = "D21";

	void pvf() {
		std::cout << data << std::endl;
	}
};

class D22 : public B2 {
	int data = 22;

	void pvf() {
		std::cout << data << std::endl;
	}
};

void f(B2& b2) {
	b2.pvf();
}

int main() {
	std::cout << "B1 Object" << std::endl;
	B1 objectB1;
	objectB1.vf();
	objectB1.f();
	objectB1.pvf();

	std::cout << "D1:B1 Object" << std::endl;
	D1 objectD1;
	objectD1.vf();
	objectD1.f(); // nincs felülirva de hivhatjuk a B1 public functionjei közül
	objectD1.pvf();

	std::cout << "B1 Reference" << std::endl;
	B1& referenceB1 = objectD1;
	referenceB1.vf();
	referenceB1.f();
	referenceB1.pvf();

	std::cout << std::endl;
	//Repeat

	std::cout << "B1 2. Object" << std::endl;
	B1 objectB1_2;
	objectB1_2.vf();
	objectB1_2.f();
	objectB1_2.pvf();

	std::cout << "D1:B1 2. Object" << std::endl;
	D1 objectD1_2;
	objectD1_2.vf();
	objectD1_2.f(); // nincs felülirva de megírtuk a D1 saját f() functionjét
	objectD1_2.pvf();

	std::cout << "B1 2. Reference" << std::endl;
	B1& referenceB1_2 = objectD1_2;
	referenceB1_2.vf();
	referenceB1_2.f();
	referenceB1_2.pvf();

	std::cout << std::endl;
	//D2

	D2 objectD2;
	objectD2.f();
	objectD2.vf();
	objectD2.pvf();

	std::cout << std::endl;
	//B2 D21 D22

	D21 objectD21;
	D22 objectD22;

	f(objectD21);
	f(objectD22);
}