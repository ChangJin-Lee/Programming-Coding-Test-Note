#include <iostream>
#include <string>
#include <map>
// it is namespace
using namespace std;

map<int, int> numbers;
map<int, int>::iterator iter;

int main() {
    int num, target;
    int avg = 0;
    int cnt = 0;
    for (int i =0 ; i< 10; i++){
        cin >> num;
        avg += num;
        if(numbers.count(num) == 0){
            numbers[num] = 1;
        }
        else{
            numbers[num]+=1;
        }
    }
    for(iter= numbers.begin(); iter!=numbers.end();iter++)
        if(cnt < iter->second){
            cnt = iter->second;
            target = iter->first;
        }

    cout << avg/10 << "\n" << target;

}