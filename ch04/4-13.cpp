#include <iostream>
#include <locale>
using namespace std;

class Histogram{
string str;
char* pstr;
char c;
int alpha[26]={0};
public:
    Histogram(string str);
    void put(string str);
    void putc(char c);
    void print();
    ~Histogram();

};

Histogram::Histogram(string str){
    this->str = str+'\n';
}

void Histogram::put(string str){
    this->str += str;
}

void Histogram::putc(char c){
    this->str += c;
}

void Histogram::print(){
    int i=0;

    pstr = new char[str.size()];

    while(str[i] != '\0'){

        pstr[i] = tolower(str[i]);

        if(isalpha(pstr[i])){
            alpha[int(pstr[i])-97]++;
        }
        i++;
    }

    i++;
    pstr[i] = '\0';
    
    cout << pstr << endl;

    for(int i=0; i<26; i++){
        cout << char(i+97) << "(" << alpha[i] << ")" << "\r\t:";
        for(int j=0; j<alpha[i]; j++){
            cout << "*";
        }
        cout << endl;
    }


}

Histogram::~Histogram(){
    delete[] pstr;
}

int main(){

    Histogram el("Wise man say,only fools rush in But I can't help.");
    el.put("falling in love with you");
    el.putc('-');
    el.put("Elvis Presley");
    el.print();
    return 0;
}