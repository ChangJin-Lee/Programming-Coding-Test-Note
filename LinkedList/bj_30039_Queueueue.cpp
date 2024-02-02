#include <iostream>
#include <queue>
#include <vector> 
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#define fastcpp ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

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