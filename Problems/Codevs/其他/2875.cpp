/*
RY¸ç²é×Öµä
*/ 
#include<iostream>
#include<string>
#include<set>
using namespace std;
set<string> S;
string t;
int n,m;
int main(){
	cin>>n;
	while(n--){cin>>t;S.insert(t);}
	cin>>m;
	while(m--){
		cin>>t;
		cout<<(S.count(t)?"Yes":"No")<<endl;
	}
	return 0;
}
