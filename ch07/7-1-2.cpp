#include <iostream>
using namespace std;

class Book{
    string title;
    int price,pages;
public:
    Book(string title="",int price=0,int pages=0);
    friend Book& operator+=(Book& op,int price);
    friend Book& operator-=(Book& op,int price);
    void show();
    string getTitle(){return title;}
};

Book::Book(string title,int price,int pages){
    this->title = title;
    this->price = price;
    this->pages = pages;
}

Book& operator+=(Book& op,int price){
    op.price += price;
    return op;
}

Book& operator-=(Book& op,int price){
    op.price -= price;
    return op;
}

void Book::show(){
    cout  << title << " " << price << "원 " << pages << " 페이지" << endl;
}

int main(){
 Book a("청춘",20000,300),b("미래",30000,500);
 a += 500;
 b -= 500;
 a.show();
 b.show();
}
 