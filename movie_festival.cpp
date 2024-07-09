#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    pair<int,int>events[n];
    for(int i=0;i<n;i++){
        int f,s;
        cin>>f>>s;
        events[i].first=s;
        events[i].second=f;
    }

    sort(events,events+n);
    int currentEventEnd=-1;
    int count=0;
    for (int i=0;i<n;i++){
        if(events[i].second>=currentEventEnd){
            currentEventEnd=events[i].first;
            count++;
        }
    }
    cout<<count;
    return 0;
}