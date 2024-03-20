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
string Board::board[100] = {"********** �Խ����Դϴ�. **********",""};



void Board::add(string str) {
    board[++count] = str;
}

void Board::print() {
    for (int i = 0; i < count + 1; i++) {
        cout << board[i] << endl;
    }cout << endl;
}


int main() {
    Board::add("�߰� ���� ���� ���� ���� �����Դϴ�.");
    Board::add("�ڵ� ����� ���� �̿����ּ���.");
    Board::print();
    Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���!");
    Board::print();
}