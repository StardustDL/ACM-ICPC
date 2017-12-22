/*
Ì°À·µÄÀñÎïËÍÀñÕß
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> m;
int np,k,t;
string ss[15];
string s;
int main(){
	cin>>np;
	for(int i=1;i<=np;i++){
		cin>>ss[i];
		m[ss[i]]=0;
	}
	while(cin>>s){
		cin>>t>>k;
		m[s]-=t;
		if(k==0)continue;
		int y=t/k;
		m[s]+=t-(y*k);
		for(int i=1;i<=k;i++){
			cin>>s;
			m[s]+=y;
		}
	}
	for(int i=1;i<=np;i++){
		cout<<ss[i]<<" "<<m[ss[i]]<<endl;
	}
	return 0;
}
