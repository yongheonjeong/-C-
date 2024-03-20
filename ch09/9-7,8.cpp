#include <iostream>
using namespace std;


class Shape{

protected:
    string name;
    int width,height;
public:
    Shape(string n="",int w=0,int h=0) { name = n; width = w; height = h;}
    virtual double getArea() = 0; // {return = 0;} - 07¹ø
    string getName() { return name; }
};

class Oval : public Shape{
public:
    Oval(string name,int w,int h) : Shape(name,w,h){
        this->width = w;
        this->height = h;
    }
    virtual double getArea(){
         double Area = 3.14*width*height;
        return Area;
    }
};


class Rect : public Shape{
public:
    Rect(string name,int w,int h) : Shape(name,w,h){}
    virtual double getArea(){
        double Area = width*height;
        return Area;
    }
};


class Triangular : public Shape{
public:
    Triangular(string name,int w,int h) : Shape(name,w,h){}
    virtual double getArea(){
        double Area = width*height/2;
        return Area;
    }
};

int main(){
    Shape* p[3];
    p[0] = new Oval("ºó´ë¶±",10,20);
    p[1] = new Rect("Âû¶±",30,40);
    p[2] = new Triangular("Åä½ºÆ®",30,40);

    for(int i=0;i<3;i++){
        cout << p[i]->getName() << "³ÐÀÌ´Â " << p[i]->getArea() << endl; 
    }

    for(int i=0;i<3;i++) delete p[i];


}