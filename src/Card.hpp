#include "Define.h"

using namespace::std;

class Card {
private:
    int Suit, Number;
    int Suit_Number;
    vector<string> Kind;
    void Name();
    void Side();
    void Suits(int);
    void Numbers(int);
    void Spade();
    void Heart();
    void Diamond();
    void Club();
    void Ace();
    void Two();
    void Three();
    void Four();
    void Five();
    void Six();
    void Seven();
    void Eight();
    void Nine();
    void Ten();
    void Jack();
    void Queen();
    void King();
    void Joker();
public:
    Card(int, int);
    vector<string> GetKind();
    int GetSuit_Number();
    static const int CardRow = 8;
};

Card::Card(int CheckSuit, int CheckNumber) : Suit(CheckSuit), Number(CheckNumber), Suit_Number(CheckNumber * 4 + CheckSuit) {
    Side();
    Suits(CheckSuit);
//  Name();
    Numbers(CheckNumber);
    Side();
}


int Card::GetSuit_Number() {
    return Suit_Number;
}

inline void Card::Suits(int CheckSuit) {
    switch (CheckSuit)
    {
        case CLUB:
            Club();     break;
        case DIAMOND:
            Diamond();  break;
        case HEART:
            Heart();    break;
        case SPADE:
            Spade();    break;
    }
}

inline void Card::Numbers(int CheckNumber) {
    switch (CheckNumber)
    {
        case ACE:
            Ace();      break;
        case TWO:
            Two();      break;
        case THREE:
            Three();    break;
        case FOUR:
            Four();     break;
        case FIVE:
            Five();     break;
        case SIX:
            Six();      break;
        case SEVEN:
            Seven();    break;
        case EIGHT:
            Eight();    break;
        case NINE:
            Nine();     break;
        case TEN:
            Ten();      break;
        case JACK:
            Jack();     break;
        case QUEEN:
            Queen();    break;
        case KING:
            King();     break;
    }
}

vector<string> Card::GetKind() {
    return Kind;
}

void Card::Name() {
    string name = {"#  YuMin  #"};
    Kind.push_back(name);
}

void Card::Side() {
    string side = {"# # # # # #"};
    Kind.push_back(side);
}

void Card::Spade() {
    vector<string> spade = {"#    A    #",
                            "#  d>*<b  #",
                            "#    -    #"};
    for (auto &&i : spade)
        Kind.push_back(i);
}

void Card::Heart() {
    vector<string> heart = {"#   * *   #",
                            "#  **.**  #",
                            "#    V    #"};
    for (auto &&i : heart)
        Kind.push_back(i);
}

void Card::Diamond() {
    vector<string> diamond = {"#    A    #",
                              "#   <*>   #",
                              "#    V    #"};
    for (auto &&i : diamond)
        Kind.push_back(i);
}

void Card::Club() {
    vector<string> club = {"#    @    #",
                           "#  @ + @  #",
                           "#    -    #"};
    for (auto &&i : club)
        Kind.push_back(i);
}

void Card::Ace() {
    vector<string> ace = {"#    *    #",
                          "#    A    #",
                          "#   * *   #"};
    for (auto &&i : ace)
        Kind.push_back(i);
}

void Card::Two() {
    vector<string> two = {"#   * *   #",
                          "#   I I   #",
                          "#   * *   #"};
    for (auto &&i : two)
        Kind.push_back(i);
}

void Card::Three() {
    vector<string> three = {"#   ***   #",
                            "#   III   #",
                            "#   ***   #"};
    for (auto &&i : three)
        Kind.push_back(i);
}

void Card::Four() {
    vector<string> four = {"#  * * *  #",
                           "#  I  V   #",
                           "#  *  *   #"};
    for (auto &&i : four)
        Kind.push_back(i);
}
void Card::Five() {
    vector<string> five = {"#   * *   #",
                           "#    V    #",
                           "#    *    #"};
    for (auto &&i : five)
        Kind.push_back(i);
}

void Card::Six() {
    vector<string> six = {"#  * * *  #",
                          "#   V  I  #",
                          "#   *  *  #"};
    for (auto &&i : six)
        Kind.push_back(i);
}

void Card::Seven() {
    vector<string> seven = {"# * *  ** #",
                            "#  V   II #",
                            "#  *   ** #"};
    for (auto &&i : seven)
        Kind.push_back(i);
}

void Card::Eight() {
    vector<string> eight = {"# * * *** #",
                            "#  V  III #",
                            "#  *  *** #"};
    for (auto &&i : eight)
        Kind.push_back(i);
}

void Card::Nine() {
    vector<string> nine = {"#  * * *  #",
                           "#  I  X   #",
                           "#  * * *  #"};
    for (auto &&i : nine)
        Kind.push_back(i);
}

void Card::Ten() {
    vector<string> ten = {"#  *   *  #",
                          "#    X    #",
                          "#  *   *  #"};
    for (auto &&i : ten)
        Kind.push_back(i);
}

void Card::Jack() {
    vector<string> jack = {"# J  J  J #",
                           "# J  J  J #",
                           "# J  J  J #"};
    for (auto &&i : jack)
        Kind.push_back(i);
}

void Card::Queen() {
    vector<string> queen = {"# Q  Q  Q #",
                            "# Q  Q  Q #",
                            "# Q  Q  Q #"};
    for (auto &&i : queen)
        Kind.push_back(i);
}

void Card::King() {
    vector<string> king = {"# K  K  K #",
                           "# K  K  K #",
                           "# K  K  K #"};
    for (auto &&i : king)
        Kind.push_back(i);
}

void Card::Joker() {
    vector<string> joker = {"#  J K R  #",
                            "#   O E   #",
                            "#  J K R  #",
                            "#   O E   #",
                            "#  J K R  #"};
    for (auto &&i : joker)
        Kind.push_back(i);
}
