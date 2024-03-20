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

    //�Ű������� �Լ������� Statistics �� ������ ������ ��� 
    //�����ڴ� ������� �ʰ� �Ҹ��ڸ� ����Ǵ� ��찡 �߻��ϹǷ�(�̶� delete[] ptr �߻�) 
    //��� �����ڷ� �����Ѵ� 
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
    if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

    int x[5];
    cout << "5 ���� ������ �Է��϶� >> ";
    for (int i = 0; i < 5; i++) cin >> x[i];

    for (int i = 0; i < 5; i++) stat << x[i];
    stat << 100 << 200;
    ~stat;

    int avg;
    stat >> avg;
    cout << "avg=" << avg << endl;
}