// Wissam Wahbe
// Class (CECS 325-01)
// Prog 1 – Fibonacci Solitaire
// (09/25/2023)
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.

using namespace std;
#include <iostream>
#include <istream>
#include <cmath>
#include <vector>
#include <ctime>

class Card {
private:
  char rank;
  char suit;

public:
  Card() {
    rank = '0';
    suit = 'm';
  }
  Card(char r, char s) {
    rank = r;
    suit = s;
  }
  int getValue() {
    int value = 0;

    if (rank == '0') {
      value = 0;
    } else if (rank == 'A') {
      value = 1;
    } else if (rank == '2') {
      value = 2;
    } else if (rank == '3') {
      value = 3;
    } else if (rank == '4') {
      value = 4;
    } else if (rank == '5') {
      value = 5;
    } else if (rank == '6') {
      value = 6;
    } else if (rank == '7') {
      value = 7;
    } else if (rank == '8') {
      value = 8;
    } else if (rank == '9') {
      value = 9;
    } else if (rank == 'T') {
      value = 10;
    } else if (rank == 'J') {
      value = 10;
    } else if (rank == 'Q') {
      value = 10;
    } else if (rank == 'K') {
      value = 10;
    }

    return value;
  }
  void show() {
    if (rank == '0') {
      std::cout << "XX";
    }
    if (rank == 'T') {
      std::cout << "10" << suit << " ";
    } else {
      std::cout << rank << suit << " ";
    }
  }
};

class Deck {
private:
  std::vector<Card> oDeck;

public:
   Deck() {
    char arrayS[] = {'S', 'H', 'D', 'C'};
    char arrayR[] = {'A', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'T', 'J', 'Q', 'K'};

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        oDeck.push_back(Card(arrayR[j], arrayS[i]));
      }
    }
  }

  void newDeck() {
    oDeck.clear();
    char arrayS[] = {'S', 'H', 'D', 'C'};
    char arrayR[] = {'A', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'T', 'J', 'Q', 'K'};

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        oDeck.push_back(Card(arrayR[j], arrayS[i]));
      }
    }
  }

  Card deal() {
    Card deal = oDeck.at(0);
    oDeck.erase(oDeck.begin());

    return deal;
  }

  void shuffle() {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
      int x = rand() % (oDeck.size());
      int y = rand() % (oDeck.size());

      Card temp = oDeck[x];
      oDeck[x] = oDeck[y];
      oDeck[y] = temp;
    }
  }

  bool isEmpty() {
    if (oDeck.size() == 0) {
      return true;
    }
    return false;
  }

  void show() {
    int counter = 1;
    for (int i = 0; i < oDeck.size(); i++) {
      oDeck[i].show();
      counter++;
      if (counter % 13 == 1) {
        cout << "\n";
      }
    }
  }
};

bool isFibo(int num) {
  int test = 5 * num * num + 4;
  int test2 = 5 * num * num - 4;

  int root = sqrt(test);
  int root2 = sqrt(test2);

  return (root * root == test || root2 * root2 == test2);
}

bool play(Deck d, Card hand[]) {
  int numOfFibo = 0;
  bool win = false;
  int trackHand = 0;
  int sum = 0;
  while (d.isEmpty() == false) {
    Card deal = d.deal();
    hand[trackHand] = deal;
    sum += deal.getValue();
    trackHand++;
    if (isFibo(sum)) {
      numOfFibo++;
      for (int i = 0; i < trackHand; i++) {
        hand[i].show();
      }
      fill_n(hand, 52, Card());
      sum = 0;
      trackHand = 0;
    }
  }
  for (int i = 0; i < trackHand; i++) {
    hand[i].show();
  }
  cout << "Last hand value: " << sum << endl << endl;
  if (isFibo(sum)) {
    cout << "Winner in " << numOfFibo << " piles!\n" << endl;
    win = true;
  } else {
    cout << "Loser in " << numOfFibo << " piles!\n" << endl;
  }
  return win;
}

int main() {
  bool win = false;
  Deck d;
  Card hand[52];
  int games = 0;
  bool exit = false;

  while (!exit) {
    cout << "Welcome to Fibonacci Solitaire!\n";
    cout << "1) Create a New Deck\n";
    cout << "2) Display Deck\n";
    cout << "3) Shuffle Deck\n";
    cout << "4) Play Fibo Solitaire\n";
    cout << "5) Win Fibo Solitaire\n";
    cout << "6) Exit";

    int input = 0;
    cout << endl;
    cin >> input;

    if (input == 1) {
      d.newDeck();
    } else if (input == 2) {
      d.show();
    } else if (input == 3) {
      if (d.isEmpty()) {
        cout << "There are no cards to shuffle!!!!!!!!!" << endl;
      } else {
        d.shuffle();
      }
    } else if (input == 4) {
      int numOfFibo = 1;
      int trackHand = 0;
      int sum = 0;
      games++;


      if (d.isEmpty()) {
        std::cout << "\nCan't play...Deck is empty!!!" << endl;
        d.newDeck();
      }
     

      while (!d.isEmpty()) {
        Card deal = d.deal();
        hand[trackHand] = deal;
        sum = sum + deal.getValue();
        trackHand++;
        if (isFibo(sum)) {
          numOfFibo++;
          for (int i = 0; i < trackHand; i++) {
            hand[i].show();
          }
          cout << "Fibo: " << sum << endl;
          fill_n(hand, 52, Card());
          sum = 0;
          trackHand = 0;
        }
      }
      for (int i = 0; i < trackHand; i++) {
        hand[i].show();
      }
      cout << endl;
      cout << "Last hand value: " << sum << endl;
      if (isFibo(sum)) {
        cout << "Winner in " << numOfFibo << " piles!\n";
        cout << "Games played: " << games << endl;
      } else if (!isFibo(sum)) {
        cout << "Loser in " << numOfFibo << " piles!\n";
      }
    } else if (input == 5) {
      win = false;
      while (!win) {
        d.newDeck();
        d.shuffle();
        games++;
        int numOfFibo = 1;
        int trackHand = 0;
        int sum = 0;
        while (!d.isEmpty()) {
          Card deal = d.deal();
          hand[trackHand] = deal;
          sum += deal.getValue();
          trackHand++;
          if (isFibo(sum)) {
            numOfFibo++;
            for (int i = 0; i < trackHand; i++) {
              hand[i].show();
            }
            cout << "Fibo: " << sum << endl;
            fill_n(hand, 52, Card());
            sum = 0;
            trackHand = 0;
          }
        }
        for (int i = 0; i < trackHand; i++) {
          hand[i].show();
        }
        cout << endl;
        cout << "Last hand value: " << sum << endl;
        if (isFibo(sum)) {
          cout << "Winner in " << numOfFibo << " piles!\n";
          cout << "Games played: " << games << endl << endl;
          win = true;
        } else if (!isFibo(sum)) {
          cout << "Loser in " << numOfFibo << " piles!\n";
        }
      }
    } else if (input == 6) {
      cout << "Exiting";
      exit = true;
    }
  }
}