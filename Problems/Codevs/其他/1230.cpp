/*
ÔªËØ²éÕÒ
*/
#include<iostream>
#include<set>
using namespace std;
int n,m,x;
set<int> s;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	while(n-->0){
		cin>>x;
		s.insert(x);
	}
	while(m-->0){
		cin>>x;
		if(s.count(x)==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
