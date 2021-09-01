#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;
bitset<13> numberQuest;
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
int main(){
    ifstream bufQuest;
    string locationQuest;
    int step = 0;
    int point = -1;
    int scorePlayer = 0;
    int scoreViewer = 0;
    while(!EndGame(&numberQuest) && scorePlayer < 6 && scoreViewer < 6){
        cout << "Enter step :";
        cin >> step;
        changePoint(point, step);
        locationQuest = "D:\\game\\quest.txt";
        locationQuest.insert(13, to_string(point + 1));
        bufQuest.open(locationQuest, ios::binary);
        string textQuest;
        getline(bufQuest , textQuest , '\r');
        bufQuest.seekg((int)bufQuest.tellg() + 1);
        cout << textQuest << endl;
        string userAnswer;
        cin >> userAnswer;
        getline(bufQuest , textQuest , '\r');
        if (textQuest == userAnswer){
            cout << "Good !\n";
            scorePlayer++;
        }else {
            cout << "wrong answer\n";
            scoreViewer++;
        }
            if (!numberQuest.test(point)){
                numberQuest.set(point);
            }
            bufQuest.close();
    }
    if (scorePlayer >= 6){
        cout << "Win player\n";
    }else if (scoreViewer >= 6){
        cout << "win viewer\n";
    }
    return 0;
}

