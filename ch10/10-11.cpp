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
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
	
	while (true) {
		cout << "년도>>";
		cin >> year;
		cin.ignore(1);

		if (year == -1) {
			cout << "총 입고된 책은 " << v.size() << "입니다." << endl;

			cout << "검색하고자 하는 저자 이름을 입력하세요>>";
			getline(cin, author);

			for (int i = 0; i < v.size(); i++) {
				if (v[i].getAuthor() == author) {
					cout << v[i].getYear() << "년도," << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
					isFind = true;
				}
			}
			if (!isFind) cout << "해당하는 도서가 없습니다." << endl;

			isFind = false;

			cout << "검색하고자 하는 년도를 입력하세요>>";
			cin >> search_year;
			cin.ignore(1);
			

			for (int i = 0; i < v.size(); i++) {
				if (v[i].getYear() == search_year) {
					cout << v[i].getYear() << "년도," << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
					isFind = true;
				}
			}

			if (!isFind) cout << "해당하는 도서가 없습니다." << endl;
 
		}

		if (year == -1)
			continue;
		else {
			cout << "책이름>>";
			getline(cin, title);

			cout << "저자>>";
			getline(cin, author);

			v.push_back(Book(year, title, author));
		}
	}
 
}