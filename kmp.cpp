//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
#define MAX 100002
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int pi[MAX];


void kmpPreprocess(string pat){
	int n=pat.length();
	int i=0,j=-1;
	while(i<n){
		while(j>=0 && pat[i]!=pat[j])
			j=pi[j];
		i++,j++;
		pi[i]=j;
	}

}

void kmp(string str, string pat){
	kmpPreprocess(pat);
	int i=0,j=0;
	int m=str.length(),n=pat.length();
	while(i<m){
		while(j>=0 && str[i]!=pat[j])
			j=pi[j];
		i++,j++;
		if(j==n){
			cout<<(i-j)+1<<" ";
			j=pi[j];
		}
	}
	cout<<endl;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jets();
    int t;
    cin>>t;
    memset(pi,-1,sizeof pi);
    while(t--){
    	string str,pat;
    	cin>>str>>pat;
    	kmp(str,pat);
    }
    return 0;
}