/*
Web Navigation
���⣺ģ���������ǰ�����˹���
������һά����ģ�� ��ע��ÿ�ݷ�һ����վ���˺����վ�������ˣ�����վ�������һ��
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string a[120],b;
    int i=1,n=0,m;//i:�´ζ����ָ�룬n:��ǰָ�룬m:����վ�� 
    a[0]="http://www.acm.org/";
    while(cin>>b&&b!="QUIT"){
        if(b=="VISIT"){
            cin>>a[i];
            n=m=i;
            i++;
            cout<<a[n]<<endl;
        }
        else if(b=="BACK"){
            if(n-1>=0){
                i--;
                cout<<a[--n]<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
        else{
            if(n+1<=m){
                i++;
                cout<<a[++n]<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
    }
    return 0;
}
