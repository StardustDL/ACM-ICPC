/*
[Usaco2010 Dec]The Trough Game
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,cnt;
int a[105][25],b[105],now[25],ans[25];
bool check() {
	for(int i=1,tot=0; i<=m; i++,tot=0) {
		for(int j=1; j<=n; j++)
			tot+=((a[i][j]&now[j])>0);
		if(tot!=b[i])return 0;
	}
	return 1;
}
void solve() {
	int t=1<<n,tmp;
	while(t--) {
		if(check()) {
			for(int i=1; i<=n; i++)ans[i]=now[i];
			if(++cnt>=2)return;
		}
		now[tmp=n]++;
		while(now[tmp]==2){
			now[tmp]=0;
			now[--tmp]++;
		}
	}
}
int main() {
	n=read();m=read();
	for(int i=1; i<=m; i++) {
		for(int j=1;j<=n;j++)scanf("%1d",&a[i][j]);
		b[i]=read();
	}
	solve();
	if(!cnt)puts("IMPOSSIBLE");
	else if(cnt==1)for(int i=1; i<=n; i++)printf("%d",ans[i]);
	else puts("NOT UNIQUE");
	return 0;
}
