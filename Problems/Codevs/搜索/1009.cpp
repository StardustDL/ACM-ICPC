/*
������
�����������ɳ˷�ԭ���ܸ���=ÿһλ���Ա�ɵ������˻�
		��ÿһλ�ɱ�ɵ�����������ֱ������Ŀ�и����ģ������Լ�ӱ仯
		����Ҫ���ű仯�ıߣ�ͼ�ۣ�DFS������ʱ�����߲�����
		�����ͨ��������ʵ�֣����ҡ�ÿһλ���Ա�ɵ����������Ƕ�������1�ĸ���
ע�⣺�����Ƽ��ɣ�
		ȡ��iλ��i��0�ƣ���(t>>(i))&1
		���㺬1������ while(t>0){t&=(t-1);ans++;}//t&(t-1) ->������ұߵ�1
		����iλ��Ϊ1��t|=1<<i;
		����iλ��Ϊ0��t&=1<<i;
*/
#include<iostream>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;
const int MAXK=16;
int k,x,y;
long long ans=1;
int a[10],cn[10];
bitset<10> hasdfs=0;
char n[31];
int geti(int t,int i){
	return (t>>(i))&1;
}
int get1cn(int t){
	int ans=0;
	while(t>0){
		t&=(t-1);
		ans++;
	}
	return ans;
}
void dfs(int e){
	if(hasdfs[e])return;
	hasdfs[e]=1;
	for(int i=0;i<=9;i++){
		if(i==e||geti(a[e],i)==0)continue;
		dfs(i);
		a[e]=a[e]|a[i];
	}
}
/*void out(int t){��һ������������� 
	for(int i=0;i<=9;i++){
		cout<<geti(t,i);
	}
	cout<<endl;
}*/
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<=9;i++)a[i]|=1<<i;//ÿ�����ֶ����Ա�Ϊ�Լ��������䣩 
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		a[x]|=1<<y;
	}
	for(int i=0;i<=9;i++){
		dfs(i);
		cn[i]=get1cn(a[i]);
	}
	for(int i=0;i<strlen(n);i++){
		ans*=cn[n[i]-'0'];
	}
	cout<<ans;
	return 0;
}
