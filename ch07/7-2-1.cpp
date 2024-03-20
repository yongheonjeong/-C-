#include <iostream>
using namespace std;

class Book{
    string title;
    int price,pages;
public:
    Book(string title="",int price=0,int pages=0);
    void show();
    string getTitle(){return title;}

    bool operator==(int price);
    bool operator==(string title);
    bool operator==(Book& op);
};

bool Book::operator==(int price){
    if(this->price == price)
        return true;
    else
        return false;
}


bool Book::operator==(string title){
    if(this->title == title)
        return true;
    else
        return false;
}


bool Book::operator==(Book& op){
    if(this->price == op.price && this->title == op.title && this->pages == op.pages)
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

 