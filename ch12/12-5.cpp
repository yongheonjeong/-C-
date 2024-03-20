#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int size = 50;
    char buf[size];
    int n=0;
    ifstream fin("sample.cpp");

    if(!fin){
        cout << "open fail";
        return 0;
    }

    while(!fin.eof()){
        
        fin.getline(buf,size,'\n');
        n = fin.gcount();

        for(int i=0;i<n;i++){
            if(buf[i] == '/' && buf[i+1] == '/')
                break;
            else
                cout << buf[i]; 
        }
        cout << endl;
    }

    fin.close();
}