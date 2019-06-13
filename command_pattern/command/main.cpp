#include <iostream>
#include <vector>

using namespace std;

struct BankAccount {
    int balance {0};
    void deposit(int amount) {
        balance += amount;
        cout << "bank deposit " << amount << " and balance is " << balance << endl;
    }
    void withdraw(int amount) {
        balance -= amount;
        cout << "bank withdraw " << amount << " and balance is " << balance << endl;
    }
};

struct Command {
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

struct BankAccountDepositCommand : Command {
    BankAccountDepositCommand(BankAccount& account, int amount):
        account_(account), amount_(amount){}
    void execute() {
        account_.deposit(amount_);
    }
    void undo() {
        account_.withdraw(amount_);
    }
private:
    BankAccount& account_;
    int amount_;
};

struct BankAccountWithdrawCommand : Command {
    BankAccountWithdrawCommand(BankAccount& account, int amount):
        account_(account), amount_(amount){}
    void execute() {
        account_.withdraw(amount_);
    }
    void undo() {
        account_.deposit(amount_);
    }
private:
    BankAccount& account_;
    int amount_;
};

struct MultiCommand : Command {
    MultiCommand(vector<Command*> commands):commands_(commands) {}
    void execute() {
        for(auto command : commands_) {
            command->execute();
        }
    }
    void undo() {
        for(auto command : commands_) {
            command->undo();
        }
    }
private:
    vector<Command*> commands_;
};

int main()
{
    BankAccount account;
    BankAccountDepositCommand deposit_command(account, 100);
    BankAccountWithdrawCommand withdraw_command(account, 200);

//example 1
//    deposit_command.execute();
//    deposit_command.undo();
//    deposit_command.execute();
//    deposit_command.undo();
//    withdraw_command.execute();
//    withdraw_command.undo();

//example 2
//    vector<Command*> commands {&deposit_command, &withdraw_command, &deposit_command};
//    MultiCommand multi_commands {commands};
//    multi_commands.execute();
//    multi_commands.undo();

    cout << account.balance << endl;
    return 0;
}
