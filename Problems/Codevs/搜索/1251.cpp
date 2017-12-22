/*
À¨ºÅ
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string> ans[20][15];
string a[15];
int n;
void dfs(int l, int r){
    string s;
    if(ans[l][r].size())return;
    if(l==r)ans[l][r].push_back(a[l]);
    else
        for(int i=l;i<r;i++){
            dfs(l,i);dfs(i+1,r);
            int m1=ans[l][i].size(), m2=ans[i+1][r].size();
            for (int j=0;j<m1;j++)
                for (int k=0;k<m2;k++){
                    if(l==i && i+1==r)
                        s = "(" + ans[l][i][j] + "*" + ans[i + 1][r][k] + ")";
                    else s = "(" + ans[l][i][j] + ans[i+1][r][k] + ")";
                    ans[l][r].push_back(s);
                }
        }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,n);
    int m=ans[1][n].size();
    for(int i = 0; i < m; i++)
        cout<<ans[1][n][i]<<endl;
    return 0;
}
