#include <iostream>
#include <iomanip>
#include <cctype>
 using namespace std;

 // ascicode 0~255 

int main() {
	int ascii = 0;
	cout.setf(ios::left);

	for (int i = 0; i < 4; i++) {
		cout << setw(8) << "dec" << setw(8) << "hexa" << setw(8) << "char";
	}cout << endl;

	for (int i = 0; i < 4; i++) {
		cout << setw(8) << "---" << setw(8) << "----" << setw(8) << "----";
	}cout << endl;

	while (ascii <= 255) {
		for (int i = 0; i < 4; i++) {
			cout << setw(8) << dec << ascii << setw(8) << hex << ascii;
			if (isprint(ascii)) {
				cout << setw(8) << (char)ascii;
			}
			else {
				cout << setw(8) << '.';
			}
			ascii++;
		}cout << endl;
	}
	 
}
