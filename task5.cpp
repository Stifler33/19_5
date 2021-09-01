#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;
bitset<13> numberQuest;
ifstream bufQuest;
bool EndGame(bitset<13> *numberQuest){
    //cout << *numberQuest << endl;
    for (int i = 0; i < numberQuest->size(); i++){
        if (numberQuest->test(i) == 0) return false;
    }
    return true;
}
void changePoint(int &point, int step){
    do {
        for (int i = point; step > 0; step--) {
            i++;
            if (i > 12) i = 0;
            point = i;
        }
        if (numberQuest.test(point)) step = 1;
    }while (numberQuest.test(point));
}
string get_text(string textGame){
    bufQuest.open(textGame, ios::binary);
    getline(bufQuest , textGame);
    return textGame;
}
int main(){

    string locationQuest;
    string locationAnswer;
    int step = 0;
    int point = -1;
    int scorePlayer = 0;
    int scoreViewer = 0;
    while(!EndGame(&numberQuest) && scorePlayer < 6 && scoreViewer < 6){
        cout << "Enter step :";
        cin >> step;
        changePoint(point, step);
        locationQuest = "D:\\game\\quest.txt";
        locationAnswer = "D:\\game\\answer.txt";
        locationQuest.insert(13, to_string(point + 1));
        locationAnswer.insert(14, to_string(point + 1));
        bufQuest.open(locationQuest, ios::binary);
        string textGame;
        getline(bufQuest , textGame);
        cout << textGame << endl;
        bufQuest.close();
        string userAnswer;
        cin >> userAnswer;
        textGame = "";
        bufQuest.open(locationAnswer, ios::binary);
        getline(bufQuest , textGame);
        bufQuest.close();
        if (textGame == userAnswer){
            cout << "Good !\n";
            scorePlayer++;
        }else {
            cout << "wrong answer\n";
            scoreViewer++;
        }
            if (!numberQuest.test(point)){
                numberQuest.set(point);
            }
    }
    if (scorePlayer >= 6){
        cout << "Win player\n";
    }else if (scoreViewer >= 6){
        cout << "win viewer\n";
    }
    return 0;
}

