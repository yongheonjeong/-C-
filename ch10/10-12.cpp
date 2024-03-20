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

	v.push_back(Word("�Ʊ�", "Baby"));
	v.push_back(Word("�ΰ�", "human"));
	v.push_back(Word("��ȸ", "Society"));
	v.push_back(Word("����", "Picture"));
	v.push_back(Word("��", "Bear"));
	v.push_back(Word("����", "dall"));
	v.push_back(Word("����", "lover"));
	v.push_back(Word("�ŷ�", "trade"));
	v.push_back(Word("����", "animal"));

	cout << "**** ���� ���� �׽�Ʈ�� �����մϴ�. ****" << endl;

	while (true) {
		cout << "���� ����: 1, ���� �׽�Ʈ: 2, ���α׷� ����:�� ��Ű >> ";
		cin >> choice;
		cin.ignore(1);
		
		switch (choice) {
		case 1:
			cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
			while (true) {
				cout << "���� >>";
				getline(cin, eng);
				if (eng == "exit") break;
				cout << "�ѱ� >>";
				getline(cin, kor);
				v.push_back(Word(kor, eng));
			}
			break;
		case 2:
			cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� �����մϴ�." << endl;
			while (true) {

				question = &v[rand() % v.size()];
				answer = question->getKor();

				cout << question->getEng() << "?" << endl;

				while (true) { // 3���� ����ֱ�

					if (pbv.size() >= 3) {
						isIn = false; // ���� ������ ���� ���� 
						break;
					}
					else {

						prw = &v[rand() % v.size()];
						for (int i = 0; i < pbv.size(); i++) { // ���� ������ pbv�ȿ� ����ְų� 
							if (prw->getKor() == pbv[i].getKor()) {
								isIn = true;
								break;
							}
						}

						if (prw == question) { // question, ������ ���ų� �ϸ� �ǳʶ�
							isIn = true;
						}

						if (!isIn) {
							pbv.push_back(*prw);

						}
						isIn = false; // �� ���� �ȿ��� 
					}
				}

				pbv.push_back(*question); //���������� �������� ������ ���� ����ֱ� 

				//------------------------ ���� �����ϱ� 

				while (true) {  // ������ 4������ ���� �����ϱ� 
					if (count >= 4) break; // count = 0, 1, 2, 3  ( 4���� )

					prw = &pbv[rand() % 4];  // pbv ���;ȿ� �ִ� ���� �߿� �����ϰ� �ϳ� �̱�

					for (int i = 0; i < 4; i++) {    // ���� ������ �ε��� ���ϱ� 
						if (pbv[i].getKor() == prw->getKor()) {
							fIndex = i; //  chk �迭�� �̿���, ���� �ߺ��� ȸ���ϱ� ���� �迭 ���� 
							break;
						}
					}

					if (chk[fIndex] == 0) // �ߺ����� �Ÿ���, �ļ�, �ش� �ε����� chk�Լ� ���� 0 �̸� ������, 1�̸� ������
					{
						chk[fIndex]++;  // count �� 0 ���� �ʱ�ȭ�� 
						cout << "(" << 1 + count << ")" << " " << prw->getKor() << " ";

						if (answer == prw->getKor()) { // ���� ����
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



				//���� ������ ���� �ʱ�ȭ 
				{
					pbv.clear();
					for (int i = 0; i < 4; i++) chk[i] = 0;
					count = 0; // ���� ������ ���� �� �ʱ�ȭ �Ǿ���� 
				} 

				 
			}// case 2 while close 
			break;
		case 3:
			return 0;
		}//switch close
	}

}