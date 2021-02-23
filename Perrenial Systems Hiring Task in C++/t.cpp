#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
    map <string, vector<string>> data;

    pair <fstream, fstream> file;
    string item, category;
  
    string itemFileName = "ItemMaster.txt"; 
    string categoryFileName = "CategoryMaster.txt"; 

    file.first.open(itemFileName.c_str()); 
    file.second.open(categoryFileName.c_str()); 
    
    cout << "1" << endl;

    while ( getline(file.second, item) && getline(file.first, category) ) 
    { 
        if( data.find(category) == data.end() )
        {
            vector<string> items;
            items.push_back(item);
            data.insert( pair<string, vector<string>>(category, items) );
        }
        else
        {
            data.find(category)->second.push_back(item);
        }
    }
}
