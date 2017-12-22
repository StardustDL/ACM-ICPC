/*
引水入城 
分析：每个点能管的点是连续的，所以先DFS，要记忆化，然后求出每个点的所管区间，转成线段覆盖
	  具体实现细节有些麻烦 
*/ 
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
struct wt{
    int left,right;
};
wt qx[501],wa;
int h[501][501],n,m,i,j,water[501][501],maxn=0,flag;
void find(int x,int y,int z){
    if((h[x][y]>h[x-1][y])&&(water[x-1][y]!=z)&&(x-1>=1)){
        water[x-1][y]=z;
        find(x-1,y,z);
    }
    if((h[x][y]>h[x+1][y])&&(water[x+1][y]!=z)&&(x+1<=n)){
        water[x+1][y]=z;
        find(x+1,y,z);
    }
    if((h[x][y]>h[x][y-1])&&(water[x][y-1]!=z)&&(y-1>=1)){
        water[x][y-1]=z;
        find(x,y-1,z);
    }
    if((h[x][y]>h[x][y+1])&&(water[x][y+1]!=z)&&(y+1<=m)){
        water[x][y+1]=z;
        find(x,y+1,z);
    }
}
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++) cin>>h[i][j];
    for(i=1;i<=m;i++)
        if(water[1][i]==0){
            water[1][i]=i;
            find(1,i,i);
            for(j=1;j<=m;j++)
                if(water[n][j]==i){
                    if(qx[i].left==0)qx[i].left=j;
					qx[i].right=j;
                }
        }
    for(i=1;i<=m;i++)water[1][i]=i;
    int t=0,ans=0;
    for(i=1;i<=m;i++)if(water[n][i]==0)t++;
    if(t>0){
        cout<<0<<'\n';
        cout<<t;
    }
    else{
        cout<<1<<'\n';
        for(i=1;i<=m;i++) if((qx[i].left==1)&&(qx[i].right>maxn)){
            maxn=qx[i].right;
            wa.right=qx[i].right;
        }
        ans++;
        while(wa.right<m){
            for(i=1;i<=m;i++) if((qx[i].left<=wa.right+1)&&(qx[i].right>maxn)) maxn=qx[i].right;
            wa.right=maxn;
            ans++;
        }
        cout<<ans;
    }
    return 0;
}
/*
#include<iostream>
#include<bitset> 
#include<cstring> 
#include<algorithm> 
using namespace std;
const int MAXN=500;
struct segment{
	int l,r;
	bool operator <(const segment &s)const{
		return l<s.l;
	}
}S[MAXN+3];
int mp[MAXN+3][MAXN+3],m,n,deep,dl,dr;
bitset<MAXN+3> vis[MAXN+3];
void input(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
}
void dfs(int x,int y){
	if(x>n||y>m||x<1||y<1||vis[x][y])return;
	vis[x][y]=1;
	if(deep<x){
		deep=x;dl=dr=y;
	}
	else if(deep==x){
		dl=min(y,dl);dr=max(y,dr);
	}
	if(mp[x][y]>mp[x+1][y]&&x+1<=n)dfs(x+1,y);
	if(mp[x][y]>mp[x][y-1]&&y-1>=1)dfs(x,y-1);
	if(mp[x][y]>mp[x][y+1]&&y+1<=m)dfs(x,y+1);
	if(mp[x][y]>mp[x-1][y]&&x-1>=1)dfs(x-1,y);
}
void load(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)vis[i]=0;
		deep=0,dl=m+1,dr=0;
		dfs(1,i);
		if(deep==n){
			S[i].l=dl;S[i].r=dr;
		}
	}
}
int opt[MAXN+3];
int main(){
	input();
	load();
	memset(opt,0,sizeof(opt));
	for(int i=1;i<=m;i++){
		for(int j=S[i].l;j<=S[i].r;j++)opt[j]=1;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(!opt[i])ans++;
	}
	if(ans==0){
		cout<<1<<endl;
		ans=0;
		int r=0,mx=0;
		for(int i=1;i<=m;i++)if(S[i].l==1&&S[i].r>r)r=S[i].r;
		ans++;
		mx=r;
		while(r<m){
			for(int i=1;i<=m;i++)if(S[i].r>mx&&S[i].l<=r)mx=S[i].r;
			r=mx;
			ans++;
		}
		cout<<ans;
	}
	else{
		cout<<0<<endl;
		cout<<ans;
	}
	return 0;
}*/
