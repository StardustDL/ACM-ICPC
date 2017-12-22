/*
等差子序列
分析：若有更长的等差序列，则必然有长度为3的
	  因为是一个n的序列，所以数列的数都是1<=x<=n的，所以可以用一个01字符串定于哪位来表示这个数是否出现过，
	  读入当前数，这个位肯定是1，然后以这位为中心，判断两边等距离的数是否异或为1，
	  如果为1说明这个等差数列的差的那个数会在后面给出，所以肯定包含等差子序列
*/
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=10000;
bitset<MAXN+3> B;
int n,m,t,e;
bool flg;
int main(){
	cin>>t;
	while(t-->0){
		flg=false;B=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e;
			if(flg)continue;
			B[e]=1;
			for(int j=e-1;j>0&&(e<<1)-j<=n&&!flg;j--)
				if(B[j]^B[(e<<1)-j])flg=true;
		}
		if(flg)cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}
