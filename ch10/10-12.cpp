#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
 

using namespace std;

class Word {
	string eng, kor;
public:
	Word(string kor, string eng) { this->eng = eng; this->kor = kor; }
	string getEng() { return eng; }
	string getKor() { return kor; }
};


int main() {
	srand((unsigned)time(NULL));

	Word* question;
	Word* prw;  // pointer random word
 
	vector<Word>v;
	vector<Word>pbv; // problem vector 

	string answer="";

	string eng = "";
	string kor = "";

	int chk[4] = { 0 };
	int fIndex = 0;
	int answerNo = 0;
	int input = 0;

	int choice = 0;

	bool isIn = false;
	int count = 0;

	v.push_back(Word("아기", "Baby"));
	v.push_back(Word("인간", "human"));
	v.push_back(Word("사회", "Society"));
	v.push_back(Word("사진", "Picture"));
	v.push_back(Word("곰", "Bear"));
	v.push_back(Word("인형", "dall"));
	v.push_back(Word("애인", "lover"));
	v.push_back(Word("거래", "trade"));
	v.push_back(Word("동물", "animal"));

	cout << "**** 영어 어휘 테스트를 시작합니다. ****" << endl;

	while (true) {
		cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료:그 외키 >> ";
		cin >> choice;
		cin.ignore(1);
		
		switch (choice) {
		case 1:
			cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
			while (true) {
				cout << "영어 >>";
				getline(cin, eng);
				if (eng == "exit") break;
				cout << "한글 >>";
				getline(cin, kor);
				v.push_back(Word(kor, eng));
			}
			break;
		case 2:
			cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;
			while (true) {

				question = &v[rand() % v.size()];
				answer = question->getKor();

				cout << question->getEng() << "?" << endl;

				while (true) { // 3문제 집어넣기

					if (pbv.size() >= 3) {
						isIn = false; // 다음 문제를 위한 설정 
						break;
					}
					else {

						prw = &v[rand() % v.size()];
						for (int i = 0; i < pbv.size(); i++) { // 뽑힌 랜덤이 pbv안에 들어있거나 
							if (prw->getKor() == pbv[i].getKor()) {
								isIn = true;
								break;
							}
						}

						if (prw == question) { // question, 문제와 같거나 하면 건너뜀
							isIn = true;
						}

						if (!isIn) {
							pbv.push_back(*prw);

						}
						isIn = false; // 한 문제 안에서 
					}
				}

				pbv.push_back(*question); //마지막으로 정답으로 선정된 문제 집어넣기 

				//------------------------ 지문 구성하기 

				while (true) {  // 선정된 4문제로 지문 구성하기 
					if (count >= 4) break; // count = 0, 1, 2, 3  ( 4문제 )

					prw = &pbv[rand() % 4];  // pbv 벡터안에 있는 보기 중에 랜덤하게 하나 뽑기

					for (int i = 0; i < 4; i++) {    // 뽑힌 벡터의 인덱스 구하기 
						if (pbv[i].getKor() == prw->getKor()) {
							fIndex = i; //  chk 배열을 이용해, 문제 중복을 회피하기 위해 배열 구함 
							break;
						}
					}

					if (chk[fIndex] == 0) // 중복문제 거르기, 꼼수, 해당 인덱스의 chk함수 값이 0 이면 미출제, 1이면 출제됨
					{
						chk[fIndex]++;  // count 는 0 으로 초기화됨 
						cout << "(" << 1 + count << ")" << " " << prw->getKor() << " ";

						if (answer == prw->getKor()) { // 정답 설정
							answerNo = count + 1;
						}
						count++;

					}
					else {
						continue;
					}

				}

				cout << ":>";
				cin >> input;
				cin.ignore(1);
				cout << endl;

				if (input > 4 || input <= 0) {
					break;
				}

				if (answerNo == input) {
					cout << "Excellent !!" << endl;
				}
				else {
					cout << "No. !!" << endl;
				}



				//다음 문제를 위한 초기화 
				{
					pbv.clear();
					for (int i = 0; i < 4; i++) chk[i] = 0;
					count = 0; // 다음 문제를 위해 꼭 초기화 되어야함 
				} 

				 
			}// case 2 while close 
			break;
		case 3:
			return 0;
		}//switch close
	}

}