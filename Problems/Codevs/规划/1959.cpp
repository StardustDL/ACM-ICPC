/*
拔河比赛
分析：刚开始题意理解错了，不太好编，但由于数据范围小，转成判定性问题，然后暴力枚举 
*/ 
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
int n,w[MAXN+3],m=0,sum=0,mn,ans;
bitset<450*MAXN+3> opt[(MAXN>>1)+3];
int main(){
	cin>>n;for(int i=1;i<=n;i++){cin>>w[i];sum+=w[i];}
	m=(n+1)>>1;
	opt[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=m-1;j>=0;j--)
			for(int k=450*i;k>=0;k--)
				if(opt[j][k])opt[j+1][k+w[i]]=1;
	mn=INF,ans=0;
	for(int i=0;i<=450*m;i++){
		if(opt[m][i]&&mn>abs(sum-(i<<1))){
			mn=abs(sum-(i<<1));
			ans=i;
		}
	}
	mn=sum-ans;
	if(mn>ans)swap(mn,ans);
	cout<<mn<<" "<<ans; 
	return 0;
}
/*
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,w[MAXN+3],opt[450*MAXN+3],s=0,sum=0; 
int main(){
	cin>>n;for(int i=1;i<=n;i++){cin>>w[i];sum+=w[i];}
	s=sum>>1;
	for(int i=1;i<=n;i++)
		for(int j=s;j>=w[i];j--)
			opt[j]=max(opt[j-w[i]]+w[i],opt[j]);
	cout<<sum<<endl;
	n=sum-opt[s];
	s=opt[s];
	if(n<s)swap(s,n);
	cout<<s<<" "<<n;
	return 0;
}
*/
