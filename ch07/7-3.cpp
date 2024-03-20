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
    cout  << title << " " << price << "ø¯ " << pages << " ∆‰¿Ã¡ˆ" << endl;
}

bool Book::operator!(){
    if(this->title == "∫≠∑ËΩ√¿Â" && this->pages == 50 && this->price == 0)
        return true;
    else 
        return false;
}

int main(){
 Book book("∫≠∑ËΩ√¿Â",0,50);
 if(!book) cout << "≤«¬•¥Ÿ" << endl;
}

 