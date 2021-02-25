class Country
{ 
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
private:
    string name;
    static vector<Election> electionList;
    vector<Citizen> citizenList;
public:
    Citizen findCitizenByUniqueId(string voterId)
    {
        for (unsigned long long i = 0; i < citizenList.size(); i++)
        {
            if (citizenList[i].getVoterId() == voterId)
            {
                return citizenList[i];
            }
        }

        return Citizen();
    }

    Citizen findCitizenByVoterId(string uniqueId)
    {
        for (unsigned long long i = 0; i < citizenList.size(); i++)
        {
            if (citizenList[i].getUniqueId() == uniqueId)
            {
                return citizenList[i];
            }
        }

        return Citizen();
    }
    static void newElection(Election election)
    {
        electionList.push_back(election);
    }
    Country(string, vector <Citizen>);

    ~Country();
};

vector<Election> Country::electionList;

Country::Country(string name, vector <Citizen> citizenList)
{
    this->name = name;
    this->citizenList = citizenList;
}

Country::~Country() {};

