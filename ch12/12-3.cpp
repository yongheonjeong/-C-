#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){

    int n=1;
    char ch;
    fstream fin("c:\\windows\\system.ini",ios::in);
 

    while( (ch = fin.get()) != EOF ){
        ch = toupper(ch);
        cout << ch;
 
    }

    fin.close();
}