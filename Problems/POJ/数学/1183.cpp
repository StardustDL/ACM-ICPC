/*
�����к�����Ӧ��
�����������⣬�Ƶ�=>arctan(1/a)=arctan[(1/b+1/c)/(1-1/b*c)]=>bc-1=a(b+c)����b=a+m,c=a+n������Ϊʲô�԰����� 
	  (a+m)*(a+n)-1=a*(a+m+a+n)=>m*n=a*a+1
	  ע��mԽ��b+cԽС������һ�£�ע�����ݷ�Χ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef unsigned int UI;
UI a,t,m;
int main(){
	cin>>a;t=a*a+1;
	for(m=a;m>=1;m--)if(t%m==0)break;
	//֮ǰд��t%a����RE�ˣ�Ϊʲô�� 
	cout<<a+a+(t/m)+m;
	return 0;
}

