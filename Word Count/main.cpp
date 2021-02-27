// Proficiency in multiple technologies. Industrial internship experience with Hackveda. Induction of new interns at Hackveda. Team Lead - Smart India Hackathon 2019 Grand Finale participant team. Proficient in Business English.

/* I want to achieve collaborated goals and set a benchmark for future growth coupled with continuous learning and persistence. Working for Collabera allows me to achieve professional goals. I am eager to learn developing and establishing strategic recruitment strategies, engaging with social media, identifying/recruiting appropriate talent, and
achieving recruitment objectives.
*/

// unsolved
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input_string;
    getline( cin, input_string);

    int num_words = 0;
    string::iterator it = input_string.begin();
    while (it != input_string.end())
    {
        if ( * it.base() == ' ')
        {
            num_words++;
        }
        it++;
    }
    
    num_words++;

    cout << num_words;
    
}