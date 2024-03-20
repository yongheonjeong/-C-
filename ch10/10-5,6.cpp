#include <iostream>
#include <vector>
using namespace std;


template<class T>   // 5 
T* concat(T a[],int sizea,T b[],int sizeb){
    T* ptr = new T[sizea+sizeb];
    for(int i=0;i<sizea;i++){
        ptr[i] = a[i];
    }

    for(int i=0;i<sizeb;i++){
        ptr[i+sizea] = b[i];
    }

    return ptr;
}

template<class T>   // 6 
T* remove(T src[],int sizeSrc,T minus[],int sizeMinus,int& retSize){
     T* ptr = new T[sizeSrc];

    int size = 0;
    bool isNotIn = true;  // mark for src[i], 중복된 src[i]는 중복 마킹 (isNotIn=false)

    for(int i=0;i<sizeSrc;i++){
        isNotIn= true;

        for(int j=0;j<sizeMinus;j++){
            if(src[i] == minus[j]){
                isNotIn = false;
            }
        }

        if(isNotIn){
            ptr[size++] = src[i];
        }

    }

    retSize = size;

    return ptr;
}

int main(){

    double a[5] = {1.0,2.0,3.0,4.0,5.0};
    double b[5] = {6.0,7.0,8.0,9.0,10.0};

    double* ptr1 = concat(a,5,b,5);  // 5 
    
    for(int i=0;i<10;i++)   
        cout << ptr1[i] << " ";
    cout << endl;


    int c[5] = {1,2,3,4,5};
    int d[5] = {6,7,8,9,10};

    int* ptr2 = concat(c,5,d,5);
    
    for(int i=0;i<10;i++)   
        cout << ptr2[i] << " ";
    cout << endl;

    int retSize = 0;
    int e[5] = {3,2,1,0,-1};
    int f[5] = {3,2,1,-2,-3};
    int* ptr3 = remove(e,5,f,5,retSize); // 6 
    for(int i=0;i<retSize;i++)   
        cout << ptr3[i] << " ";
    cout << endl;



}