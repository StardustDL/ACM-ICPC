/*
A Bug's Life
���⣺�������ϣ���������ͬһ�����е����ߣ��ж����������Ƿ�ì�� 
���������鼯�����Բ�㣬��ע�����ѷ���ì�ܣ���������ѭ������Ϊ��ǰ���ݻ�û�ж��꣬������Ӱ����������� 
*/
#include<cstdio>
using namespace std;
const int MAXN=2000;
int n,m,a,b;
struct uniset{
	int pa[2*MAXN+3];
	void init(int n){
		for(int i=1;i<=2*n;i++)pa[i]=i;
	}
	int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	void unions(int a,int b){
		int fa=find(a),fb=find(b);
		if(a==b)return;
		pa[fa]=fb;
	}
}S;
int main(){
	int t;bool flg;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		flg=true;
		scanf("\n%d %d",&n,&m);S.init(n);
		while(m-->0){
			scanf("\n%d %d",&a,&b);
			if(!flg)continue;
			if(!S.same(a,b)){
				S.unions(a,b+n);
				S.unions(a+n,b);
			}
			else flg=false;
		}
		printf("Scenario #%d:\n",i);
		if(flg)printf("No suspicious bugs found!");
		else printf("Suspicious bugs found!");
		printf("\n\n");
	}	
	return 0;
}
