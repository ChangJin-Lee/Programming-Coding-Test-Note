# coding_test_python
파이썬 코테준비 연습
해야함

## EOF?
####  https://www.acmicpc.net/board/view/39199
#### input() 보다는 sys.stdin.readline()을 사용하자


## recursive
#### 파이썬에서는 recursive가 1,000번으로 제한됨. 
#### 만약 1,000을 넘어가면 RecursionError: maximum recursion depth exceeded while pickling an object 가 뜰것임.
#### -> while문을 쓰던지 해야함 recursive로 한계가 있음.

## edge case? 

## 어려웠던 문제

#### 1002번 터렛 -> 원의 내접 외접 관련 문제. 제곱의 오차에 관련된 케이스가 어려웠음

## 파이썬에서 테스트를 더 쉽게하자. unittest, assert 관련

#### 파이썬은 동적 특성으로 인해 애플리케이션 대부분에 있어 테스팅이 매우 중요하다. 컴파일러로는 버그를 찾을 수 없다. 버그를 찾는 유일한 방법은 코드를 실행해 모든 기능을 점검하는 것이다.
##### assert <표현식> [, '진단 메시지']
#### 사용자 입력(예: 웹 양식 같은 것을 통해 입력한 데이터)을 검사하는 데 assert를 사용하면 안 된다. 내부적인 점검과 불변 조건(항상 참인 조건)을 검사하는 것이 목적이다.

### 계약 프로그래밍(Contract Programming)
#### https://wikidocs.net/84431 

