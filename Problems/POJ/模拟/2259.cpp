/*
Team Queue
题意：多个队列的模拟 
*/
#include<iostream>  
#include<cstdio>  
#include<queue>  
#include<cstring>  
#include<map>
#include<bitset>
using namespace std;  
const int MAXN=1000;  
int n;  
bitset<MAXN+3> vis;
queue<int> q[MAXN],que;//que: 总队列,里面存的是子队列的编号 q[i]: 第i个子队列,里面存的是元素值
map<int,int> team;
int main(){  
    int kase=0;  
    while(scanf("%d",&n)!=EOF,n){
    	team.clear();
    	while(!que.empty())que.pop();
    	for(int i=1;i<=n;i++)while(!q[i].empty())q[i].pop(); 
    	vis=0;
        for(int i=0,m,t;i<n;++i){  
            scanf("%d",&m);
            while(m--){scanf("%d",&t);team[t]=i;}  
        }
        printf("Scenario #%d\n",++kase);  
        char str[25];  
        while(scanf("%s",str)!=EOF){
            if(strcmp(str,"STOP")==0){  puts(""); break;}  
            if(strcmp(str,"ENQUEUE") == 0){  
                int t;  
                scanf("%d",&t);
                q[team[t]].push(t);  
                if(!vis[team[t]]){  
                    que.push(team[t]);  
                    vis[team[t]]=1;  
                }  
            }
			else if(strcmp(str,"DEQUEUE")==0){  
                printf("%d\n",q[que.front()].front());  
                q[que.front()].pop();  
                if(q[que.front()].empty()){  
                    vis[que.front()]=0;  
                    que.pop();  
                }  
            }  
        }  
    }  
    return 0;  
}  
