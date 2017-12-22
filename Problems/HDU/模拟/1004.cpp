/*
Let the Balloon Rise
题意：给一些颜色，选出现次数最多的颜色 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<map> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
map<string,int> mp;
int mx,p,n,t;
string s;
string ans;
int main(){
	while(cin>>n,n){
		mp.clear();mx=0;
		for(int i=1;i<=n;i++){
			cin>>s;
			if(mp.count(s)==0){
				t=mp[s]=1;
			}
			else t=++mp[s];
			if(t>mx){
				mx=t;
				ans=s;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

