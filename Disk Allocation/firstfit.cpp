#include<bits/stdc++.h>
using namespace std;

void firstFit(int blocks[],int m,int processes[],int n){
    int alloc[n];
    memset(alloc,-1,sizeof(alloc));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocks[j]>=processes[i]){
                alloc[i]=j;
                blocks[j]-=processes[i];
                break;
            }
        }
    }
    cout<<"----------FIRST FIT----------"<<endl;
    cout<<"Process ID\t"<<"Size\t"<<"Block Id\n";
    for(int i=0;i<n;i++){
        if(alloc[i]!=-1) cout<<i<<"\t\t"<<processes[i]<<"\t\t"<<alloc[i]<<endl;
        else cout<<i<<"\t\t"<<processes[i]<<"\t\t"<<"Not Allocated"<<endl;
    }
}

int main(){
    int bs[]={100,500,300,200,600};
    int ps[]={212,417,300,800};
    firstFit(bs,5,ps,4);
    return 0;
}