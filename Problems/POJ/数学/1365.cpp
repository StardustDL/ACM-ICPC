/*
Prime Land
题意：给出一个数x的质因数分解，求x-1的质因数分解 
	  为什么本机能编译成功，交了就编译失败。。 
*/
#include<iostream>
#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXP=10000;
bitset<MAXP+3> isp;
int pris[5003],prin=0;
long x;
struct Ans{
	int p,t;
	bool operator <(const Ans &a)const{
		return p<a.p;
	}
};
vector<Ans> ans;
void init(){
	isp=0;
	for(int i=2;i<=MAXP;i++){
		if(!isp[i]){
			pris[++prin]=i;
			for(int j=i*i;j<=MAXP;j+=i){
				isp[j]=1;
			}
		}
	}
	cout<<prin;
}
bool input(){
	int t,e;x=1;char c;
	cin>>t;
	if(t==0)return false;
	cin>>e;
	do{
		for(int i=1;i<=e;i++)x*=t;
		scanf("%c",&c);if(c=='\n')return true;
		cin>>t>>e;
	}while(1);
}
void solve(long x){
	x--;ans.clear();
	for(int i=1;i<=prin&&x>0;i++){
		if(x%pris[i]==0){
			int k=0;
			while((x%pris[i]==0)&&(x>0)){
				x/=pris[i];
				k++;
			}
			ans.push_back((Ans){pris[i],k});
		}
	}
}
void output(){
	sort(ans.begin(),ans.end());
	for(int i=ans.size()-1;i>=0;i--){
		cout<<ans[i].p<<" "<<ans[i].t<<" ";
	}
	cout<<endl;
}
int main(){
	init();
	while(input()){
		//cout<<x<<endl;
		solve(x);output();
	}
	return 0;
} 
/*AC代码
#include<stdio.h>
#include<string.h>
int prime[3000],e[3000];
int main(){
	char a[1000],b[5],c[5];
	int u,v,x;
	while(1){
		gets(a);
		sscanf(a,"%d",&u);
		if(u==0)break;
		x=1;
		int len=0,l=strlen(a);
	    while(1){
			sscanf(a+len,"%s%s",b,c);
			sscanf(b,"%d",&u);
			sscanf(c,"%d",&v);
			while(v--)x*=u;
			len+=strlen(b)+2+strlen(c);
			if(len>l)break;
		}
		x--;
		int tot=0;
		for(u=2;x>1&&u*u<=x;u++){
			if(x%u==0){
				prime[tot]=u;
				e[tot]=0;
				do{
					e[tot]++;
					x/=u;
				}while(x%u==0);
				tot++;
			}
		}
		if(x>1){prime[tot]=x;e[tot++]=1;}
		for(int i=tot-1;i>0;i--)
			printf("%d %d ",prime[i],e[i]);
		printf("%d %d\n",prime[0],e[0]);
	}
	return 0;
} 
*/
