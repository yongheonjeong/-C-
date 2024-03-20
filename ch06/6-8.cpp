#include <iostream>
#include <string>
using namespace std;

class Trace {
    static string(*tptr)[100];

public:
    Trace();
    ~Trace();
    static void put(string function, string statement);
    static void print();
    static void print(string function);


};

string(*Trace::tptr)[100];

Trace::Trace() {
    tptr = new string[5][100];

    for (int i = 0; i < 5; i++) {
        tptr[i][0] = "";
        for (int j = 1; j < 100; j++) {
            tptr[i][j] = "";
        }
    }
}

Trace::~Trace() {
    delete[] tptr;
}

void Trace::put(string function, string statement) {
    int i = 0;
    int j = 1;
    bool notfound = true;

    while (tptr[i][0] != "" && i <= 4) {
        i++;
        if (tptr[i][0] == function) {
            notfound = false;

            while (tptr[i][j] != "" && j < 100) {
                j++;
            }
            tptr[i][j] = statement;
            break;
        }
    }

    if (notfound) {
        tptr[i][0] = function;
        tptr[i][j] = statement;
    }

}
void Trace::print(string function) {
    for (int i = 0; i < 5; i++) {
        if (tptr[i][0] == function) {
            for (int j = 1; tptr[i][j] != ""; j++) {
                cout << tptr[i][0] << " : ";
                cout << tptr[i][j] << endl;
            }
            return;
        }
        else
            continue;
    }

    cout << function << "is not traced" << endl;
}

void Trace::print() {
    for (int i = 0; tptr[i][0] != ""; i++) {
        for (int j = 1; tptr[i][j] != ""; j++) {
            cout << tptr[i][0] << " : ";
            cout << tptr[i][j] << endl;
        }
        cout << endl;
    }
}


void f() {
    int a, b, c;
    cout << "두개의 정수를 입력하세요>>";
    cin >> a >> b;
    Trace::put("f()", "정수를 입력 받았음");
    c = a + b;
    Trace::put("f()", "합 계산");
    cout << "합은" << c << endl;
}


int main() {
    Trace trk;
    Trace::put("main()", "프로그램 시작합니다.");
    f();
    Trace::put("main()", "종료");

    Trace::print("f()");
    Trace::print();

}