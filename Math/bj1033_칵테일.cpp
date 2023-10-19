#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

typedef struct ver
{
    int line;
    int weight;
} ver;

ver vertex[15];

// 유클리드 호제법을 이용한 최대공약수 구하기
// 두 수의 기약 분수는  (a * b) / gcd 로 나타낼 수 있음.
int Gcd(int a, int b)
{
    int A = max(a, b);
    int B = min(a, b);

    while (A % B != 0)
    {
        int R = A % B;
        A = B;
        B = R;
    }
    return B;
}

// 두 수를 최대 공약수로 나눈 결과
void setGcd(int &p, int &q)
{
    int gcd;
    gcd = Gcd(p, q);
    p /= gcd;
    q /= gcd;
}

void update(int idx, int val, int line, int cnt, int n)
{
    int branch = vertex[idx].line;
    vertex[idx].weight *= val;
    vertex[idx].line = line;
    if (cnt == 1 && branch != line && branch != -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (vertex[i].line == branch && i != idx)
            {
                update(i, val, line, 2, n);
            }
        }
    }
}

int main()
{

    // a b p q
    // a번 재료의 질량을 b번 재료의 질량으로 나눈 값이 p/q 라는 뜻이다.
    //      5
    //      4 0 1 1
    //      4 1 3 1
    //      4 2 5 1
    //      4 3 7 1

    //  3/0 = 7/5
    //  3 * 5 = 7 * 0
    //  3 : 0 = 7 : 5

    // 4
    // c d 3 4
    // a b 3 1
    // d a 7 5
    // a d 20 21
    // b d 5 21

    // a = 3b
    // 7a = 5d
    // 3d = 4c
    // 4/3 * 5 d = 7a
    // 20d = 21a
    // a d 20 21
    // 21b = 5d

    int n;               // need to ingredient
    int a, b, p, q;      // input values
    int aVal, bVal, gcd; // using in while loop
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vertex[i].weight = 1;
        vertex[i].line = -1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> p >> q;
        setGcd(p, q);
        aVal = vertex[b].weight * p;
        bVal = vertex[a].weight * q;
        setGcd(aVal, bVal);
        update(a, aVal, i, 1, n);
        update(b, bVal, i, 1, n);
    }

    for (int i = 0; i < n; i++)
        cout << vertex[i].weight << " ";
    cout << endl;
}