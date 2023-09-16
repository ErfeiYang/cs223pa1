#include "player.hpp"

void Player::playername() {//get players name
    std::string name;
    std::cout << "\nPlease Enter Your Name: ";

    std::cin >> name;
    pName = name;
}
void Player::resetP() { points = 0; }//reset point to 0
void Player::giveP() { points += 1; }// when player got correct anwers they will get one point
void Player::takeP() { points -= 1; }// when player got wrong anwers they will lose one point

std::string Player::getPlayerName() const { return pName; }
int Player::getPlayerPts() const { return points; }

void printRule() {//display the rule
    std::cout << "\tGame Rule:\n";
    std::cout
        << "\tEnter the commands and description the fuction.Follow the descrip you will choose a number when you choose correct you will get one point if you choose wrong you will lose one points. You can get NEGATIVE points.\n\n";
}


void play_game(std::vector<Data>& detal, List<Node<Data>>& loadedList, Player& activeP) {
    const int upperBound = loadedList.getListSize();
    int numCmdsThisGame = 0;
    while (numCmdsThisGame < 5 || numCmdsThisGame > upperBound) {
        std::cout << numCmdsThisGame << std::endl;
        std::cout << "\tPlease enter the number of commands to play(5-30): ";
        std::cin >> numCmdsThisGame;
    }
    std::vector<int> gLength(numCmdsThisGame);
    for (int i = 0; i < numCmdsThisGame; ++i) {
        gLength[i] = rand() % upperBound;
        for (int j = 0; j < i; ++j) {
            if (gLength[j] == gLength[i]) {
                i--;
                break;
            }
        }
    }
    int points = 0;
    for (int i = 0; i < numCmdsThisGame; ++i) {
        int rNum = gLength[i];
        int choice = rand() % 3 + 1;
        int options[3];
        options[choice - 1] = rNum;
        int x = rNum;
        for (int j = 0; j < 3; ++j) {
            if (j == choice - 1) continue;
            x = rand() % upperBound;
            for (int k = 0; k < j; ++k) {
                if (options[k] == x) {
                    x = rand() % upperBound;
                    k = -1;
                }
            }
            options[j] = x;
        }
        std::cout << detal[rNum].getCname() << ":\n";
        for (int j = 0; j < 3; ++j) {
            std::cout << j + 1 << ". " << detal[options[j]].getCinfo() << "\n";
        }
        int userInput = choice;
        std::cout << "Enter your answer:\n " << std::endl;
        std::cin >> userInput;
        if (userInput == choice) {
            std::cout << "Correct! You got " << detal[rNum].getCpoint() << " point\n" << std::endl;
            points += detal[rNum].getCpoint();
        }
        else {
            std::cout << "Wrong! You lost 1 point\n" << std::endl;
            points--;
        }
    }
    std::cout << "Total points: " << points << std::endl;
}

void loadPreviousGame(std::vector<Data>& buffVec, List<Node<Data>>& loadedList,
    Player& activeP) {
    play_game(buffVec, loadedList, activeP);
}

void addCommand(List<Node<Data>>& list, std::vector<Data>& buffVec) {
    std::string uInput;
    Data* temp = nullptr;
    temp = new Data;

    std::cout << "add a new command:\n";
    std::cout << "Please enter the command's name: ";
    std::cin >> uInput;
    temp->Cname(uInput);

    std::cout << "Please enter a description for the command: ";
    std::cin >> uInput;
    temp->Cinfo(uInput);

    Node<Data>* newNode = nullptr;
    newNode = new Node<Data>;
    newNode->NodeData = temp;

    list.appendNode(*newNode);
    buffVec.push_back(*temp);
}

void removeCommand(List<Node<Data>>& list) {
    std::string uInput;
    Data* temp = nullptr;
    temp = new Data;

    std::cout << "remove command:";
    std::cout << "Please enter the name of the command you want to remove: ";
    std::cin >> uInput;
    temp->Cname(uInput);

    Node<Data>* toBeDeleted = nullptr;
    toBeDeleted = new Node<Data>;
    toBeDeleted->NodeData = temp;

    list.deleteNode(*toBeDeleted);
}

bool openFileOut(std::fstream& file, std::string fName) {
    file.open(fName, std::ios::out);

    if (file.fail())
        return false;
    else
        return true;
}


void exitFunction(Player& activeP, List<Node<Data>>& list) {
    wCMD(list);
    wProf(activeP);
}
void wCMD(List<Node<Data>>& list) {
    std::ofstream updateCmdFile("commands.csv");
    if (!updateCmdFile) {
        std::cerr << "Error, couldn't open the file.\n";
        return;
    }

    for (auto nodePtr = list.getListHead(); nodePtr; nodePtr = nodePtr->next) {
        auto thisNodeData = nodePtr->NodeData;
        if (!thisNodeData->getCname().empty()) {
            updateCmdFile << thisNodeData->getCname() << ","
                << thisNodeData->getCinfo() << "," << thisNodeData->getCpoint() << "\n";
        }
    }
}


void wProf(Player& pl) {
    std::fstream profile;
    std::string tokName = pl.getPlayerName();
    int tokPts = pl.getPlayerPts();

    if (openFileOut(profile, "profiles.csv"))
        std::cout << "File opened successfully for WRITING." << std::endl;
    else
        std::cout << "ERROR. Did not open file successfully." << std::endl;

    profile << "\"" << tokName << "\""
        << ", " << tokPts << std::endl;

    profile.close();
}
