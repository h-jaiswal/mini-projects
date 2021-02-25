class Person
{
private:
    string name;
    short age;
protected:
    Person()
    {
        name = "NOT SET";
        age = -1;
    }
    Person(string, short);

    ~Person();
};

Person::Person(string name, short age)
    {
        this->name = name;
        this->age = age;
    }

Person::~Person() {};