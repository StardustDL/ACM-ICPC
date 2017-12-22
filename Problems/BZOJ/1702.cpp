/*

分析：有趣的转化： 
		sum[j][k]用b1 b2 b3表示 sum[i - 1][k]用a1 a2 a3表示
		(b1-a1)==(b2-a2)==(b3-a3)==P(b1-a1)
		所有式子减去(b1-a1)得到:
		((b2-b1)-(a2-a1)) == ((b3-b1)-(a3-a1)) == P-(b1-a1) == 0
		也就是说[i,j]满足条件的话，满足下面的条件就可以了~
		b2-b1 == a2-a1
		b3-b1 == a3-a1 
	  这样减去第一项，hash一下 
*/
#include <cstdio>
#include <set>
#include <map>
#include <iostream>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXM = 30 + 2;
int n, m,ans = 0;
int sum[MAXN][MAXM], t;
map<string, int> q;
map<string, int>::iterator it;
inline int get(int k,int p){
	return (k>>(p-1))&1;
}
char str[200];
inline string change(int *a){
	t=0;
	for(int i=m;i>1;--i){
		int tmp=a[i];
		if (!tmp)str[t ++] = '0';
		while(tmp){
			str[t ++]=tmp%10+'0';
			tmp/=10;
		}
	}
	str[t]='\0';
	return str;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int rm;scanf("%d",&rm);
		for(int j=1;j<=m;++j)sum[i][j]=get(rm,j);
		for(int j=1;j<=m;++j)sum[i][j]+=sum[i-1][j];
	}
	for(int i=1;i<=n;++i){
		for(int j=2;j<=m;++j)
			sum[i][j]-=sum[i][1];
		sum[i][1]=0;
	}
	for(int i=n;i>=0;--i){
		if ((it = q.find(change(sum[i]))) != q.end())ans=max(ans,(*it).second-i);
		else q[change(sum[i])]=i;
	}
	printf("%d\n", ans);
	return 0;
}
/*为什么过不了= = 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<string>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int n,k,sum[MAXN+3][31],ans=0;
int hash(int l){
	int ans=0;
	for(int i=1;i<k;i++)ans=(ans*131+sum[l][i])%10000007;
	return ans;
}
string to(int l){
	string s="";
	for(int i=1;i<k;i++)s.append(1,char(sum[l][i]+'0'));
	return s;
}
map<int,int> mp;
map<int,int>::iterator it;
int main(){
	scanf("%d%d",&n,&k);
	for(int x,i=1;i<=n;i++){
		scanf("%d",&x);
		for(int j=0;j<k;j++)
			sum[i][j]=sum[i-1][j]+((x>>j)&1);
		//for(int j=1;j<k;j++)cout<<sum[i][j]<<" ";cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k;j++)sum[i][j]-=sum[i][0];
		sum[i][0]=0;
	}
	for(int i=1;i<=n;i++){
		int t=hash(i);
		if((it=mp.find(t))!=mp.end())ans=max(ans,i-(*it).second);
		else mp[t]=i;
		//if(mp.count(t))ans=max(ans,i-mp[t]);
		//else mp[t]=i;
	}
	printf("%d\n",ans);
	return 0;
}
*/ 
