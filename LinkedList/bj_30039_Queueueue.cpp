#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

// {"name":"Local: bj_30039_Queueueue","url":"d:\\Github\\Coding-Test\\LinkedList\\bj_30039_Queueueue.cpp","tests":[{"id":1706879519146,"input":"33\nempty\nhpush 2\nvpush 3\nvfront\nempty\nhpush 4\nhfront\nvpush 1\nhpush 5\nmiddle\nvback\nhback\nvpush 6\nmiddle\nhsize\nvpop\nvfront\nhpop\nvsize\nhpop\nsize\nhpop\nhpop\nvpop\nvpop\nsize\nvfront\nhfront\nvback\nhback\nhpop\nsize\nempty","output":"1\n2\n0\n2\n4\n1\n5\n4\n3\n2\n4\n3\n3\n1\n3\n5\n4\n6\n-1\n0\n-1\n-1\n-1\n-1\n-1\n0\n1"},{"id":1706879528694,"input":"33\nhpush 1\nvpush 2\nvpush 3\nvpop\nvpop\nvpop\nvpush 1\nvpush 2\nhpush 3\nvpop\nvpop\nhpush 4\nhpush 5\nvpush 6\nvpush 7\nhpop\nvpop\nhpop\nvpop\nhpop\nvpush 1\nvpush 2\nvpush 3\nvpush 4\nvpop\nhpush 5\nhpush 6\nhpop\nvpop\nhpop\nvpop\nhpop\nhpop","output":"1\n2\n3\n1\n2\n3\n4\n6\n5\n7\n1\n3\n2\n5\n6\n4\n-1"},{"id":1706879537736,"input":"33\nmiddle\nhpush 1\nmiddle\nvpush 2\nmiddle\nhpush 3\nmiddle\nvpush 4\nmiddle\nhpush 5\nmiddle\nvpush 6\nmiddle\nhpush 7\nmiddle\nvpush 8\nmiddle\nhpush 9\nmiddle\nvpush 10\nmiddle\nhpop\nmiddle\nhpop\nmiddle\nhpop\nmiddle\nhpop\nmiddle\nhpop\nmiddle\nhpop\nmiddle","output":"-1\n1\n1\n1\n2\n3\n3\n3\n4\n5\n5\n2\n5\n4\n7\n5\n7\n7\n9\n9\n6\n6\n3"}],"interactive":false,"memoryLimit":1024,"timeLimit":3000,"srcPath":"d:\\Github\\Coding-Test\\LinkedList\\bj_30039_Queueueue.cpp","group":"local","local":true}

class Queueueue
{
private:
    vector<int> hq; // 수평방향 큐
    vector<int> vq; // 수직방향 큐
    int hIndex = 0;
    int vIndex = 0;
public:
    int realEmpty();
    int empty();
    void middle();
    void UpdateQueueue(bool isHorizontal, int x);
    void hpush(int x);
    void hpop();
    void hfront();
    void hback();
    void hsize();
    void vpush(int x);
    void vpop();
    void vfront();
    void vback();
    void vsize();
    void size();
    void showQ();
};

int Queueueue::realEmpty()
{
    return hq.empty() && vq.empty() ? 1 : 0;
}

int Queueueue::empty()
{
    return hq.empty() || vq.empty() ? 1 : 0;
}

void Queueueue::middle()
{
    if(realEmpty())
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << hq[hIndex] << "\n";
    }
}

void Queueueue::UpdateQueueue(bool isHorizontal, int x)
{
    hq.size() % 2 == 0 ? hIndex = (hq.size() / 2) - 1 : hIndex = (hq.size() / 2);
    vq.size() % 2 == 0 ? vIndex = (vq.size() / 2) - 1 : vIndex = (vq.size() / 2);

    if(hIndex == -1)
        hIndex = 0;
    if(vIndex == -1)
        vIndex = 0;

    if( x != -1) // pop이 아닐때
    {
        // hpush일 경우
        if(isHorizontal)
        {
            if(vq.empty())
                vq.push_back(x);
            else
            {
                if( vq.size() == 0 )
                {
                    vq[vIndex] = x;
                }
                else
                {
                    vq[vIndex] = hq[hIndex];
                }
            }
        }
        // vpush일 경우
        else
        {
            if(hq.empty())
                hq.push_back(x);
            else
            {
                if(hq.size() == 0 )
                {
                    hq[hIndex] = x;
                }
                else
                {
                    hq[hIndex] = vq[vIndex];
                }
            }
        }
    }
    else    // pop일 때
    {
        // hpop일 경우
        if(isHorizontal)
        {
            if( hq.size() == 0 )
            {
                if(!vq.empty())
                {
                    vq.erase(vq.begin()+vIndex);
                    if(!vq.empty())
                    {
                        if(vIndex)
                        {
                            vq.size() % 2 == 0 ? vIndex = (vq.size() / 2) - 1 : vIndex = (vq.size() / 2);
                        }
                        else
                        {
                            vIndex = 0;
                        }
                        hq.push_back(vq[vIndex]);
                    }
                }
                else
                {
                    vq.clear();
                    hq.clear();
                }
            }
            else
            {
                vq[vIndex] = hq[hIndex];
            }
        }
        // vpop일 경우
        else
        {
            if( vq.size() == 0)
            {
                if(!hq.empty())
                {
                    hq.erase(hq.begin()+hIndex);
                    if(!hq.empty())
                    {
                        if(hIndex)
                        {
                            hq.size() % 2 == 0 ? hIndex = (hq.size() / 2) - 1 : hIndex = (hq.size() / 2);
                        }
                        else
                        {
                            hIndex = 0;
                        }
                        vq.push_back(hq[hIndex-1]);
                    }
                }
                else
                {
                    vq.clear();
                    hq.clear();
                }
            }
            else
            {
                hq[hIndex] = vq[vIndex];
            }
            
        }
    }
}

