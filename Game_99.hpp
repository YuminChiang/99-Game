#include "Player.hpp"

using namespace::std;

class Game_99 {
private:
    int Sum;
    int Point;
    int Select;
    int OutPlayer;
    vector<Player> Players;
    vector<int> Score;
    int Round;
    int PlayerNum;
    int DeckNum;
    Deck aDeck;
    void RunRound();
    void ReSet();
    void Process();
    void GetSum();
    bool CheckSum(int, int);
    void AddPoint();
    void PrintPoint();
    void SortRank();
    void PrintRank();
    void CheckDeck();
    void GameName();
    void Start();
    void View_Suits();
    void Rule();
    void EnterRound();
    void EnterPlayerNum();
    void EnterDeckNum();
    void DeckDeal();
    void SetPlayerName();
    void SetOrder();
    void OrderCardtoDeck();
    void Sort();
    void SetID();
    void PrintOrder();
    void PlayerPlay(int*);
    void Add_Sub(int, int);
    void Rotate(int*);
    bool CheckRotate();
    void Designate(int*);
    bool CheckDesignate();
    void Pass(int);
    bool CheckLife();
    bool CanPlay(Player);
    void Out(int);
    void Clean();
    void PlaySpadeAce(int);
    void PlayAce(int);
    void PlayTwo(int);
    void PlayThree(int);
    void PlayFour(int*);
    void PlayFive(int*);
    void PlaySix(int);
    void PlaySeven(int);
    void PlayEight(int);
    void PlayNine(int);
    void PlayTen(int, int);
    void PlayJack(int);
    void PlayQueen(int, int);
    void PlayKing(int);
public:
    Game_99();
    void RunGame();
};

Game_99::Game_99() {
    Start();
    Players.resize(PlayerNum);
    SetPlayerName();
}

void Game_99::GetSum() {
    cout << " Sum : " << Sum << endl << endl;
}

bool Game_99::CheckSum(int PlayerOrder, int AddNum) {
    return Sum + AddNum <= MAX;
}

void Game_99::GameName() {
    cout << " # # # # # #" << 
    endl << " # Game_99 #" << 
    endl << " # # # # # #" << endl << endl;
}

void Game_99::Start() {
    GameName();
    View_Suits();
    Rule();
    EnterRound();
    EnterPlayerNum();
    EnterDeckNum();
    cout << endl;
}

void Game_99::View_Suits() {
    vector<string> Suits = {" SPADE    HEART   DIAMOND   CLUB  ",
                            "   A       * *       A        @   ",
                            " d>*<b    **.**     <*>     @ + @ ",
                            "   -        V        V        -   ",
                            " SPADE    HEART   DIAMOND   CLUB  "};
    for (auto &&i : Suits)
        cout << i << endl;
    cout << endl;
}

