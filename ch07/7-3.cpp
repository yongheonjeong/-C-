#include <iostream>
using namespace std;

class Book{
    string title;
    int price,pages;
public:
    Book(string title="",int price=0,int pages=0);
    void show();
    string getTitle(){return title;}
    bool operator!();

};

Book::Book(string title,int price,int pages){
    this->title = title;
    this->price = price;
    this->pages = pages;
}

 

void Book::show(){
    cout  << title << " " << price << "�� " << pages << " ������" << endl;
}

bool Book::operator!(){
    if(this->title == "�������" && this->pages == 50 && this->price == 0)
        return true;
    else 
        return false;
}

int main(){
 Book book("�������",0,50);
 if(!book) cout << "��¥��" << endl;
}

 