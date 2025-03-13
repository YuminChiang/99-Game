#include "Deck.hpp"

using namespace::std;

class Player {
private:
    Deck Player_Deck;
    int Point;
    string Name;
    int ID;
    int Priority;
    int Eliminate_ID;
    int Life_Death;
public:
    Player();
    void Reset();
    void SetPoint(int);
    int GetPoint();
    void ChangPoint();
    void Death();
    bool GetLife_Death();
    void SetName();
    void GetName();
    void SetID(int);
    int GetID();
    void SetEliminateID(int);
    int GetEliminateID();
    void SetPriority(int);
    int GetPriority();
    Card GetCard(int);
    int GetSuit_Number(int);
    void ShowCard(int);
    void Draw(Card);
    void PlayCard(int);
    void Discard(int);
    void SetHandsCard(int);
    void Display_Card();
    void CleanHand();
};

Player::Player() : Point(0), Life_Death(1) {}

void Player::Reset() {
    Life_Death = 1;
    CleanHand();
}

void Player::CleanHand() {
    Player_Deck.Eliminate_Deck();
}

void Player::Display_Card() {
    Player_Deck.Display();
}

void Player::SetHandsCard(int Num) {
    Player_Deck.SetMaxCards(Num);
}

Card Player::GetCard(int Select) {
    return Player_Deck.GetCard(Select - 1);
}

int Player::GetSuit_Number(int Select) {
    return Player_Deck.GetCard(Select - 1).GetSuit_Number();
}

void Player::ShowCard(int Select) {
    Player_Deck.ShowCard(Select - 1);
}

void Player::PlayCard(int Select) {
    ShowCard(Select);
    Discard(Select);
}

void Player::Discard(int Select) {
    Player_Deck.DeleteCard(Select - 1);
}

void Player::Draw(Card aCard) {
    Player_Deck.AddCard(aCard);
}

void Player::Death() {
    Life_Death = 0;
}

void Player::SetEliminateID(int OutOrder) {
    Eliminate_ID = OutOrder;
}
int Player::GetEliminateID() {
    return Eliminate_ID;
}

bool Player::GetLife_Death() {
    return Life_Death;
}

void Player::SetPoint(int add_sub) {
    Point += add_sub;
}

int Player::GetPoint() {
    return Point;
}

void Player::SetName() {
    cin >> Name;
}

void Player::GetName() {
    cout << ' ' << Name;
}

void Player::SetID(int ID) {
    this->ID = ID;
}

int Player::GetID() {
    return ID;
}

void Player::SetPriority(int Number) {
    Priority = Number;
}

int Player::GetPriority() {
    return Priority;
}
