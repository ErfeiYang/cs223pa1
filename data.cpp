#include "data.hpp"

void Data::Cname(std::string& c) { CName = c; }
void Data::Cinfo(std::string& c) { CInfo = c; }
void Data::Cpoint(int c) { CPoint = c; }
std::string Data::getCname() const { return CName; }
std::string Data::getCinfo() const { return CInfo; }
int Data::getCpoint() const { return CPoint; }


void Data::operator=(const Data& right) {//get command
    CName = right.getCname();
    CInfo = right.getCinfo();
    CPoint = right.getCpoint();
}

bool Data::operator==(Data& right) const {//campare
    if (CName.compare(right.CName) != 0) {
        return false;
    }
    else
        return true;
}


bool openF1(std::fstream& file, std::string fName) {//open file
    file.open(fName, std::ios::in);

    if (file.fail())
        return false;
    else
        return true;
}


void Pvector(std::vector<Data>& dital) {//open file
    std::fstream dataFile;

    if (openF1(dataFile, "commands.csv")) {
        std::cout << "File opened successfully." << std::endl;

        if (true) {
            CopyFile(dataFile, dital);
            std::cout << "Data copied successfully." << std::endl;
        }
        else {
            std::cout << "Data copy failed." << std::endl;
        }

        dataFile.close();
    }
    else {
        std::cout << "File open error!" << std::endl;
    }
}

void CopyFile(std::fstream& file, std::vector<Data>& cmdVec) {
    char line[1000] = { '\0' };
    std::string data;
    int point;
    Data temp;

    while (!file.eof()) {
        file.getline(line, 1000, ',');
        data = line;
        temp.Cname(data);
        file.getline(line, 1000, ',');
        data = line;
        if (line[0] == '\"') {
            data += ',';
            file.getline(line, 1000, '\"');
            data += line;
            data += '\"';
            file.getline(line, 1000, ',');
        }
        temp.Cinfo(data);

        file.getline(line, 100, '\n');
        point = atoi(line);
        temp.Cpoint(point);

        cmdVec.push_back(temp);
    }
}

void pList(List<Node<Data>>& ourList, std::vector<Data>& bufferVec) {
    for (const auto& data : bufferVec) {
        auto tempDat = std::make_unique<Data>(data);
        auto tempNode = std::make_unique<Node<Data>>();
        tempNode->NodeData = tempDat.get();
        ourList.appendNode(*tempNode);
        tempDat.release();
        tempNode.release();
    }
}

void printMenu() {
    std::cout << "\nMenu: \n"
        "1. Display Rules\n"
        "2. Play game\n"
        "3. Load Privoous Game\n"
        "4. Add command\n"
        "5. Remove Command\n"
        "6: Display All Commands\n"
        "7. Exit" << std::endl << std::endl;
}

void display_all_commands(List<Node<Data>>& activeCmdList) {
    int index = 1;
    Node<Data>* pCur = activeCmdList.getListHead();
    std::cout << std::endl << "\t6. display_all_commands" << std::endl;
    while (pCur != nullptr) {
        std::cout << index << " - " << pCur->NodeData->getCname() << " - " << pCur->NodeData->getCinfo() << std::endl;
        pCur = pCur->next;
        index++;
    }
}
