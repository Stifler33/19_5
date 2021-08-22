#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    ifstream buffer;
    stringstream output;
    buffer.open("C:\\Users\\bagi3\\ClionProjects\\19.5\\Excel.txt");
    buffer.is_open() ? cout << "File open !\n" : cout << "Error open file\n";
    int number = 0;
    int totalNumber = 0;
    string str;
    string outputStr;
    string data;
    int maxNum = 0;
    while (!buffer.eof()){
        getline(buffer, str, ' ');
        try{
            number = stoi(str);
            totalNumber += number;
            getline(buffer, data, '\n');
            if (number > maxNum){
                maxNum = number;
                output << number;
                outputStr = "";
                outputStr = output.str();
                output.str("");
            }else output.str("");
        } catch(invalid_argument){
            output << str << " ";
        }
    }
    cout << outputStr << endl;
    cout << "total money paid :";
    cout << totalNumber << endl;
}