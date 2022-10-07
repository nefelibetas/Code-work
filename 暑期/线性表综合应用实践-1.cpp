#include <iostream>
#include <list>


using namespace std;

int main (int argc, char *argv[])
{

    int n, m, s, cnt;
    cnt = 0;
    cin >> n >> m >> s;

    list<int> people;
    list<int> dead;
    for(int i = 1; i <= n; i ++) people.push_back(i);
    
    auto it = people.begin();
    
    int idx = 1;
    while (cnt < n - s)
    {
        if (idx % m == 0){
            cnt ++;
            dead.push_back(*it);
            it = people.erase(it);
        } else {
            it ++;
        }
        if (it == people.end()) {
            it = people.begin();
        }
        idx ++;
    }

    cout << "死者顺序：";
    for (auto dv = dead.begin(); dv != dead.end(); dv ++) {
        cout << *dv << " ";
    }
    cout << endl << "生者：";
    for (auto sv = people.begin(); sv != people.end(); sv ++) {
        cout << *sv << " ";
    }
    return 0;
}
