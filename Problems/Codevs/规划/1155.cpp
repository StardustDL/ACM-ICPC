/*
金明的预算方案
分析：有依赖关系的背包DP，由于只有两个附件，所以只有四种转移，直接枚举即可 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=32000,MAXM=60;
struct thing{
	bool ism;
	int f1,f2,v,w;
	thing(){
		ism=false;
		f1=f2=v=w=0;
	}
}th[MAXM+3];
int n,m,opt[MAXN/10+3];
void input(){
	cin>>n>>m;
	n/=10;
	int t;
	for(int i=1;i<=m;i++){
		cin>>th[i].v>>th[i].w>>t;
		th[i].v/=10;
		th[i].w*=th[i].v;
		if(t==0)th[i].ism=true;
		else{
			th[i].ism=false;
			if(th[t].f1==0)th[t].f1=i;
			else th[t].f2=i;
		}
	}
	th[0].w=-1;
}
int Max(int a,int b,int c,int d,int e){
	return max(a,max(b,max(c,max(d,e))));
}
int dp(){
	int k=0;
	for(int i=1;i<=m;i++){
		if(!th[i].ism)continue;
		thing &t=th[i];
		thing &l=th[t.f1],&r=th[t.f2];
		for(int j=n;j>=t.v;j--){
			opt[j]=Max(
				opt[j],
				opt[j-t.v]+t.w,
				(l.w!=-1&&j-t.v-l.v>=0)?opt[j-t.v-l.v]+t.w+l.w:0,
				(r.w!=-1&&j-t.v-r.v>=0)?opt[j-t.v-r.v]+t.w+r.w:0,
				(l.w!=-1&&r.w!=-1&&j-t.v-l.v-r.v>=0)?opt[j-t.v-l.v-r.v]+t.w+l.w+r.w:0
			);
		}
	}
	return opt[n];
}
int main(){
	ios::sync_with_stdio(false);
	input();
	cout<<dp()*10;
	return 0;
}

