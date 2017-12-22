/*
Fast Food
���⣺n���ӹ�����m��ԭ�ϳ���ԭ�ϳ���ַ��ӹ���һ�£�m<=n������ѷ��䣬ʹ��ÿ���ӹ�����������������Ǹ�ԭ�ϳ�����ʹ���ܾ�����С��
������dp[i][j]Ϊǰi������j��ԭ�ϳ���ѷ�����ܴ��ۡ����⣬���ڼӹ�������[a,b]��ԭ�ϳ�ȥ���ǵķ���Ӧ���ǽ��������м��Ǹ����ϣ��������ҹ�������ȣ��������ľ���֮����С��
	  dp[i][j]=min(dp[k][j-1]+ds[k+1][i])����ַλ�þ���(k+1+i)/2λ�ã�������pre[i][j]��¼��ԭ�ϳ���ص��������˵㣬�������һ�¾����ˡ�
	  ��Ϊû�н�ds�������㣬WA�ü��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
int ds[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3],pre[MAXN+3][MAXN+3],n,k,d[MAXN+3];
struct Ans{
	int depot,from,to;
	Ans(int d,int f,int t):depot(d),from(f),to(t){}; 
	bool operator<(const Ans &ne)const{  
        return depot<ne.depot;  
    } 
};
vector<Ans> vs;
bool input(){
	scanf("%d%d",&n,&k);
	if(n==0&&k==0)return false;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	d[n+1]=INF;d[0]=-INF;
	memset(ds,0,sizeof(ds));
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int t=d[(i+j)>>1],l=i,r=j,&a=ds[i][j];
			while(l<=r)a+=abs(t-d[l++]);
		}
	}
	return true;
}
void dp(){
	memset(opt,INF,sizeof(opt));
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
		opt[i][1]=ds[1][i];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=k;j++)
			for(int e=1,tp;e<i;e++)
				if(opt[i][j]>(tp=opt[e][j-1]+ds[e+1][i]))
					opt[i][j]=tp,pre[i][j]=e;
	vs.clear();
	for(int i=n,j=k,e;j!=0;){
		e=pre[i][j];if(e==-1)e=0;
		vs.push_back(Ans((e+i+1)>>1,e+1,i));
		i=e;j--;
	}
	sort(vs.begin(),vs.end());
}
void output(){
	for(int i=0;i<vs.size();i++){  
		printf("Depot %d at restaurant %d serves restaurant",i+1,vs[i].depot);  
		if(vs[i].from==vs[i].to) printf(" %d\n",vs[i].from);
		else printf("s %d to %d\n",vs[i].from,vs[i].to);
    }  
    printf("Total distance sum = %d\n\n",opt[n][k]); 
}
int main(){
	int kase=0;
	while(input()){
		printf("Chain %d\n",++kase);
		dp();
		output();
	}
	return 0;
}
