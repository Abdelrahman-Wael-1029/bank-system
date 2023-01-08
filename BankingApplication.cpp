#include "BankingApplication.h"

int Client::number_client = 0;

void BankApplication::run() {
    int choice;
    string id;
    while (true) {

        cout << "1. Create a New Account\n"
                "2. List Clients and Accounts\n"
                "3. Withdraw Money\n"
                "4. Deposit Money\n"
                "5-Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                if (add_client()) {
                    cout << "The account has been created successfully\n";
                } else {
                    cout << "The account has been created fail\n";
                }
                break;
            case 2:
                for (auto i: clients) {
                    i->info();
                }
                break;
            case 3:
                if (Withdraw()) {
                    cout << "The withdraw successfully\n";
                } else {
                    cout << "The Withdraw fail\n";
                }
                break;
            case 4:
                if (Deposit()) {
                    cout << "The Deposit successfully\n";
                } else {
                    cout << "The Deposit fail\n";
                }
                break;
            case 5:
                return;
            default:
                cout << "invalid choice\n";
        }
    }
}

bool BankApplication::add_client() {
    string name, id, password, phone, address;
    double balance;

    cout << "Enter your name: ";
    getline(cin >> ws, name);

    cout << "Enter your phone: ";
    getline(cin >> ws, phone);

    cout << "Enter your address: ";
    getline(cin >> ws, address);

    cout << "Enter your password: ";
    getline(cin >> ws, password);

    cout << "Enter your money: ";
    cin >> balance;

    id = "FCAI-" + to_string(Client::number_client++);

    BankAccount *bank = nullptr;
    int choice;
    cout << "1-basic account\n"
            "2-saving account\n";
    cin >> choice;
    while (choice != 1 && choice != 2) {
        cout << "invalid choice\n";
        cin >> choice;
    }
    if (choice == 1) {
        bank = new BankAccount(balance);
    } else {
        if (balance < (double) 1000) {
            return false;
        }
        bank = new SavingsBankAccount(balance);
    }

    Client *client = new Client(name, phone, id, address, password);

    client->set_bank(bank);
    bank->set_client(client);

    client->info();
    clients.push_back(client);
    client = nullptr;
    bank = nullptr;
    return true;


}

bool BankApplication::Withdraw() {
    int ind = -1;
    string id;
    cout << "enter your id: ";
    cin >> id;
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i]->get_id() == id) {
            ind = i;
            break;
        }
    }
    int amount;
    cout << "Enter the amount your want withdraw it: ";
    cin >> amount;
    if (clients[ind]->get_bank().Withdraw(amount)){
        clients[ind]->info();
        return true;
    }
    return false;
}

bool BankApplication::Deposit() {
    int ind = -1;
    string id;
    cout << "enter your id: ";
    cin >> id;
    for (int i = 0; i < clients.size(); ++i) {
        if (clients[i]->get_id() == id) {
            ind = i;
            break;
        }
    }
    int amount;
    cout << "Enter the amount your want Deposit it: ";
    cin >> amount;
    if (clients[ind]->get_bank().Deposit(amount)){
        clients[ind]->info();
        return true;
    }

    return false;
}
