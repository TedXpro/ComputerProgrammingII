/*      Name                ID
1. Newal Yeman          UGR/9108/14
2. Yigerem Bisrat       UGR/5026/14
3. Yodahe Gossa         UGR/9595/14
4. Yoak Moges           UGR/3567/14
5. Yohannes Belay       UGR/4223/14
*/
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;

const char DELIMITTER = ',';
enum Transaction
{
    DEPOSIT,
    WITHDRAW,
    TRANSFER
};
enum UserType
{
    ADMIN,
    USER
};

// functions for admin();
void admin();
void addUser();
void deleteUser();
void deleteLines();
void viewAllUser();
// functions for user();
void user();
string readCurrentTime();
bool checkUser(string, string[]);
void writeTransactionFile(string, Transaction, int);
// bool login(int);
void deposit(string, int, bool flag = false);
void withdraw(string);
bool checkAmount(string, int);
void debitMoney(string, int);
void transfer(string);
void viewAccount(string);
vector<string> split(string, char DELIMITTER);

int main()
{
    int choice; // holds the choice the user enters.
    do
    {
        // Creating menus:
        cout << "\tWelcome to our ATM.\n";
        cout << "Select respective numbers to Login as:\n";
        cout << "1. Admin\n";
        cout << "2. User\n";
        cout << "3. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // check if its a valid input.
        while (choice > 3 || choice < 1)
        {
            cout << "your choice MUST be between 1 - 3.\n";
            cout << "Please enter the right choice: ";
            cin >> choice;
        }

        // Admin Menu.
        if (choice == 1)
            admin();
        else if (choice == 2)
            user();
    } while (choice != 3);
    cout << "Thank you for banking with us.\n";
    cout << "------------------------------\n";
    return 0;
}

/**
 * This function is responsible for Admin Menu.
 */
void admin()
{
    const int PASSWORD = 1234;
    int pass;        // pass holds the password for the admin
    int adminChoice; // holds the choice the admin enters from the admin menu.
    cout << "Enter the Password: ";
    cin >> pass;

    // ifstream readData("userFile.txt");
    // // int num
    int counter = 1;
    while (pass != PASSWORD)
    {
        if (counter >= 3)
        {
            cout << "You have entered the maximum number of times!\n";
            cout << "Thank You for using Our ATM\n";
            return;
        }
        cout << "The password you entered is not correct!\n";
        cout << "Attempt " << counter << "/3\n";
        counter++;
        cout << "Please try again: ";
        cin >> pass;
    }
    do
    {
        cout << "\n\tWelcome to Admin Menu\n";
        cout << "1. Add user\n";
        cout << "2. Delete User\n";
        cout << "3. View All user\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> adminChoice;

        // check for valid input.
        while (adminChoice > 4 || adminChoice < 1)
        {
            cout << "Your choice must be between 1 - 4\n";
            cout << "Enter your choice: ";
            cin >> adminChoice;
        }

        if (adminChoice == 1)
            addUser();
        else if (adminChoice == 2)
            deleteUser();
        else if (adminChoice == 3)
            viewAllUser();

    } while (adminChoice != 4);
}

/**
 * This function will add users to the files user and account
 *
 */
