/*
hyundai kia genesis에서 하나를 선택하고, 선택한 브랜드의 차 라인업에서 차를 선택하는 코드다.
hyundai, kia, genesis class는 전부 hyundai_kia class에서 상속 받았다.
입출력 예시와 main 함수를 보고 hyundai_kia class, hyundai class, kia class, genesis class를 구현하라.
*/

//입출력 예시 1
//(출력)Avante Sonata Grandeur
//(출력)Soul Niro Sportage Sorento Stinger
//(출력)g70 g80 g90 gv70 gv80
//(출력)
//(출력)hyundai kia or genesis ?
//(입력)genesis
//(출력)g70 g80 g90 gv70 gv80 ? 
//(입력)gv70
//(출력)car available

//입출력 예시 2
//(출력)Avante Sonata Grandeur
//(출력)Soul Niro Sportage Sorento Stinger
//(출력)g70 g80 g90 gv70 gv80
//(출력)
//(출력)hyundai kia or genesis ?
//(입력)hyundai
//(출력)Avante Sonata Grandeur ?
//(입력)Elantra
//(출력)car unavailable

#include <iostream>
#include <string>
using namespace std;

class hyundai_kia {
public:
	string line;
	string word;
	string lineup() {
		return line;
	}

	int startIndex=0;
	int fIndex=0;
	int count = 0;
    /* find(' ',startIndex) 함수는 startIndex 부터 시작하여(첫 인덱스를 0부터카운트) 
    ' '에 해당하는 인덱스 값을 반환한다.
    substr(startIndex,count) 함수는 startIndex부터 시작하여(첫 인덱스를 0부터 카운트하여 startIndex 값)
    count 숫자만큼 글자를 읽어들인다.
    그러기 위해 find()함수가 반환한 ' '인덱스에 해당하는 값을 fIndex에 저장하고 
    count = fIndex - startIndex 공식을 이용하여 substring()함수로 ' '을 기준으로 구분하여 글자를 읽는다
    */
	string find(string choice) {
		while (true) {
			fIndex = line.find(' ' , startIndex);  // find()가 반환하는 값은 0부터 시작해서 해당되는 char의 인덱스 값
			count = fIndex - startIndex;
			if (line.substr(startIndex, count) == choice) {
				return "car available";
			}
			else {
				startIndex = fIndex+1;
			}
												// (fIndex는 0부터 시작한 인덱스값을 저장하기 때문에)
			if (startIndex >= line.length()) {  // 마지막fIndex+1 == line.length()
				
				return "car unavailable";
			}
		}
	}
};

class hyundai : public hyundai_kia {
	
public:	
	hyundai(string line="Avante Sonata Grandeur ") {
		this->line = line;
	}
	
};

class kia : public hyundai_kia{
public:	
	kia(string line= "Soul Niro Sportage Sorento Stinger ") {
		this->line = line;
	}
};

class genesis : public hyundai_kia{
public:	
	genesis(string line="g70 g80 g90 gv70 gv80 ") {
		this->line = line;
	}
};



//아래 main 함수는 수정 불가...
int main()
{
	//string test = "abc xyz"; //여기저기 힌트가 있다.
	//cout << test.find("abc") << " " << test.find("xyz") << " " <<  test.find("abcd") << endl;
	hyundai myhyundai;
	kia mykia;
	genesis mygenesis;
	cout << myhyundai.lineup() << endl; //"Avante Sonata Grandeur" 출력
	cout << mykia.lineup() << endl;     //"Soul Niro Sportage Sorento Stinger" 출력
	cout << mygenesis.lineup() << endl; //"g70 g80 g90 gv70 gv80" 출력
	cout << endl;

	
	string choice;
	hyundai_kia* ptr = 0;
	cout << "hyundai kia or genesis? " << endl; //브랜드 choice에 따라서 동적 객체 생성 
	cin >> choice;
	if (choice == "hyundai") {
		ptr = new hyundai;
	}
	else if (choice == "kia") {
		ptr = new kia;
	}
	else if (choice == "genesis") {
		ptr = new genesis;
	}
	else {
		cout << "not found" << endl;
	}
	if (ptr != 0) {
		cout << ptr->lineup() << "?" << endl;//브랜드 choice에 따라서 생성된 클라스의 자동차 lineup
		cin >> choice; //차 choice
		cout << ptr->find(choice) << endl;
		//차 choice가 lineup에 있으면 "car available"출력, 없으면 "car unavailable" 출력
		//힌트: lineup() 반환 값을 string에 넣어서 사용할수 있다
	}

	delete ptr;

	
	return 0;
}
