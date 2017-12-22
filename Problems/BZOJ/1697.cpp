/*
[Usaco2007 Feb]Cow Sorting牛排序
分析：将问题转成置换，可以发现置换的一个循环内一定是用最小的去和其他的交换。但还有一种：用全体的最小的交换进来，进行交换，再交换回去，可能更优 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=10000;
int a[MAXN+3],b[MAXN+3],c[10*MAXN+3],n;//注意c是数值范围 
vector<int> g[MAXN+3];
bool vis[MAXN+3];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)c[b[i]]=i;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int id=c[a[i]];
        if(vis[id])continue;
        cnt++;
        do{
        	g[cnt].push_back(b[id]);//也可以写成a[id]，其实就差一位 （因为是循环，所以不会错 
        	vis[id]=1;
        	id=c[a[id]];
		}while(!vis[id]);
    }
    long long sum=0;
    for(int i=1;i<=cnt;i++){
        int sz=g[i].size(),mn=*min_element(g[i].begin(),g[i].end());
        for(int j=0;j<sz;j++)sum+=g[i][j];
        sum-=mn;
        sum+=min((sz-1)*mn,(sz-1)*b[1]+2*(b[1]+mn));
    }
    printf("%lld\n",sum);
    return 0;
}
