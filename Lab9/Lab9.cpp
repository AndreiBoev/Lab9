#include <iostream>
#include <string>
#include <vector>
using namespace std;

int subStr(int k1, vector<string>& mas1, vector<string>& mas2, vector<int>& nom);
int nompodstr(int k2, vector<string>& mas2);
bool change(string& s);

int main()
{
    int k1, k2, i, num;
    vector<string> mas1;
    vector<string> mas2;
    vector<int> nom;

    string s;
    do
    {
        cout << "Enter number of lines: ";
        cin >> k1;
        if (cin.fail())    
            cin.clear();
        getline(cin, s);
    } while (k1 <= 0);
    cout << "Enter " << k1 << " strings" << endl;
    for (i = 0; i < k1; i++)
    {
        string input;
        getline(cin, input);
        mas1.push_back(input);
    }

    k2 = subStr(k1, mas1, mas2, nom);
    if (k2 == 0)
        cout << "No substrings" << endl;
    else
    {
        cout << "Substrings:" << endl;
        for (i = 0; i < k2; i++)
            cout << mas2[i] << endl;
    }

    num = nompodstr(k2, mas2);
    if (num == -1)
        cout << "No necessary substrings" << endl;
    else
    {
        cout << "Necessary substring: " << mas2[num] << endl;
        if (change(mas1[nom[num]]))
            cout << "Changed string: " << mas1[nom[num]];
        else
            cout << "No changes in string" << endl;
    }
    return 0;
}

int subStr(int k1, vector<string>& mas1, vector<string>& mas2, vector<int>& nom)
{
    for (int i = 0; i < k1; i++)
    {
        string temp;
        for (char c : mas1[i])
            if (isdigit(c))
            {
                if (!temp.empty()) {
                    mas2.push_back(temp);
                    nom.push_back(i);
                    temp.clear();
                }
            }
            else
                temp += c;
        if (!temp.empty()) {
            mas2.push_back(temp);
            nom.push_back(i);
        }
    }
    return mas2.size();
}

int nompodstr(int k2, vector<string>& mas2) 
{
    for (int i = 0; i < k2; i++)
    {
        bool flag = false;
        for (char c : mas2[i]) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            return i;
        }
    }
    return -1;
}

bool change(string& s)
{
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '{')
            s.replace(i, 1, "begin"), flag = true;
        else if (c == '}')
            s.replace(i, 1, "end"), flag = true;
    }
    return flag;
}