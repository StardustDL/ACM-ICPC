/*
Help Jimmy
分析：dp[i][0]表示从上数第i层左边到达地面的最小时间，dp[i][1]为从右边的最小时间
	  先找到下落到的板，然后直接计算即可，记忆化搜索易编 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct data{
	int x1,x2,y;
	bool operator < (const data &t)const{
		return y>t.y;
	}
}a[MAXN+3];
int dp[MAXN+3][2];
bool v[MAXN+3];
int n,maxy;
void dfs(int);
void solve(int,int& ,int);
void solve(int i,int &val,int x){//求解第i个板，从横坐标为x的地方下落（一定是左边缘或右边缘）的最优解，存到val中 
	val=INF;
	bool flg=false;
	int j=i+1;
	while(j<=n&&!(a[j].x1<=x&&x<=a[j].x2))j++;//找到能接住的第一块板
	if(j>n){//若没有
		if(a[i].y<=maxy)val=a[i].y;
		else val=-1;
	}
	else{
		if(a[i].y-a[j].y>maxy)val=-1;//下落距离过大 
        else{//计算最优值 
        	dfs(j);
			if(dp[j][0]==-1&&dp[j][1]==-1)val=-1;
            if(dp[j][0]!=-1)val=min(val,dp[j][0]+abs(a[j].x1-x)+a[i].y-a[j].y);
            if(dp[j][1]!=-1)val=min(val,dp[j][1]+abs(a[j].x2-x)+a[i].y-a[j].y);
		}
	}
}
void dfs(int i){
	if(v[i])return;
    v[i]=true;
    solve(i,dp[i][0],a[i].x1);
    solve(i,dp[i][1],a[i].x2);
}
int main(){
    int t,x,y,ans;
    cin>>t;
    while(t--){
		cin>>n>>x>>y>>maxy;
        for(int i=1;i<=n;i++)cin>>a[i].x1>>a[i].x2>>a[i].y;
        sort(a+1,a+n+1);
        //for(int i=1;i<=n;i++)cout<<a[i].y<<endl;
        memset(dp,0,sizeof(dp));
        memset(v,false,sizeof(v));
        ans=INF;
        bool flg=false;
        int j=1;
        while(!(a[j].x1<=x&&x<=a[j].x2) && j<=n)j++;//找到能接住的第一块板 
        if(j>n)ans=y;//一定有解，这里不用判断 
        else{
			dfs(j);
            if(dp[j][0]!=-1)ans=min(ans,dp[j][0]+abs(a[j].x1-x)+y-a[j].y);
            if(dp[j][1]!=-1)ans=min(ans,dp[j][1]+abs(a[j].x2-x)+y-a[j].y);
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
          

