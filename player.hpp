#pragma once
#ifndef GAME_OPTIONS_HPP
#define GAME_OPTIONS_HPP
#include "data.hpp"
#include "pa1.hpp"
#include"Node.hpp"

class Player {
protected:
    std::string pName;
    int points;

public:

    Player() {
        pName = "";
        points = 0;
    }
    void resetP();
    void playername();
    void giveP();
    void takeP();
    std::string getPlayerName() const;
    int getPlayerPts() const;
};


class MatchInstance {
public:
    std::vector<std::string> cmdTable;
    std::vector<int> choiceTable;

    MatchInstance() {
        cmdTable = { "", "", "", "" };
        choiceTable = { 0, 0, 0, 0 };
    }
};

void printRule();
void play_game(std::vector<Data>& buffVec, List<Node<Data>>& loadedList, Player& activeP);
void loadPreviousGame(std::vector<Data>&, List<Node<Data>>&, Player&);
void addCommand(List<Node<Data>>&, std::vector<Data>&);
void removeCommand(List<Node<Data>>&);
bool openFileOut(std::fstream&, std::string);
void wCMD(List<Node<Data>>& list);
void wProf(Player& pl);
#endif