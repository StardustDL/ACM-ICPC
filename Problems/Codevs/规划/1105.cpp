/*
过河
分析：由于路很长，石子却很少，先压缩，但压缩的条件很关键，这里设定为R=20
	  方程很好写，但是注意特判S=T的情况 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXL=1000000,MAXM=100,INF=0x3f3f3f3f,REST=33,R=20;
int l,s,t,m,cr,la,x[MAXM+3],k[MAXM+3],opt[MAXL+REST];
bitset<MAXL+3> has;
void input(){
	cin>>l>>s>>t>>m;
	has=0;
	la=0;
	for(int i=1;i<=m;i++)cin>>k[i];
	sort(k+1,k+m+1);
	for(int i=1;i<=m;i++){
		int tt=k[i]-k[i-1];//cout<<tt<<endl;
		if(tt>2*(t-s)+R){
			//cout<<"!!!";
			x[i]=x[i-1]+2*(t-s)+R;
		}
		else x[i]=x[i-1]+tt;
		//cout<<tt<<" "<<x[i]<<endl;
		has[x[i]]=1;
	}
	//cout<<endl;
	l=x[m]+2*(t-s)+3;
	/*for(int i=1;i<=l;i++){
		cout<<x[i]<<" ";
	}*/
}
int dp(){
	memset(opt,INF,sizeof(opt));
	opt[0]=0;
	int e=t+R;
	for(int i=1;i<=l+e+1;i++){
		for(int j=s;j<=t;j++){
			if(i-j<0)break;
			opt[i]=min(opt[i-j],opt[i]);
		}
		opt[i]+=has[i];
	}
	int ans=INF;
	for(int i=0;i<=e+1;i++){
		ans=min(opt[l+i],ans);
	}
	if(s==t){//如果S==T，ans为石子距离是S的倍数的个数
		ans=0;for(int i=1;i<=m;i++)ans+=!(k[i]%s); 
	}
	return ans;
}
int main(){
	input();
	cout<<dp();
	return 0;
}
