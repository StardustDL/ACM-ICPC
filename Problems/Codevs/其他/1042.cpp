/*
进制转换
分析：理解题意是关键 
*/
#include<iostream>
using namespace std;
const int MAXN=40;
int w[MAXN+1],wn=0,n,r;
void to(int n,int r){
	int cur=MAXN+1;
	while(n!=0){
		w[--cur]=n%r;
		if(w[cur]<0){//如果此位小于0，那么要补回一个r 
			w[cur]-=r;n=n/r+1;
		}else n/=r;
	}
	wn=cur;
}
void output(){
	cout<<n<<"=";
	for(int i=wn;i<=MAXN;i++){
		if(w[i]<10)cout<<w[i];
		else cout<<(char)('A'+w[i]-10);
	}
	cout<<"(base"<<r<<")"<<endl;
}
int main(){
	while(cin>>n>>r){to(n,r);output();}
	return 0;
}
