#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long int sum=0;
    int mark=0;
    int count =0;
    for(int l=0;l<940;l++){
        char a[100];
        fgets(a,100,stdin);
        int i=1;
        int flag=0;
        int x=0,y=0;
        if(strcmp(a,"dont()\n")==0){
            mark=1; count++;
        }
        if(strcmp(a,"do()\n")==0){
            mark=0; count++;

        }
        while(a[i]!=','){
            if(a[i]<'0'||a[i]>'9'){flag=1;break;}
            else x=x*10+(int)(a[i]-'0');
            i++;
        }
        i++;
        if(flag==1){continue;}
        else{
            while(a[i]!=')'){
            if(a[i]<'0'||a[i]>'9'){flag=1;break;}
            else y=y*10+(int)(a[i]-'0');
            i++;
            }
            if(flag==1){continue;}
            else{if(mark==0){sum+=x*y;}}
        }
    }
    cout<<sum<<endl;
    cout << count;
}