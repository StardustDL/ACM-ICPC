/*
[JLOI2011]小A的烦恼
分析：模拟 
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
const int MAXN=1000;
using namespace std;
int total,m,cnt[MAXN+3];
string ans[MAXN+3],name;
int main(){
    cin >> total;
    for(int num,i = 1; i <= total; ++i) {
        cin >> num >> name;
        ans[0] += name;
        m = max(m,num);
        memset(cnt,0,sizeof(cnt));
        for(int j = 1; j <= num; ++j) {
            string temp;
            cin >> temp;
            ans[j] += temp;
            for(string::iterator it = temp.begin(); it != temp.end(); ++it)
                cnt[j] += *it == ',';
        }
        int _max = *max_element(cnt + 1,cnt + num + 1);
        for(int j = 0; j < MAXN; ++j)
            for(int k = cnt[j]; k <= (i == total ? _max - 1:_max); ++k)
                ans[j] += ',';
    }
    for(int i = 0; i <= m; ++i)
        cout << ans[i] << endl;
    return 0;
}
