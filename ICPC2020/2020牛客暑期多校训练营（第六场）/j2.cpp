#include <bits/stdc++.h>
using namespace std;
int n, i, j, Var[26], Fld[26][26], _Var[26], _Fld[26][26];
string CmdL[205], CmdR[205], tmp;

bool Update()
{
    for (int i = 0; i < 26; ++i)
        if (Var[i] != _Var[i])
            return true;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            if (Fld[i][j] != _Fld[i][j])
                return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> CmdL[i] >> tmp >> CmdR[i];
    do
    {
        for (i = 0; i < 26; ++i)
            _Var[i] = Var[i];
        for (i = 0; i < 26; ++i)
            for (j = 0; j < 26; ++j)
                _Fld[i][j] = Fld[i][j];
        for (i = 1; i <= n; ++i)
            if (CmdR[i].length() == 1 && islower(CmdR[i][0]))
            {
                Var[CmdL[i][0] - 'A'] |= 1 << (CmdR[i][0] - 'a');
            }
            else if (CmdR[i].length() == CmdL[i].length())
            {
                Var[CmdL[i][0] - 'A'] |= Var[CmdR[i][0] - 'A'];
            }
            else if (CmdL[i].length() == 3)
            {
                for (j = 0; j < 26; ++j)
                    if (Var[CmdL[i][0] - 'A'] & (1 << j))
                        Fld[j][CmdL[i][2] - 'a'] |= Var[CmdR[i][0] - 'A'];
            }
            else
            {
                for (j = 0; j < 26; ++j)
                    if (Var[CmdR[i][0] - 'A'] & (1 << j))
                        Var[CmdL[i][0] - 'A'] |= Fld[j][CmdR[i][2] - 'a'];
            }
    } while (Update());
    for (i = 0; i < 26; ++i)
    {
        cout << (char)(i + 'A') << ": ";
        for (j = 0; j < 26; ++j)
            if (Var[i] & (1 << j))
                cout << (char)(j + 'a');
        cout << '\n';
    }
}