#include <iostream>
#include <fstream>
using namespace std;

 
int main(){
     
fstream fin("test.txt",ios::in);

string line;

while(getline(fin,line)){
    cout << line << endl;
}

fin.close();


}