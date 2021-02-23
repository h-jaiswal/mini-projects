/*
Perrenial Systems Task in C, C++ or Java

Task Details

1. It shall read ItemMaster.txt file
2. It shall compare every item in above file with CategoryMaster.file
3. Group items by category and print them
4. Task user input ( ask the user to enter a category) for which you need to display all categories 
5. Display all items corresponding to the category provided as input
*/

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

    while ( getline(file.first, item) && getline(file.second, category) ) 
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

    cout << "2" << endl;

    file.first.close();
    file.second.close();

    cout << "3" << endl;


    cout << "Available Categories: \n";
    
    map <string, vector<string>>::iterator it = data.begin();
    while( it != data.end() )
    {
        cout << it->first << "\n";
        it++;
    }

    string user_input;
    cout << "Enter a category: ";
    getline( cin, user_input) ;

    for (int i = 0; i < data.find(user_input)->second.size(); i++)
    {
        cout << data.find(user_input)->second.at(i) << "\n";

    }
    
    return 0; 
}