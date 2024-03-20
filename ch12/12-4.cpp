#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){

    ifstream fin("c:\\windows\\system.ini"); // <fstream> include !! 
    
    char ch;
    while((ch=fin.get()) != EOF){
        cout << (char)toupper(ch);
    }
    
    fin.close();
}