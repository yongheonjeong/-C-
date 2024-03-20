/*
hyundai kia genesis���� �ϳ��� �����ϰ�, ������ �귣���� �� ���ξ����� ���� �����ϴ� �ڵ��.
hyundai, kia, genesis class�� ���� hyundai_kia class���� ��� �޾Ҵ�.
����� ���ÿ� main �Լ��� ���� hyundai_kia class, hyundai class, kia class, genesis class�� �����϶�.
*/

//����� ���� 1
//(���)Avante Sonata Grandeur
//(���)Soul Niro Sportage Sorento Stinger
//(���)g70 g80 g90 gv70 gv80
//(���)
//(���)hyundai kia or genesis ?
//(�Է�)genesis
//(���)g70 g80 g90 gv70 gv80 ? 
//(�Է�)gv70
//(���)car available

//����� ���� 2
//(���)Avante Sonata Grandeur
//(���)Soul Niro Sportage Sorento Stinger
//(���)g70 g80 g90 gv70 gv80
//(���)
//(���)hyundai kia or genesis ?
//(�Է�)hyundai
//(���)Avante Sonata Grandeur ?
//(�Է�)Elantra
//(���)car unavailable

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
    /* find(' ',startIndex) �Լ��� startIndex ���� �����Ͽ�(ù �ε����� 0����ī��Ʈ) 
    ' '�� �ش��ϴ� �ε��� ���� ��ȯ�Ѵ�.
    substr(startIndex,count) �Լ��� startIndex���� �����Ͽ�(ù �ε����� 0���� ī��Ʈ�Ͽ� startIndex ��)
    count ���ڸ�ŭ ���ڸ� �о���δ�.
    �׷��� ���� find()�Լ��� ��ȯ�� ' '�ε����� �ش��ϴ� ���� fIndex�� �����ϰ� 
    count = fIndex - startIndex ������ �̿��Ͽ� substring()�Լ��� ' '�� �������� �����Ͽ� ���ڸ� �д´�
    */
	string find(string choice) {
		while (true) {
			fIndex = line.find(' ' , startIndex);  // find()�� ��ȯ�ϴ� ���� 0���� �����ؼ� �ش�Ǵ� char�� �ε��� ��
			count = fIndex - startIndex;
			if (line.substr(startIndex, count) == choice) {
				return "car available";
			}
			else {
				startIndex = fIndex+1;
			}
												// (fIndex�� 0���� ������ �ε������� �����ϱ� ������)
			if (startIndex >= line.length()) {  // ������fIndex+1 == line.length()
				
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



//�Ʒ� main �Լ��� ���� �Ұ�...
int main()
{
	//string test = "abc xyz"; //�������� ��Ʈ�� �ִ�.
	//cout << test.find("abc") << " " << test.find("xyz") << " " <<  test.find("abcd") << endl;
	hyundai myhyundai;
	kia mykia;
	genesis mygenesis;
	cout << myhyundai.lineup() << endl; //"Avante Sonata Grandeur" ���
	cout << mykia.lineup() << endl;     //"Soul Niro Sportage Sorento Stinger" ���
	cout << mygenesis.lineup() << endl; //"g70 g80 g90 gv70 gv80" ���
	cout << endl;

	
	string choice;
	hyundai_kia* ptr = 0;
	cout << "hyundai kia or genesis? " << endl; //�귣�� choice�� ���� ���� ��ü ���� 
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
		cout << ptr->lineup() << "?" << endl;//�귣�� choice�� ���� ������ Ŭ���� �ڵ��� lineup
		cin >> choice; //�� choice
		cout << ptr->find(choice) << endl;
		//�� choice�� lineup�� ������ "car available"���, ������ "car unavailable" ���
		//��Ʈ: lineup() ��ȯ ���� string�� �־ ����Ҽ� �ִ�
	}

	delete ptr;

	
	return 0;
}
