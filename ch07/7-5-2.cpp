#include <iostream>
using namespace std;

class Color{
    int RED=0;
    int GREEN=0;
    int BLUE=0; 
public:
    Color(int RED,int GREEN,int BLUE);
    friend Color operator+(Color op1,Color op2);
    friend bool operator==(Color op1,Color op2);
    void show();

};

 Color operator+(Color op1,Color op2){
    Color tmp = op1;
    tmp.RED += op2.RED;
    tmp.BLUE += op2.BLUE;
    tmp.GREEN += op2.GREEN;
    return tmp;
 }

 bool operator==(Color op1,Color op2){
    Color tmp = op1;
    if( tmp.RED == op2.RED && tmp.BLUE == op2.BLUE && tmp.GREEN == op2.GREEN)
        return true;
    else 
        return false;
 }

Color::Color(int RED=0,int GREEN=0,int BLUE=0){
    this->RED = RED;
    this->GREEN = GREEN;
    this->BLUE = BLUE;
}
    
void Color::show(){
    cout << "RED: " << RED << " GREEN: " << GREEN << " BLUE: " << BLUE << endl;
}

int main(){
    Color red(255,0,0), blue(0,0,255),c;
    c = red + blue;
    c.show();

    Color fuchsia(255,0,255);
    if(c==fuchsia)
        cout << "보라색 맞음";
    else
        cout << "보라색 아님";
    

    
}