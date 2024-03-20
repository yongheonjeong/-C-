#include <iostream>
using namespace std;

class Book{
    string title;
    int price,pages;
public:
    Book(string title="",int price=0,int pages=0);
    Book& operator+=(int price);
    Book& operator-=(int price);
    void show();
    string getTitle(){return title;}
};

Book::Book(string title,int price,int pages){
    this->title = title;
    this->price = price;
    this->pages = pages;
}

Book& Book::operator+=(int price){
    Book& op = *this;
    op.price += price;
    return op;
}

Book& Book::operator-=(int price){
    Book& op = *this;
    op.price -= price;
    return op;
}

void Book::show(){
    cout  << title << " " << price << "�� " << pages << " ������" << endl;
}

int main(){
 Book a("û��",20000,300),b("�̷�",30000,500);
 a += 500;
 b -= 500;
 a.show();
 b.show();
}
 