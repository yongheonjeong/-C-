#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

class word {
	char rchar;
	int index;
public:
	word(char rchar, int index = 0) {
		this->rchar = rchar;
		this->index = index;
	}
	char getChar() { return rchar; }
	int getIndex() { return index; }
};

int main() {
	srand((unsigned)time(NULL));

	string line;
	string* ptr;
	vector<string> v;
	vector<word> charv;
	int wordsSize = 0;
	char rchar;
	int index = 0;
	bool isIn = false;
	int count = 0;
	char input;

	ifstream fin("words.txt");

	while (getline(fin, line)) {
		v.push_back(line);
		wordsSize++;
	}
	

	cout << setw(30) << setfill('-') << "" << endl;
	cout << setw(15) << setfill(' ') << "지금부터 행맨 게임을 시작합니다!" << endl;
	cout << setw(30) << setfill('-') << "" << endl;
	
	while (true) {
		ptr = &v[rand() % wordsSize];
		line = *ptr;

		while (true) {		//랜덤단어 집어넣기
			if (charv.size() >= 2) {
				isIn = false;
				break;
			}

			index = rand() % line.length();
			rchar = line[index];
			for (int i = 0; i < charv.size(); i++) {
				if (charv[i].getChar() == rchar) {
					isIn = true;
					break;
				}
			}

			if (!isIn) {
				charv.push_back(word(rchar,index));
			}
		}

		while (true) {	// 출력 
			if (charv.size() <= 0) {
				cout << line << endl;
				break;
			}

			if (count >= 5) {
				cout << "5번 실패하였습니다." << endl;
				cout << line << endl;
				count = 0;
				break;
			}

			isIn = false;

			for (int i = 0; i < line.length(); i++) {	
				for (int j = 0; j < charv.size(); j++) {
					if (charv[j].getIndex() == i)
					{
						isIn = true;
						break;
					}
				}
				if (!isIn) {
					cout.put(line[i]);
					
				}
				else {
					cout.put('-');
					isIn = false;
				}

			}cout << endl;


			cout << ">>";
			cin >> input;
			cin.ignore(1);
			count++;

			for (int i = 0; i < charv.size(); i++) {
				if (charv[i].getChar() == input) {
					charv.erase(charv.begin() + i);
					break;
				}
			}
		}

		cout << "Next(y/n)? ";
		cin >> input;
		cin.ignore(1);

		if (input == 'n') {
			break;
		}
		else if(input == 'y'){
			count = 0;
			charv.clear();
		}
		else {
			break;
		}
	}
	
	fin.close();

}