#include <iostream>
using namespace std;

template<class T>  //  1 
T biggest(T* a,int size){
    
    T max = a[0];

    for(int i=1;i<size;i++){
        if(max<a[i]){
            max = a[i];
        }
    }

    return max;
}

template<class T>   // 2 
bool equalArrays(T* a,T* b,int size){
    for(int i=0;i<size;i++){
        if(a[i] != b[i])
            return false;
    }

    return true;
}

template<class T> // 3
T* reverseArray(T* a,int size){
    T tmp;
    for(int i=0;i<size/2;i++){
        tmp = a[i];
        a[i] = a[size-1-i];
        a[size-1-i] = tmp;
    }
    return a;
}

template<class T> //4
bool search(T value,T arr[],int size){

    for(int i=0;i<size;i++){
        if(arr[i] == value)
            return true;
    }
        return false;
}



int main(){

    int x[] = {1,10,100,5,4};
    cout << biggest(x,5) << endl;   // 1


    int y[] = {1,10,100,5,4};
    int z[] = {1,10,100,5,4};

    if(equalArrays(y,z,5)){    // 2
        cout << "같다" << endl;
    }else{
        cout << "다르다" << endl;
    }



    int a[] = {1,10,100,5,4};  
    int* ptr;
    ptr = reverseArray(a,5);  // 3
    for(int i=0;i<5;i++){
        cout << ptr[i] << " ";
    }cout << endl;


    if(search(100,x,5)) cout << "100이 배열 x에 포함되어 있다"; //4
    else cout << "100이 배열 x에 포함되어 있지 않다.";
    

}