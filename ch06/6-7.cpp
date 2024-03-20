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
    cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;

    for(int i=0;i<10;i++){
        cout << Random::nextInt() << " ";
    } cout << endl;

    cout<< "알파벳을 랜덤하게 10개 출력합니다." << endl;
     for(int i=0;i<10;i++){
        cout << Random::nextAlphabet() << " ";
    } cout << endl;

     cout<< "알파벳을 랜덤하게 10개 출력합니다." << endl;
     for(int i=0;i<10;i++){
        cout << Random::nextDouble() << " ";
    } cout << endl;

    return 0;
}