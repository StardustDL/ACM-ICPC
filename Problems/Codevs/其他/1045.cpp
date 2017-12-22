/*
回文数
分析：翻转，累加，进位，判断 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=41;
int n,m[MAXN],t[MAXN],mn;
void input(){
	cin>>n;
	char c;int i=0;
	while(cin>>c){
		if(c<='9')m[++i]=c-'0';
		else m[++i]=c-'A'+10;
	}
	mn=i;
}
bool check(){
	for(int i=1;i<=mn;i++){
		if(m[i]!=m[mn-i+1])return false;
	}
	return true;
}
int solve(){
	int ans=0;
	while(ans++<30){
		memset(t,0,sizeof(t));
		for(int i=1;i<=mn;i++)t[i]=m[i]+m[mn-i+1];
		for(int i=1;i<=mn;i++){
			if(t[i]>=n){
				t[i]-=n;t[i+1]+=1;
			}
		}
		if(t[mn+1]!=0)mn++;
		memcpy(m,t,sizeof(t));
		if(check())break;
	}
	return ans;
} 
int main(){
	input();
	n=solve();
	if(n>30){
		cout<<"Impossible!";
	}
	else cout<<"STEP="<<n;
	return 0;
}
