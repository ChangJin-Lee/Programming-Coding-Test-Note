#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int i,n;
    char word[35];
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        gets(word);
        if(word[0]>=97)
            word[0]-=32;
        puts(word);
    }
//    int i,n;
//    string word;
//    cin >> n;
//    cin.ignore();
//    for(i=0;i<n;i++){
//        getline(cin,word);
//        if(word[0]>=97)
//            word[0]-=32;
//        cout << word << "\n";
//    }
}


//#include <stdio.h>
//#include <string.h>
//#define MAX 50
//
//char ch[MAX];
//
//int main(void){
//    int test;
//    scanf("%d ", &test);
//    for (; test >= 1; test--){
//        gets(ch + 1);
//        if (ch[1] >= 'a') ch[1] -= 32;
//        puts(ch + 1);
//    }
//    return false;
//}