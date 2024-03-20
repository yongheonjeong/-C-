#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    int n=1;
    string line;
    fstream fin("c:\\windows\\system.ini",ios::in);
    while(getline(fin,line)){
        cout << n++ << " : " << line << endl;
    }

    fin.close();
}