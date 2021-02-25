
class Voter
{
private:
    string voterId;  
    string pollingBoothId;

protected:
    static unsigned long long totalVoterCount;
    static unsigned long long unidentifiedVoterCount;

protected:

    Voter()
    {
        totalVoterCount++;
        unidentifiedVoterCount++;

        voterId = "NOT SET";
        pollingBoothId = "NOT SET";
    }
    Voter(string voterId, string pollingBoothId)
    {
        totalVoterCount++;

        this->voterId = voterId;
        this->pollingBoothId = pollingBoothId;
    }

    

    void setVoterId(string voterId)
    {
        this->voterId = voterId;
    }

    ~Voter();

public:
    string getVoterId()
    {
        return voterId;
    }
};

unsigned long long Voter::totalVoterCount = 0;
unsigned long long Voter::unidentifiedVoterCount = 0;

Voter::~Voter() { totalVoterCount--; };
