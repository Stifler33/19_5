#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;
int main(){
    ifstream bufQuest;
    string locationQuest;
    bitset<13> numberQuest;
    int sector = 0;
    cin >> sector;
    locationQuest = "D:\\game\\quest.txt";
    locationQuest.insert(13, to_string(sector));
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
    return 0;
}

