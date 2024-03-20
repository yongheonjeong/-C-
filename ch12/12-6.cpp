#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    
    char ch;
    int n=0,totalSize=0,sum=0;
    int count=1;
    int chk=0;
    ifstream fin("c:\\windows\\system.ini");
    ofstream fout("system.txt");

   fin.seekg(0,ios::end);
   totalSize = fin.tellg();
   fin.seekg(0,ios::beg);
    
    //파일은 219B 크기가 맞으나 글자수가 219인걸 의미하지 않음
    //첫번째 tellg()의 값은 14가 나옴, 그래서 글자수로 측정하기보단
    //tellg()를 이용하여 퍼센트를 측정해야함 

    while((ch = fin.get())!=EOF){
        fout.put(ch);
        n = fin.tellg();
        
        if(  n >= ((totalSize/10) * count)){
            cout << ".21B " << 10*count++ << endl;
        }
        
    }
    
    cout << "." << n  <<"B 복사 완료"<<endl;  
 
    fin.close();
    fout.close();
    
}