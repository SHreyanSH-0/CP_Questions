#include <bits/stdc++.h>
using namespace std;

int main(){
    int totalBlocks;
    cin>>totalBlocks;
    vector<int> disk(totalBlocks,0);
    int files;
    cin>>files;
    map<string,pair<int,int>> table;
    while(files--){
        string name;
        int size;
        cin>>name>>size;
        int start=-1,cnt=0;
        for(int i=0;i<totalBlocks;i++){
            if(disk[i]==0){
                if(cnt==0) start=i;
                cnt++;
                if(cnt==size) break;
            }else{
                cnt=0;
                start=-1;
            }
        }
        if(cnt==size){
            for(int i=start;i<start+size;i++) disk[i]=1;
            table[name]={start,size};
            cout<<"Allocated "<<name<<" "<<start<<" "<<start+size-1<<"\n";
        }else{
            cout<<"Cannot allocate "<<name<<"\n";
        }
    }
    int q;
    cin>>q;
    while(q--){
        string name;
        cin>>name;
        if(table.count(name)){
            int s=table[name].first;
            int sz=table[name].second;
            for(int i=s;i<s+sz;i++) disk[i]=0;
            table.erase(name);
            cout<<"Freed "<<name<<"\n";
        }else{
            cout<<"File not found\n";
        }
    }
}
