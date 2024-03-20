#include <iostream>
using namespace std;


int main() {

	char ch;

	while ((ch = cin.get()) != EOF) {
	
		if (ch == ';') {
			cout.put('\n');
			cin.ignore(10,'\n');
		}
		else cout.put(ch);

	}
}
