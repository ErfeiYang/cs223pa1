#include "data.hpp"
#include "player.hpp"
/*
* Name:Erfei Yang
* Class: cpts 223
*/
// ADVANTAGES/DISADVANTAGES LINKED LIST:
// Advantage: Dynamic allocation of memory - Linked lists allow for efficient memory allocation by allocating memory only when required, as opposed to arrays that pre - allocate a set amount of memory regardless of actual usage.This is particularly useful for storing commandsand descriptions, where the number of elements is unknown or subject to change.

// Disadvantage : Poor Random Access Time - Unlike arrays, linked lists do not allow for constant - time access to individual elements, as each element must be traversed starting from the head.This makes it less suitable for applications that require quick access to specific commands or descriptions, as time complexity would be linear O(n) in the worst case scenario.
 
// ADVANTAGES/DISADVANTAGES ARRAY:
// Advantage: Constant Access Time - Arrays allow for constant-time access to individual elements, making it suitable for storing user profiles where quick access to specific user information is required.

// Disadvantage: Static allocation of memory - Arrays pre-allocate a set amount of memory regardless of actual usage, which can lead to memory inefficiencies when storing user profiles where the number of profiles is unknown or subject to change.
int main() 
{

    srand((unsigned int)time(NULL));
    std::vector<Data> cBuf;
    Pvector(cBuf);
    List<Node<Data>> cList;
    pList(cList, cBuf);
    Player PlayerA;
    PlayerA.playername();


    int opt = 0;

    do
    {
        printMenu();
        std::cout << "Select yor option: \n";
        std::cin >> opt;
        if (opt > 7)
        {
            std::cout << "\nPlease select 1-7 \n";
        }
        switch (opt) {
        case 1:
            std::cout << "\t1: Rules\n";
            printRule();
            break;
        case 2:
            PlayerA.resetP();
            std::cout << "\t2: New Game\n";
            play_game(cBuf, cList, PlayerA);
            break;
        case 3:
            std::cout << "\t3: Load Game\n";
            loadPreviousGame(cBuf, cList, PlayerA);
            break;
        case 4:
            std::cout << "\t4: Add Command\n";
            addCommand(cList, cBuf);
            break;
        case 5:
            std::cout << "\t5: Remove Command\n";
            removeCommand(cList);
            break;
        case 6:
            std::cout << "\t6: Display Commands\n";
            display_all_commands(cList);
            break;
        case 7:
            std::cout << "\t7: Exiting\n\n";
            break;
        }

    } while (opt != 7);





    wCMD(cList);
    wProf(PlayerA);
    cList.~List();
    return 0;
}