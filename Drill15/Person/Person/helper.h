#include <string>

bool containsChar(std::string string, const char that) {
	for (int i = 0; i < string.length(); ++i)
		if (string[i] == that)
			return true;
	return false;
}