/*
K-th Number
���⣺��̬���������KС 
����������������ģ�������ɢ����ʹ�ü����߶��������߶�������k����ʱ����ƽ����ѯ��k����һ�����ݽ���ϵ���Ϣ������������ߡ�������ֱ���Ÿ���= =��
	  ���������䣬���Կ����뵽ά��ÿ��ǰ׺�ļ����߶�����Ȼ����������ǰ׺�͵�˼�����KС������Ǽ��׿ɳ־û��߶��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
struct node{
	int lc,rc,sum;//lc��ʾ����ڵ�����ӽڵ���±꣬ע�ⲻ������ͨ�߶���ֱ�Ӱ��ѵķ�ʽ�� 
}ns[20*MAXN+3];
int T[MAXN+3],tot;//totά������ڴ�صĴ�С��T���ÿ���߶������ڵ� 
void init(int l,int r,int &curt){//��ʼ��curt����������䳤��l..r����һ����һ����߶�����࣬���ڵ���ʲô��ϢҲû�� 
	node &X=ns[(curt=++tot)];
	X.sum=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	init(l,mid,X.lc);
	init(mid+1,r,X.rc);
}
void change(int last,int val,int l,int r,int &curt){//�޸Ľ��last����ʵ��һ�����߶�������valֵ����+1����������Ϊl..r������������node�м�¼���䷶Χ��Ϣ��������Ҫ�־û����½ڵ�Ϊcurt 
	node &X=ns[curt=++tot];
	X=ns[last];X.sum++;//������Ϣ������+1 
	if(l==r)return;
	int mid=(l+r)>>1;//����������е㣬��val����߾͵ݹ���������ע������Ͳ�ѯ������ 
	if(val<=mid)change(ns[last].lc,val,l,mid,X.lc);
	else change(ns[last].rc,val,mid+1,r,X.rc);
}
int query(int s,int t,int l,int r,int k){//��ѯ�����߶���s,t�Ĳ��Ӧ��Ŀ�е����䣩����ѯ��KС 
	if(l==r)return l;
	int mid=(l+r)>>1,cnt=ns[ns[t].lc].sum-ns[ns[s].lc].sum;//�����������=cnt,��Ҫ��k���бȽϣ�ͬʱҪ���������е㣬��Ҫ��֤�ݹ�����ֹ 
	if(k<=cnt)return query(ns[s].lc,ns[t].lc,l,mid,k);//���������� 
	else return query(ns[s].rc,ns[t].rc,mid+1,r,k-cnt);//���������ڣ����k-cntС 
}
int rank[MAXN+3],a[MAXN+3],n,m;
void solve(){
	int l,r,k;tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memcpy(rank,a,sizeof(a));
	sort(a+1,a+n+1);
	int cnt=unique(a+1,a+n+1)-a-1;//ȥ�� 
	init(1,cnt,T[0]);//��ʼ��T[0] 
	for(int i=1;i<=n;i++)rank[i]=lower_bound(a+1,a+cnt+1,rank[i])-a;//��ɢ�� 
	for(int i=1;i<=n;i++)change(T[i-1],rank[i],1,cnt,T[i]);//�޸� 
	while(m--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",a[query(T[l-1],T[r],1,cnt,k)]);//��ѯ 
	}
}
int main(){
	solve();
	return 0;
}

