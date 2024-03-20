#include <iostream>
using namespace std;

class Matrix{
    int arr[4] = {0};
public:
    Matrix(int a,int b,int c,int d);
    Matrix operator+(Matrix& op);
    Matrix& operator+=(Matrix& op);
    bool operator==(Matrix& op);
    void show();
};

Matrix::Matrix(int a=0,int b=0,int c=0,int d=0){
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  arr[3] = d;
}

Matrix Matrix::operator+(Matrix& op){
    Matrix tmp = *this;
    for(int i=0;i<4;i++){
        switch(i){
             case 0:
                tmp.arr[0] += op.arr[0];
                break;

             case 1:
                tmp.arr[1] += op.arr[1];
                break;
                
             case 2:
                tmp.arr[2] += op.arr[2];
                break;

             case 3:
                tmp.arr[3] += op.arr[3];
                break;
        }
    }

    return tmp;
}

Matrix& Matrix::operator+=(Matrix& op){
    Matrix& tmp = *this;
 
    for(int i=0;i<4;i++){
        switch(i){
             case 0:
                tmp.arr[0] += op.arr[0];
                break;

             case 1:
                tmp.arr[1] += op.arr[1];
                break;
                
             case 2:
                tmp.arr[2] += op.arr[2];
                break;

             case 3:
                tmp.arr[3] += op.arr[3];
                break;
        }
    }

    return tmp;

}

bool Matrix::operator==(Matrix& op){
    Matrix tmp = *this;
    if(tmp.arr[0] == op.arr[0]&&tmp.arr[1] == op.arr[1]
       &&tmp.arr[2] == op.arr[2]&&tmp.arr[3] == op.arr[3])
       return true;
    else 
        return false;
}

void Matrix::show(){
    for(int i=0;i<4;i++){
        if(i==0){
          cout  << "Matrix = { " << arr[i] << " "; 
          continue;
        }else if(i>0 && i<3){
        cout << arr[i] << " ";
        }
        if(i==3){
            cout << arr[i] << " }";
            break;
        }
    }
    cout << endl;
}


int main(){
    Matrix a(1,2,3,4),b(2,3,4,5),c;
    c = a + b;
    a += b;
    a.show();
    b.show();
    c.show();

    if( a==c ){
        cout << "a and c are the same" << endl;
    }
}