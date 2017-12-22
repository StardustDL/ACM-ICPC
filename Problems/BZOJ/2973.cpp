/*
ʯͷ��Ϸ
���������ǵ�lcm(1,2,3,4,5,6)=60�����Բ�������ÿ60��һ��ѭ����
		����0~9����0~9��ʯͷ���ø��ӡ���һ��һֱΪ1��ת��0~9�� 
		NWSE����������������е�ʯͷ�Ƶ����ڵĸ��ӡ���ǰλ�����㣬ת�Ƶ�����λ�� 
		D������������ӵ�ʯͷ����ǰλ����0 
		��������ʾ��ת�ƾ������ʽ��Ԥ�����ǰ60���ת�ƾ����Լ����ǵĳ˻���
		�þ�������ݼ��ټ��㼴�ɡ� 
		ע��������㽻����A*B!=B*A���������㽻����A*B!=B*A ���������㽻����A*B!=B*A  
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
typedef long long LL; 
struct matrix{
	LL a[70][70];
	int n,m;
	void clear(){memset(a,0,sizeof(a));}
	LL* operator [](const int &d){
		return a[d];
	}
};
void mulply(matrix &a,matrix &b,matrix &c){
	static matrix t;
	t.n=a.n;t.m=b.m;
	for(int i=0;i<=a.n;i++){
		for(int j=0;j<=b.m;j++){
			t[i][j]=0;
			for(int k=0;k<=a.m;k++)(t[i][j]+=a[i][k]*b[k][j]);
		}
	}
	c=t;
}
void ksm(matrix a,int n,matrix &c){
	static matrix t;
	t.n=a.n;t.m=a.m;
	for(int i=0;i<=a.n;i++)for(int j=0;j<=a.m;j++)t[i][j]=(i==j);
	while(n){
		if(n&1)mulply(t,a,t);
		mulply(a,a,a);
		n>>=1;
	}
	c=t;
}
matrix w[70],one,res,tmp;
char s[15],b[15][15],c;
LL ans=0;
int n,m,t,q,id[15][15],N,l[15],a[15][15];
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&q);
	for(int i=1,j;i<=n;i++)
		for(scanf("%s",s+1),j=1;j<=m;j++)
			id[i][j]=++N,a[i][j]=s[j]-'0';
	for(int i=0;i<q;i++)scanf("%s",b[i]+1),l[i]=std::strlen(b[i]+1),b[i][0]=b[i][l[i]];
	one.n=one.m=N;
	for(int i=0;i<=one.n;i++)for(int j=0;j<=one.m;j++)one[i][j]=(i==j);
	w[0]=one;
	for(int i=1;i<=60;i++){
		w[i][0][0]=1;w[i].n=w[i].m=N;
		for(int j=1;j<=n;j++)
			for(int k=1,c,x,y;k<=m;k++){
      			c=b[a[j][k]][i%l[a[j][k]]];
			    if(c>='0'&&c<='9')w[i][0][id[j][k]]=c-'0',w[i][id[j][k]][id[j][k]]++;
			    else if(c=='N'){
			    	x=j-1,y=k;
			    	if(x>=1)w[i][id[j][k]][id[x][y]]=1;
			    }
			    else if(c=='S'){
			    	x=j+1,y=k;
			    	if(x<=n)w[i][id[j][k]][id[x][y]]=1;
			    }
			    else if(c=='W'){
			    	x=j,y=k-1;
			    	if(y>=1)w[i][id[j][k]][id[x][y]]=1;
			    }
			    else if(c=='E'){
			    	x=j,y=k+1;
			    	if(y<=m)w[i][id[j][k]][id[x][y]]=1;
			    }
    		}
	}
	for(int i=1;i<=60;i++)mulply(w[i-1],w[i],w[i]);
	ksm(w[60],t/60,res);
	mulply(res,w[t%60],res);//ע��w[t%60]Ҫ�ҳˣ���Ϊԭʽ��w[1]*w[2]*...*w[60]*w[1]*...*w[t%60]
	for(int i=1;i<=N;i++)ans=max(ans,res[0][i]);
	printf("%lld\n",ans);
	return 0;
}
