class Election
{
private:
    static string countryName;
    string electionId;
    vector<Booth> boothList;
    int isActive; // 0 means active and 1 means not active

public:
    int getIsActive()
    {
        return isActive;
    }
    Booth findBooth(string pollingBoothId)
    {
        for (unsigned long long i = 0; i < boothList.size(); i++)
        {
            if (boothList[i].getBoothId() == pollingBoothId)
            {
                return boothList[i];
            }
        }

        return Booth();
    }
    vector<Booth> getBoothList()
    {
        return boothList;
    }

    Election(string electionId, vector<Booth> boothList);
    ~Election();

};

Election::Election(string electionId, vector<Booth> boothList)
{
    this->electionId = electionId;
    this->boothList = boothList;
    this->isActive = 0;
}

Election::~Election() {};
