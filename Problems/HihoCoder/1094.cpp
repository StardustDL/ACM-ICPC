#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN=200;
int n,m;
char mp[MAXN+3][MAXN+3];
char d[4][4];
void out(){
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)cout<<d[i][j];cout<<endl;}
}
void rotate(){//clockwise
    static char t[3][3];
    t[0][0]=d[2][0];t[0][2]=d[0][0];t[2][2]=d[0][2];t[2][0]=d[2][2];
    t[0][1]=d[1][0];t[1][2]=d[0][1];t[2][1]=d[1][2];t[1][0]=d[2][1];
    t[1][1]=d[1][1];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)d[i][j]=t[i][j];

    //out();
}
bool compare(int x,int y){
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(mp[x+i][y+j]!=d[i][j])return false;
    return true;
}
set< pair<int,int> > S;//Must unique
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>mp[i][j];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)cin>>d[i][j];
    for(int k=0;k<4;k++){
        rotate();
        for(int i=2;i<=n-1;i++)
            for(int j=2;j<=m-1;j++){
                if(mp[i][j]!=d[1][1])continue;
                if(compare(i-1,j-1)){
                    S.insert(make_pair(i,j));
                }
            }
    }
    for(set< pair<int,int> >::iterator it=S.begin();it!=S.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}