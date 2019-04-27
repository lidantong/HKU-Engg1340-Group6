#include "generate.h"
#include "grocery.h"

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
    grocery *g = new grocery[cnt]();
    for (int i = 0; i < cnt; i++)
    {
        g[i].name = generate_name(rand() % name_len + 1);
        g[i].t =  rand() % 1000 / 100.0;
        g[i].val = rand() % 1000 / 100.0;
        g[i].cnt =  rand() % 10;
    }
    for (int i = 0; i < cnt; i++)
    {
    	fout << g[i].name << " ";
	fout << g[i].t << " ";
	fout << g[i].val << " ";
	fout << g[i].cnt << endl;
	}
	delete[] g;
	fout.close();
}
