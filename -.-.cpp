#include <bits/stdc++.h>
using namespace std;
set < pair < int,int > > edges;
vector < int > nodes, nodes_taken;
long long int ans;
const int connected= 5;
ifstream os;
ofstream on;

void checker()
{
    map < int,int > cnt;
    set < int > st;
    for(auto x : nodes_taken) { //jesob subset e ase sob set e anlam
        st.insert(x);
        cnt[x]=0;
    }

    for(auto x : edges){
        if(st.find(x.first) != st.end() and st.find(x.second) != st.end()) {
            cnt[x.first]++, cnt[x.second]++;
        }
    }
    bool f = 1;
    for(auto x : cnt){
        if(x.second < connected) f = 0;
    }
    ans += f;
    if(f){
        for(auto x : nodes_taken){
            on << x << " " ;
        }

        on << endl;
    }
}
void solve(int pos)
{
    if(pos >= nodes.size()) {
        checker();
        return ;
    }
    nodes_taken.push_back(nodes[pos]);
    solve(pos + 1);
    nodes_taken.pop_back();
    solve(pos+1);
}

int main()
{


    os.open("input.txt");
    on.open("components.txt");

    if(!os.is_open() or !on.is_open()){
        cout << "error :)\n";
    }
    else {
        map < pair < int, int >, int >  mp;
        int ec = 0;
        set < int > uniq;

        int a,b;
        while(os >> a >> b) {
            uniq.insert(a);
            uniq.insert(b);

            if(a > b) swap(a,b);
            edges.insert({a,b});
        }
        for(auto x : uniq) nodes.push_back(x);


        solve(0);
        //cout << ans << endl;
        os.close();
    }

}
