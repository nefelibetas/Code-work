#include <iostream>
#include <list>


using namespace std;

int main (int argc, char *argv[])
{

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    list<int> people;
    list<int> dead;
    for(int i = 1; i <= n; i ++) people.push_back(i);
    
    auto it = people.begin();

    while (people.size() > s){
        for (int i = 0; i < m - 1; i ++){
            if (++ it == people.end()){
                it = people.begin();
            }
        }
        dead.push_back(*it);
        it = people.erase(it);
        for (int i = 0; i < k - 1; i ++){
            if (it == people.begin()){
                it = people.end();
            } 
            it --;
        }
        dead.push_back(*it);
        it = people.erase(it);
        if (it == people.begin()){
            it = people.end();
        }
        it --;
    }
    cout << "死者顺序：";
    for (auto d : dead) cout << d << ' ';
    cout << endl << "生者：";
    for (auto p : people) cout << p << ' ';
    return 0;
}
