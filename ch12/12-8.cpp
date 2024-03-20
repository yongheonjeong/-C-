#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

int main(){
    ifstream fin1("c:\\windows\\system.ini");
    ifstream fin2("c:\\windows\\system.ini");
    ofstream fout("editPlus.txt");
    char ch=0;
    fin1.seekg(0);
    while( (ch != EOF)){ // 처음과 마지막을 읽음

        for(int i=0;i<2;i++){
            for(int j=0;j<8;j++){
                 ch = fin1.get();    
                
                if(isprint((int)ch)){
                cout << setw(2) << hex << (int)ch;
                }else{
                    cout << "  ";
                }
                    if(i==7)
                        cout << "   "; // tab
                    else
                        cout << " "; // space
            }
            cout << "   "; // tab
        }
          cout << " ";  //space  
          
         for(int i=0;i<2;i++){
            for(int j=0;j<8;j++){
                ch = fin2.get();
                if(isprint(ch)){
                cout << setw(2) << ch;
                }else{
                    cout << setw(2) << ".";
                    if(i==7)
                        cout << "   "; // tab
                } 
            }      
               cout << " ";      
        }


        cout << endl;
    }
    fin1.close();
    fin2.close();
    fout.close();
}