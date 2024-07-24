#include <iostream>
#include <string.h>
#include <list>
#include <ctime>

class todoItem
{
private:
    int id;
    std::string description;
    bool completed;

public:
    todoItem() : id(0), description(""), completed(false) {}
    ~todoItem() = default;

    bool crate(std::string new_description)
    {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }
    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }
};

int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.2.0";
    std::list<todoItem> todoItmes;
    std::list<todoItem>::iterator it;

    srand(time(NULL));

    todoItmes.clear();

    while (1)
    {
        system("cls");
        std::cout << "TODO LIST MAKER- " << version << std::endl;
        std::cout << std::endl
                  << std::endl;

        for (it = todoItmes.begin(); it != todoItmes.end(); it++)
        {

            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " |  " << it->getDescription() << " | "
                      << completed << std::endl;
        }
        if (todoItmes.empty())
        {
            std::cout << "[A]DD YOUR FIRST TODO" << std::endl;
        }
        std::cout << std::endl
                  << std::endl;

        std::cout << "[A]DD YOUR FIRST TODO" << std::endl;
        std::cout << "[C]OMPLETE A TODO" << std::endl;
        std::cout << "[Q]UIT" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'Q')
        {
            std::cout << "HAVE A GREAT DAY!!!" << std::endl;
            break;
        }
        else if (input_option == 'A')
        {
            std::cout << "ADD A NEW DESCRIPTION : ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            todoItem newItem;
            newItem.crate(input_description);
            todoItmes.push_back(newItem);
        }
        else if (input_option == 'C')
        {
            std::cout << "ENTER ID TO MARK COMPLETED : " << std::endl;
            std::cin >> input_id;

            for (it = todoItmes.begin(); it != todoItmes.end(); it++)
            {
                if (input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }
}