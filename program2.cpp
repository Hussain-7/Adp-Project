#include<iostream> 
#include<string>
#include<algorithm>

using namespace std;

void lcs(string s1, string s2, int m, int n)
{
    int** L = new int* [m + 1];
    for (int i = 0; i < m + 1; i++) {
        L[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    int index = L[m][n];
    char* lcs = new char[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[index - 1] = s1[i - 1];
            i--; j--; index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "Longest Common Subsequence of " << s1 << " and " << s2 << " is " << lcs;
    for (int i = 0; i < m + 1; i++)
        delete[] L[i];
    delete[] L;
}

int main()
{

    string str1 = "";
    string str2 = "";
    
    cout << "Enter string 1 : ";
    getline(cin,str1);
    cout << "Enter string 2 : ";
    getline(cin, str2);
    int m = str1.length();
    int n = str2.length();
    lcs(str1, str2, m, n);
    cout << "\n\n" << endl;
    return 0;
}