void addUser()
{
    UserType user = USER;
    string firstName, fathersName, line;
    int password, balance;
    char ch;

    cout << "Enter the firstName: ";
    cin >> firstName;
    cout << "Enter fahters Name: ";
    cin >> fathersName;
    cout << "Enter Sex M/f: ";
    cin >> ch;

    while (ch != 'M' && ch != 'm' && ch != 'f' && ch != 'F')
    {
        cout << "Please enter either M/F for male or female respectively: ";
        cin >> ch;
    }

    if (ch == 'f' || ch == 'F')
        ch = 'F';
    else
        ch = 'M';

    ifstream readData("userFile.txt");
    int accNum = 9999; // cross check if there is already a line in the user file.
    vector<string> v;
    while (getline(readData, line))
    {
        v = split(line, DELIMITTER);
        accNum = stoi(v[1]);
    }
    accNum += 1;
    readData.close();
    cout << "Enter Password: ";
    cin >> password;

    while (password < 1000 || password > 9999)
    {
        cout << "Invalid PIN lenght. It must have 4 characters.\n";
        cout << "Enter Password: ";
        cin >> password;
    }

    cout << "Enter initial Balance starting from 50$: ";
    cin >> balance;

    while (balance < 50)
    {
        cout << "The initial balance must start form 50\n";
        cout << "Please Enter another amount: ";
        cin >> balance;
    }

    ofstream writeUserData("userFile.txt", ios::app);
    writeUserData << user << "," << accNum << "," << firstName << "," << fathersName << "," << password << "," << ch << endl;

    writeUserData.close();

    ofstream writeAccData("accountFile.txt", ios::app);
    writeAccData << accNum << "," << balance << endl;
    writeAccData.close();
}

/**
 * This function will delete users from the files; userfiles
 * account files.
 *
 */
void deleteUser()
{
    string accNum, name[4];

    string line;
    vector<string> v;
    cout << "Enter the account number to be deleted: ";
    cin >> accNum;

    if (checkUser(accNum, name))
    {

        ifstream readUserData("userFile.txt");       // to read data from the user file.
        ofstream writeTempData("temporaryFile.txt"); // to write data on the temporary file.

        while (getline(readUserData, line))
        {
            v = split(line, DELIMITTER);
            if (v[1] == accNum)
            {
                string ch;
                cout << "Are you sure you want to delete Account ";
                cout << "Number " << accNum << "?\n";
                cout << "Press Q/q to return to main menu or any other key to continue: ";
                cin >> ch;
                if (ch == "Q" || ch == "q")
                    return;
                continue;
            }
            writeTempData << line << endl;
        }

        readUserData.close();
        writeTempData.close();

        ifstream readTempData("temporaryFile.txt");
        ofstream writeUserData("userFile.txt");

        while (getline(readTempData, line))
        {
            writeUserData << line << endl;
        }

        readTempData.close();
        writeUserData.close();

        //  deleting data from the account file.
        ifstream readAccFile("accountFile.txt"); // to read data from the account file.
        ofstream writeTData("temporaryFile.txt");

        while (getline(readAccFile, line))
        {
            v = split(line, DELIMITTER);
            if (v[0] == accNum)
            {
                continue;
            }
            writeTData << line << endl;
        }

        readAccFile.close();
        writeTData.close();

        ifstream readTData("temporaryFile.txt");
        ofstream writeAccFile("accountFile.txt");

        while (getline(readTData, line))
            writeAccFile << line << endl;

        readTData.close();
        writeAccFile.close();

        cout << "\nAccount number " << accNum << " has successfully been deleted!\n";
        cout << "------------------------------------------------------\n";
    }
    else
        cout << "\nAccount number doesnt exist!\n";
}

/**
 * This function will display all the user info
 * requested by the admin.
 */
void viewAllUser()
{
    vector<string> v;
    string info;
    ifstream readData("userFile.txt");
    cout << "\nThe Users are:\n";
    cout << "AccNum  FirstName  FathersName  Sex\n";
    while (getline(readData, info))
    {
        v = split(info, DELIMITTER);
        cout << v[1] << "\t" << v[2] << "    " << v[3] << "\t" << v[5] << endl;
    }
    cout << "------------------------------------------\n";
    char ch;
    cout << "\nPress any key to continue: ";
    cin >> ch;
}

/**
 * This function is for user menu.
 */
