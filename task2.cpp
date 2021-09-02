#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    string locationFile;
    ifstream buffer;
    while (locationFile != "no"){
        cout << "Enter location file :";
        getline(cin,locationFile);
        buffer.open(locationFile, ios::binary);
        if(buffer.is_open()){
            cout << "File open !\n";
        } else{
            cerr << "Error open file\n";
            continue;
        }
        while (!buffer.eof()){
            char outputText[100] = {'\0'};
            buffer.read(outputText, 99);
            cout << outputText;
        }
        buffer.close();
        cout << "\nopen another file ?\n";
        getline(cin,locationFile);
        if (locationFile == "no") {
            cout << "Goodbye !\n";
            break;
        }
    }
    return 0;
}