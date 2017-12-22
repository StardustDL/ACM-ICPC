/*
��������
����������Ҫ�������е���������̰��
	  �Ȱ���A�ľ���Ӵ�С�����ȴ�����A��Զ�ģ�ά������B�ľ��룬
	  �൱�ڵ㲻�Ͽ���A��Ȼ��ά����Щ�㵽B����Զ���룬 
	  ��Ϊ����ƽ���ͣ��ҿ�����������С��ϵ����䣬���Բ��ؿ����������ں������� 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f; 
struct node{
	int da,db;
	bool operator < (const node &t)const{
		return da>t.da;
	}
}nd[MAXN+3];
int dist(int a,int b,int x,int y){
	return (int)(pow(a-x,2)+pow(b-y,2));
}
int xa,ya,xb,yb,n;
void input(){
	cin>>xa>>ya>>xb>>yb;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		nd[i].da=dist(a,b,xa,ya);
		nd[i].db=dist(a,b,xb,yb);
	}
	sort(nd+1,nd+n+1);//����A�ľ���Ӵ�С���� 
}
int solve(){
	int ans=INF,s=0;
	for(int i=1;i<=n;i++){
		//ע���������˳��ans�ĸ���ʹ�õ����ϴε�sֵ 
		ans=min(ans,nd[i].da+s);//���´𰸣��Ե�ǰ�ĵ��A�ľ���Ϊ�뾶 
		s=max(s,nd[i].db);//ά��ǰi���ĵ�B��������ֵ 
	}
	return ans;
}
int main(){
	input();
	cout<<solve();
	return 0;
}
