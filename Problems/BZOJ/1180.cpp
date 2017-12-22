/*
[CROATIAN2009]OTOCI
·ÖÎö£ºLCT 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=30000+10;
int c[MAXN+3][2],sum[MAXN+3],fa[MAXN+3],v[MAXN+3],rev[MAXN+3];
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void update(int x){
	sum[x]=sum[c[x][0]]+sum[c[x][1]]+v[x];
}
void pushdown(int x){
	int l=c[x][0],r=c[x][1];
	if(rev[x]){
		rev[x]^=1;rev[l]^=1;rev[r]^=1;
		swap(c[x][0],c[x][1]);
	}
}
bool isroot(int x){
	return !(c[fa[x]][0]==x||c[fa[x]][1]==x);
}
void rotate(int x){
	int y=fa[x],z=fa[y],l=c[y][1]==x,r=l^1;
	if(!isroot(y))c[z][c[z][1]==y]=x;
	fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
	c[y][l]=c[x][r];c[x][r]=y;
	update(y);update(x);
}
int st[MAXN+3],top;
void splay(int x){
	top=0;st[++top]=x;
	for(int i=x;!isroot(i);i=fa[i])st[++top]=fa[i];
	while(top)pushdown(st[top--]);
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if(c[y][0]==x ^ c[z][0]==y)rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void access(int x){
	for(int i=0;x;i=x,x=fa[x])
		splay(x),c[x][1]=i,update(x);
}
void makeroot(int x){
	access(x);splay(x);rev[x]^=1;
}
void link(int x,int y){
	makeroot(x);
	fa[x]=y;
}
int getroot(int x){
	access(x);splay(x);
	while(c[x][0])x=c[x][0];
	return x;
}
int n,q;
char s[20];
int main(){
	n=read();
	for(int i=1;i<=n;i++)v[i]=sum[i]=read();
	for(q=read();q;q--){
		scanf("%s",s);
		int x=read(),y=read();
		if(s[0]=='b'){
			if(getroot(x)==getroot(y)){
				puts("no");
				continue;
			}
			else {
				puts("yes");
				link(x,y);
			}
		}
		else if(s[0]=='p'){
			makeroot(x);
			v[x]=y;update(x);
		}
		else if(s[0]=='e'){
			if(getroot(x)!=getroot(y)){
				puts("impossible");
				continue;
			}
			else{
				
				makeroot(x);
				access(y);
				splay(y);
				printf("%d\n",sum[y]);
			}
		}
	}
	return 0;
}