void Game_99::Rule() {
    cout << " 1. Rule" << endl
    << " 2. Continue" << endl << endl;
    int Rule_Type;
    cout << " Please enter : ";
    while(cin >> Rule_Type, cin.fail() || Rule_Type < RULE || Rule_Type > CONTINUE)
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro!!!";
        cout << "Re-enter : ";
    }
    cout << endl;
    switch (Rule_Type)
    {
    case RULE:
    {
        cout << " -Game pre-work-" << endl << endl
        << " 1. At the beginning, all points for each player are 0" << endl
        << " 2. The number of players is limited to 2 ~ 4" << endl
        << " 3. Each player has 5 cards in hand" << endl << endl;
        cout << " -Point calculation-" << endl << endl
        << " Ace of Spades: Zeroing" << endl
        << " A : Add 1." << endl
        << " 2 : Add 2." << endl
        << " 3 : Add 3." << endl
        << " 4 : Rotate." << endl
        << " Note : 4 This function card is only suitable for four-player games," << endl
        << "        and when there are only two or three people," << endl
        << "        it is used as a general plus 4." << endl
        << " 5 : Designation" << endl
        << " 6 : Add 6." << endl
        << " 7 : Add 7." << endl
        << " 8 : Add 8." << endl
        << " 9 : Add 9." << endl
        << " 10 : Add 10 or subtract 10." << endl
        << " J : Skip a round" << endl
        << " Q : Plus 20 or minus 20." << endl
        << " K : 99 (the point value becomes 99)" << endl << endl;
        cout << " -Process-" << endl << endl
        << " 1. At the beginning of the game," << endl 
        << "    each player first draws a card from the initial deck (52 cards) to determine the order of the cards." << endl 
        << "    If the numbers are the same, then match the suit size (spade > heart > diamond > club)." << endl
        << " 2. According to the cards drawn, the bigger the ID, the smaller the ID" << endl
        << "    For example, if two players draw the 2 of spades and the king of hearts successively," << endl
        << "    the ID of the player who draws the king of hearts is 1," << endl
        << "    and the ID of the player who draws the 2 of spades is 2" << endl
        << " 3. Give each player 5 cards in hand" << endl
        << " 4. Play the cards in order" << endl
        << " 5. In the process of playing cards," << endl
        << "    if the player's remaining hand cards plus the existing points value are greater than 99," << endl
        << "    and the non-functional cards (Ace of Spades, 4, 5, 10, J, Q, K) can be played, they will be eliminated." << endl
        << " 6. The first player to be eliminated gets 1 point, the second player gets 2 points, and so on." << endl
        << "    The player who is not eliminated at the end gets the score of the number of players." << endl
        << " 7. After the game is over, all points of each player will be compared to determine the ranking." << endl << endl;
    }   break;
    case CONTINUE:
        break;
    }
}

void Game_99::EnterRound() {
    cout << " Round : ";
    while(cin >> Round, cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro!!!Re-enter : ";
    }
}

void Game_99::EnterPlayerNum() {
    cout << " Number of player : ";
    while(cin >> PlayerNum, cin.fail() || PlayerNum < Min || PlayerNum > Max)
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro!!!Re-enter : ";
    }
}

void Game_99::EnterDeckNum() {
    cout << " Number of Deck : ";
    while(cin >> DeckNum, cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro!!!";
        cout << "Re-enter : ";
    }
    while (DeckNum--)
        aDeck.Complete_Deck();
}

void Game_99::DeckDeal() {
    for (int i = 0; i < HandCards; i++)
        for (auto &&i : Players)
            i.Draw(aDeck.Deal());
}

void Game_99::RunGame() {
    while (Round--)
    {
        RunRound();
        ReSet();
        PrintPoint();
        Sleep(DELAY * 5);
    }
    SortRank();
    PrintRank();
}

void Game_99::RunRound() {
    Sum = 0;
    OutPlayer = 0;
    Point = 1;
    aDeck.Shuffle();
    SetOrder();
    aDeck.Shuffle();
    DeckDeal();
    Process();
    AddPoint();
}

void Game_99::Process() {
    while (CheckLife())
    {
        for (int Order = 0; Order < PlayerNum && CheckLife(); Order++)
        {
            CheckDeck();
            GetSum();
            if (Players.at(Order).GetLife_Death())
            {
                Players.at(Order).GetName();
                cout << " : " << endl << endl;
                Players.at(Order).SetHandsCard(HandCards);
                Players.at(Order).Display_Card();
                Players.at(Order).GetName();
                cout << " play (1 ~ 5) : ";
                if (CanPlay(Players.at(Order)))
                    PlayerPlay(&Order);
                else {
                    cout << " You have no hand to play" << endl; 
                    Out(Order);
                }
            }
        }
    }
}

void Game_99::ReSet() {
    for (auto &&i : Players)
        i.Reset();
}

void Game_99::SetPlayerName() {
    for (auto &&i : Players)
    {
        cout << " Player name: ";
        i.SetName();
    }   
    cout << endl;
}

