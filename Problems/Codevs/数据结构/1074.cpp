/*
ʳ����
�������Ƚϸ߼��Ĳ��鼯��
	  ���Խ�ʳ������ϵת�ɲ��鼯�ı�Ȩ��ע��mod 3
	  ������cin����ʹ�����Ż�����TLE 
*/#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=50000;
struct uniset{
	int pa[MAXN+3],d[MAXN+3];//pa[a]==pa[b]=>d[i]=0:ͬ��;d[i]=1:B��A;d[i]=2:A��B; 
	
	void init(int n){
		for(int i=1;i<=n;i++)pa[i]=i;
		memset(d,0,sizeof(d));
	}
	int find(int x){
		if(x!=pa[x]){
			int t=find(pa[x]);
			d[x]=(d[x]+d[pa[x]])%3;//��ʱpa[x]��û�ı� 
			pa[x]=t;
		}
		return pa[x];
	}
	bool unions(int a,int b,int t){//tȡ0(ͬ��),1(a��b),�����Ƿ�������� 
		int fa=find(a),fb=find(b);
		if(fa==fb){
			return ((d[b]-d[a]+3)%3==t);//����d�Ķ���õ� 
		}
		pa[fb]=fa;
		d[fb]=(d[a]-d[b]+t+3)%3;//��һ���ǹ��ɵó�����������ϸ����
		return true;
	}
}S;
int main(){
	int k,n,a,b,c,ans=0;
	scanf("%d %d\n",&n,&k);
	S.init(n);
	while(k-->0){
		scanf("%d %d %d",&a,&b,&c);
		if(c==b&&a==2||b>n||c>n)ans++;
		else if(!S.unions(b,c,a-1))ans++;
	}
	printf("%d",ans);
	return 0;
}
