/*
[POI2005]sam-Toy Cars
分析：记录下每个玩具下次出现的位置，每次要删的话选一个最远的删掉，用堆维护这一过程 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
#define pa pair<int,int>
using namespace std;
const int MAXN=500000; 
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,K,p,ans;
int a[MAXN+3],nxt[MAXN+3],last[MAXN+3];
bool mark[MAXN+3];
priority_queue<pa>q;
int main(){
    n=read();K=read();p=read();
    for(int i=1;i<=n;i++)last[i]=p+1;
    for(int i=1;i<=p;i++)a[i]=read();
    for(int i=p;i;i--){
        nxt[i]=last[a[i]];
        last[a[i]]=i;
    }
    for(int i=1;i<=p;i++){
        if(mark[a[i]]){q.push(make_pair(nxt[i],a[i]));continue;}
        if(K)K--;
        else{
            while(!mark[q.top().second])q.pop();
            mark[q.top().second]=0;q.pop();
        }
        q.push(make_pair(nxt[i],a[i]));
        mark[a[i]]=1;ans++;
    }
    printf("%d\n",ans);
    return 0;
}
