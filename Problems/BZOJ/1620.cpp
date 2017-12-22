/*
[Usaco2008 Nov]Time Management 时间管理
分析：贪心，每个时间都有个完成时间，那么我们就从最大的 完成时间的开始往前推
		每一次更新最早开始时间（min(ans, a[i].y)代表i事件最早的完成时间） 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1000;
struct thing{
    int t,s;
    bool operator <(const thing &t)const{
         return s<t.s;
    }
}ts[MAXN+3];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&ts[i].t,&ts[i].s);
    sort(ts+1,ts+n+1);
    int ans=ts[n].s;
    for(int i=n;i>=1;i--){
        ans=min(ans,ts[i].s)-ts[i].t; 
    } 
    if(ans<0)puts("-1");
    else printf("%d\n",ans);
    return 0;
}


