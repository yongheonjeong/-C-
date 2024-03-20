#include <iostream>
using namespace std;

class Board {
    static int count;
    static string board[100];
public:
    static void add(string str);
    static void print();
};
int Board::count = 0;
string Board::board[100] = {"********** 게시판입니다. **********",""};



void Board::add(string str) {
    board[++count] = str;
}

void Board::print() {
    for (int i = 0; i < count + 1; i++) {
        cout << board[i] << endl;
    }cout << endl;
}


int main() {
    Board::add("중간 고사는 감독 없는 자율 시험입니다.");
    Board::add("코딩 라운지 많이 이용해주세요.");
    Board::print();
    Board::add("진소리 학생이 경진대회 입상하였습니다. 축하해주세요!");
    Board::print();
}