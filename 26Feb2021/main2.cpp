// find shortest substring containing all characters of a given string
// unsolved

// NOTEL: this is MINIMUM SUBSTRING PROBLEM TO BE SOLVED USING SLIDING WINDOWS TECHNIQUE
// AKA BELOW CODE IS IRRELEVANT 
#include <bits/stdc++.h>
using namespace std;

vector<string> subString(char str[], int n) 
{
    vector<string> substrList;
    // Pick starting point
    for (int len = 1; len <= n; len++) 
    {    
        // Pick ending point
        for (int i = 0; i <= n - len; i++) 
        {
            string substr = "";
            //  Print characters from current
            // starting point to current ending
            // point.  
            int j = i + len - 1;            
            for (int k = i; k <= j; k++) 
                substr += str[k];
             
            substrList.push_back(substr);
        }
    }

    return substrList;
}


string shortestsubstr(string str, string query)
{
    vector<string> substrList2;
    char strarr[str.size()+1];
    strcpy( strarr, str.c_str() );
    vector<string> substrList = subString( strarr, str.size()+1);

    vector<string>::iterator it = substrList.begin();
    while( it != substrList.end() )
    {
        int count = 0;
        for (int i = 0; i < query.size() ; i++)
        {
            if ( it->find_first_of( query[i] != string::npos) )
            {
                count++;
                it->replace( it->find_first_of( query[i]) , 1, '#');
            }
        }
        if ( count == query.size() )
        {
            substrList2.push_back( it );
        }
    }

    string shortest2 = "";
    vector<string> itt = substrList2.begin();

    int min = 0;
     while( itt != substrList2.end() )
     {
         if ( min < itt->length() )
         {
             min = itt->length();
             shortest2 = itt;
         }
     }
     

    return shortest2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline( cin, str);

    string query;

    getline( cin, query);

    cout << shortestsubstr(str, query);
}   
