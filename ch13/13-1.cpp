#include <iostream>
using namespace std;

int sum(int a,int b){
    if(a>b){
        throw "잘못된 입력";
    }else if(a<0 || b<0){
        throw "음수 처리 안 됨";
    }else{
        return a+b;
    }
}

int main(){
    try{
        cout << sum(2,5) << endl;
        cout << sum(-1,5) << endl;
    }catch(const char* s){
        cout << s << endl;
    }
}