#include <iostream>
#include <string>
 using namespace std;
 
 class Phone {
	 string name;
	 string telnum;
	 string address;
 public:
	 Phone(string name = "", string telnum = "", string address = "") {
		 this->name = name;
		 this->telnum = telnum;
		 this->address = address;
	 }

	 friend ostream& operator<<(ostream& cout, Phone p);
	 friend istream& operator>>(istream& cin, Phone& p);
};

 ostream& operator<<(ostream& cout, Phone p) {
	 cout << "(" << p.name << "," << p.telnum << "," << p.address << ")";
	 return cout;
 }

 istream& operator>>(istream& cin, Phone& p) {
	 cout << "�̸�:";
	 getline(cin, p.name);
	 cout << "��ȭ��ȣ:";
	 getline(cin, p.telnum);
	 cout << "�ּ�:";
	 getline(cin, p.telnum);
	 return cin;
 }

int main() {
	
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}
