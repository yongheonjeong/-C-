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
    
    //������ 219B ũ�Ⱑ ������ ���ڼ��� 219�ΰ� �ǹ����� ����
    //ù��° tellg()�� ���� 14�� ����, �׷��� ���ڼ��� �����ϱ⺸��
    //tellg()�� �̿��Ͽ� �ۼ�Ʈ�� �����ؾ��� 

    while((ch = fin.get())!=EOF){
        fout.put(ch);
        n = fin.tellg();
        
        if(  n >= ((totalSize/10) * count)){
            cout << ".21B " << 10*count++ << endl;
        }
        
    }
    
    cout << "." << n  <<"B ���� �Ϸ�"<<endl;  
 
    fin.close();
    fout.close();
    
}