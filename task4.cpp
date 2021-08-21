#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream forFile;
    cout << "Enter location file :";
    string location;
    cin >> location;
    string extension = location.substr(location.size() - 4);
    if (extension == ".png" || extension == ".PNG"){
        cout << "extension good\n";
    }else {
        cerr << "Error extension !\n";
        return 0;
    }
    forFile.open(location, ios::binary);
    if (forFile.is_open()){
        cout << "File open !\n";
    }else{
        cerr << "Error file open\n";
        return 0;
    }
    char buffer[4];
    forFile.seekg(1);
    forFile.read(buffer, 3);
    if ((string)buffer == "PNG"){
        cout << "File PNG\n";
    }else cerr << "File not PNG\n";
    forFile.close();
    return 0;
}
