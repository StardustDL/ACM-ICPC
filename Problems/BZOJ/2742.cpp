/*
[HEOI2012]Akai����ѧ��ҵ
������ö�ٷ��ӷ�ĸ����ģ���������Ƿ�Ϊ�㼴�ɡ�
	  ���ӱ�����A[0]�����ӣ���ĸ������A[n]������ ���������ǲ�̫���ס�
	  ע�������ʱ����з���ֱ��ת��double�ǲ��е�= =�� 
*/
#include<iostream>
#include<cstdio>
#include<cmath> 
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
typedef long long LL;
const LL MOD=1000000007; 
struct Q{
	int a,b;bool neg;
	Q(int a,int b,bool n):a(a),b(b),neg(n){}
	bool operator <(const Q &t)const{
		if(neg&&(!t.neg)) return true;
		if((!neg)&&t.neg) return false;
 		if(!neg) return a*t.b<t.a*b;
		else return a*t.b>t.a*b;
		/*double x1=a*(neg?-1.0:1.0)/b,x2=t.a*(neg?-1.0:1.0)/t.b;//WA
		return x1<x2;*/
	}
	void output(){
		if(neg)putchar('-');
		if(a%b)printf("%d/%d",a,b);
		else printf("%d",a/b);
	}
};
vector<Q> ans;
int n,A[MAXN+3];
LL t1[MAXN+3],t2[MAXN+3];
vector<int> a,b;
void div_num(vector<int> &a,int x){
	x=abs(x);
	int t=(int)(sqrt(x*1.0));
	for(int i=1;i<=t;i++)if(x%i==0){a.push_back(i);if(i!=x/i)a.push_back(x/i);}
}
bool check(Q t){//����sigam{A[i]*a^i*b(n-i)}��������������b^n��Ϊ���̵�ֵ������Ϊ��MOD�����£����̽��Ϊ��ȼ���ǰ���Ǹ�ʽ��Ϊ0 
	LL ans=0;
	t1[0]=t2[0]=1;
	for(int i=1;i<=n;i++)t1[i]=t.a*t1[i-1]%MOD,t2[i]=t.b*t2[i-1]%MOD;
	for(int i=0;i<=n;i++){
		LL del=(LL)((LL)A[i]*t1[i]%MOD)*t2[n-i]%MOD;
		if(t.neg && (i&1)){//ע�⸺������ 
			ans=(ans-del+MOD)%MOD;
		}
		else{
			ans=(ans+del)%MOD;
		}
	}
	return ans==0;
}
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d",&n);int len=-1;
	for(int i=0,x;i<=n;i++){
		scanf("%d",&x);
		if(len==-1&&x==0)continue;
		A[++len]=x;
	}
	if(len!=n)ans.push_back(Q(0,1,0));//ע����0/1����Ϊ���RE��= = 
	n=len;
	div_num(a,A[0]);div_num(b,A[n]);
	//cout<<A[0]<<" "<<A[n]<<endl;
	//cout<<a.size()<<" "<<b.size()<<endl; 
	Q t=Q(0,0,0);
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){//cout<<a[i]<<" "<<b[j]<<" "<<gcd(a[i],b[j])<<endl;
			if(gcd(a[i],b[j])!=1)continue;
			t=Q(a[i],b[j],0);
			if(check(t))ans.push_back(t);
			t=Q(a[i],b[j],1);
			if(check(t))ans.push_back(t);
		}
	}
	printf("%d\n",ans.size());
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		ans[i].output();
		puts("");
	}
	return 0;
}

