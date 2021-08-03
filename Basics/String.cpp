#include<bits/stdc++.h>
#define long long ll
using namespace std;
#define deb(x) cout<<#x <<": "<<x<<endl;  
#define fo(i,a,b) for(int i = a; i <b; i++)

/* COUNT FREQUENCY OF EVERY CHAR IN STRING */

void countFreqinString(string str){
	int count[26] = {0};
	for (int i = 0; i < str.length(); i++) {
		count[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] > 0) {
			cout << char(i + 'a') << " " << count[i] << endl;
		}
	}
}

/* Check If a String is Subsequence of Other */

bool isSubseq(string s1,string s2,int n,int m){
	int j=0;
	for(int i=0; i<n && j<m;i++){
		if(s1[i] == s2[j])
			j++;
	}
	return j==m;
}

/* Check If a String is Subsequence of Other */

bool isSubseqR(string s1,string s2,int n,int m){
	if(m==0) return true;
	if(n==0) return false;

	if(s1[n-1] == s2[m-1])
		return isSubseqR(s1,s2,n-1,m-1);
	else
		return isSubseqR(s1,s2,n-1,m);
}

/* Check for Anagram */

bool areAnagramNaive(string &s1,string &s2){
	int n1 = s1.length();
	int n2 = s2.length();
	if (n1 != n2)
		return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	return (s1 == s2);
}

/* Check for Anagram */
const int CHAR = 256;
bool areAnagramEfficient(string &s1,string &s2){
	int n1 =s1.length();
	int n2 = s2.length();
	if(n1!=n2) return false;
	int count[CHAR] = {0};
	for(int i=0;i<s1.length();i++){
		count[s1[i]]++;
		count[s2[i]]--;
	}
	for(int i=0;i<CHAR;i++)
		if(count[i]!=0) return false;
	return true;
}



void rough(){
	char str[] = {'g','h','d','\0'};
	char str1[] = {'b','c','d','z','v','\0'};
	int res = strcmp(str,str1);
	// cout<<str<<" "<<str1<<" "<<res;
	string lala;
	getline(cin,lala);
	cout<<lala<<" ";
}


int main(){
	// countFreqinString("geeksforgeeks");
	// rough();
	string st1 = "apple";
	string st2 = "alppe";

	int n = st1.length();
	int m =st2.length();
	cout<<areAnagramEfficient(st1,st2);
	return 0;
}