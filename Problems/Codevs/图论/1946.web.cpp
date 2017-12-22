/*
阿狸的打字机 
分析：一开始，就是暴力KMP，
	  对每一个询问利用KMP查询一下出现过多少次，统计得到40分。
	  后来学了AC自动机又听说用它可以拿30分，
	  本来想试试，结果看了题解才发现自己完全没有掌握AC自动机的精髓。
	  这道题是用AC自动机里的fail指针连成的树做的。
	  首先有一个朴素算法： 
	  就是找到第y个单词在trie树上的路径然后沿着每一个点的fail指针走，
	  如果找到x就加1（想想fail指针建立的过程）。
	  由此可以运用逆向思维，
	  以x为根的子树沿着fail指针倒着走能找到多少个y路径上的点就说明x在y上出现过几次。
	  每次都dfs找一遍，这样可以得到70分。
	  可以提前dfs出整个fail树上每个节点最先到达的时间和最后到达时间，
	  因为是dfs所以开始时间——结束时间内都是在同一颗子树上，可以用树状数组去维护，AC。
	  还有一些细节，
	  在建图时一边读入一遍就建立tire（AC自动机），
	  遇到P就标记，遇到B就回退一步（到当前节点的父亲节点），
	  遇到小写字母就建立tire树。
	  同时这是一个离线算法，将询问做成一个边表就可以一次处理多个，
	  处理时遇到P就在x开始时间——结束时间内求有多少个点，
	  遇到B就退回父亲并在当前节点的开始时间处开始删除1，
	  遇到小写字母就在当前节点开始时间处加1。
	  因为如果每次没有B，那比x先插入的点一定不会到x的子树中（len（后面的串）〉=len（前面）），
	  如果有B子树中比x靠前的点也已通过删除删掉了，
	  所以x开始时间——x结束时间求和就是答案。
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 100005
using namespace std;
struct node{
       int next[26],fail,father;
}ac[MAXN];
struct rec{
       int y,n;
}e1[MAXN],e2[MAXN];
int first[MAXN],second[MAXN],ls[MAXN],le[MAXN],num[MAXN],quary[MAXN][3],tree[MAXN];
int top,tn,tot,all,len,t,m,sum;
char S[MAXN],s[MAXN];

void Buildfail(){
    queue<int> q;
    ac[0].fail=-1;
    q.push(0);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
          	int tmp=ac[u].next[i],p;
        	if (tmp){
                for(p=ac[u].fail;p!=-1;p=ac[p].fail)
					if (ac[p].next[i]) {ac[tmp].fail=ac[p].next[i];break;}
                if (p==-1) ac[tmp].fail=0;
            	q.push(tmp);
            }
        }    
    }
}
void Dfs(int k){
     ls[k]=++t;
     for (int i=first[k];i;i=e1[i].n)
         Dfs(e1[i].y);
     le[k]=t;
}
void Buildtree(){
     for (int i=1;i<=tn;i++){
         e1[++tot].y=i;
         e1[tot].n=first[ac[i].fail];
         first[ac[i].fail]=tot;
     }
     Dfs(0);
}
void Init(){
     scanf("%s",S);
     int p=0;
     top=-1,len=strlen(S);
     for (int i=0;i<len;i++){
        if (S[i]=='P') num[++sum]=p;
        if (S[i]=='B') p=ac[p].father;
        if ('a'<=S[i] && S[i]<='z'){
			int index=S[i]-'a';
            if (!ac[p].next[index]){
				ac[++tn].father=p;
                ac[p].next[index]=tn;
            }
			p=ac[p].next[index];
         }
     }
     Buildfail();
     Buildtree();
     scanf("%d",&m);
     for (int i=1;i<=m;i++){
         scanf("%d %d",&quary[i][0],&quary[i][1]);
         quary[i][0]=num[quary[i][0]],quary[i][1]=num[quary[i][1]];
         e2[++all].y=i;
         e2[all].n=second[quary[i][1]];
         second[quary[i][1]]=all;
     }
}
int treesum(int k){
    int ans=0;
    for (;k>0;k-=k & (-k))
        ans+=tree[k];
    return ans;
}

void treeinc(int k,int det){
    for (;k<=t;k+=k&(-k))tree[k]+=det;
}

void Solve(){
     int p=0;
     for (int i=0;i<len;i++){
         if (S[i]=='P') 
		 	for(int j=second[p];j;j=e2[j].n)
				quary[e2[j].y][2]=treesum(le[quary[e2[j].y][0]])-treesum(ls[quary[e2[j].y][0]]-1);
         if (S[i]=='B') {treeinc(ls[p],-1);p=ac[p].father;}
         if ('a'<=S[i] && S[i]<='z') {p=ac[p].next[S[i]-'a'];treeinc(ls[p],1);}
     }
     for (int i=1;i<=m;i++)
         printf("%d\n",quary[i][2]);
     return;
}

int main(){
    Init();
    Solve();
    return 0;
}
