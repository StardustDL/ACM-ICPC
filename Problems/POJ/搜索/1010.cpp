/*
STAMPS
题意：给出不同类型的一组邮票，类型面值可能相同。求符合总面值，且最多取4张邮票的最佳方案。最佳方案满足以下要求：
	  类型数最多。如果类型数相同，则张数少者。如果张数也相同，则单张面值最大者。如果以上都相同，则无最佳方案（平局）。 
分析：dfs+剪枝+细节 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=300;
int n,m,tot;
int stamp[MAXN+3],ans[5],ansnum,sel[5];
bool tie, none,vis[MAXN+3];
void input(){
    n=1;
    if(scanf("%d", &stamp[0])==EOF)exit(0);
    while(scanf("%d",&stamp[n]),stamp[n])n++;
}
int cal(int a[], int n){
    int ret=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        if(!vis[a[i]]){vis[a[i]]=true;ret++;}
    return ret;
}
int getmax(int a[], int n){
    int ret=0;
    for(int i=0;i<n;i++)ret=max(ret,stamp[a[i]]);
    return ret;
}
void compare(){
    int ksel=cal(sel, tot),kans=cal(ans, ansnum);
    int maxans=getmax(ans, ansnum),maxsel=getmax(sel, tot);
    if (ansnum==-1||ksel>kans||(ksel==kans&&ansnum>tot)||(ksel==kans&&ansnum==tot&&maxans<maxsel)){
        tie=false;
        ansnum=tot;
        memcpy(ans,sel,sizeof(sel));
        return;
    }
    if(ksel==kans&&ansnum==tot&&maxans==maxsel)tie=true;
}
void dfs(int now, int money){
    if(money>m)return;
    if(money==m){
        none=false;
        compare();
    }
    if(tot==4)return;
    for(int i=now;i<n;i++){
        sel[tot++]=i;
        dfs(i,money+stamp[i]);
        tot--;
    }
}
void print(){
    if(none){printf("%d ---- none\n",m);return;}
    printf("%d (%d):",m,cal(ans,ansnum));
    if(tie){puts(" tie");return;}
    for(int i=0;i<ansnum;i++)printf(" %d",stamp[ans[i]]);
    puts(""); 
}
int main(){
    while(1){
        input();
        sort(stamp, stamp + n);
        while(scanf("%d", &m), m){
            tot=0;ansnum=-1;
            tie=false;none=true;
            dfs(0,0);
            if(!none)sort(ans,ans+ansnum);
            print();
        }
    }
    return 0;
}
