/*
[POI2007]��ʻ����egz
������������һ�����ۣ�һ���������ܵ������еĳ�·�ĳ�Ҫ�������ܹ���������ߺ����ұߵ�·��
		���ǽ����б߷���ͳ������ߺ����ұߵ����濪ʼ��ͬʱ�ܹ�����ĳ�������Ŀ������ԭ���Ŀ��г���������
		Ȼ��ӱ���ô���أ� 
		���ǰ�ÿ��·�����������������ֿ���������������ң��ѱ߰���m[i]���ϵ�������
		Ȼ����n[i]Ϊ�ؼ���������������У�ʹ�ö����Ż���
		���ڵ�i��·��i-1-(n[i]С��i��·��ɵ�����������г���)�������ټӵı�����
		�������Ϊlt[i],���Ƽ����rt[i]����Ȼlt,rt���ǵ����ġ�
		��������ֻҪ����lt[i]+rt[j]<=k(i>=j)��ô��i-j+1���´𰸼��ɣ�����i����ʱ��j�����ֵҲ���ӣ�O(n)����ָ��ɨһ�鼴�ɡ�	
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=100000;
struct data{
	int pos,val;//pos���ڶ����ϵ�λ�ã� val���ϱ��ϵ�λ�� 
	data() {}
	data(int p,int v):pos(p),val(v) {}
}a1[MAXN+3],a2[MAXN+3];//a1ά������󣬴����ҵı� ��a2 ά������󣬴��ҵ���ı�
int tot1,tot2;
int n,m,p,k,ans;
int l[MAXN+3],r[MAXN+3];
bool cmp1(const data &x,const data &y){
	return x.pos < y.pos || x.pos == y.pos && x.val < y.val;//������λ��������ΰ��ϱ���С������Ϊ�Ƿ����ˣ��ϱ������ϣ���Ŀ��Ե�С�� 
}
bool cmp2(const data &x,const data &y){
	return x.pos > y.pos || x.pos == y.pos && x.val < y.val;
}
int c[MAXN+3];
void add(int x,int y){
	for(;x;x-=x&-x)c[x]=max(c[x],y);
}
int getmax(int x){
	int re=0;
	for(;x<=m;x+=x&-x)re=max(re,c[x]);
	return re;
}
int main(){
	int i,j,x,y,z;
	cin>>n>>m>>p>>k;++m;
	for(i=1;i<=p;i++){
		scanf("%d%d%d",&x,&y,&z);++y;
		if(z)a1[++tot1]=data(x+1,y);
		else a2[++tot2]=data(x,y);
	}
	sort(a1+1,a1+tot1+1,cmp1);
	sort(a2+1,a2+tot2+1,cmp2);
	l[0]=r[n+1]=-1;
	memset(c,0,sizeof(c));
	for(j=1,i=1;i<=n;i++){
		l[i]=l[i-1]+1;
		for(;j<=tot1&&a1[j].pos==i;j++){
			int temp=getmax(a1[j].val)+1;
			l[i]=min(l[i],(i-1)-temp);
			add(a1[j].val,temp);
		}
	}
	memset(c,0,sizeof(c));
	for(j=1,i=n;i;i--){
		r[i]=r[i+1]+1;
		for(;j<=tot2&&a2[j].pos==i;j++){
			int temp=getmax(a2[j].val)+1;
			r[i]=min(r[i],(n-i)-temp);
			add(a2[j].val,temp);
		}
	}
	for(j=1,i=1;i<=n;i++){
		for(;i-j+1&&l[i]+r[j]>k;j++);
		ans=max(ans,i-j+1);
	}
	for(i=1;i<=n;i++)
		if(!l[i]&&!r[i])--ans;//����ǰ�Ϳ��еģ����߶�����Ҫ�ӱߣ�ȥ�� 
	cout<<ans<<endl;
	return 0;
}


