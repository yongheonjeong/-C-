#include <iostream>
using namespace std;

void pt1(){

 char ch;
    int count = 0;
    while((ch=cin.get()) != '\n'){
        if(ch=='a'){ 
            count++;
         }
    }    

    cout << count << endl;
}

void pt2(){

    char ch;
    int count=0;
    while(true){
        cin.get(ch);
        if(ch==' ') count++;
        if(ch=='\n') break;
    }

    cout << count;
}

void pt3(){
    char ch; 
    cin.ignore(30,';');
    while((ch=cin.get()) != EOF){
        cout.put(ch);
        if(ch=='\n'){
            cin.ignore(30,';');
        }
    }
}

int main(){
 
}