void user()
{
    int controller = 0;

    string name[4], line, accNum, pass;
    vector<string> v;

    cout << "Enter your account number: ";
    cin >> accNum;

    if (!checkUser(accNum, name))
    {
        cout << "The account " << accNum << " doesn't exist!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> pass;

    while (pass != name[1])
    {
        cout << "Invalid Password\nPleas try again!\n";
        cout << "Enter password: ";
        cin >> pass;
    }

    int choice;
    if (name[3] == "M") // Greet User.
        cout << "\nWelcome Mr. " << name[0] << endl;
    else
        cout << "\nWelcome Mrs. " << name[0] << endl;
    do
    {
        cout << "\nWelcome to User Menu\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. View Account\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (choice >= 6 || choice <= 0)
        {
            cout << "Please enter between 1 - 6: ";
            cin >> choice;
        }

        if (choice == 1)
        {
            int money;
            cout << "Enter the amount of money to be deposited to your account: ";
            cin >> money;
            deposit(accNum, money);
        }
        else if (choice == 2)
            withdraw(accNum);
        else if (choice == 3)
            transfer(accNum);
        else if (choice == 4)
            viewAccount(accNum);
    } while (choice != 5);
}

/**
 * This function will check if the user if in the user file.
 *
 * @param accNo holds the account number to be checked.
 * @param name holds empty array that will hold the name of the user.
 *
 * @return true if the user is in the userFile.
 */
bool checkUser(string accNo, string name[])
{
    string line;
    vector<string> v;
    ifstream readUserFile("userFile.txt");

    while (getline(readUserFile, line))
    {
        v = split(line, DELIMITTER);
        if (v[1] == accNo)
        {
            name[0] = v[2]; // to hold the first name.
            name[1] = v[4]; // to hold the password.
            name[2] = v[3]; // to hold the fathers name;
            name[3] = v[5]; // to hold the sex of the user.
            return true;
        }
    }
    return false;
}

/**
 * This function will read the current time.
 *
 * @return the current time.
 */
string readCurrentTime()
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    return ctime(&currentTime);
}

/**
 * This function will write all the transacton details to
 * the transaction file.
 *
 * @param accNo holds the account number.
 * @param trans holds the enum type.
 * @param amount holds the amount of money transacted.
 */
void writeTransactionFile(string accNo, Transaction trans, int amount)
{
    ofstream writeData("transaction.txt", ios::app);

    string time = readCurrentTime();
    string transType;
    if (trans == 0)
        transType = "Deposit";
    else if (trans == 1)
        transType = "Withdraw";
    else
        transType = "Transfer";
    writeData << "Transaction Type: " << transType << ", Account Number: " << accNo << ", Amount: " << amount << ", Time: " << time << endl;
    writeData.close();
}

/**
 * This function will handle money deposit to a user account.
 *
 * @param accNo holds the account of the user.
 * @param amount holds the amount of money to be deposited.
 */
void deposit(string accNo, int amount, bool flag)
{
    int num;
    string line, str;
    vector<string> v;
    ifstream readAccFile("accountFile.txt");
    ofstream writeTempFile("temporaryFile.txt");

    while (getline(readAccFile, line))
    {
        v = split(line, DELIMITTER);

        if (v[0] == accNo)
        {
            num = stoi(v[1]);
            num += amount;
            str = to_string(num);
            v[1] = str;
            writeTempFile << v[0] << "," << v[1] << endl;
            continue;
        }
        writeTempFile << line << endl;
    }

    readAccFile.close();
    writeTempFile.close();

    Transaction trans = DEPOSIT;
    writeTransactionFile(accNo, trans, amount);

    ifstream readTempFile("temporaryFile.txt");
    ofstream writeAccFile("accountFile.txt");

    while (getline(readTempFile, line))
    {
        v = split(line, DELIMITTER);

        if (v[0] == accNo)
        {
            if (flag == 0)
            {
                cout << "The money has been deposited successfully.\n";
                cout << "Your current balance is " << v[1] << endl;
            }
        }
        writeAccFile << line << endl;
    }
    char ch;
    cout << "Press any key to continue: ";
    cin >> ch;
    readTempFile.close();
    writeAccFile.close();
}