void Game_99::SetOrder() {
    cout << " DeterPlayer_Deck player order" << endl << endl;
    for (auto &&i : Players)
    {
        i.GetName();
        cout << " : " << endl << endl;
        i.Draw(aDeck.Deal());
        Sleep(DELAY);
        i.ShowCard(OrderCard);
        i.SetPriority(i.GetSuit_Number(OrderCard));
    }
    OrderCardtoDeck();
    Sort();
    SetID();
    PrintOrder();
}

void Game_99::OrderCardtoDeck() {
    for (auto &&i : Players)
    {
        aDeck.AddCard(i.GetCard(OrderCard));
        i.Discard(OrderCard);
    }
}

void Game_99::CheckDeck() {
    if (!aDeck.GetSize()) {
        cout << "No cards, wait a moment";
        for (int i = 0; i < 5; i++) {
            Sleep(DELAY);
            cout << '.';
        }
        cout << endl;
        aDeck.Complete_Deck();
        aDeck.Shuffle();
    }
}

void Game_99::Sort() {
    for (int i = 0; i < PlayerNum - 1; i++)
        for (int j = i + 1; j < PlayerNum; j++)
            if (Players.at(i).GetPriority() > Players.at(j).GetPriority())
                swap(Players.at(i), Players.at(j));
}

void Game_99::SetID() {
    for (int i = 0; i < PlayerNum; i++)
        Players.at(i).SetID(i + 1);
}

void Game_99::PrintOrder() {
    cout << " Order : " << endl << " --------" << endl;
    for (auto &&i : Players)
    {
        if (i.GetLife_Death()) {
            cout << " Player " << i.GetID() << ' ';
            i.GetName();
            cout << endl;
        }
    }
    cout << endl;
}

void Game_99::PlayerPlay(int* PlayerOrder) {
    while(cin >> Select, cin.fail() || Select < First_Card || Select > Last_Card)
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro!!!Replay : ";
    }
    int Suit_Number = Players.at(*PlayerOrder).GetSuit_Number(Select);
    switch (Suit_Number) {
        case Club_Ace: case Diamond_Ace: case Heart_Ace:
            PlayAce(*PlayerOrder);   
            break;
        case Spade_Ace:    
            PlaySpadeAce(*PlayerOrder);  
            break;
        case Club_Two: case Diamond_Two: case Heart_Two: case Spade_Two:
            PlayTwo(*PlayerOrder);
            break;
        case Club_Three: case Diamond_Three: case Heart_Three: case Spade_Three:
            PlayThree(*PlayerOrder);
            break;
        case Club_Four: case Diamond_Four: case Heart_Four: case Spade_Four:
            PlayFour(&*PlayerOrder);   
            break;
        case Club_Five: case Diamond_Five: case Heart_Five: case Spade_Five:
            PlayFive(&*PlayerOrder);
            break;
        case Club_Six: case Diamond_Six: case Heart_Six: case Spade_Six:
            PlaySix(*PlayerOrder);
            break;
        case Club_Seven: case Diamond_Seven: case Heart_Seven: case Spade_Seven:
            PlaySeven(*PlayerOrder);
            break;
        case Club_Eight: case Diamond_Eight: case Heart_Eight: case Spade_Eight:
            PlayEight(*PlayerOrder);
            break;
        case Club_Nine: case Diamond_Nine: case Heart_Nine: case Spade_Nine:
            PlayNine(*PlayerOrder);
            break;
        case Club_Ten: case Diamond_Ten: case Heart_Ten: case Spade_Ten:
            PlayTen(Suit_Number, *PlayerOrder);
            break;
        case Club_Jack: case Diamond_Jack: case Heart_Jack: case Spade_Jack:
            PlayJack(*PlayerOrder);     
            break;
        case Club_Queen: case Diamond_Queen: case Heart_Queen: case Spade_Queen:
            PlayQueen(Suit_Number, *PlayerOrder);  
            break;
        case Club_King: case Diamond_King: case Heart_King: case Spade_King:
            PlayKing(*PlayerOrder);
            break;
    }
}

