/*
[HAOI2007]理想的正方形
分析：预处理以每个点为右下角的正方形的最大最小值，这一步用单调队列n^2解决，维护每一列的单调队列，再维护行的单调队列 
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x7FFFFFFF;
int a,b,n;
int mp[MAXN+3][MAXN+3];
int q[MAXN+3][MAXN+3],h[MAXN+3],t[MAXN+3],s,e,dq[MAXN+3];
int mx[MAXN+3][MAXN+3],ans,mn[MAXN+3][MAXN+3];
void input(){
    scanf("%d%d%d",&a,&b,&n);
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            scanf("%d",&mp[i][j]);
}
void getmax(){
    for(int i=1;i<=b;i++)h[i]=1,t[i]=0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){//预处理每一列的单调队列，只考虑前i行 
            while(h[j]<=t[j]&&i-q[j][h[j]]+1>n)h[j]++;
            while(h[j]<=t[j]&&mp[q[j][t[j]]][j]<=mp[i][j])t[j]--;
            q[j][++t[j]]=i;
        }
        e=0;s=1;
        for(int j=1;j<=b;j++){//处理这一行的单调队列 
            while(s<=e&&j-dq[s]+1>n)s++;
            while(s<=e&&mp[q[dq[e]][h[dq[e]]]][dq[e]]<=mp[q[j][h[j]]][j]) e--;
            dq[++e]=j;
            mx[i][j]=mp[q[dq[s]][h[dq[s]]]][dq[s]];
        }
    }
}
void getmin(){
    for(int i=1;i<=b;i++)h[i]=1,t[i]=0;
    for(int i=1;i<=a;i++){
    	for(int j=1;j<=b;j++){
    		while(h[j]<=t[j]&&i-q[j][h[j]]+1>n)h[j]++;
    		while(h[j]<=t[j]&&mp[q[j][t[j]]][j]>=mp[i][j])t[j]--;
    		q[j][++t[j]]=i;
		}
		e=0;s=1;
		for(int j=1;j<=b;j++){
			while(s<=e&&j-dq[s]+1>n)s++;
			while(s<=e&&mp[q[dq[e]][h[dq[e]]]][dq[e]]>=mp[q[j][h[j]]][j])e--;
			dq[++e]=j;
			mn[i][j]=mp[q[dq[s]][h[dq[s]]]][dq[s]]; 
		}
	}
}
int solve(){
    getmin();
    getmax();
    ans=INF;
    for(int i=n;i<=a;i++)
        for(int j=n;j<=b;j++)
            ans=min(ans,mx[i][j]-mn[i][j]);
    return ans;
}
int main(){
    input();
    printf("%d\n",solve());
    return 0;
}
