/*
�滰�ͼٻ� 
����������1��û�б�ɹ�����
	  ��x�˱����ɼ���,y���˱����ɼ��
	  ��ʣ�µ�n-x-y���˾��ǳɼ�������ͬ���ˣ�
	  ������˿���һ���߶Σ������t����˵��x��y��ͬ��
	  ��ô�����߶ε�Ȩ�ؾ�Ϊt����ô����ͱ���ˣ�
	  ��m���߶Σ�ÿ���߶���һ��Ȩ��
	  ��ʹÿ���߶γ��Ȼ����ཻ��ǰ����Ȩֵ���
	  ����߶θ���
	  ����2�� 
	  �����˵�滰���������𰸼�Ϊn-ans
	  ��dp[i]��ʾ��ǰi��������ж�����˵�滰
	  dp[i] = max{dp[j-1]+sum[j][i]} ����sum[j][i]��ʾ��������Ϊ[j, i]������
	  ����N̫��sumҪ��map�ķ�ʽ������DPʱ��Ҫת��vector 
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
