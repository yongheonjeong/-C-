#include <iostream>
using namespace std;

class Dept{
    int size;
    int* scores;
public:
Dept(int size){
    this->size = size;
    scores = new int[size];
}
~Dept();
int getSize(){return size;}
void read();
bool isOver60(int index);
};

void Dept::read(){
    int num = 0;
    cout << "10�� ���� �Է�>>";
    for(int i=0;i<10;i++){
        cin >> num;
        scores[i] = num; 
    }
}

bool Dept::isOver60(int index){
        if(scores[index] >=60)
            return true;
        else
            return false;
}

int countPass(Dept& dept){
    int count =0;
    for(int i=0;i<dept.getSize();i++){
        if(dept.isOver60(i)) count++;
    }

    return count;
}

Dept::~Dept(){
    delete[] scores;
}


   

int main(){
    Dept com(10);
    com.read();
    int n = countPass(com);
    cout << "60�� �̻���" << n << "��";
}