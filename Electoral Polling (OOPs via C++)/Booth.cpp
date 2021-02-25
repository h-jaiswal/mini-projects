class Citizen;

struct BoothVoter
{
    Citizen citizen; // List of eligible voter's for that booth
    bool hasVoted;
};

class Booth
{
private:
    string boothId;     // ID of polling booth where the Booth is placed in a particular election
    vector<BoothVoter> boothVoterList;

public:

    int addVote(Citizen citizen);

    string getBoothId()
    {
        return boothId;
    }

    Booth() {};
    
    Booth(string boothId, vector<BoothVoter> boothVoterList)
    {
        this->boothId = boothId;
        this->boothVoterList = boothVoterList;
    }
    
    ~Booth();
};

int Booth::addVote(Citizen citizen)
{
    // find citizen in booth voter list
    for (unsigned long long i = 0; i < boothVoterList.size(); i++)
    {
        if ( boothVoterList[i].citizen.getVoterId() == citizen.getVoterId() )
        {
           if (! boothVoterList[i].hasVoted)
           {
               boothVoterList[i].hasVoted = ! boothVoterList[i].hasVoted;
               return 0; // SUCCESS
           }
        }
    }
    return 1; // FAIL
}

Booth::~Booth() {};