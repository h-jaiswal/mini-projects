#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#include "Person.cpp"
#include "Voter.cpp"
#include "Citizen.cpp"
#include "Booth.cpp"
class Country;
class Election;
#include "Election.cpp"
#include "Country.cpp"

Country createCountry();
Election createElection(Country);
Booth createBooth(Country);

void hashLine() { cout << "######################################################" << endl; }

int main()
{   
    
    cout << "Register Country Data: " << endl;
    const Country country = createCountry();
    hashLine();

    cout << endl;
    
    hashLine();
    cout << "Register Election Data: " << endl;
    const Election election = createElection(country);
    hashLine();

    cout << endl;
    country.newElection(election);

    // Now to add a vote in a booth -> citizen must provide voter id -> if corresponding citizen is in booth voter list then vote caste at the booth else not 
}

Country createCountry()
{
    string name;
    unsigned long long citizenCount;

    cout << "Enter country name: ";
    cin >> name;
    
    cout << "Enter number of citizens: ";
    cin >> citizenCount;

    vector<Citizen> citizenList;

    hashLine();
    cout << "Enter Citizen Data: " << endl;

    for (unsigned long long i = 0; i < citizenCount; i++)
    {
        string uniqueId;
        string name;
        short age = 0;

        cout << "Enter details of citizen #" << (i+1) << endl;

        cout << "Enter Unique Id: ";
        getline( cin.ignore(), uniqueId);

        cout << "Enter name: ";
        getline( cin.ignore(), name);

        cout << "Enter age: ";
        cin >> age;

        if ( age >= 18)
        {   
            cout << "Enter Electoral Details: " << endl;

            string voterId;
            string pollingBoothId = "NOT SET";

            cout << "Enter VoterId: ";
            getline( cin.ignore(), voterId);

            citizenList.push_back( Citizen(uniqueId, name, age, voterId, pollingBoothId) );
        }
        else
        {
            citizenList.push_back( Citizen(uniqueId, name, age) );
        }

        cout << endl;
    }
    hashLine();
    return Country(name, citizenList);
}

Booth createBooth(Country country)
{
    string boothId;
    vector<BoothVoter> boothVoterList;

    unsigned long long voterCount = 0;

    cout << "Enter Booth Id: ";
    getline( cin.ignore(), boothId);

    cout << "Enter number of Voter in Booth Number #" << boothId << endl;
    cin >> voterCount;

    for (unsigned long long i = 0; i < voterCount; i++)
    {
        string uniqueId;

        cout << "Enter details of voter #" << (i+1) << endl;
        cout << "Unique ID: ";
        getline( cin.ignore(), uniqueId);

        Citizen citizen = country.findCitizenByUniqueId(uniqueId); // Find coressponding citizen in the country

        if ( citizen.getUniqueId() == "NOT SET")
        {
            cout << "Invalid Unique Id. Continue for next citizen." << endl;
            continue;
        }
        BoothVoter boothVoter;
        boothVoter.citizen = citizen;
        boothVoter.hasVoted = false;

        boothVoterList.push_back(boothVoter);
    }
    
    return Booth( boothId, boothVoterList);
}


Election createElection(Country country)
{
    string electionId;

    unsigned long long boothCount = 0;
    vector<Booth> boothList;

    cout << "Enter Election Id: ";
    getline( cin.ignore(), electionId );

    cout << "Enter number of Polling Booths: ";
    cin >> boothCount;

    hashLine();
    cout << "Enter Booth Data: " << endl;
    for (unsigned long long i = 0; i < boothCount; i++)
    {
        cout << "Booth #" << (i+1) << endl;
        cout << endl;

        Booth booth = createBooth(country);

        boothList.push_back(booth);

        cout << endl;
    }
    hashLine();
    
    Election election( electionId, boothList);

    return election;
}

