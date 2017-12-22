/*
[Usaco2005 oct]Flying Right 飞行航班
分析：贪心。到某个点如果有一些奶牛 如果有空座位就让它们上
	  否则如果它的目标离车上目标最远的牛要近 就把那头牛踢下去换新牛.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio> 
using namespace std;
const int MAXN=10000; 
struct node{
    int v,w;
    const bool operator <(const node &b)const{
        return v<b.v;
    }
    node(int v,int w):v(v),w(w){}
};
int K,N,C;
vector<node> d1[MAXN+3],d2[MAXN+3];
int a[2][MAXN+3];
priority_queue<node> q;
int solve(vector<node> *t,int flag){
    int k=0,ans=0;
    while(!q.empty())q.pop();
    for(int i=1;i<=N;i++){
        ans+=a[flag][i];//扫到这里时，已经删除了不能上飞机的，此时的a[flag][i]表示在i下飞机的 
        k-=a[flag][i];
        for(int j=0;j<t[i].size();j++){
        	k+=t[i][j].w;
            q.push(t[i][j]);
        }
        while(k>C){
            node tp=q.top();q.pop();//取 最远的，删除 
            if(k-C>=tp.w){
                k-=tp.w;
                a[flag][tp.v]-=tp.w;
            }
            else{
                a[flag][tp.v]-=(k-C);
                tp.w-=k-C;
                k=C;
                q.push(tp);
            }
        }
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&K,&N,&C);
    for(int i=1,u,v,w;i<=K;i++){
        scanf("%d%d%d",&u,&v,&w);
        if(v>u){
            d1[u].push_back(node(v,w));
            a[0][v]+=w;
        }
        else{
            d2[N-u+1].push_back(node(N-v+1,w));
            a[1][N-v+1]+=w;
        }
    }
    printf("%d\n",solve(d1,0)+solve(d2,1));
    return 0;
}
