/*
Accept Ratio
���������������������
	  ��� f(n, a, b) ��ʾ����Ľ⣬��ôһ���� f(n, a, b) = f(n, a, (a + b) / 2) + f(n, (a + b) / 2 + 1, b)��
	  ����֪������ [n / a] = [n / b] ʱ��f(n, a, b) = (b - a + 1) * [n / a]�������Ϳ�һ�㡣
	  ��֪��b����nʱ����������Ϊ1������n����bʱ���������� i ���� [a, b]��[n / i] > 1��
	  ��ˣ�������ʱ�����㷨ʱ�临�ӶȲ��������㷨�����һ�γ�����������ȡ����ʱ�临�Ӷ�ΪO(1)����ô���㷨��ʱ�临�Ӷ�ΪO(b-a)�� 
*/
#include<iostream>
using namespace std;
typedef long long LL;
LL up(LL a,LL b){
	if(a%b==0)return a/b;
	else return a/b+1;
}
LL solve(LL n,LL a,LL b){
	if(a>b)return 0;
	if(up(n,a)==up(n,b))return (b-a+1)*up(n,a);
	if(n<b)return solve(n,a,n-1)+(b-n+1);
	return solve(n,a,(a+b)>>1)+solve(n,((a+b)>>1)+1,b);
}
int main(){
	LL n,a,b;
	cin>>n>>a>>b;
	cout<<solve(n,a,b);
	return 0;
}
