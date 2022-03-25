//대문자, 소문자별로 13만큼 뒤로 밀어서 출력하라는 문제였다
//나는 아스키 코드로 생각햇는데, 굳이 그럴 필요가 업었다.
//생각해보면, 'a', 'A' 이런식으로 적으면  pc는 알아서 아스키 코드 값으로 알아듣는다.
//그니까 122-13 이런식으로 할 필요가 없고 'A'+13 이런식으로 써도 된다는 말임.

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int i;
    string s;
    getline(cin,s);
    for(i=0;i<s.length();i++){
        if(s[i] != ' '){
            if(65<=s[i] and s[i]<=90){ // 대문자라면
                if(s[i]>77){
                    s[i]= 65+12-(90-s[i]);
                }
                else{
                    s[i]+=13;
                }
            }
            else if(97<=s[i] and s[i]<=122){ // 소문자라면
                if(s[i]>109){
                    s[i] = 97+12-(122-s[i]);
                }
                else{
                    s[i]+=13;
                }
            }
        }
    }
    cout << s;
}


// 고수들의 의견을 첨가한 코드
#include<stdio.h>

char s[111];

char conv(char a){
    if('a'<=a && a<='z')return (a-'a'+13)%26+'a';
    if('A'<=a && a<='Z')return (a-'A'+13)%26+'A';
    return a;
}

int main(){
    gets(s);
    for(int i=0; s[i]; i++)putchar(conv(s[i]));
    return 0;
}