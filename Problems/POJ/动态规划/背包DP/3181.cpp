/*
Dollar Dayz
���⣺��n�ֽ�Ϊ���ڵ���1С�ڵ���k�������ж����ַַ��������������⣩
��������������ȫ�����⣬ö�����1..k��opt[j]+=opt[j-i]
	  ��һ�������뵽�ķ����� ��a[i][j]��ʾ���ǵ�����j����ƴ��ʱ����i��ƴ�ӷ��������Եõ�״̬ת�Ʒ������£�
		a[i][j]=a[i][j-1]+a[i-j][j-1]+a[i-2j][j-1]+a[i-3j][j-1]��+a[0][j-1]��˼�����ԣ��ͽ�j-1״̬���Ե���a[i][j]��״̬��������ӡ����ڵõ��Ľ�������൱���Ѿ�������long long������Ӧ���ô����������������������ݣ��ô����ᳬ��һ�룬����ͨ�������ĳ�����Դﵽ����������Ϊ33λ����ô�����ǿ��Խ�����long long�����ֽ���ƴ�ӣ����һ������33λ������
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL a[1010],b[1010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    b[0]=1;
    for(int i=1;i<=k;i++)
        for(int j=i;j<=n;j++){
            a[j]=a[j]+a[j-i]+(b[j]+b[j-i])/INF;
            b[j]=(b[j]+b[j-i])%INF;
        }
    if(a[n])printf("%lld%018lld",a[n],b[n]);
    else printf("%lld\n",b[n]);
    return 0;
}
