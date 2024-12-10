#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Player {
    int jerseyNumber;
    string name;
    int age;
    string position;
};

void addPlayer(vector<Player>& team);
void displayPlayers(const vector<Player>& team);
void updatePlayer(vector<Player>& team);
void deletePlayer(vector<Player>& team);
void printBanner(string text);

int main() {
    vector<Player> team;
    int choice;
    
    printBanner("Volleyball Team Management System");
    
    do {
        cout << "\n1. Add Player\n";
        cout << "2. View Players\n";
        cout << "3. Update Player\n";
        cout << "4. Delete Player\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPlayer(team);
                break;
            case 2:
                displayPlayers(team);
                break;
            case 3:
                updatePlayer(team);
                break;
            case 4:
                deletePlayer(team);
                break;
            case 5:
                cout << "Thank you for using the system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void addPlayer(vector<Player>& team) {
    Player p;
    cout << "Enter jersey number: ";
    cin >> p.jerseyNumber;
    cin.ignore(); // Clear buffer
    cout << "Enter name: ";
    getline(cin, p.name);
    cout << "Enter age: ";
    cin >> p.age;
    cin.ignore();
    cout << "Enter position: ";
    getline(cin, p.position);

    team.push_back(p);
    cout << "Player added.\n";
}

void printBanner(string text) {
    cout << "==========================================\n";
    cout << "||                                      ||\n";
    cout << "     " << text << "\n";
    cout << "||                                      ||\n";
    cout << "==========================================\n";
}

void displayPlayers(const vector<Player>& team) {
    if (team.empty()) {
        cout << "No players in the team." << endl;
        return;
    }

    cout << "Jersey\t\tName\t\t\tAge\t\tPosition\n";
    for (const auto& player : team) {
        cout << player.jerseyNumber << "\t\t" << player.name << "\t\t" 
             << player.age << "\t\t" << player.position << "\n";
    }
}

void updatePlayer(vector<Player>& team) {
    int jerseyNumber;
    cout << "Enter jersey number of player to update: ";
    cin >> jerseyNumber;

    for (auto& player : team) {
        if (player.jerseyNumber == jerseyNumber) {
            cin.ignore(); // Clear buffer
            cout << "Enter new name: ";
            getline(cin, player.name);
            cout << "Enter new age: ";
            cin >> player.age;
            cin.ignore();
            cout << "Enter new position: ";
            getline(cin, player.position);

            cout << "Player updated.\n";
            return;
        }
    }

    cout << "Player not found.\n";
}

void deletePlayer(vector<Player>& team) {
    int jerseyNumber;
    cout << "Enter jersey number of player to delete: ";
    cin >> jerseyNumber;

    for (auto it = team.begin(); it != team.end(); ++it) {
        if (it->jerseyNumber == jerseyNumber) {
            team.erase(it);
            cout << "Player deleted.\n";
            return;
        }
    }

    cout << "Player not found.\n";
}


