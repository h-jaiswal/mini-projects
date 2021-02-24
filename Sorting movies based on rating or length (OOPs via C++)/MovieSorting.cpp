#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Movie {
    string movieTitle;
    double rating; // char is lighter
    short lengthInMins;
};

bool compareRating(Movie &m1, Movie &m2) {
    return m1.rating > m2.rating;
}
     
bool compareLength(Movie &m1, Movie &m2) {
    return m1.lengthInMins < m2.lengthInMins;
}

int main() {
   int movieListSize;
   cin >> movieListSize;

   Movie *movieList = new Movie[movieListSize];

   // Input
    for (int i = 0; i < movieListSize; i++) {
        cout << "Please provide details of Movie #" << (i+1) << endl << endl;
        cout << "Title: ";
        getline(cin.ignore(), movieList[i].movieTitle);

        cout << "Rating (0-5): ";
        cin >> movieList[i].rating;

        cout << "Length (mins): ";
        cin >> movieList[i].lengthInMins;
        
        cout << endl;
    }

    short sortFilter;

    cout << "Sort on basis of -" << endl;
    cout << "1.Rating\n2.Length" << endl;
    cout << "(Enter choice): ";
    cin >> sortFilter;

    switch (sortFilter) {
    case 1:
        sort(movieList, movieList+movieListSize, compareRating);
        break;
    case 2:
        sort(movieList, movieList+movieListSize, compareLength);
        break;
    default:
        break;
    }

    for (int i = 0; i < movieListSize; i++) {
        cout << (i+1) << ". ";

        cout << movieList[i].movieTitle << " ";
        cout << "Rating: " << movieList[i].rating << " " ;
        cout << "Length: " << movieList[i].lengthInMins ;

        cout << endl;
    }
    return 0;
}