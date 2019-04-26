#include "generate.h"
#include <time.h>
#include <string>

const int name_len = 10;

void generate(int cnt)
{
    srand(time(NULL));
    rand();
    string filename = generate_name(rand() % name_len + 1);
    generate_customer(filename);
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
    ofstream fout((filename + ".txt").c_str());
    int cnt = rand() % 50 + 1;
    for (int i = 0; i < cnt; i++)
    {
        fout << generate_name(rand() % name_len + 1) << " ";
        fout << rand() % 1000 / 100 << " ";
        fout << rand() % 1000 / 100 << " ";
        fout << rand() % 100 << endl;
    }
    fout.close();
}
