/*
[Scoi2014]��������������
������һ�����ۣ�����ѡ���k�������Ҷ˵㶼��nʱ���ܱ�֤����
		��f[i][j]��ʾǰi��������j�ε����LIS
		��ô��f[i][j]=max{f[k][l]|k<i,l<=j,a[k]+l<=a[i]+j}+1
		������άƫ��Ϳ����ö�ά��״������
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,MAXK=500,MAXA=5000,INF=0x3f3f3f3f;
int n,K,a[MAXN+5],c[MAXA+MAXK+5][MAXK+5],mx,ans;
#define lowbit(x) (x&-x)
void modify(int x,int y,int v){
	for(int i=x;i<=mx+K;i+=lowbit(i))
		for(int j=y;j<=K+1;j+=lowbit(j))
			c[i][j]=max(c[i][j],v);
}
int query(int x,int y){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans=max(c[i][j],ans);
	return ans;
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);mx=max(a[i],mx);}
	for(int i=1;i<=n;i++){
		for(int j=K;~j;j--){
			int tmp=query(a[i]+j,j+1)+1;//ע��j���Ҵ�һλ 
			ans=max(tmp,ans);
			modify(a[i]+j,j+1,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}

