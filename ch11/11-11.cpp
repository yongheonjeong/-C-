#include <iostream>
#include <string>
 using namespace std;
 
 istream& pos(istream& cin) {
	 cout << "À§Ä¡´Â? ";
	 return cin;
}

int main() {
	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;
}
