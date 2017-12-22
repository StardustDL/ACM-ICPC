#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
string dealStr(string &s){  
    vector<char> vResult;  
    vResult.push_back(s[0]);  
    for(int i = 1; i < s.size()-1; i++){  
        int preI = i - 1;  
        while(s[i+1] == s[i])i++;
        if(i-1 == preI)vResult.push_back(s[i]);  
    }  
    return string(vResult.begin(), vResult.end());  
}
char c[4] ="ABC";
int main(){
    int T;cin >> T;
    while(T--){
        string str;  
        cin >> str;  
        str = "#" + str + "$";  
        int maxCount = 0;
        for(int i = 1; i < str.size(); i++){  
            for(int k = 0; k < 3 ; k++){  
                string s(str);  
                s.insert(i, 1, c[k]);  
                int len = s.size();  
                while(true){
                    s = dealStr(s) + "$";  
                    if(s.size() < len)len = s.size();  
                    else break;
                }
                maxCount = max(maxCount,(int)(str.size()-s.size()+1));
            }
        }  
        cout << maxCount << endl;  
    }
    return 0;
}