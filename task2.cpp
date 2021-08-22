#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    string locationFile;
    ifstream buffer;
    while (locationFile != "no"){
        cout << "Enter location file :";
        //cin >> locationFile;
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
            buffer.read(outputText, 100);
            cout << outputText << endl;
        }
        buffer.close();
        cout << "open another file ?\n";
        //cin >> locationFile;
        getline(cin,locationFile);
        if (locationFile == "no") {
            cout << "Goodbye !\n";
            break;
        }
    }
    return 0;
}