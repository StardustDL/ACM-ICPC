/*
[JSOI2008]火星人prefix
分析：用splay维护字符串区间Hash值，然后二分+hash判断答案 
	  这个splay的写法不错，注意留开头和结尾的0，这样保证取区间时是没有问题的 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MOD=9875321;
const int MAXN=150000+5; 
int ch[MAXN+3][2],pa[MAXN+3],id[MAXN+3];
int size[MAXN+3],v[MAXN+3],ha[MAXN+3],p[MAXN+3];
int n,m,rt,sz;
char str[MAXN+3];
void update(int k){
	int l=ch[k][0],r=ch[k][1];
	size[k]=size[l]+size[r]+1;
	ha[k]=ha[l]+(LL)v[k]*p[size[l]]%MOD+(LL)p[size[l]+1]*ha[r]%MOD;
	ha[k]%=MOD;
}
void rotate(int x,int &k){
	int f=pa[x],g=pa[f],l=ch[f][0]!=x,r=l^1;
	if(f==k)k=x;
	else {
		if(ch[g][0]==f)ch[g][0]=x;
		else ch[g][1]=x;
	}
	pa[x]=g;pa[f]=x;pa[ch[x][r]]=f;
	ch[f][l]=ch[x][r];ch[x][r]=f;
	update(f);update(x);
}
void splay(int x,int &k){
	while(x!=k){
		int f=pa[x],g=pa[f];
		if(f!=k){
			if(ch[f][0]==x^ch[g][0]==f)rotate(x,k);
			else rotate(f,k);
		}
		rotate(x,k);
	}
}
int find(int k,int rk){
    int l=ch[k][0],r=ch[k][1];
    if(size[l]+1==rk)return k;
    else if(size[l]>=rk)return find(l,rk);
    else return find(r,rk-size[l]-1);
}
void insert(int k,int val){
	int x=find(rt,k+1),y=find(rt,k+2);
	splay(x,rt);splay(y,ch[x][1]);
	int z=++sz;ch[y][0]=z;pa[z]=y;v[z]=val;
	update(z);update(y);update(x);
}
void build(int l,int r,int f){
    if(l>r)return;
    int now=id[l],last=id[f];
    if(l==r){
        v[now]=ha[now]=str[l]-'a'+1;
        pa[now]=last;size[now]=1;
        if(l<f)ch[last][0]=now;
        else ch[last][1]=now;
        return;
    }
    int mid=(l+r)>>1;now=id[mid];
    build(l,mid-1,mid);build(mid+1,r,mid);
    v[now]=str[mid]-'a'+1;
	pa[now]=last;
	update(now);
    if(mid<f)ch[last][0]=now;
    else ch[last][1]=now;
}
int query(int k,int val){
	int x=find(rt,k),y=find(rt,k+val+1);
	splay(x,rt);splay(y,ch[x][1]);
	return ha[ch[y][0]];
}
int solve(int x,int y){
	int l=1,r=min(sz-x,sz-y)-1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(query(x,mid)==query(y,mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}
int main(){
	scanf("%s",str+2);
	n=strlen(str+2);
	p[0]=1;
	for(int i=1;i<=MAXN;i++)p[i]=p[i-1]*27%MOD;
	for(int i=1;i<=n+2;i++)id[i]=i;
	build(1,n+2,0);//前留一个，后留一个(str[1]=0,str[n+2]='\0'=0) 
	sz=n+2;rt=(n+3)>>1;
	scanf("%d",&m);
	int x,y;
	char s[2],d[2];
	for(int i=1;i<=m;i++){
		scanf("%s",s+1);
		scanf("%d",&x);
		switch(s[1]){
			case 'Q':
				scanf("%d",&y);
				printf("%d\n",solve(x,y));
				break;
			case 'R':
				scanf("%s",d+1);x=find(rt,x+1);splay(x,rt);//注意前面留了一个,x+1指的是原串的x 
				v[rt]=d[1]-'a'+1;update(rt);
				break;
			case 'I':
				scanf("%s",d+1);insert(x,d[1]-'a'+1);
				break;
		}
	}
	return 0;
}
