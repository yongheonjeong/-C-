#include <iostream>
#include <string>
 using namespace std;
 
 class CoffeeMaker {
	 int coffee, sugar, cream, water, cup;

	 bool chk_material() {
		 if (coffee <= 0 || sugar <= 0 || cream <= 0 || water <= 0 || cup <= 0) {
			 cout << "��ᰡ �����մϴ�." << endl;
			 return true;
		 }
		 else {
			 return false;
		 }
	 }

 public:
	 CoffeeMaker(int coffee = 3, int sugar = 3, int cream = 3, int water = 3, int cup = 3) {
		 this->coffee = coffee; this->sugar = sugar; this->cream = cream; this->water = water;
		 this->cup = cup;
	 }

	 void print() {
		 cout << "Coffee\r\t";  for (int i = 0; i < coffee; i++) cout << '*'; cout << endl;
		 cout << "Sugar\r\t";  for (int i = 0; i < sugar; i++) cout << '*'; cout << endl;
		 cout << "CREAM\r\t";  for (int i = 0; i < cream; i++) cout << '*'; cout << endl;
		 cout << "Water\r\t";  for (int i = 0; i < water; i++) cout << '*'; cout << endl;
		 cout << "Cup\r\t";  for (int i = 0; i < cup; i++) cout << '*';  cout << endl;
	 }

	 bool normalCoffee() {
		 if (chk_material()) {
			 return true;
		 }
		 else {
			 coffee--;  water--; cup--;
			 cout << "���ִ� ���� Ŀ�� ���Խ��ϴ� ~~" << endl;
			 print();
			 return false;
		 }
	 }


	 bool sugarCoffee() {
		 if (chk_material()) {
			 return true;
		 }
		 else {
			 coffee--; sugar--; water--; cup--;
			 cout << "���ִ� ���� Ŀ�� ���Խ��ϴ� ~~" << endl;
			 print();
			 return false;
		 }
	 }


	 bool blackCoffee() {
		 if (chk_material()) {
			 return true;
		 }
		 else {
			 coffee--; sugar--; water--; cup--; cream--;
			 cout << "���ִ� �� Ŀ�� ���Խ��ϴ� ~~" << endl;
			 print();
			 return false;
		 }
	 }


	 
};

int main() {
	int choice = 0;

	CoffeeMaker* c = new CoffeeMaker(); 
	
	cout << "-------��ǰ Ŀ�� ���Ǳ��մϴ�.-------" << endl;
	c->print();
	while (true) {
		cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4 >> ";
		cin >> choice;

		switch (choice) {
			case 0:
				if (c->normalCoffee()) {
					continue;
				}
				break;

			case 1:
				if (c->sugarCoffee()) {
					continue;
				}
				break;

			case 2:
				if (c->blackCoffee()) {
					continue;
				}
				break;
			case 3:
				delete c;
				c = new CoffeeMaker();
				cout << "��� ���� ä��ϴ�.~~" << endl;
				c->print();
				break;
			case 4:
				return 0;
				break;
			default:
				cout << " 0~4���� �������ּ���! " << endl;
				break;
		}
	}
}
