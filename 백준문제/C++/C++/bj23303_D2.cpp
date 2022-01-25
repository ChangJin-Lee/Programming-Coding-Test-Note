#include <iostream>
#include <string>

using namespace std;
// it is namespace
bool checkstr(string strings) {
	for (int i = 0; i < strings.length() - 1; i++) {
		if ((strings[i] == 'D' || strings[i] == 'd') && strings[i + 1] == '2') {
			return true;
		}
	}
	return false;
}

int main() {
	string strings;
	getline(cin, strings); // cin >> strings; why use getline? -> because cin is ended when encountered blank
	if (checkstr(strings)) cout << "D2";
	else cout << "unrated";
}