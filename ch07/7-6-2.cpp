#include <iostream>
using namespace std;

class Matrix{
    int arr[4] = {0};
public:
    Matrix(int a,int b,int c,int d);
    friend Matrix operator+(Matrix op1,Matrix op2);
    friend Matrix& operator+=(Matrix& op1,Matrix op2);
    friend bool operator==(Matrix op1,Matrix op2);
    void show();
};

Matrix::Matrix(int a=0,int b=0,int c=0,int d=0){
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  arr[3] = d;
}

Matrix operator+(Matrix op1,Matrix op2){
    Matrix tmp = op1;
    for(int i=0;i<4;i++){
        switch(i){
             case 0:
                tmp.arr[0] += op2.arr[0];
                break;

             case 1:
                tmp.arr[1] += op2.arr[1];
                break;
                
             case 2:
                tmp.arr[2] += op2.arr[2];
                break;

             case 3:
                tmp.arr[3] += op2.arr[3];
                break;
        }
    }

    return tmp;
}

Matrix& operator+=(Matrix& op1,Matrix op2){
    Matrix& tmp = op1;
 
    for(int i=0;i<4;i++){
        switch(i){
             case 0:
                tmp.arr[0] += op2.arr[0];
                break;

             case 1:
                tmp.arr[1] += op2.arr[1];
                break;
                
             case 2:
                tmp.arr[2] += op2.arr[2];
                break;

             case 3:
                tmp.arr[3] += op2.arr[3];
                break;
        }
    }

    return tmp;

}

bool operator==(Matrix op1,Matrix op2){
    Matrix tmp = op1;
    if(tmp.arr[0] == op2.arr[0]&&tmp.arr[1] == op2.arr[1]
       &&tmp.arr[2] == op2.arr[2]&&tmp.arr[3] == op2.arr[3])
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