/**
 * This function will handle Money withdrawal from user account.
 *
 * @param accNo holds the account number of the user.
 */
void withdraw(string accNo)
{
    int amount, choice;
    cout << "Choose Amount\n";
    cout << "1. 100\n";
    cout << "2. 300\n";
    cout << "3. 500\n";
    cout << "4. 1000\n";
    cout << "5. 5000\n";
    cout << "6. Other Amount\n";
    cout << "7. Cancel Withdrawal\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice > 7 || choice < 1)
    {
        cout << "The choice must be between 1 - 6\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        amount = 100;
        if (checkAmount(accNo, amount))
            debitMoney(accNo, amount);
        else
        {
            cout << "The amount of money in your bank acocunt is not sufficient.\n";
            withdraw(accNo);
        }
    }
    else if (choice == 2)
    {
        amount = 300;
        if (checkAmount(accNo, amount))
            debitMoney(accNo, amount);
        else
        {
            cout << "The amount of money in your bank acocunt is not sufficient.\n";
            withdraw(accNo);
        }
    }
    else if (choice == 3)
    {
        amount = 500;
        if (checkAmount(accNo, amount))
            debitMoney(accNo, amount);
        else
        {
            cout << "The amount of money in your bank acocunt is not sufficient.\n";
            withdraw(accNo);
        }
    }
    else if (choice == 4)
    {
        amount = 1000;
        if (checkAmount(accNo, amount))
            debitMoney(accNo, amount);
        else
        {
            cout << "The amount of money in your bank acocunt is not sufficient.\n";
            withdraw(accNo);
        }
    }
    else if (choice == 5)
    {
        amount = 5000;
        if (checkAmount(accNo, amount))
            debitMoney(accNo, amount);
        else
        {
            cout << "The amount of money in your bank acocunt is not sufficient.\n";
            withdraw(accNo);
        }
    }
    else if (choice == 6)
    {
        cout << "Enter the amount of money to be debited from your account: ";
        cin >> amount;

        if (checkAmount(accNo, amount))
            debitMoney(accNo, amount);
        else
        {
            cout << "\nThe amount of money in your bank acocunt is not sufficient.\n";
            cout << "Please try again!\n";
            withdraw(accNo);
        }
    }
    else
        return;
    char ch;
    cout << "Enter any key to continue: ";
    cin >> ch;
}

/**
 * This function will check if the user has enough amount of
 * money in the bank account to ne debitted.
 *
 * @param accNo holds the account number of the user.
 * @param amount holds the amount of money to be checked.
 *
 * @return true if the user has enough amount of money in the bankacocunt.
 */
bool checkAmount(string accNo, int amount)
{
    vector<string> v;
    string line;
    int num;

    ifstream readAccFile("accountFile.txt");
    while (getline(readAccFile, line))
    {
        v = split(line, DELIMITTER);
        if (v[0] == accNo)
        {
            num = stoi(v[1]);
            if ((num - 50) >= amount)
                return true; // The user has enough amount of money.
            else
                return false; // The user doesn't have enough amount of money.
        }
    }
    return false;
}

/**
 * This function will debit a given amount of money from the user.
 *
 * @param accNo holds the account number of the user.
 * @param amount holds the amount of money to be debited from the user.
 */
void debitMoney(string accNo, int amount)
{
    string line;
    int num;
    vector<string> v;

    ifstream readAccFile("accountFile.txt");
    ofstream writeTempFile("temporaryFile.txt");

    while (getline(readAccFile, line))
    {
        v = split(line, DELIMITTER);
        if (v[0] == accNo)
        {
            num = stoi(v[1]);
            num -= amount;

            cout << "\n"
                 << amount << "\nBirr has succesfull been debited from your account.\n";
            cout << "The amount of money left in your bank account is " << num << endl;

            v[1] = to_string(num);
            writeTempFile << v[0] << "," << v[1] << endl;
            continue;
        }
        writeTempFile << line << endl;
    }
    readAccFile.close();
    writeTempFile.close();

    Transaction trans = WITHDRAW;
    writeTransactionFile(accNo, trans, amount);

    ifstream readTempFile("temporaryFile.txt");
    ofstream writeAccFile("accountFile.txt");

    while (getline(readTempFile, line))
    {
        writeAccFile << line << endl;
    }
    readTempFile.close();
    writeAccFile.close();
}

