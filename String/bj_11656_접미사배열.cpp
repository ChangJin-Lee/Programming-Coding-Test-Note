#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastcpp ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string GetSuffixFromString(string s, int start);

int main(){
    fastcpp;
    vector<string> v;
    string input;

    cin >> input;

    for(int index = 0; index < input.length(); index++){
        v.push_back(GetSuffixFromString(input, index));
    }

    sort(v.begin(), v.end());

    for(int index = 0; index < input.length(); index++){
        cout << v[index] << "\n";
    }
}

string GetSuffixFromString(string s, int start)
{
    string tmp = "";
    for(int index = start; index < s.length(); index++)
    {
        tmp += s[index];
    }
    return tmp;
}