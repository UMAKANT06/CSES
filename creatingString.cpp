#include<bits/stdc++.h>
using namespace std;

string s;
vector<string> perms;
int char_count[26];
void search(){
    for(int i=0;i<s.length();i++){
        
    }
}
int main() {
	cin >> s;
	for (char c : s) { char_count[c - 'a']++; }

	search();

	cout << perms.size() << '\n';
	for (const string &perm : perms) { cout << perm << '\n'; }
}