#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

typedef struct MyStruct 
{
    int num;
    string name;
    string sub;
} ns;

vector<ns> reg;

void Insert(int n){
    while(n --){
        int num;
        string name, sub;
        cin >> num >> name;
        getchar();
        getline(cin, sub);
        ns s = {num, name, sub};
        reg.push_back(s);
    }
}

void Select(string subject){
    for (auto r : reg){
        if (subject == "" || r.sub == subject){
            printf("%03d ", r.num);
            cout << r.name << " " << r.sub << endl;
        }
    }
}

void Update(int id, string sub){
    for (auto r = reg.begin(); r != reg.end(); r ++){
        if (id == r->num) {
            r->sub = sub;
            break;
        }
    }
    Select("");
}

void Delete(int id){
    for (auto r = reg.begin(); r != reg.end(); r ++){
        if (id == r->num) {
            reg.erase(r);
            break;
       }
    }
    Select("");
}

typedef pair<string, int> psi;
bool cmp(const psi &a, const psi &b){
    if (a.second != b.second){
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
}

void Sum(){
    map<string, int> sum;
    vector<psi> vpsi;
    for (auto r : reg) {
        sum[r.sub] ++;
    }
    for (auto s : sum){
        vpsi.push_back({s.first, s.second});
    }
    sort(vpsi.begin(), vpsi.end(), cmp);
    for (auto v : vpsi){
        cout << v.first << " " << v.second << endl;
    }
}

int main (int argc, char *argv[])
{
    int m = 6;
    while (m --)
    {
        int op, n;
        string m;
        cin >> op;
        switch (op) {
            case 1:
                cin >> n;
                Insert(n);
                break;
            case 2:
                Select("");
                break;
            case 3:
                getchar();
                getline(cin, m);
                Select(m);
                break;
            case 4:
                cin >> n;
                getchar();
                getline(cin, m);
                Update(n, m);
                break;
            case 5:
                cin >> n;
                Delete(n);
                break;
            default:
                Sum();
                break;
        }
        
    }

    return 0;
}
