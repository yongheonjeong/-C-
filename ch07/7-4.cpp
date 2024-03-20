#include <iostream>
#include <string>
using namespace std;

class Book{
    string title;
    int price,pages;
public:
    Book(string title="",int price=0,int pages=0);
    void show();
    string getTitle(){return title;}
    friend bool operator<(string op1,Book& op2);
};

Book::Book(string title,int price,int pages){
    this->title = title;
    this->price = price;
    this->pages = pages;
}

 
void Book::show(){
    cout  << title << " " << price << "�� " << pages << " ������" << endl;
}

bool operator<(string op1,Book& op2){
    if( op1.compare(op2.title)<0){
        return true;
    }else
        return false;
}

int main(){
 Book a("û��",20000,300);
 string b;
 cout << "å �̸��� �Է��ϼ��� >> ";
 getline(cin,b);
 if(b<a)
    cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���!" << endl;
}
 