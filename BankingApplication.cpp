#include "BankingApplication.h"

int Client::number_client = 0;

void BankApplication::run() {
    ifstream file;
    file.open("Bank_Clients.txt");
    string name, id, pass, phone, address, kind_bank;
    double balance;
    string str;
    while (getline(file, str)) {
        stringstream s(str);
        string temp;
        s >> temp;
        name += temp;
        s >> temp;
        name += temp;
        s >> temp;
        name += temp;
        s >> temp;
        pass = temp;
        s >> temp;
        id += temp;
        s >> temp;
        phone += temp;
        s >> temp;
        balance = stod(temp);
        s >> temp;
        kind_bank = temp;
        while (s >> temp) {
            address += temp + " ";
        }
        password.emplace(pass);
        address.pop_back();
        BankAccount *bank = nullptr;
        auto *client = new Client(name, phone, id, address, pass);
        if (kind_bank == "Saving") {
            bank = new SavingsBankAccount(balance);
        } else {
            bank = new BankAccount(balance);
        }
        client->set_bank(bank);
        bank->set_client(client);
        clients.push_back(client);
        ++Client::number_client;
    }

    int choice;
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
                Withdraw();
                break;
            case 4:
                Deposit();
                break;
            case 5:
                return;
            default:
                cout << "invalid choice\n";
        }
    }
}

bool BankApplication::valid_name(const string &name) {
    regex ch("[a-zA-Z]* [a-zA-Z]* [a-zA-Z]*");
    return regex_match(name, ch);
}

bool BankApplication::valid_phone(const string &phone) {
    regex ch("(01)(0|1|2|5)[0-9]{8}");
    return regex_match(phone, ch);
}

bool BankApplication::valid_password(const string &pass) {
    regex ch("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[^a-zA-Z0-9])[\\S]{8,}$");
    int val = (int) regex_match(pass, ch);
    if (!val) {
        cout << "enter valid password\n";
        return false;
    }
    if (password.find(pass) != password.end()) {
        cout << "used password enter other password\n";
        return false;
    }
    return true;
}

bool BankApplication::add_client() {
    string name, id, pass, phone, address;
    double balance;

    cout << "Triple enter your name: ";
    getline(cin >> ws, name);
    while (!valid_name(name)) {
        cout << "enter valid name\n";
        getline(cin >> ws, name);
    }

    cout << "Enter your phone: ";
    getline(cin >> ws, phone);

    while (!valid_phone(phone)) {
        cout << "enter valid phone\n";
        getline(cin >> ws, phone);
    }

    cout << "Enter your address: ";
    getline(cin >> ws, address);

    cout << "Enter your password contain upper and lower letter and number and punctuation: ";
    getline(cin >> ws, pass);

    while (!valid_password(pass)) {

        getline(cin >> ws, pass);
    }

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

    auto *client = new Client(name, phone, id, address, pass);

    client->set_bank(bank);
    bank->set_client(client);
    password.emplace(pass);

    fstream file;
    file.open("Bank_Clients.txt", ios::app);
    string add;
    add += name;
    add += " ";
    add += pass;
    add += " ";
    add += id;
    add += " ";
    add += phone;
    add += " ";
    add += to_string(balance);
    add += " ";
    if (choice == 1) {
        add += "Basic ";
    } else add += "Saving ";
    add += address;
    add += '\n';
    file << add;
    client->info();
    clients.push_back(client);
    client = nullptr;
    bank = nullptr;
    return true;
}

void BankApplication::Withdraw() {
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
    if (!~ind) {
        cout << "incorrect id\n";
        return;
    }
    string pass;
    cout << "enter the password : ";
    for (int i = 0; i < 4; ++i) {
        cin >> pass;
        if (pass != clients[ind]->get_password()) {
            cout << "incorrect password\n";
        } else break;
        if (i == 3) {
            return;
        }
    }
    int amount;
    cout << "Enter the amount your want withdraw it: ";
    cin >> amount;
    if (clients[ind]->get_bank().Withdraw(amount)) {
        cout << "The withdraw successfully\n";
        clients[ind]->info();
        return;
    }
    cout << "The Withdraw fail\n";
}

void BankApplication::Deposit() {
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
    if (!~ind) {
        cout << "incorrect id\n";
        return;
    }
    string pass;
    cout << "enter the password : ";
    for (int i = 0; i < 4; ++i) {
        cin >> pass;
        if (pass != clients[ind]->get_password()) {
            cout << "incorrect password\n";
        } else break;
        if (i == 3) {
            return;
        }
    }
    int amount;
    cout << "Enter the amount your want Deposit it: ";
    cin >> amount;
    if (clients[ind]->get_bank().Deposit(amount)) {
        cout << "The Deposit successfully\n";
        clients[ind]->info();
        return;
    }
    cout << "The Deposit fail\n";
}
