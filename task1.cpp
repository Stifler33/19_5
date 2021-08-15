#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream buf;
string curWord(string &str){
    char sy[1];
    buf.read(sy,1);
    if (*sy == '.' || *sy == ',' || *sy == ' ' || *sy == '\n' || *sy == '\0') {
        return str;
    }else {
        str += *sy;
        return curWord(str);
    }
}
int main() {
    buf.open("C:\\Users\\bagi3\\CLionProjects\\19.5\\text.txt", ios::binary);
    if (!buf.is_open()){
        cout << "not open file !\n";
        return 0;
    }else cout << "open file !\n";
    cout << "enter a word :";
    string userStr;
    cin >> userStr;
    int count = 0;
    while (!buf.eof()){
        string word;
        if (curWord(word) == userStr){
            count++;
        }
    }
    buf.close();
    cout << count;
}