class Citizen : private Person, public Voter
{
private:
    static unsigned long long citizenCount;
    string uniqueId;
public:

    string getUniqueId()
    {
        return uniqueId;
    }
    Citizen()
    {
        uniqueId = "NOT SET";
    }
    Citizen(string, string, short);
    Citizen(string, string, short, string, string);
    ~Citizen();
};

unsigned long long Citizen::citizenCount = 0;


Citizen::Citizen(string uniqueId, string name, short age) : Person(name, age), Voter()
{
    citizenCount++;
    this->uniqueId = uniqueId;
}

Citizen::Citizen(string uniqueId, string name, short age, string voterId, string pollingBoothId) : Person(name, age), Voter(voterId, pollingBoothId)
{
    citizenCount++;
    this->uniqueId = uniqueId;
}

Citizen::~Citizen() { citizenCount--; };

