#include<iostream> 
#include<fstream>
using namespace std;
int main() {
 ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
 
 ofstream fout("system.txt", ios::out | ios::binary);
 
 char ch = 0;
 fin.seekg(0, ios::end);
 int length = fin.tellg();

 for (int i = 0; i < length; i++) {
  fin.seekg(length-1-i, ios::beg);
  ch=fin.get();
  fout.put(ch);
 }
 
 fin.close();
 fout.close();
} 