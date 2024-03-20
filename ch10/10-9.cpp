#include <iostream>
#include <vector>
using namespace std;


double avg(vector<int>& v, vector<int>::iterator& it) {
    double sum = 0.0;
    for (it = v.begin(); it != v.end(); it++) {
        sum += *it;
    }
    return sum/v.size();
}

void print(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    } cout << endl;
}

int main() {
    double sum = 0.0;
    int num = 0;
    vector<int> v;
    vector<int>::iterator it;

    while (true) {
        cout << "정수를 입력하세요(0을 입력하면 종료)>>";
        cin >> num;
        if (num != 0) {
            v.push_back(num);
            print(v);
            cout << "평균 = " << avg(v, it) << endl;
        }
        else if(num==0){
            break;
        }
         
    }


}