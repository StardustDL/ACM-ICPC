/*
酸性差值
分析：就是计数，然后找最大和次大，
	  注意结果有两种可能：
	  最大频率最大值-次大频率最小值
	  次大频率最大值-最大频率最小值
*/
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXR=1000;
int n,t,r[MAXR+3],cm=0,cn=0,pm,pn,ans=0;
int main(){
	cin>>n;
	memset(r,0,sizeof(r));
	while(n-->0){
		cin>>t;r[t]++;
	}
	for(int i=MAXR;i>=1;i--){
		if(r[i]>cm){
			cn=cm;
			cm=r[i];
		}
		else if(r[i]>cn)cn=r[i];
	}
	for(int i=1;i<=MAXR;i++)if(r[i]==cn){pn=i;break;}
	for(int i=MAXR;i>=1;i--)if(r[i]==cm){pm=i;break;}
	ans=abs(pm-pn);
	for(int i=1;i<=MAXR;i++)if(r[i]==cm){pm=i;break;}
	for(int i=MAXR;i>=1;i--)if(r[i]==cn){pn=i;break;}
	if(abs(pm-pn)>ans)ans=abs(pm-pn);
	cout<<ans;
	return 0;
} 
