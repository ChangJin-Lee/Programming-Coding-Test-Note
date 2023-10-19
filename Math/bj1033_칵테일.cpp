#include <iostream>
#include <algorithm>

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