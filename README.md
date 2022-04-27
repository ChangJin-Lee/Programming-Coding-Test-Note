

# About Python
Coding Test
코테준비 연습

# 오류
unindent does not match any outer indentation level
indentation Error : 들여쓰기 오류


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

#### 1018번 체스문제 

## 파이썬에서 테스트를 더 쉽게하자. unittest, assert 관련

#### 파이썬은 동적 특성으로 인해 애플리케이션 대부분에 있어 테스팅이 매우 중요하다. 컴파일러로는 버그를 찾을 수 없다. 버그를 찾는 유일한 방법은 코드를 실행해 모든 기능을 점검하는 것이다.
##### assert <표현식> [, '진단 메시지']
#### 사용자 입력(예: 웹 양식 같은 것을 통해 입력한 데이터)을 검사하는 데 assert를 사용하면 안 된다. 내부적인 점검과 불변 조건(항상 참인 조건)을 검사하는 것이 목적이다.

### 계약 프로그래밍(Contract Programming)
#### https://wikidocs.net/84431 


##


# algorithm

### *** Dynamic programming
#### 분할정복 즉 Divide and conquer 에서는 풀었던 문제를 다시 반복해서 풀지만 다이나믹 프로그래밍에서는 단 한번만 문제를 푼다.
#### 내가 이해한 다이나믹 프로그래밍의 핵심은 다음과 같다
##### - "현재 상태를 기억하고 그 상태를 계속해서 갱신해 나간다"
#### 메모이제이션 방법과도 같지만 결국 풀었던 문제는 풀지 않는다는 말과 같다.
#### 그리디 방법이나 분할정복으로는 풀리지 않는 문제들이 다이나믹 프로그래밍으로는 정말 쉽게 풀린다.

##


### *** Backtracking
#### 백트레킹은 모든 경우의 수를 찾아보는 방법이다. 유명한 문제로는 체스판 위에 퀸을 움직이는 경우의 수이다.
#### 내가 이해한 백트래킹의 핵심은 다음과 같다
##### - "모든 경우의 수 중에서 원하는 조건에 해당하는 경우의 수만을 계산하겠다."


### 브루트 포스(brute force)
#### 완전탐색 알고리즘이다. 
#### 해가 존재할 것으로 예상되는 모든 영역을 전체 탐색하는 방법이다.
#### DFS, BFS 좋은 도구이다.
