/*
[Baltic2004]sequence
�������ȿ���ֻҪ��z1<=z2<=...<=zn���������������
		t[1]<=t[2]<=...<=t[n]����ʱz[i] = t[i].
		t[1]>=t[2]>=...>=t[n]����ʱz[i]=x��xΪ����t����λ��.
		���ǿ��Խ�ԭ���л��ֳ�m�����䣬ÿһ�εĽ�Ϊ���������λ����
	  ʵ�֣�
		�����Ѿ������ǰk���������Ž⣬�����ֳ���m�����䣬ÿ����������Ž�Ϊw[i](w[1]<=w[2]<=...<=w[m])�����ڿ��ǵ�k + 1�������Ƚ�t[k + 1]��������һ�����䣬���Ž�Ϊw[m+1]����ʱ����w[m]>w[m+1]����ϲ�����m��m + 1��Ȼ���ҳ�������Ľ⣨��λ�������ظ���������ֱ��w[m]<=w[m+1].
		���ά����λ�������ѵĴ�С�������䳤�ȵ�һ��ʱɾ���Ѷ�Ԫ�أ�����е�Ԫ��һ���Ǹ������ڽ�С��һ��Ԫ�أ��Ѷ�Ԫ�ؼ�Ϊ���������λ����
		��ֻ��z1<=z2<=...<=zn�������
		Ȼ��Ҫ�����ֻ��Ҫ��ԭ����t[i]�ĳ�t[i] - i���ٰ�������������������orz�� 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
int v[MAXN+3],ch[MAXN+3][2],dist[MAXN+3],sz[MAXN+3],rt[MAXN+3],tot=0,l[MAXN+3],r[MAXN+3];
int merge(int x,int y){
	if(!x || !y)return x^y;
	if(v[x]<v[y])swap(x,y);
	ch[x][1]=merge(ch[x][1],y);
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	if(dist[ch[x][0]]<dist[ch[x][1]])swap(ch[x][0],ch[x][1]);
	dist[x]=dist[ch[x][1]]+1;
	return x;
}
void pop(int &x){x=merge(ch[x][0],ch[x][1]);}
int newnode(int x){
	v[++tot]=x;sz[tot]=1;
	ch[tot][1]=ch[tot][1]=dist[tot]=0;
	return tot;
}
int n,a[MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i]-=i;}
	int cnt=0;
	for(int i=1;i<=n;i++){
		rt[++cnt]=newnode(a[i]);
		l[cnt]=r[cnt]=i;
		while(cnt>1 && v[rt[cnt]]<v[rt[cnt-1]]){//ע����cnt>1 
			cnt--;
			rt[cnt]=merge(rt[cnt],rt[cnt+1]);
			r[cnt]=r[cnt+1];
			while(sz[rt[cnt]]*2>(r[cnt]-l[cnt]+2))pop(rt[cnt]);
		}
	}
	long long ans=0;
	for(int i=1;i<=cnt;i++){
		int t=v[rt[i]];
		for(int j=l[i];j<=r[i];j++)ans+=abs(t-a[j]);
	}
	printf("%lld\n",ans);
	return 0;
}

