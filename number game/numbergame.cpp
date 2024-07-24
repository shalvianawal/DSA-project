#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

using namespace std;

map<string, int> mi;
map<string, int> hints;

void playGame() {
    string name;
    cout << "Enter your Name: ";
    cin >> name;

    int difficulty;
    cout << "Choose difficulty level (1: Easy, 2: Medium, 3: Hard): ";
    cin >> difficulty;

    int maxRange, trials;
    switch (difficulty) {
        case 1:
            maxRange = 50; // Easy: 0-49
            trials = 10;
            break;
        case 2:
            maxRange = 100; // Medium: 0-99
            trials = 6;
            break;
        case 3:
            maxRange = 200; // Hard: 0-199
            trials = 4;
            break;
        default:
            cout << "Invalid difficulty level. Defaulting to Medium.\n";
            maxRange = 100;
            trials = 6;
    }

    if (hints.find(name) == hints.end()) {
        hints[name] = 3; // Everyone starts with 3 hints
    }

    srand(time(0));
    int ranNum = rand() % maxRange;

    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│                                           │" << endl;
    cout << "│     Let's Play Guess a Number...          │" << endl;
    cout << "│                                           │" << endl;
    cout << "└───────────────────────────────────────────┘" << endl;

    bool win = false;
    int guess;
    int pTries = 0;

    while (!win && pTries < trials) {
        cout << "Guess a Number (0-" << maxRange-1 << "): ";
        cin >> guess;
        pTries++;

        if (guess == ranNum) {
            cout << "Congratulations! You Guessed the Number in " << pTries << " Tries." << endl;
            win = true;

            // ENTERING INTO THE LEADER BOARD
            if (mi.find(name) == mi.end()) {
                mi[name] = 1;
            } else {
                mi[name]++;
                if (mi[name] % 3 == 0) { // Award an extra hint for every 3 correct answers
                    hints[name]++;
                    cout << "You have earned an extra hint! You now have " << hints[name] << " hints." << endl;
                }
            }
        } else {
            cout << "Do you want a hint? (yes/no): ";
            string useHint;
            cin >> useHint;

            if (useHint == "yes" && hints[name] > 0) {
                hints[name]--;
                if (guess < ranNum) {
                    int diff = ranNum - guess;
                    if (diff <= 10) {
                        cout << "Too low but very close!" << endl;
                    } else if (diff <= 20) {
                        cout << "Low, but close. Guess again." << endl;
                    } else {
                        cout << "Too low and too far. Guess again." << endl;
                    }
                } else {
                    int diff = guess - ranNum;
                    if (diff <= 10) {
                        cout << "Too high but very close!" << endl;
                    } else if (diff <= 20) {
                        cout << "High, but close. Guess again." << endl;
                    } else {
                        cout << "Too high and too far. Guess again." << endl;
                    }
                }
                cout << "You have " << hints[name] << " hints remaining." << endl;
            } else if (useHint == "yes" && hints[name] == 0) {
                cout << "Sorry, you have no hints remaining." << endl;
            } else if (useHint == "no") {
                if (guess < ranNum) {
                    cout << "Too low. Guess again." << endl;
                } else {
                    cout << "Too high. Guess again." << endl;
                }
            }
        }
    }

    if (!win) {
        cout << "You failed the game. The correct number was " << ranNum << "." << endl;
    }
}

void displayLeaderBoard() {
    cout << "\nHere is the LeaderBoard:\n";
    cout << "Name\tScore\tHints\n";
    for (const auto& i : mi) {
        cout << i.first << "\t" << i.second << "\t" << hints[i.first] << endl;
    }
    cout << endl;
}

// FUNCTION WILL BE USED TO DISPLAY THE MENU AND IT WILL HANDLE THE CHOICES OF THE USER
void displayMenu() {
    int choice;

    do {
        cout << "\nOptions:\n"
             << "1. Play\n"
             << "2. View LeaderBoard\n"
             << "3. Exit\n"
             << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                displayLeaderBoard();
                break;
            case 3:
                cout << "Thanks for Playing. Goodbye\n";
                break;
            default:
                cout << "Please enter a valid choice.\n";
                break;
        }
    } while (choice != 3);
}

int main() {
    displayMenu();
    return 0;
}