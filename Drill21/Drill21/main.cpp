#include "std_lib_facilities.h"
#include <map>

struct Item {
	string name;
	int iid;
	double value;
	Item(string s, int id = 1, double val = 1.0) {
		this->name = s;
		this->iid = id;
		this->value = val;
	}
};

template<typename T> void printValues(const T& az) {
	for (const auto& ez : az)
		cout << ez << endl;
	cout << endl;
}

std::ostream& operator<<(std::ostream& os, const Item& i) { os << i.name << ' ' << i.iid << ' ' << i.value << std::endl; return os; }

template<typename T> void vectorDrill(vector<T>& vi) {
	printValues(vi);

	std::sort(vi.begin(), vi.end(), [](Item i1, Item i2) { return i1.name < i2.name; });
	cout << "Sorted by name:" << std::endl;
	printValues(vi);

	std::sort(vi.begin(), vi.end(), [](Item i1, Item i2) { return i1.iid < i2.iid; });
	cout << "Sorted by iid:" << std::endl;
	printValues(vi);

	std::sort(vi.begin(), vi.end(), [](Item i1, Item i2) { return i1.value > i2.value; });
	cout << "Sorted by value:" << std::endl;
	printValues(vi);

	vi.insert(vi.end(), Item("horse shoe", 99, 12.34));
	vi.insert(vi.end(), Item("Canon S400", 99, 12.34));
	cout << "With inserted values:" << std::endl;
	printValues(vi);

	vi.erase(std::find_if(vi.begin(), vi.end(), [](Item i1) { return i1.name == "python"; }));
	vi.erase(std::find_if(vi.begin(), vi.end(), [](Item i1) { return i1.name == "snake"; }));
	cout << "With 2 elements erased" << std::endl;
	printValues(vi);
}

template<typename T> void listDrill(list<T>& li) {
	cout << endl << "List:" << endl;

	printValues(li);

	li.sort([](Item i1, Item i2) { return i1.name < i2.name; });
	cout << "Sorted by name:" << std::endl;
	printValues(li);

	li.sort([](Item i1, Item i2) { return i1.iid < i2.iid; });
	cout << "Sorted by iid:" << std::endl;
	printValues(li);

	li.sort([](Item i1, Item i2) { return i1.value > i2.value; });
	cout << "Sorted by value:" << std::endl;
	printValues(li);

	li.insert(li.end(), Item("horse shoe", 99, 12.34));
	li.insert(li.end(), Item("Canon S400", 99, 12.34));
	cout << "With inserted values:" << std::endl;
	printValues(li);

	li.erase(std::find_if(li.begin(), li.end(), [](Item i1) { return i1.name == "python"; }));
	li.erase(std::find_if(li.begin(), li.end(), [](Item i1) { return i1.name == "snake"; }));
	cout << "With 2 elements erased" << std::endl;
	printValues(li);
}

template<typename T, typename V> void printMap(const map<T, V>& m) { for (const auto& kek : m) cout << kek.first << ' ' << kek.second << endl; }
template<typename T, typename V> void eraseMap(map<T, V>& m) { m.erase(m.begin(), m.end()); }

template<typename T, typename V> void readMap(int size, std::map<T, V>& m) {
	T t;
	V v;
	for (int i = 0; i < size; ++i) {
		cout << "Write in a key: ";
		cin >> t;
		cout << "Write in a value: ";
		cin >> v;
		m[t] = v;
	}
}

template<typename T, typename V> void mapDrill(std::map<T, V>& m) {
	cout << "Map:" << endl;
	printMap(m);
	eraseMap(m);
	cout << "Map erased!" << endl;
	readMap(10, m);
	printMap(m);

	int sum = 0;
	for (const auto k : m) sum += k.second;
	cout << "Sum of values in the map: " << sum << endl;

	map <int, string> mis;
	for (const auto k : m) mis[k.second] = k.first;
	cout << "New map: " << endl;
	printMap(mis);
}

int main() {
	std::ifstream input("items.txt");

	std::cout << std::endl << "Vector:" << std::endl;

	vector<Item> vi;
	std::list<Item> li;
	map<std::string, int> msi;

	std::string n;
	int id;
	double val;

	while (input >> n >> id >> val) { 
		vi.push_back(Item(n, id, val));
		li.push_back(Item(n, id, val));
		msi[n] = id;
	}

	vectorDrill(vi);
	listDrill(li);
	mapDrill(msi);

	vector<double> vd;
	double in;
	std::ifstream input2("floats.txt");
	while (input2 >> in) vd.push_back(in);
	cout << "vd:" << endl;
	printValues(vd);

	vector<int> vi1;
	for (double d : vd) vi1.push_back(d);
	cout << "vi1:" << endl;
	printValues(vi1);

	cout << "Pairs: " << endl;

	for (int i = 0; i < vd.size(); i++) {cout << vd[i] << ' ' << vi1[i];}

	double sumVd = .0;
	int sumVi = 0;

	for (double d : vd) sumVd += d;
	for (int i : vi1) sumVi += i;

	cout << "Sum of vd: " << sumVd;
	cout << "Sum of vi1: " << sumVi;
	double difference = sumVd - sumVi;
	cout << "Difference: " << difference;

	reverse(vd.begin(), vd.end());
	cout << "Reversed vd:" << endl;
	printValues(vd);

	double mean = sumVd / vd.size();
	cout << "vd mean: " << mean << endl;

	vector<double> vd2;
	for (double d : vd) {
		if (d < mean)
			vd2.push_back(d);
	}

	std::sort(vd2.begin(), vd2.end(), [](double d, double d2) { return d > d2; });
	cout << "vd2:" << endl;
	printValues(vd2);

	return 0;
}