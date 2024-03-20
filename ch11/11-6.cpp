#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int num = 0;
	cout.setf(ios::left); // flag 
	cout << setw(15) << "Number" << setw(15) << "Sqaure" << setw(15) << "Sqaure Root" << endl;	 // manipulator
 
	for (int i = 0; i < 10; i++) {
		cout.fill('_'); // function call 
		cout.precision(3);
		cout << setw(15) << num << setw(15) << num * num << setw(15) << sqrt(num) << endl;
		num += 5;
	}
}
