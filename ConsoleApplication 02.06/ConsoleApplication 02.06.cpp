#include <iostream>
#include <map>
class Client
{
private:
    int _id;
    std::string _name;
    float _bill;
 public:
     Client(int id, std::string name, float bill, std::map<int, Client*>&map) : _id(id), _name(name), _bill(bill)
    {
         map[_id] = this;
    }
    Client(Client& client)
    {
        _id = client._id;
        _name = client._name;
        _bill = client._bill;

    }

    void ShowData()
    {
        std::cout << "Id: " << _id << '\n';
        std::cout << "Name" << _name << '\n';
        std::cout << "Bill" << _bill << '\n';
    }


   /* void Foo ()
    {
        this->_id;
    }*/

};



int main()
{
    setlocale(LC_ALL, "Russian");
    std::map<int, Client*>clients;
    Client* client = new Client(12, "john", 987987.5f, clients);
    Client* client2 = new Client(56, "Alex", 987987.5f, clients);
    Client* client3 = new Client(33, "Monika", 987987.5f, clients);
   
    auto it = clients.begin();

    for (; it != clients.end(); ++it)
    {
        std::cout << "client id - " << it->first << "  :\n";
        it->second->ShowData();
        std::cout << "\n\n";

    }
    //client->Foo();
}

