/*
[NOIP1998P3]2���ݴη�
�������ݹ鴦�� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
string solve(int x){
	if(x==1)return "";
	string ans="(";
	for(int i=15;i>0;i--){
		if(x>>i&1){
			ans+="2"+solve(i)+"+";
		}
	}
	if(x&1)ans+="2(0)";
	else ans.erase(ans.length()-1);
	ans+=")";
	return ans;
}
int main(){
	int n;cin>>n;
	string ans=solve(n);
	cout<<ans.substr(1,ans.length()-2)<<endl;;
	return 0;
}

