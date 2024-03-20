#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player;

class Gambling{
Player* players;
public:
    Gambling();
    void play_game();
    ~Gambling();
};

class Player{
string name;
public:
    string& setName();
    string getName();
    
};
string Player::getName(){
    return name;
}

string& Player::setName(){
    return name;
}

Gambling::Gambling(){
    srand((unsigned)time(NULL));

    int i=0;

    players = new Player[2];
    cout << "첫번째 선수 이름>>";
    cin >> players[i++].setName();
    cout << "두번째 선수 이름>>";
    cin >> players[i].setName();

    play_game();
}

Gambling::~Gambling(){
    delete[] players;
}

void Gambling::play_game(){
    int i=0;
    char c;
    int randn[3];

     
    while(true){
        if(i>=1){
            i = 0;
        }

        cout << players[i].getName() << ": <Enter> ";
        cin >> c;
        if(c!='\n'){
            cin.ignore();
            continue;
        }
        else{

            for(int r=0;r<3;r++){
                randn[r] = rand()%3;
            }
            cout << "\t";
            for(int k=0;k<3;k++){
                cout << randn[k] << "\t";
            }

            if(randn[1]==randn[2] && randn[2]==randn[3]){
                cout << players[i].getName() << "님 승리!!";
                break;
            }else
            {
                cout << "아쉽군요!";
            }
            i++;
        }
    }
}

int main(){
    Gambling first;
    
}