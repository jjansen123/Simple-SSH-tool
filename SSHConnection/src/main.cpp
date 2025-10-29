#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <string>
#include "json.hpp"
#include <vector>

using namespace std;
using json = nlohmann::json;

const string PROFILE_FILE = "ssh_profiles.json";

json loadProfiles() {
    ifstream file(PROFILE_FILE);
    if (!file.is_open()) return json::object();
    json profiles;
    file >> profiles;
    file.close();
    return profiles;
}

void saveProfiles(const json& profiles) {
    ofstream file(PROFILE_FILE);
    if (file.is_open()) {
        file << profiles.dump(4);
        file.close();
    }
}

void sshConnect(const string& host, int portNumber, const string& userName) {
    system("cls");
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Establishing connection, please wait...\n";
    this_thread::sleep_for(chrono::seconds(5));
    system("cls");

    string command = "ssh -p " + to_string(portNumber) + " " + userName + "@" + host;
    system(command.c_str());
}

int main() {
    int mainChoice;
    string host = "localhost";
    string userName;
    int portNumber = 2222;
    string input;

    json profiles = loadProfiles();

    cout << "What action would you like to perform?" << endl;
    cout << "1. SSH connect into a virtual machine" << endl;
    cout << "2. Profiles management" << endl;
    cout << "3. Coming soon" << endl;
    cout << "> ";
    cin >> mainChoice;
    cin.ignore();
    system("cls");

    if (mainChoice == 1) {
        cout << "Please enter the host address for SSH connection (default is localhost): " << endl;
        cout << "> ";
        getline(cin, input);
        if (!input.empty()) host = input;

        cout << "Please enter the port number for SSH connection (default is 2222): " << endl;
        cout << "> ";
        getline(cin, input);
        if (!input.empty()) portNumber = stoi(input);

        cout << "Please enter the username for SSH connection: " << endl;
        cout << "> ";
        getline(cin, userName);

        sshConnect(host, portNumber, userName);

        cout << "\nPress Enter to exit...";
        cin.get();
    }
    else if (mainChoice == 2) {
        bool keepRunning = true;
        while (keepRunning) {
            system("cls");
            int profileChoice;
            cout << "Profiles Menu:" << endl;
            cout << "1. List profiles" << endl;
            cout << "2. Add profile" << endl;
            cout << "3. Use profile" << endl;
            cout << "4. Delete profile" << endl;
            cout << "5. Back to main menu" << endl;
            cout << "> ";
            cin >> profileChoice;
            cin.ignore();

            switch (profileChoice) {
            case 1: {
                system("cls");
                cout << "Saved profiles:\n";
                int index = 1;
                for (auto& p : profiles.items()) {
                    cout << index << ". " << p.key() << ": "
                        << p.value()["user"] << "@"
                        << p.value()["host"] << ":"
                        << p.value()["port"] << endl;
                    index++;
                }
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }
            case 2: {
                system("cls");
                string profileName;
                cout << "Profile name: ";
                getline(cin, profileName);

                cout << "Host (default localhost): ";
                getline(cin, host);
                if (host.empty()) host = "localhost";

                cout << "Port (default 2222): ";
                getline(cin, input);
                portNumber = input.empty() ? 2222 : stoi(input);

                cout << "Username: ";
                getline(cin, userName);

                profiles[profileName] = { {"host", host}, {"port", portNumber}, {"user", userName} };
                saveProfiles(profiles);
                cout << "Profile saved!\n";
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }
            case 3: {
                system("cls");
                if (profiles.empty()) {
                    cout << "No profiles available!\n";
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                }

                cout << "Available profiles:\n";
                vector<string> keys;
                int index = 1;
                for (auto& p : profiles.items()) {
                    cout << index << ". " << p.key() << endl;
                    keys.push_back(p.key());
                    index++;
                }
                cout << "Enter profile number to use: ";
                int sel;
                cin >> sel;
                cin.ignore();

                if (sel >= 1 && sel <= keys.size()) {
                    string chosen = keys[sel - 1];
                    auto p = profiles[chosen];
                    host = p["host"];
                    portNumber = p["port"];
                    userName = p["user"];
                    sshConnect(host, portNumber, userName);
                }
                else {
                    cout << "Invalid selection!\n";
                    cout << "\nPress Enter to continue...";
                    cin.get();
                }
                break;
            }
            case 4: {
                system("cls");
                if (profiles.empty()) {
                    cout << "No profiles available!\n";
                    cout << "\nPress Enter to continue...";
                    cin.get();
                    break;
                }

                cout << "Available profiles:\n";
                vector<string> keys;
                int index = 1;
                for (auto& p : profiles.items()) {
                    cout << index << ". " << p.key() << endl;
                    keys.push_back(p.key());
                    index++;
                }
                cout << "Enter profile number to delete: ";
                int sel;
                cin >> sel;
                cin.ignore();

                if (sel >= 1 && sel <= keys.size()) {
                    profiles.erase(keys[sel - 1]);
                    saveProfiles(profiles);
                    cout << "Profile deleted!\n";
                }
                else {
                    cout << "Invalid selection!\n";
                }
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
            }
            case 5: {
                keepRunning = false;
                break;
            }
            default: {
                cout << "Invalid choice!\n";
                cout << "\nPress Enter to continue...";
                cin.get();
            }
            }
        }
    }
    else {
        cout << "This feature is coming soon or invalid!" << endl;
        cout << "\nPress Enter to exit...";
        cin.get();
    }

    return 0;
}
