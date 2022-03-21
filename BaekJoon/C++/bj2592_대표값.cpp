//그냥 처음에 했던 생각처럼 101개의 배열을 선언하고 해당하는 배열에 빈도수를 넣어주는게 메모리가 더 적게듬
//c++에서는 key:value를 어떻게 나타낼까?
//구글링해 본 결과로는 map이라는 헤더파일을 import해서 iterator도 선언해주면 충분히 쓸 수 있다.
//근데 이 문제에서는 map을 쓰면 코드 길이도 길어지고 메모리도 많이 먹으므로 그냥 배열 101개를 선언하는게 더 낫다.

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