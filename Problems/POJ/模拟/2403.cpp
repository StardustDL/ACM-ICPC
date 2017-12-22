/*
Hay Points
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;
int m,n;
string st;
long long ans;
map<string,int>dict;
int main(){
    scanf("%d%d",&m,&n);
    ans=0;
    for(int i=0;i<m;i++){
        cin>>st;cin>>dict[st];
    }
    getchar();
    while(n--){
        ans=0;
        while(cin>>st,st!=".")
            if(dict.find(st)!=dict.end())ans+=dict[st];
        cout<<ans<<endl;
    }
    return 0;
}

