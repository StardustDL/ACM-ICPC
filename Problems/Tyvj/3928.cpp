/*
为电脑寻找合适的CPU
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
struct data{
	int p,c;
	bool operator <(const data &t)const{
		return c<t.c;
	}
}ds[MAXN+3];
int n,a,b,c,k,cnt=0;
string s;
int main(){
	cin>>n;
	cin>>s>>s;
	switch(s[s.length()-1]){
		case '7':k=7;break;
		case '8':k=8;break;
		case 'p':k=9;break;
	}
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		if(b!=k)continue;
		ds[++cnt].p=a;
		ds[cnt].c=c;
	}
	sort(ds+1,ds+cnt+1);
	for(int i=1;i<=cnt;i++)cout<<ds[i].p<<" "<<ds[i].c<<endl;
	if(!cnt)cout<<"WK"<<endl;
	return 0;
}

