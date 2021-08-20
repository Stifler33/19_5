#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream forFile;
    cout << "Enter location file :";
    string location;
    cin >> location;
    string extension = location.substr(location.size() - 3);
    if (extension == "png" || extension == "PNG"){
        cout << "extension good\n";
    }else {
        cout << "Error extension !\n";
        return 0;
    }
    forFile.open(location, ios::binary);
    forFile.is_open() ? cout << "File open !\n" : cout << "Error file open\n";
    char buffer[4];
    forFile.seekg(1);
    forFile.read(buffer, 3);
    cout << buffer << endl;
    forFile.close();
    return 0;
}
