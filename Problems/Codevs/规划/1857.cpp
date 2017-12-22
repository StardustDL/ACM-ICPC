/*
真话和假话 
分析：方法1（没有编成功）：
	  有x人比他成绩好,y个人比他成绩差，
	  那剩下的n-x-y个人就是成绩和他相同的了，
	  把这段人看成一条线段，如果有t个人说的x，y相同，
	  那么这条线段的权重就为t，那么问题就变成了：
	  有m条线段，每个线段有一个权，
	  求使每条线段长度互不相交的前提下权值最大。
	  变成线段覆盖
	  方法2： 
	  求最多说真话的人数，答案即为n-ans
	  设dp[i]表示在前i名中最多有多少人说真话
	  dp[i] = max{dp[j-1]+sum[j][i]} 其中sum[j][i]表示名次区间为[j, i]的人数
	  由于N太大，sum要用map的方式，而且DP时还要转成vector 
*/
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=100000;
struct segment{
	int x,y;
	
	bool operator <(const segment &t)const{
		return y<t.y||y==t.y&&x<t.x;
	}
}; 
struct maxseg{
	map<segment,int> cnt;
	int opt[MAXN+3],cur;
	
	void add(int x,int y){
		segment s=(segment){x,y};
		if(cnt.count(s)){
			cnt[s]++;
		}
		else cnt[s]=1;
	}
	
	int Solve(){
		//sort(vs.begin(),vs.end());
		memset(opt,0,sizeof(opt));
		cur=1;
		map<segment,int>::iterator it;
		for(it=cnt.begin();it!=cnt.end();it++){
			segment t=it->first;
			int w=it->second;
			while(cur<=t.x){
				opt[cur]=max(opt[cur],opt[cur-1]);
				cur++;
			}
			opt[t.y]=max(opt[t.y],opt[t.x]+w);
		}
		it--;int e=(it->first).y;
		while(cur<=e){
			opt[cur]=max(opt[cur],opt[cur-1]);
			cur++;
		}
		return opt[e];
	}
}worker;
int main(){
	int n,a,b;
	cin>>n;
	while(n-->0){
		cin>>a>>b;
		worker.add(a+1,n-b+1);
	}
	cout<<worker.Solve();
	return 0;
}*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int MAXN=100000;
int opt[MAXN+3],n,a,b;
vector<int> q[MAXN+3];
map<pair<int,int>,int> s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int l=a+1,r=n-b;
		if(l>r)continue;
		s[make_pair(l,r)]++;
		if(s[make_pair(l,r)]==1)q[r].push_back(l);
	}
	for(int i=1;i<=n;i++){
		opt[i]=opt[i-1];
		for(int j=0;j<q[i].size();j++)
			opt[i]=max(opt[i],opt[q[i][j]-1]+min(i-q[i][j]+1,s[make_pair(q[i][j],i)]));
	}
	cout<<n-opt[n];
	return 0;
}
