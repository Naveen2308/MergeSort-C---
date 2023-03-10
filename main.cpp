#include<iostream>
#include<vector> 
using namespace std;
void merge(vector<int> &a,int l,int mid,int h){
    vector<int> temp;
    int i,j;
    i=l;
    j=mid+1;
    while(i<= mid && j<=h){
        if(a[i] >= a[j]){
            temp.push_back(a[j]);
            j++;
        }
        else{
            if(a[i] <= a[j]){
                temp.push_back(a[i]);
                i++;
            }
        }
    }
    while(i <= mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j <= h){
        temp.push_back(a[j]);
        j++;
    }
    for(int i=l;i<=h;i++){
        a[i]=temp[i-l];
    }
}
void mergersort(vector<int> &a,int l,int h){
    if(l == h){
        return;
    }
    int mid=(l+h)/2;
    mergersort(a,l,mid);
    mergersort(a,mid+1,h);
    merge(a,l,mid,h);
}
int main(){
    vector<int> a={3,4,2,5,1};
    mergersort(a,0,4);
    for(auto nums: a){
        cout<<nums<<endl;
    }
}