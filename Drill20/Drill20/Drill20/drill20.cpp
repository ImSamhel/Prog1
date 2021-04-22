#include "std_lib_facilities.h"

namespace drill {
	template<typename Iter1, typename Iter2> Iter2& copy(Iter1 f1, Iter1 e1, Iter2 f2) {
		while (f1 != e1) {
			*f2 = *f1;
			f1++;
			f2++;
		}
		return f2;
	}
	template<typename T>void cout(T& az) {
		for (auto ez : az)
			std::cout << ez << ' ';
		std::cout << std::endl;
	}
}

int main() {
	array<int,10> arr{0,1,2,3,4,5,6,7,8,9};
	vector<int> vekivek{arr.begin(),arr.end()};
	list<int> lst{arr.begin(),arr.end()};

	cout << "Originals:" << std::endl;
	cout << "Array: "; drill::cout(arr);
	cout << "Vector: "; drill::cout(vekivek);
	cout << "List: "; drill::cout(lst);
	cout << std::endl;

	array<int, 10> arr2 = arr;
	vector<int> vekivek2 = vekivek;
	list<int> lst2 = lst;

	cout << "Copies:" << std::endl;
	cout << "Array2: "; drill::cout(arr2);
	cout << "Vector2: "; drill::cout(vekivek2);
	cout << "List2: "; drill::cout(lst2);
	cout << std::endl;
	/*
	* copy constructor:
	* 
	array<int, 10> arr2(arr);
	vector<int> vekivek2(vekivek);
	list<int> lst2(lst);
	*/

	list<int>::iterator it = lst.begin();

	for (int i = 0; i < 10; ++i) {
		arr[i] += 2;
		vekivek[i] += 3;
		*it += 5;
		advance(it,1);
	}

	cout << "Advanced:" << std::endl;
	cout << "Array: "; drill::cout(arr);
	cout << "Vector: "; drill::cout(vekivek);
	cout << "List: "; drill::cout(lst);
	cout << std::endl;

	drill::copy(arr.begin(), arr.end(), vekivek.begin());
	drill::copy(lst.begin(), lst.end(), arr.begin());

	cout << "Array copied into the Vector and the List copied into the Array:" << std::endl;
	cout << "Array: "; drill::cout(arr);
	cout << "Vector: "; drill::cout(vekivek);
	cout << "List: "; drill::cout(lst);
	cout << std::endl;

	auto veki3 = find(vekivek, 3);
	auto lst27 = find(lst, 27);
	int veki3p = distance(vekivek.begin(), veki3);
	int lst27p = distance(lst.begin(), lst27);

	if (veki3p != vekivek.size()) {
		cout << "Number 3 in the vector is on the: " << veki3p << ". position." << std::endl;
	}
	else cout << "Number 3 is not in the vector." << std::endl;
	cout << std::endl;
	if (lst27p != lst.size()) {
		cout << "Number 27 in the list is on the: " << lst27p << ". position." << std::endl;
	} 
	else cout << "Number 27 is not in the list." << std::endl;
	
	return 0;
}