/*
��Ѻ�ﷸ
��������һ��жԹ�ϵ����һ���ߣ����˿��������㣬���ֵ���ɱߵ�Ȩֵ��
	  ��ô���������Ȱ�Ȩֵ�ɴ�С���б�����֮��ÿ��ȡ�ߣ����ߵ����������ڵ�ǰ�ļ�¼���ܷ�ֵ����������У�������ԣ����¼���ǲ���ͬһ�����У�������У���ǰ�ߵ�Ȩֵ���Ǵ𰸣���Ϊ���ɾȥ��ǰ�߻�ʹ֮ǰ��ĳ����Щ���߻ָ�������ȵ�ǰ����š�
	  ������ǵ������ʣ�����ж������ܷ�ֵ����������У��Լ���μ�¼���㲻��ͬһ�����С�
		��һ�����⣺��ʼʱÿ�������һ�����ϣ��ò��鼯��¼���������ѯ�����Ѿ���ͬһ�����ˣ�˵����֮ǰ��ĳ�β���ʹ�����Ǻϲ�����һ�����ϣ���˷ֿ���ʹ֮ǰ��ĳ���߻ָ������Բ��ֿܷ���
		�ڶ������⣺�ò��鼯��¼��ͬһ��������Ƚϼ򵥣�����¼����һ��������ȴ�Ƚ����ѡ���ô���ǲ���������һЩ��Ӱ�㡰��i+nΪi��Ӱ�㣬Ӱ����ԭ�㲻��ͬһ�����ϣ���ô���Ǳ������a��i+n��ͬһ����������ʾa��i����ͬһ�������ˡ�ע��Ҫ�ԳƵغϲ� 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=20000,MAXM=5*MAXN;
struct tar{
	int a,b,c;
	bool operator < (const tar &b)const{
		return c<b.c;
	}
};
int pa[2*MAXN+3],n,m;
tar ts[MAXM+3];
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
void unions(int a,int b){
	a=find(a);b=find(b);
	if(a!=b)pa[a]=b;
}
bool same(int a,int b){
	return find(a)==find(b);
}
void init(){
	int a,b,c;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ts[i].a>>ts[i].b>>ts[i].c;
	}
	sort(ts+1,ts+m+1);
	for(int i=1;i<=2*n;i++)pa[i]=i;
}
int solve(){
	for(int i=m;i>=1;i--){
		tar &t=ts[i];
		if(same(t.a,t.b)){
			return t.c;
		}
		unions(t.a,t.b+n);
		unions(t.b,t.a+n);
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	init();
	cout<<solve();
	return 0;
}
