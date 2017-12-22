/*
Gangsters
题意：有一伙人要去饭店，饭店的门可以控制大小，但是每个时间间隔只能开大一个或者关闭一个，每个人有一个肥胖值，到场时间和繁荣度。人在他的到场时间到达饭店，如果饭店的门正好符合他的体型，饭店就能获得当前的繁荣度。问最大的繁荣度是多少。
分析：两种DP：
	  opt[i][j]表示i时刻容量为j，则有
		opt[i][j]=max{opt[i-1][j],opt[i-1][j-1],opt[i-1][j+1]}+当前时刻能获得的价值 
		单独处理j=0和j=k的情况。
	  此方法WA了。。但不知道为什么。<UCTAG>
	  另一个方法是：对于一个时间T和一个人P，T时间下S开度的状态只能从0~T-S转移过来，有了这个就有了状态方程。
		dp[i] = max(dp[j] + p);其中ti-tj>si-sj。 
*/
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=100,MAXT=30000;
int n,k,T,opt[2][MAXN+3],t[MAXN+3],p[MAXN+3],s[MAXN+3],ans=0;
bitset<MAXT+3> has=0;
int getw(int tme,int l){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t[i]==tme&&s[i]==l)ans+=p[i];
	}
	return ans;
}
int main(){
	cin>>n>>k>>T;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		has[t[i]]=1;
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=0;i<=T;i++){
		if(i>0)opt[i%2][0]=max(opt[(i-1)%2][0],opt[(i-1)%2][1])+(has[0]?getw(i,0):0);
		for(int j=1;j<k;j++){
			int w=0;
			if(has[i])w=getw(i,j);
			opt[i%2][j]=max(opt[(i-1)%2][j],max(opt[(i-1)%2][j-1],opt[(i-1)%2][j+1]))+w;
		}
		opt[i%2][k]=max(opt[(i-1)%2][k],opt[(i-1)%2][k-1])+(has[k]?getw(i,k):0);
	}
	for(int i=0;i<=k;i++){
		ans=max(opt[T%2][i],ans);
	}
	cout<<ans;
	return 0;
}*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100;
struct peo{
    int p,s,t;
    bool operator < (const peo& ano) const{
        return t < ano.t;
    }
}g[MAXN+3];
int n,k,t,opt[MAXN+3],ans=0;
int main(){
    scanf("%d%d%d",&n,&k,&t);
    for(int i=1;i<=n;i++)scanf("%d",&g[i].t);
    for(int i=1;i<=n;i++)scanf("%d",&g[i].p);
    for(int i=1;i<=n;i++)scanf("%d",&g[i].s);
    g[0].t=g[0].s=g[0].p=0;
    sort(g+1,g+n+1);
    for(int i=1;i<=n;i++){
        opt[i]=-1;
        for (int j=0;j<i;j++){
            if(opt[j]==-1)continue;
            if(abs(g[i].s-g[j].s)<=g[i].t-g[j].t)
            	opt[i]=max(opt[i],opt[j]+g[i].p);
        }
        ans=max(ans,opt[i]);
    }
    cout<<ans<<endl;
    return 0;
}
