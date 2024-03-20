#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random{

public:
    static void seed() { srand((unsigned)time(0)); }
    static int nextInt(int min=0,int max=32767);
    static char nextAlphabet();
    static double nextDouble();
};
int Random::nextInt(int min,int max){
    return rand() % (max-min+ 1) + min;
}

char Random::nextAlphabet(){
    if(rand()%2){
        return rand()% (90-65+1) + 65;
    }else
    {
        return rand()% (122-97+1) + 97;
    }
}

double Random::nextDouble(){
    return rand()*0.00001;
}

int main(){
    Random::seed();
    cout << "1���� 100���� ������ ���� 10���� ����մϴ�." << endl;

    for(int i=0;i<10;i++){
        cout << Random::nextInt() << " ";
    } cout << endl;

    cout<< "���ĺ��� �����ϰ� 10�� ����մϴ�." << endl;
     for(int i=0;i<10;i++){
        cout << Random::nextAlphabet() << " ";
    } cout << endl;

     cout<< "���ĺ��� �����ϰ� 10�� ����մϴ�." << endl;
     for(int i=0;i<10;i++){
        cout << Random::nextDouble() << " ";
    } cout << endl;

    return 0;
}