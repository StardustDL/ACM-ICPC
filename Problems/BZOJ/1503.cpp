/*
[NOI2004]郁闷的出纳员
分析：维护一个集合:
	  支持插入元素，所有集合内元素加上K，所有集合内元素减去K，查询第K 大。
	  用w值记录它的加减情况，加（减）操作加在w上加（减）val，当新来一个的时候你插入树中应该是以前工资未变化时的相对值，也就是val-w 
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int MAXN=2e5+100;
int lim;
struct SplayTree {  
    int sz[MAXN];  
    int ch[MAXN][2];  
    int pre[MAXN];  
    int rt,top;  
    inline void up(int x){  
        sz[x]  = cnt[x]  + sz[ ch[x][0] ] + sz[ ch[x][1] ];  
    }  
    inline void Rotate(int x,int f){  
        int y=pre[x];  
        ch[y][!f] = ch[x][f];  
        pre[ ch[x][f] ] = y;  
        pre[x] = pre[y];  
        if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] =x;  
        ch[x][f] = y;  
        pre[y] = x;  
        up(y);  
    }  
    inline void Splay(int x,int goal){//将x旋转到goal的下面  
        while(pre[x] != goal){  
            if(pre[pre[x]] == goal) Rotate(x , ch[pre[x]][0] == x);  
            else {  
                int y=pre[x],z=pre[y];  
                int f = (ch[z][0]==y);  
                if(ch[y][f] == x) Rotate(x,!f),Rotate(x,f);  
                else Rotate(y,f),Rotate(x,f);  
            }  
        }  
        up(x);  
        if(goal==0) rt=x;  
    }  
    inline void RTO(int k,int goal){//将第k位数旋转到goal的下面  
        int x=rt;  
        while(sz[ ch[x][0] ] != k-1) {  
            if(k < sz[ ch[x][0] ]+1) x=ch[x][0];  
            else {  
                k-=(sz[ ch[x][0] ]+1);  
                x = ch[x][1];  
            }  
        }  
        Splay(x,goal);  
    }  
    inline void Newnode(int &x,int c){  
        x=++top;  
        ch[x][0] = ch[x][1] = pre[x] = 0;  
        sz[x]=1; cnt[x]=1;  
        val[x] = c;  
    }  
    inline void init(){  
        sum=ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;  
        rt=top=0; cnt[0]=0;  
    }  
    inline void Insert(int &x,int key,int f){  
        if(!x){  
            Newnode(x,key);  
            pre[x]=f;
            Splay(x,0);
            return;  
        }  
        if(key==val[x]){
            cnt[x]++;
            sz[x]++;
            Splay(x,0);
            return;
        }
		else if(key<val[x])Insert(ch[x][0],key,x);
		else Insert(ch[x][1],key,x);
        up(x);  
    }  
    void del(int &x,int f){  
        if(!x)return;  
        if(val[x]>=lim)del(ch[x][0],x);
		else{  
            sum+=sz[ch[x][0]]+cnt[x];  
            x=ch[x][1];
            pre[x]=f;
            if(f==0) rt=x;
            del(x,f);
        }  
        if(x)up(x);
    }  
    inline int find_kth(int x,int k){  
        if(k<sz[ch[x][0]]+1)return find_kth(ch[x][0],k);  
        else if(k > sz[ ch[x][0] ] + cnt[x] )   
            return find_kth(ch[x][1],k-sz[ch[x][0]]-cnt[x]);  
        else{   
            Splay(x,0);  
            return val[x];  
        }  
    }  
    int cnt[MAXN];  
    int val[MAXN];  
    int sum;  
}spt;  
int main(){
    int n,m;
    char op[5];
    scanf("%d%d",&n,&m);
    int w=0;
    spt.init();
    while(n--){
        int k;
        scanf("%s%d",op,&k);
        if(op[0]=='I'){
            if(k<m)continue;
            spt.Insert(spt.rt,k-w,0);
        }
        else if(op[0]=='A')w+=k;
        else if(op[0]=='S'){
            w-=k;
            lim=m-w;
            spt.del(spt.rt,0);
        }
        else{
            int sz=spt.sz[spt.rt];
            if(k>sz)printf("-1\n");
            else printf("%d\n",spt.find_kth(spt.rt,sz-k+1)+w);
        }
    }
    printf("%d\n",spt.sum);
    return 0;
}