/**
 * This function will handle the money Transaction between two accounts.
 *
 * @param senderAccount holds the account number of the sender.
 */
void transfer(string senderAccount)
{
    string name[4], recieverAccount;
    int money;
    char ch;
    do
    {
        cout << "Enter the account number of the reciever: ";
        cin >> recieverAccount;

        if (recieverAccount == senderAccount)
        {
            cout << "\nYou have entered your own account!\n";
            cout << "Please try again.\n";
            cout << "-------------------------------------";
            return;
        }

        while (!checkUser(recieverAccount, name))
        {
            cout << "The account doesnt exist!\n";
            cout << "Would you like to return to User Menu?\n";
            cout << "Press 'q/Q' to return to user menu or anyother key to continue: ";
            cin >> ch;
            if (ch == 'q' || ch == 'Q')
                return;
            cout << "Enter the account number of the reciever: ";
            cin >> recieverAccount;
        }

        cout << "Enter the Amount of money to be transfered to " << name[0] << ": ";
        cin >> money;

        while (!checkAmount(senderAccount, money))
        {
            cout << "The amount of money in your bank account doesnt allow ";
            cout << "you to transfer " << money << endl;
            cout << "Please try again!\n";

            cout << "Enter the Amount of money to be transfered to " << name[0] << ": ";
            cin >> money;
        }

        cout << "\nReciever name: " << name[0] << " " << name[2] << endl;
        cout << "Reciever account: " << recieverAccount << endl;
        cout << "Amount of Money: " << money << " Birr\n";
        cout << "Would you like to continue (Y/n): ";
        cin >> ch;

        if (ch == 'N' || ch == 'n')
        {
            cout << "Would you like to return to user menu Y/n: ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
                return;
        }
    } while (ch == 'N' || ch == 'n');

    cout << "\nTransfer Successful!";
    debitMoney(senderAccount, money); // to debit from the sender account.
    deposit(recieverAccount, money, true);
    cout << "-----------------------------------------------------\n";
}

/**
 * This function will view the account.
 *
 * @param accNo holds the account number of the user.
 */
void viewAccount(string accNo)
{
    string line;
    vector<string> v;

    ifstream readUserFile("userFile.txt");
    while (getline(readUserFile, line))
    {
        v = split(line, DELIMITTER);

        if (v[1] == accNo)
        {
            cout << "\nName: " << v[2] << " " << v[3] << endl;
            cout << "Account Number: " << accNo << endl;
            break;
        }
    }
    readUserFile.close();

    ifstream readAccountFile("accountFile.txt");
    while (getline(readAccountFile, line))
    {
        v = split(line, DELIMITTER);

        if (v[0] == accNo)
        {
            cout << "Available Balance: " << v[1] << endl;
            break;
        }
    }
    readAccountFile.close();

    char ch;
    cout << "Press any key to continue: ";
    cin >> ch;
}

/**
 * This function will slpit a line read from a file and stores it in a vector.
 *
 * @param str holds the line read from a file.
 * @param delimiter holds the delimitter value.
 *
 * @return strings in vector form.
 */
vector<string> split(string str, char DELIMITTER)
{
    vector<string> splittedSubstrings;
    int index = 0;
    string substring = "";
    while (index < str.length())
    {
        if (str[index] == DELIMITTER)
        {
            splittedSubstrings.push_back(substring);
            substring = "";
            index++;
            continue;
        }
        substring += str[index++];
    }
    if (substring != "")
    {
        splittedSubstrings.push_back(substring);
    }
    return splittedSubstrings;
}