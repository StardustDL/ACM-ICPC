/*
金明的预算方案
方法一：枚举每个状态的主件 
未通过测试 
*/
#include<iostream>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=32000,MAXM=60;
struct st{
	bitset<MAXN+3> inb;
	int ans;
	
	st(){
		inb=0;ans=0;
	}
};
int n,m,v[MAXM+3],p[MAXM+3],q[MAXM+3],r[MAXM+3];
st opt[MAXN+3];
bool cmp(const int i,const int j){
	return q[i]<q[j];
}
void read(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>p[i]>>q[i];
		r[i]=i;
	}
}

int solve(){
	for(int i=1;i<=m;i++){
		int k=r[i];
		for(int j=n;j>=v[k];j--){
			st &t=opt[j-v[k]];
			if((t.ans+v[k]*p[k]>opt[j].ans)&&((t.inb[q[k]]==1)||(q[k]==0))){
				opt[j].ans=t.ans+v[k]*p[k];
				opt[j].inb=t.inb;
				opt[j].inb[k]=1;
			}
		}
	}
	return opt[n].ans;
}
int main(){
	read();
	sort(r+1,r+m+1,cmp);
	cout<<solve();
	return 0;
}
