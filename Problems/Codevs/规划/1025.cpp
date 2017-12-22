/*
ѡ��
�������Լӱ��ε�01������ȥ�أ�Ԥ�����ѡ�ˣ�01���� 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=103;
double d;
int n,k,x,v[MAXN],w[MAXN],r[MAXN],b[MAXN],opt[MAXN*10],base=0;
void input(){
	cin>>n>>k;
	cin>>d;
	x=d*10;
	for(int i=1;i<=n;i++){
		cin>>d;
		v[i]=d*10;
	}
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>r[i];
	for(int i=1;i<=k;i++)cin>>b[i];
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[j]==r[i]){
				r[i]=0;
			}
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(r[j]==b[k]){
				x-=v[j];
				r[j]=0;
				base+=w[j];
			}
		}
	}
}
int solve(){
	for(int i=1;i<=n;i++){
		if(r[i]==0)continue;
		for(int j=x;j>=v[i];j--){
			opt[j]=max(opt[j],opt[j-v[i]]+w[i]);
		}
	}
	return opt[x];
}
int main(){
	ios::sync_with_stdio(false);
	input();
	init();
	cout<<base+solve();
	return 0;
}
