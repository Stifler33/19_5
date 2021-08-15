#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    string locationFile;
    ifstream buffer;
    while (locationFile != "no"){
        cout << "Enter location file :";
        cin >> locationFile;
        buffer.open(locationFile, ios::binary);
        buffer.is_open() ? cout << "File open !\n" : cout << "Error open file\n";
        while (!buffer.eof()){
            char outputText[100] = {'\0'};
            buffer.read(outputText, 100);
            cout << outputText << endl;
        }
        buffer.close();
        cout << "open another file ?\n";
        cin >> locationFile;
        if (locationFile == "no") {
            cout << "Goodbye !\n";
            break;
        }
    }
    return 0;
}