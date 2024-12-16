#include<bits/stdc++.h>
#include<fstream>
using namespace std;
const int total_number=85;//总共有85个人
struct student
{
    string number;
    string real;
    string luogu;
    map<string,int>score;
    int rank;
     student()
    {

    }
    student(string _number,string _real,string _luogu,int _rank)
    {
        number=_number;
        real=_real;
        luogu=_luogu;
        rank=_rank;
    }
    bool operator<(const student b)const 
    {
        return rank<b.rank;
    }
};
struct Class
{
    vector<student>S;
    void add(student c)
    {
        S.push_back(c);
    }
    student &real_find(string real)
    {
        for(auto& t:S)
        {
            if(t.real==real)
            {
                return t;
            }
        }
        return S[0];
    }
    student &number_find(string number)
    {
        for(auto& t:S)
        {
            if(t.number==number)
            {
                return t;
            }
        }
        return S[0];
    }
    student& luogu_find(string luogu)
    {
        for(auto& t:S)
        {
            if(t.luogu==luogu)
            {
                return t;
            }
        }
        return S[0];
    }
    void print()
    {
        fstream out("out2.txt",ios::in|ios::trunc|ios::out);
        sort(S.begin(),S.end());
        for(auto t:S)
       {
            
            out<<t.score["a1"]<<","<<t.score["a2"]<<","<<t.score["a3"]<<","<<t.score["b1"]<<","<<t.score["b2"]<<","<<t.score["b3"]<<","<<t.score["b4"]<<",";
            out<<t.rank<<","<<t.real;
         out<<"\n";
         }
    }
}table;
void get_work(string filename,string workname)
{
    fstream in(filename.c_str());
    if(!in.is_open())
    {
        cerr<<"YES\n";
        return;
    }
    string s;
    int cnt=0;
    while(in>>s)
    {
       // cerr<<s<<"\n";
        if(s[0]=='#')
        {
            ++cnt;
            string luogu;
            in>>luogu;
            int score;
            student&one=table.luogu_find(luogu);
            in>>score;
            if(one.real=="")
            {
                cout<<luogu<<"此人没有登记"<<"\n";
            }
            if(score!=0)
            one.score[workname]=((total_number-cnt+1)*40.0/total_number+60);
            cerr<<score<<" "<<one.score[workname]<<"\n";
        }
    }
    //cout<<1<<"\n";
}
signed main()
{
    freopen("student.txt","a+",stdin);

    string a,b,c;
    table.add(student("","","",0));
    while(cin>>a>>b>>c)
    {
        table.add(student(c,a,b,0));
        //cout<<a<<" "<<b<<" "<<c<<"\n";
    }
    fstream in("order.txt");
    int cc;
    while(in>>a>>cc)
    {
        auto& t=table.real_find(a);
        cerr<<a<<" "<<cc<<"\n";
        if(t.real=="")
        {
            table.add(student(" ",a," ",cc));
        }
        else t.rank=cc;
    }

    get_work("h1.txt","a1");
    get_work("h2.txt","a2");
    get_work("h3.txt","a3");
    get_work("e1.txt","b1");
    get_work("e2.txt","b2");
    get_work("e3.txt","b3");
    get_work("e4.txt","b4");
    table.print();
}