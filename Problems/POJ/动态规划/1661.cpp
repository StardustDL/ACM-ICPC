/*
Help Jimmy
������dp[i][0]��ʾ��������i����ߵ���������Сʱ�䣬dp[i][1]Ϊ���ұߵ���Сʱ��
	  ���ҵ����䵽�İ壬Ȼ��ֱ�Ӽ��㼴�ɣ����仯�����ױ� 
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
void solve(int i,int &val,int x){//����i���壬�Ӻ�����Ϊx�ĵط����䣨һ�������Ե���ұ�Ե�������Ž⣬�浽val�� 
	val=INF;
	bool flg=false;
	int j=i+1;
	while(j<=n&&!(a[j].x1<=x&&x<=a[j].x2))j++;//�ҵ��ܽ�ס�ĵ�һ���
	if(j>n){//��û��
		if(a[i].y<=maxy)val=a[i].y;
		else val=-1;
	}
	else{
		if(a[i].y-a[j].y>maxy)val=-1;//���������� 
        else{//��������ֵ 
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
        while(!(a[j].x1<=x&&x<=a[j].x2) && j<=n)j++;//�ҵ��ܽ�ס�ĵ�һ��� 
        if(j>n)ans=y;//һ���н⣬���ﲻ���ж� 
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
          

