#include <string>
#include "std_lib_facilities.h"

template<typename T> struct S {
private:
	T val;
public:
	S(T a) { val = a; }
	T& get() const;
	T& get();
	S<T> operator=(const T&);
};

template<typename T> T& S<T>::get() const {
	return S::val;
}

template<typename T> T& S<T>::get() {
	return S::val;
}

template<typename T> S<T> S<T>::operator=(const T& t) {
	S::val = t.get();
	return this;
}

template<typename T> void read_val(T& v) {
	T t;
	std::cin >> t;
	v = t;
}
int main() {
	vector<int> vekivek{ 1, 2, 3 };

	S<int> Int(2);
	S<char> Char('c');
	S<double> Double(2.69);
	S<std::string> String("besencz");
	S<vector<int>> Vector(vekivek);

	std::cout << (Int.get()) << std::endl;
	std::cout << (Char.get()) << std::endl;
	std::cout << (Double.get()) << std::endl;
	std::cout << (String.get()) << std::endl;
	for (int k : Vector.get()) std::cout << k << std::endl;

	read_val(Int.get());
	read_val(Char.get());
	read_val(Double.get());
	read_val(String.get());

	std::cout << (Int.get()) << std::endl;
	std::cout << (Char.get()) << std::endl;
	std::cout << (Double.get()) << std::endl;
	std::cout << (String.get()) << std::endl;

	return 0;
}