//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void display(vector<int>& vec){
	for(int& i : vec){
		cout<<i<<" ";
	}
	cout<<endl;
}

int partition(vector<int>& vec,int start,int end){
	int pindex=start;
	int pval=vec[end];
	for(int i=start;i<end;++i){
		if(vec[i]<=pval){
			swap(vec[i],vec[pindex]);
			pindex++;
		}
	}
	swap(vec[end],vec[pindex]);
	return pindex;
}

void quicksort(vector<int>& vec,int start,int end){
	if(start<=end){
		int p=partition(vec,start,end);
		quicksort(vec,start,p-1);
		quicksort(vec,p+1,end);
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jets();
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;++i){
    	cin>>vec[i];
    }
    display(vec);
    quicksort(vec,0,n-1);
    display(vec);
    
    return 0;
}