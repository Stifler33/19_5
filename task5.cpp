#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;
bool EndGame(bitset<13> *numberQuest){
    cout << *numberQuest << endl;
    for (int i = 0; i < numberQuest->size(); i++){
        if (numberQuest->test(i) == 0) return false;
    }
    return true;
}
void changePoint(int &point, int &step){
    for (int i = point; step > 0; step--){
        i++;
        if (i > 12) i = 0;
        point = i;
    }
}
int main(){
    ifstream bufQuest;
    string locationQuest;
    bitset<13> numberQuest;
    int step = 0;
    int point = -1;
    while(!EndGame(&numberQuest)){
    cin >> step;
        changePoint(point, step);
    //"C:\\quest\\Quest.txt";
    locationQuest = "C:\\quest\\Quest.txt";
    locationQuest.insert(14, to_string(point + 1));
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
    }else cout << "wrong answer\n";
        if (!numberQuest.test(point)){
            numberQuest.set(point);
        }
        bufQuest.close();
    }
    return 0;
}

