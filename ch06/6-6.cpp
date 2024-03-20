//ex06
#include <iostream>
using namespace std;

class ArrayUtility2 {
    static int* p[2];
public:
    static int* concat(int s1[], int s2[], int size);
    static int* remove(int s1[], int s2[], int size, int& retSize);
    ~ArrayUtility2();

};
ArrayUtility2::~ArrayUtility2() {
    delete[] p[0];
    delete[] p[1];
}


int* ArrayUtility2::p[2] = { p[0] = NULL,p[1] = NULL };

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
    int s3_size = 0;
    
    p[0] = new int[size*2];

    for (int i = 0; i < size; i++) {
        p[0][s3_size++] = s1[i];
    }
    for( int  i =0; i<size;i++){
        p[0][s3_size++] = s2[i];
    }

    return p[0];
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
    int s3_size = 0;

 
    p[1] = new int[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (s1[i] == s2[j]) {
                s1[i] = NULL;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (s1[i] != NULL) {
            p[1][s3_size++] = s1[i];
        }
    }

    retSize = s3_size;
 
    return p[1];
}

int main() {
    int* ptr;
    int rmsize = 0;

    int x[5] = { 0 };
    int y[5] = { 0 };
    int num = 0;

    cout << "���� 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";

    for (int i = 0; i < 5; i++) {
        cin >> num;
        x[i] = num;
    }

    cout << "���� 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        y[i] = num;
    }

    ptr = ArrayUtility2::concat(x, y, 5);
    cout << "��ģ ���� �迭�� ����Ѵ�" << endl;
    for (int i = 0; i < 10; i++) {
        cout << ptr[i] << " ";
    } cout << endl;

    ptr = ArrayUtility2::remove(x, y, 5, rmsize);
    cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ "<< rmsize << endl;
    for (int i = 0; i < rmsize; i++) {
        cout << ptr[i] << " ";
    } cout << endl;

}