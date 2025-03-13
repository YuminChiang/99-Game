#include "bits/stdc++.h"
#include <windows.h>

#ifndef Def_h
#define Def_h
#define Unit_Shuffle 5
#define DELAY 500
#define SEED chrono::system_clock::now().time_since_epoch().count()
#define First_Card 1
#define Last_Card 5
#define OrderCard 1
#define HandCards 5
#define Min 2
#define Max 4
#define CLEAN 100
#define MAX 99

enum Suits {CLUB = 1, DIAMOND, HEART, SPADE};
enum Numbers {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum Club_Number {Club_Ace = 5, Club_Two = 9, Club_Three = 13, Club_Four = 17, Club_Five = 21, Club_Six = 25, Club_Seven = 29, Club_Eight = 33, Club_Nine = 37, Club_Ten = 41, Club_Jack = 45, Club_Queen = 49, Club_King = 53};
enum Diamond_Number {Diamond_Ace = 6, Diamond_Two = 10, Diamond_Three = 14, Diamond_Four = 18, Diamond_Five = 22, Diamond_Six = 26, Diamond_Seven = 30, Diamond_Eight = 34, Diamond_Nine = 38, Diamond_Ten = 42, Diamond_Jack = 46, Diamond_Queen = 50, Diamond_King = 54};
enum Heart_Number {Heart_Ace = 7, Heart_Two = 11, Heart_Three = 15, Heart_Four = 19, Heart_Five = 23, Heart_Six = 27, Heart_Seven = 31, Heart_Eight = 35, Heart_Nine = 39, Heart_Ten = 43, Heart_Jack = 47, Heart_Queen = 51, Heart_King = 55};
enum Spade_Number {Spade_Ace = 8, Spade_Two = 12, Spade_Three = 16, Spade_Four = 20, Spade_Five = 24, Spade_Six = 28, Spade_Seven = 32, Spade_Eight = 36, Spade_Nine = 40, Spade_Ten = 44, Spade_Jack = 48, Spade_Queen = 52, Spade_King = 56};
enum Rule_version {RULE = 1, CONTINUE};
enum GetPoint  {OnePoint = 1, TwoPoint, ThreePoint, FourPoint};

#endif /* Def_h */