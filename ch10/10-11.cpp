#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
	string title, author;
	int year;
public:
	Book(int year , string title, string author );
	string getTitle() { return title; }
	string getAuthor() { return author; }
	int getYear() { return year; }
};
 
Book::Book(int year = 0, string title = "", string author = "") {
	this->title = title;
	this->author = author;
	this->year = year;
}


int main() {
	string title, author;
	int year,search_year;
	bool isFind = false;
	vector<Book> v; 
	cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�." << endl;
	
	while (true) {
		cout << "�⵵>>";
		cin >> year;
		cin.ignore(1);

		if (year == -1) {
			cout << "�� �԰�� å�� " << v.size() << "�Դϴ�." << endl;

			cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���>>";
			getline(cin, author);

			for (int i = 0; i < v.size(); i++) {
				if (v[i].getAuthor() == author) {
					cout << v[i].getYear() << "�⵵," << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
					isFind = true;
				}
			}
			if (!isFind) cout << "�ش��ϴ� ������ �����ϴ�." << endl;

			isFind = false;

			cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
			cin >> search_year;
			cin.ignore(1);
			

			for (int i = 0; i < v.size(); i++) {
				if (v[i].getYear() == search_year) {
					cout << v[i].getYear() << "�⵵," << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
					isFind = true;
				}
			}

			if (!isFind) cout << "�ش��ϴ� ������ �����ϴ�." << endl;
 
		}

		if (year == -1)
			continue;
		else {
			cout << "å�̸�>>";
			getline(cin, title);

			cout << "����>>";
			getline(cin, author);

			v.push_back(Book(year, title, author));
		}
	}
 
}