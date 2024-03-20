#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class human;
class mass;
void print(human h);

class human{
    int ssn;
    int money;
public:
   string name;
   human(string n="?"){
    name = n;
    ssn = rand()%1000000;
    money = rand()%1000;
   }

   void operator<<(human& a){
    this->money += a.money;
    a.money = 0;
   }

   friend void print(human h);
   friend mass;
   friend human operator+(human a,human b);
};

class mass{

public:
 human people[100];
 int sumMoney(){
    int sum = 0;
    for(int i=0;i<100;i++){
        sum += people[i].money;
    }
    return sum;
 }
};

void print(human h){
    cout << h.name << " " << h.ssn << " $" << h.money << endl;
}

human operator+(human a,human b){
    human r;
    r.name = a.name + " " + b.name;
    r.ssn = rand()%1000000;
    r.money = a.money + b.money;
    return r; 
}

human operator+(human a,string lastname){
    human  r;
    r.name = a.name + " " + lastname;
    return r; 
}

human operator+(string firstname,human a){
    human  r;
    r.name = firstname + " " + a.name;
    return r; 
}

int main(){
    human k("Kate"),j("Jake"),m;
    print(k);
    print(j);

    m = k + j; //m = operator+(k,j);
    print(m);

    k << j; //k.operator<<(j);
    print(k);
    print(j);

    human jose("Jose"),father,cousin;
    father = jose + "Rodrigez"; //father = operator+(jose,"Rodrigez");
    cousin = "Rodrigez" + jose; //cousin = operator+("Rodrigez",human)
    print(father);
    print(cousin);

    return 0;

}