void Game_99::PlaySpadeAce(int PlayerOrder) {
    Sum = 0;
    Clean();
    Players.at(PlayerOrder).GetName();
    cout << " rest to zero." << endl << endl;
    Players.at(PlayerOrder).PlayCard(Select);
}

void Game_99::PlayAce(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 1)) {
        Sum += 1;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus one." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayTwo(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 2)) {
        Sum += 2;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus two." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayThree(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 3)) {
        Sum += 3;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus three." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayFour(int* PlayerOrder) {
    if (PlayerNum == 4) 
        Rotate(&*PlayerOrder);
    else {
        if (CheckSum(*PlayerOrder, 4)) {
            Sum += 4;
            Clean();
            Players.at(*PlayerOrder).GetName();
            cout << " plus four." << endl << endl;
        } else {
            Clean();
            Out(*PlayerOrder);    
        } 
        Players.at(*PlayerOrder).PlayCard(Select);
        Players.at(*PlayerOrder).Draw(aDeck.Deal());
    }
    
}

void Game_99::PlayFive(int* PlayerOrder) {
    Designate(&*PlayerOrder);
}

void Game_99::PlaySix(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 6)) {
        Sum += 6;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus six." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlaySeven(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 7)) {
        Sum += 7;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus seven." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayEight(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 8)) {
        Sum += 8;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus eight." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayNine(int PlayerOrder) {
    if (CheckSum(PlayerOrder, 9)) {
        Sum += 9;
        Clean();
        Players.at(PlayerOrder).GetName();
        cout << " plus nine." << endl << endl;
    } else {
        Clean();
        Out(PlayerOrder);
    }
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayTen(int Suit_Number, int PlayerOrder) {
    Add_Sub(Suit_Number, PlayerOrder);
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayJack(int PlayerOrder) {
    Pass(PlayerOrder);
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayQueen(int Suit_Number, int PlayerOrder) {
    Add_Sub(Suit_Number, PlayerOrder);
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::PlayKing(int PlayerOrder) {
    Sum = 99;
    Clean();
    Players.at(PlayerOrder).GetName();
    cout << " set to 99." << endl << endl;
    Players.at(PlayerOrder).PlayCard(Select);
    Players.at(PlayerOrder).Draw(aDeck.Deal());
}

void Game_99::Add_Sub(int Input, int PlayerOrder) {
    char sign;
    cout << " Add(+) or Sub(-) : ";
    while(cin >> sign, cin.fail() || sign != '+' && sign != '-')
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro!!!Re-enter : ";
    }
    Clean();
    if (Input >= Club_Ten && Input <= Spade_Ten) {
        if (sign == '+') {
            if (CheckSum(PlayerOrder, 10)) {
                Sum += 10;
                Players.at(PlayerOrder).GetName();
                cout << " plus ten." << endl << endl;
            } else
                Out(PlayerOrder);
        } else {
            Sum - 10 > 0 ? Sum -= 10 : Sum = 0;
            Players.at(PlayerOrder).GetName();
            cout << " minus ten." << endl;
        }
    } else {
        if (sign == '+') {
            if (CheckSum(PlayerOrder, 20)) {
                Sum += 20;
                Players.at(PlayerOrder).GetName();
                cout << " plus twenty." << endl << endl;
            } else
                Out(PlayerOrder);
        } else {
            Sum - 20 > 0 ? Sum -= 20 : Sum = 0;
            Players.at(PlayerOrder).GetName();
            cout << " minus twenty." << endl;
        }
    }
    cout << endl;
}

void Game_99::Rotate(int* PlayerOrder) {
    Clean();
    PrintOrder();
    Players.at(*PlayerOrder).GetName();
    cout << " changed order." << endl << endl;
    Players.at(*PlayerOrder).PlayCard(Select);
    Players.at(*PlayerOrder).Draw(aDeck.Deal());
    reverse(Players.begin(), Players.end());
    for (int i = 0; i < PlayerNum; i++) 
        if (Players.at(*PlayerOrder).GetID() == Players.at(i).GetID())
            if (!i)
                *PlayerOrder = 0;
            else if (i == PlayerNum - 1)
                *PlayerOrder = PlayerNum - 1;
            else
                *PlayerOrder = i - 1;
    PrintOrder();
}

void Game_99::Designate(int* PlayerOrder) {
    Clean();
    PrintOrder();
    int Designate_Player;
    Players.at(*PlayerOrder).GetName();
    cout << ", who do you want to designate Player ID: ";
    while(cin >> Designate_Player, cin.fail() || Designate_Player == Players.at(*PlayerOrder).GetID() || Designate_Player < 0 && Designate_Player > PlayerNum - 1)
    {
        cin.clear();
        cin.ignore(256,'\n');
        cout << " Erro or designate yourself!!!Re-enter : ";
    }
    Players.at(*PlayerOrder).GetName();
    cout << " designated to";
    cout << " Player " << Players.at(Designate_Player - 1).GetID() << '.' << endl << endl;
    Players.at(*PlayerOrder).PlayCard(Select);
    Players.at(*PlayerOrder).Draw(aDeck.Deal());
    for (int i = 0; i < PlayerNum; i++)
        if (Players.at(i).GetID() == Designate_Player)
            if (!i)
                *PlayerOrder = PlayerNum - 1;
            else if (i == PlayerNum - 1)
                *PlayerOrder = PlayerNum - 2;
            else
                *PlayerOrder = i - 1;
}

void Game_99::Pass(int PlayerOrder) {
    Clean();
    Players.at(PlayerOrder).GetName();
    cout << " skiped this turn." << endl << endl;
}

bool Game_99::CheckLife() {
    int LifePlayer = 0;
    for (auto &&i : Players)
        if (i.GetLife_Death())
            LifePlayer++;
    return LifePlayer != 1;
}

bool Game_99::CanPlay(Player aPlayer) {
    
    return true;
}

void Game_99::Out(int PlayerOrder) {
    Players.at(PlayerOrder).SetEliminateID(++OutPlayer);
    Players.at(PlayerOrder).Death();
    Players.at(PlayerOrder).GetName();
    cout << " Out!!!" << endl << endl;
}

void Game_99::AddPoint() {
    for (auto &&i : Players)
    {
        switch (i.GetEliminateID())
        {
        case 1:
            i.SetPoint(OnePoint);
            break;
        case 2:
            i.SetPoint(TwoPoint);
            break;
        case 3:
            i.SetPoint(ThreePoint);
            break;
        default:
            i.SetPoint(PlayerNum);
            break;
        }
    }
}

void Game_99::PrintPoint() {
    for (auto &&i : Players)
    {
        cout << " Player " << i.GetID();
        i.GetName();
        cout << " point : " << i.GetPoint() << endl;
    }
    cout << endl;
}

void Game_99::SortRank() {
    for(int i = 0; i < PlayerNum - 1; i++) 
        for (int j = i + 1; j < PlayerNum; j++) 
            if (Players.at(i).GetPoint() < Players.at(j).GetPoint())
                swap(Players.at(i), Players.at(j));
}

void Game_99::PrintRank() {
    cout << " Game Over" << endl << endl;
    cout << " Game settlement";
    for (int i = 0; i < 5; i++) 
    {
        Sleep(DELAY);
        cout << '.';
    }
    Clean();
    vector<string> Rank = {" 1st ", " 2nd ", " 3rd ", " 4th "};
    cout << " #Announce ranking#" << endl
    << " ------------------" << endl;
    for (int i = 0; i < PlayerNum; i++)
    {
        cout << Rank.at(i) << ":";
        Players.at(i).GetName();
        cout << endl;
    }
    cout << endl;
}

void Game_99::Clean() {
    for (int i = 0; i < CLEAN; i++)    
        cout << endl;
}