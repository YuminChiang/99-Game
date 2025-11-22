#include "Card.hpp"

using namespace::std;

class Deck {
private:
    vector<Card> CardSet;
    vector<string> Buffer;
    int BufferCnt;
    int MaxCards;
public:
    Deck();
    void Complete_Deck();
    void AddCard(Card);
    void DeleteCard(int);
    void Shuffle();
    void SetMaxCards(int);
    Card Deal();
    Card GetCard(int);
    int Play(int);
    void Display();
    void ShowCard(int);
    void toBuffer(Card);
    void Flush();
    void Check();
    void Eliminate_Deck();
    int GetSize();
};

Deck::Deck() {
    Buffer.resize(Card::CardRow);
    BufferCnt = 0;
}

int Deck::GetSize() {
    return CardSet.size();
}

Card Deck::GetCard(int Select) {
    return CardSet.at(Select);
}

void Deck::SetMaxCards(int MaxCards) {
    this->MaxCards = MaxCards;
}

void Deck::Complete_Deck() {
    for (int i = CLUB; i <= SPADE; i++)
        for (int j = ACE; j <= KING; j++)
            CardSet.push_back(Card(i, j));
}

void Deck::Eliminate_Deck() {
    CardSet.clear();
}

void Deck::AddCard(Card Input) {
    CardSet.push_back(Input);
}

Card Deck::Deal() {
    Card tmp = CardSet.at(CardSet.size() - 1);
    CardSet.pop_back();
    return tmp;
}

void Deck::Shuffle() {
    cout << " Shuffling";
    for (int i = 0; i < Unit_Shuffle; i++)
    {
        Sleep(DELAY);
        cout << '.';
    }
    for (int i = SPADE; i <= CLUB; i++)
        for (int j = ACE; j <= KING; j++)
            CardSet.push_back(Card(i, j));
    shuffle(CardSet.begin(), CardSet.end(), default_random_engine((unsigned)SEED));
    cout << endl << endl;
}

void Deck::Display() {
    for (auto &card : CardSet)
    {
        toBuffer(card);
        Check();
    }
    if (BufferCnt != 0)
        Flush();
}

void Deck::toBuffer(Card card) {
    for (int Row = 0; Row < Card::CardRow; Row++)
        Buffer[Row] += " " + card.GetKind()[Row] + " ";
    BufferCnt++;
}

void Deck::Check() {
    if (BufferCnt == MaxCards)
        Flush();
}

void Deck::Flush() {
    for (auto &&i : Buffer)
    {
        cout << i << endl;
        i.clear();
    }
    cout << endl;
    BufferCnt = 0;
}

void Deck::ShowCard(int Select) {
    for (auto &&i : CardSet.at(Select).GetKind())
        cout << ' ' << i << endl;
    cout << endl;
}

void Deck::DeleteCard(int Select) {
    CardSet.erase(CardSet.begin() + Select);
}
