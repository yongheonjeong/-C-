#include <iostream>
using namespace std;

class Statistics {
    int* ptr;
    static int size;
public:
    Statistics();
    bool operator!();
    void operator~();
    friend Statistics& operator<<(Statistics& op1, int op2);
    void operator>>(int& op);
    ~Statistics();

    //매개변수나 함수내에서 Statistics 로 변수를 선언할 경우 
    //생성자는 실행되지 않고 소멸자만 실행되는 경우가 발생하므로(이때 delete[] ptr 발생) 
    //모두 참조자로 선언한다 
};
int Statistics::size = 0;

Statistics::Statistics() {
    ptr = new int[5];
    for (int i = 0; i < 5; i++) {
        ptr[i] = 0;
    }
}

bool Statistics::operator!() {
    if (this->ptr[0] == 0)
        return true;
    else
        return false;
}

void Statistics::operator~() {
    Statistics& tmp = *this;
    for (int i = 0; i < Statistics::size; i++) {
        cout << tmp.ptr[i] << " ";
    }cout << endl;
}

Statistics& operator<<(Statistics& op1, int op2) {

    if (Statistics::size < 5) {
        op1.ptr[Statistics::size++] = op2;
    }
    else if (Statistics::size >= 5)
    {
        int* nptr = new int[Statistics::size + 1];
        for (int i = 0; i < Statistics::size; i++) {
            nptr[i] = op1.ptr[i];
        }
        nptr[Statistics::size++] = op2;
        delete[] op1.ptr;
        op1.ptr = nptr;
    }
    return op1;
}

void Statistics::operator>>(int& op) {
    Statistics& tmp = *this;
   
    int sum = 0;
    for (int i = 0; i < Statistics::size; i++) {
        sum += tmp.ptr[i];
    }

    op = float(sum) / Statistics::size;
}
 
Statistics::~Statistics() {
    delete[] ptr;
}

int main() {
    Statistics stat;
    if (!stat) cout << "현재 통계 데이터가 없습니다." << endl;

    int x[5];
    cout << "5 개의 정수를 입력하라 >> ";
    for (int i = 0; i < 5; i++) cin >> x[i];

    for (int i = 0; i < 5; i++) stat << x[i];
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg;
    cout << "avg=" << avg << endl;
}