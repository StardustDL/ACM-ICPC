/*
Charlie's Change
���⣺������Ӳ�ң�1�֣�5�֣�10�֣�25�֣��ֱ���a,b,c,d�֣�����һ��n��Ǯ��Ҫ����������n��Ǯ�����Ҫ��Ӳ���������������������ĸ���Ӳ�ҵ�����
����������������������ÿ����Ʒ�ļ�ֵ����ͬ�ģ�����1�������Կ��Բ��ö��ر���������ȫ�����Ӽ��������ɣ������ڿ������жϣ�ע�ⲻ���׿������жϵĴ��룬����ά��������С�ſ��Ա�֤���� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=10000;
int ans[26],num[MAXN+3],path[MAXN+3],opt[MAXN+3];
int p,c[5]={0,1,5,10,25},t[5];
int main(){
    while(scanf("%d %d %d %d %d",&p,&t[1],&t[2],&t[3],&t[4])>0,(p+t[1]+t[2]+t[3]+t[4])){
        memset(opt,0,sizeof(opt));
        memset(ans,0,sizeof(ans));
        memset(path,0,sizeof(path));
        opt[0]=1;
        for(int i=1;i<=4;i++){
            memset(num,0,sizeof(num));
            for(int j=c[i];j<=p;j++)
	           	if(opt[j-c[i]]&&opt[j-c[i]]+1>opt[j]&&num[j-c[i]]<t[i]){   //һ����˵����ȫ������Ӳ����û�����Ƶģ���һ������Ȼ������ǰ���ĳ������ɣ�����Ҳ�Ͳ���Ҫdp[j-c[i]]>0�����ǣ�����õ�����ȫ������Ӳ�����ܵ������ƣ�Ҳ�͵�����Щ��������������ɣ�����Ҫ����Щ���ų�
	            	opt[j]=opt[j-c[i]]+1;
	                num[j]=num[j-c[i]]+1;
	                path[j]=j-c[i];
	            }
        }
        int i=p;
        if(opt[p]){
            while(i!=0){
                ans[i-path[i]]++;
                i=path[i];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[1],ans[5],ans[10],ans[25]);
        }
        else  printf("Charlie cannot buy coffee.\n");
    }
    return 0;
}
