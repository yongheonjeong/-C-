#include <iostream>
using namespace std;

class Book{
    string title;
    int price,pages;
public:
    Book(string title="",int price=0,int pages=0);
    void show();
    string getTitle(){return title;}

    friend bool operator==(Book& op,int price);
    friend bool operator==(Book& op,string title);
    friend bool operator==(Book& op1,Book& op2);
};

bool operator==(Book& op,int price){
    if(op.price == price)
        return true;
    else
        return false;
}


bool operator==(Book& op,string title){
    if(op.title == title)
        return true;
    else
        return false;
}


bool operator==(Book& op1,Book& op2){
    if(op1.price == op2.price && op1.title == op2.title && op1.pages == op2.pages)
        return true;
    else
        return false;
}
Book::Book(string title,int price,int pages){
    this->title = title;
    this->price = price;
    this->pages = pages;
}
 

void Book::show(){
    cout  << title << " " << price << "원 " << pages << " 페이지" << endl;
}


int main(){
    Book a("명품 C++",30000,500),b("고품C++",30000,500);
    if( a == 30000) cout << "정가 30000원" << endl;
    if( a == "명품 C++") cout << "명품 C++ 입니다." << endl;
    if( a == b ) cout << "두 책이 같은 책입니다." << endl;
}

 