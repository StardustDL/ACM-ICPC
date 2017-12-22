/*
[POI2015]Piecz??
分析：每次选择左上角的没有沾的然后和印章左上角配在一起沾一下。
		把纸和印章的x都用链表串起来就能把复杂度降为n^2
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
inline int read(){
    int x=0;char ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int T,n,m,a,b,cnt,top;
int mp[1005][1005],qx[1000005],qy[1000005],xx[1000005],yy[1000005];
char ch[1005];
bool check(int x,int y){
	for(int i=1;i<=cnt;i++){
		int tx=x+xx[i],ty=y+yy[i];
		if(tx>n||ty>m||tx<1||ty<1)return 0;
		if(!mp[tx][ty])return 0;
		else mp[tx][ty]=0;
	}
	return 1;
}
int main(){
	T=read();
	while(T--){
		memset(mp,0,sizeof(mp));
		n=read();m=read();a=read();b=read();
		cnt=top=0;
		for(int i=1;i<=n;i++){
			scanf("%s",ch+1);
			for(int j=1;j<=m;j++)
				if(ch[j]=='x'){
					top++;qx[top]=i;qy[top]=j;
					mp[i][j]=top;
				}
		}
		int tx,ty;
		for(int i=1;i<=a;i++){
			scanf("%s",ch+1);
			for(int j=1;j<=b;j++)if(ch[j]=='x'){
				if(!cnt)tx=i,ty=j;
				cnt++;
				xx[cnt]=i-tx,yy[cnt]=j-ty;
			}
		}
		bool flag=0;
		for(int i=1;i<=top;i++)
			if(mp[qx[i]][qy[i]])
				if(!check(qx[i],qy[i])){
					puts("NIE");flag=1;break;
				}
		if(!flag)puts("TAK");
	}
	return 0;
}
