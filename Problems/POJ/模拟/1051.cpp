/*
P,MTHBGWB 
题意：http://www.cnblogs.com/dengeven/archive/2013/08/13/3255367.html 
分析：好麻烦的模拟 
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char, string> dictionary;
int main(){
    int n;
    cin >> n;
    dictionary['A'] = ".-";
    dictionary['B'] = "-...";
    dictionary['C'] = "-.-.";
    dictionary['D'] = "-..";
    dictionary['E'] = ".";
    dictionary['F'] = "..-.";
    dictionary['G'] = "--.";
    dictionary['H'] = "....";
    dictionary['I'] = "..";
    dictionary['J'] = ".---";
    dictionary['K'] = "-.-";
    dictionary['L'] = ".-..";
    dictionary['M'] = "--";
    dictionary['N'] = "-.";
    dictionary['O'] = "---";
    dictionary['P'] = ".--.";
    dictionary['Q'] = "--.-";
    dictionary['R'] = ".-.";
    dictionary['S'] = "...";
    dictionary['T'] = "-";
    dictionary['U'] = "..-";
    dictionary['V'] = "...-";
    dictionary['W'] = ".--";
    dictionary['X'] = "-..-";
    dictionary['Y'] = "-.--";
    dictionary['Z'] = "--..";
    dictionary['_'] = "..--";
    dictionary['.'] = "---.";
    dictionary[','] = ".-.-";
    dictionary['?'] = "----";
    for (int case_id = 1; case_id <= n; ++case_id) {
        int len[100],size;
        string en_message,en_code,de_message;
        cin >> en_message;
        size = en_message.size();
        for (size_t i = 0; i < size; ++i) {
            string code = dictionary[en_message[i]];
            en_code += code;
            len[i] = code.size();
        }
        int p = 0;
        for (int i = size - 1; i >= 0; --i) {
            char code;
            for (map<char, string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
                if (it->second == en_code.substr(p, len[i])) {
                    code = it->first;
                    break;
                }
            }
            de_message += code;
            p += len[i];
        }
        cout << case_id << ": " << de_message << endl;
    }
    return 0;
}

