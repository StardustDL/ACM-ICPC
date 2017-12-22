/*
[CTSC2007]���ݱ���Backup
���������ȣ���֪һ��ѡ�������ڵģ�������K�Ե����죬��ʧһ���ԣ���ÿ�������ǰ��ĵ���ԣ�����ÿ��������һ��Ȩֵd[i]-d[i-1] 
	  �����뵽̰�ģ������ά���أ�
	  �տ�ʼһ����ѡȨֵ��С�ģ���������ʹ����������������㲻��ѡ���������ܵ��½������
	  ���Բ����µ㣬�����������滻��Ȩֵ��left[x]+right[x]-val[x]������ѡ������㣬����Ȼ��x�������
	  �����ȶ��л�ƽ����ά��������
	  �߽紦��val[1]=INF,val[n+1]=INF
	  ��Ϊѡ�˵�һ���㣬�����û�е㣬����ѡһ�����ţ�
	  ѡ�˵�n���㣬Ϊ��֤֮�󲻻�ѡ��n+1��������ڵĵ㣬���INF
	  Ps:0x3f3f3f3f�Դ���106000000 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define P(x) (pre[x])
#define N(x) (nxt[x])
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	int pos,val;
	data(int p,int v):pos(p),val(v){}
	bool operator <(const data &t)const{
		return val<t.val||val==t.val&&pos<t.pos;
	}
};
int nxt[MAXN+3],pre[MAXN+3],val[MAXN+3],d[MAXN+3],n,k,ans;
set<data> S;
set<data>::iterator it;
int main(){
	scanf("%d%d",&n,&k);;
	for(int i=1;i<=n;i++){scanf("%d",&d[i]);val[i]=d[i]-d[i-1];}
	val[1]=INF;val[n+1]=INF;
	for(int i=2;i<=n;i++){
		nxt[i]=i+1;
		pre[i]=i-1;
		S.insert(data(i,val[i]));
	}
	for(int i=1,pos;i<=k;i++){
		it=S.begin();
		pos=(*it).pos;
		ans+=(*it).val;
		S.erase(data(pos,val[pos]));
		S.erase(data(P(pos),val[P(pos)]));
		S.erase(data(N(pos),val[N(pos)]));
		val[pos]=val[P(pos)]+val[N(pos)]-val[pos];
		S.insert(data(pos,val[pos]));
		P(pos)=P(P(pos));
		N(pos)=N(N(pos));
		if(P(pos))N(P(pos))=pos;
		if(N(pos))P(N(pos))=pos;
	}
	printf("%d\n",ans);
	return 0;
}

