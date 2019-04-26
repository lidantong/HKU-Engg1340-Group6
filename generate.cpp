#include "generate.h"

const int name_len = 10;

vector <string> generate(int cnt)
{
    srand(time(NULL));
    rand();
    vector <string> ans;
    for (int i = 0; i < cnt; i++)
    {
        ans.push_back(generate_name(rand() % name_len + 1) + ".txt");
        generate_customer(ans[i]);
    }
    return ans;
}

string generate_name(int len)
{
    string s = "";
    for (int i = 0; i < len; i++)
        s += rand() % 26 + 'a';
    return s;
}

void generate_customer(string filename)
{
    ofstream fout(filename.c_str());
    int cnt = rand() % 10 + 1;
    for (int i = 0; i < cnt; i++)
    {
        fout << generate_name(rand() % name_len + 1) << " ";
        fout << rand() % 1000 / 100.0 << " ";
        fout << rand() % 1000 / 100.0 << " ";
        fout << rand() % 10 << endl;
    }
    fout.close();
}
