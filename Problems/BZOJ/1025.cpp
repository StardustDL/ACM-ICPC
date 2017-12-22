/*
[SCOI2009]��Ϸ
��������������ת��һ�¡�
		����ÿһ����Ӧ��ϵa-bΪ��a->b��һ���ߣ�
		��ôͼ��һ������n������ÿ������ȳ��ȶ�Ϊ1��
		��֤һ������һ���򼸸�����
		ʵ�������������⼸������С����С��������
		���󣺺�Ϊn�����е���С������������
		��ô����ֱ��DP��
		Ԥ����������opt[j]��ʾ��ɺ�=j�����е�LCM������
		��opt[j]=opt[j]+opt[j-p]+opt[j-p*p]+opt[j-p^3]+...(each p <= n)
		����ֻҪ��֤��<=n���ɣ���Ϊ���²�����1�����ɡ�
		ans=sigma(0<=i<=n,opt[i]) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=1000,INF=0x3f3f3f3f;
ULL opt[2][MAXN+3];
vector<int> pris;
bitset<MAXN+3> isp;
void init(int size){
	isp=0;
	for(int i=2;i<=size;i++){
		if(isp[i])continue;
		pris.push_back(i);
		for(int j=i*i;j<=size;j+=i)isp[j]=1;
	}
}
ULL solve(int n){
	memset(opt,0,sizeof(opt));int cur=0;opt[0][0]=1;
	for(int i=0;i<pris.size();i++,cur^=1){
		//cout<<pris[i]<<endl;
		memcpy(opt[cur^1],opt[cur],sizeof(opt[cur^1]));//ע������ĸ��� 
		for(int p=pris[i];p<=n;p*=pris[i])
			for(int j=p;j<=n;j++)
				opt[cur^1][j]+=opt[cur][j-p];
	}
	ULL ans=0;
	for(int i=0;i<=n;i++)ans+=opt[cur][i];
	return ans;
}
int n;
int main(){
	cin>>n;
	init(n);
	cout<<solve(n)<<endl;
	return 0;
}