void Queueueue::hpush(int x)
{
    hq.push_back(x);
    UpdateQueueue(true, x);
}

void Queueueue::hpop()
{
    if(!hq.empty())
    {
        cout << hq.front() << "\n";
        hq.erase(hq.begin());
    }
    else
    {
        if(vq.empty() && !hq.empty())
        {
            int front = hq.front();
            hq.erase(hq.begin());
            cout << front << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    UpdateQueueue(true, -1);
}

void Queueueue::hfront()
{
    if(!empty())
    {
        cout << hq.front() << "\n";  
    }
    else
    {
        cout << "-1\n";
    }
}

void Queueueue::hback()
{
    if(!empty())
    {
        cout << hq.back() << "\n";  
    }
    else
    {
        cout << "-1\n";
    }
}

void Queueueue::hsize()
{
    cout << hq.size() << "\n";  
}

void Queueueue::vpush(int x)
{
    vq.push_back(x);
    UpdateQueueue(false, x);
}

void Queueueue::vpop()
{
    if(!vq.empty())
    {
        cout << vq.front() << "\n";
        vq.erase(vq.begin());
    }
    else
    {
        if(!vq.empty() && hq.empty())
        {
            int front = vq.front();
            vq.erase(vq.begin());
            cout << front << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
    UpdateQueueue(false, -1);
}

void Queueueue::vfront()
{
    if(!empty())
    {
        cout << vq.front() << "\n";  
    }
    else
    {
        cout << "-1\n";
    }
}

void Queueueue::vback()
{
    if(!empty())
    {
        cout << vq.back() << "\n";  
    }
    else
    {
        cout << "-1\n";
    }
}

void Queueueue::vsize()
{
    cout << vq.size() << "\n";
}

void Queueueue::size()
{
    if(!empty())
        cout << hq.size() + vq.size() - 1 << "\n";
    else
        cout << 0 << "\n";
}

void Queueueue::showQ()
{
    cout << "hq size and content : " << hq.size()  << "\n";
    for(auto k : hq)
    {
        cout << k << " ";
    }

    cout << "\nvq size and content : "  << vq.size()  << "\n";

    for(auto m : vq)
    {
        cout << m << " ";
    }
    cout << "\n";
}


int main()
{
    fastcpp;
    int n, x;
    string cmd;
    string input;
    stringstream ss;
    Queueueue myQ;

    cin >> n;
    n++;
    while(n--)
    {
        ss.clear();
        getline(cin, input);
        ss.str(input);
        ss >> cmd;

        // cout << cmd << "\n";

        if(cmd == "hpush")
        {
            ss >> x;
            myQ.hpush(x);
        }
        else if (cmd == "vpush")
        {
            ss >> x;
            myQ.vpush(x);
        }
        else if (cmd == "hpop")
        {
            myQ.hpop();
        }
        else if (cmd == "hfront")
        {
            myQ.hfront();
        }
        else if (cmd == "hback")
        {
             myQ.hback();
        }
        else if (cmd == "hsize")
        {
             myQ.hsize();
        }
        else if (cmd == "vpop")
        {
            myQ.vpop();
        }
        else if (cmd == "vfront")
        {
            myQ.vfront();
        }
        else if (cmd == "vback")
        {
             myQ.vback();
        }
        else if (cmd == "vsize")
        {
             myQ.vsize();
        }
        else if (cmd == "size")
        {
             myQ.size();
        }
        else if (cmd == "empty")
        {
            cout << myQ.realEmpty() << "\n";
        }
        else if (cmd == "middle")
        {
            myQ.middle();
        }

        // myQ.showQ();
    }
}