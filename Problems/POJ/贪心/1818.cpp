/*
ATP
���⣺��2^e���ˣ�ÿ���˵�����Ϊ�������a-b>=k��aһ����Ӯb������һ��
	  ��Ҫ�����С��t��ʹ��t��һ���ı������ź����Ӯ���������� 
������̰�� + ����
	  ���������Ϊp���ˣ���̰�Ĳ����ǣ� p���һ���루p-k����������������е���Ȼ�ģ���Ϊ������p�������ܱ�pӮ�����У���p-k���������׳ŵ����һ�ֵġ�
	  ֤����������p���һ����m����������m > p-k����(p-k)��ĳһ����a����ʱ����ܣ�
������������ͬʱ��һ��m����b������mʤ������Ϊm�ŵ������һ�֣��������ǽ�����һ���еģ�p-k����m��
����������������һ������m��a��������Ϊ��p-k���ܱ�a��ܣ�mҲһ���ܱ�a��ܣ���p-k����b��������p-k��ʤ����
�������������������ں����İ����У�m��λ�ö���Ϊ��p-k���ң�p-k���ŵ����һ�֡�������û�з����仯��
��������������˰�̰�Ĳ��Եı��������Ǵ��ڵġ�
	  �������Ͻ��ۣ��Ϳ��ԡ��ݹ顱�İ��ű������磨p-k���ڵ����ڶ�������ѡ��ͣ�p-k-k��������
	  �������ʤ�����ˣ������Ϲ����ж��Ƿ���С�O(nlogn) 
	  ��˵��logn���� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,queue[5010],add;char elio[5010];
bool vali(int person){
    int kase,tail,t,x=(int)(log10(n*1.0)/log10(2.0));
    memset(elio,0,sizeof(elio));
    //������Ϊ��elio[i]=j ��ʾi���һ��ʤ�����ڵ�����j��
    elio[person]=1;tail=person;
    add=0;queue[add++]=person;
    //�ܹ�x�֣�����kase=iʵ���ϱ�ʾ������i�ֱ�����
    for(kase=1;kase<=x;kase++){
        t=add;
        for(int i=0;i<t;i++){
            for(int j=max(1,queue[i]-k);j<=tail;j++){
                if(elio[j]==0){
                   elio[j]=kase+1;
                   queue[add++]=j;//�������飬��Ϊ��һ��ѭ��������һ�ֱ�������ҪΪ��������
				   break;
                }
            }
        }
    }
    for(int i=1;i<=tail;i++)if(elio[i]==0)return 0;//֮ǰ������û���䵽����û�кϷ�����
    return 1;
}
int main(){
    int st,ed,mid,i;
    scanf("%d %d",&n,&k);
    st=1,ed=n;
    if(vali(ed))st=ed;
    else while(ed-st>1){//����
         mid=(st+ed)>>1;
		 if(vali(mid))st=mid;
         else ed=mid;
    }
    printf("%d\n",st);
    return 0;
}
