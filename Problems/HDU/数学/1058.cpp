/*
Humble Numbers
题意：求因子只有{2,3,5,7}，的数列中的n项
分析：离线，用priority_queue和set做，但是WA了。。。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
int dp[6000] = { 0, 1 },i2 = 1, i3 = 1, i5 = 1, i7 = 1, cnt = 1, N;
char lst[5][5] = { "th", "st", "nd", "rd" };
int getUp(){
    int t=min(min(2*dp[i2],3*dp[i3]), 
              min(5*dp[i5],7*dp[i7]));  
    if(t==2*dp[i2])++i2;
    if(t==3*dp[i3])++i3;
    if(t==5*dp[i5])++i5;
    if(t==7*dp[i7])++i7; 
    return t; 
}
void init(){
    for(int i=2;i<=5842;++i)dp[i]=getUp();
}
char* getLst(int n) {
     if(n%100!=11&&n%10==1)return lst[1];
     else if(n%100!=12&&n%10==2)return lst[2];
     else if(n%100!=13&&n%10==3)return lst[3];
     else return lst[0];      
}
int main(){
    init();
    while(scanf("%d",&N)!=EOF&&N){
          printf("The %d",N);
          printf("%s",getLst(N));
          printf(" humble number is %d.\n",dp[N]);      
    }
    return 0;
} 
/* 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue> 
#include<set>
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
const LL ARR[4]={2,3,5,7};
struct cmp{
	bool operator ()(const LL a,const LL b){
		return a>b;
	}
};
priority_queue<LL,vector<LL>,cmp> q;
set<LL> S;
struct Ans{
	int k;
	LL m;
	void outputk(){
		printf("%d",k);
		if(k>=10&&k<=20){printf("th");return;} 
		switch(k%10){
			case 1:printf("st");break;
			case 2:printf("nd");break;
			case 3:printf("rd");break;
			default:printf("th");break;
		}
	}
}ans[MAXN+3];
bool cmp(int i,int j){return ans[i].k<ans[j].k;}
int r[MAXN+3],cur=0,n=0,rc=1;
int main(){
	int t;while(scanf("%d",&t),t)ans[r[++n]=n].k=t;
	sort(r+1,r+n+1,cmp);
	q.push(1);
	while(rc<=n){
		t=q.top();q.pop();
		cur++;
		if(ans[r[rc]].k==cur){
			ans[r[rc]].m=t;rc++;
			while(rc<=n&&ans[r[rc]].k==cur){
				ans[r[rc]].m=t;rc++;
			}
		}
		for(int i=0;i<4;i++){
			if(S.count(ARR[i]*t)==0){
				S.insert(ARR[i]*t);q.push(ARR[i]*t); 
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("The ");
		ans[i].outputk();
		printf(" humble number is %lld.\n",ans[i].m);
	}
	return 0;
}
*/ 
