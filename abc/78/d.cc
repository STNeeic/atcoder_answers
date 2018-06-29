#include <iostream>
#include <vector>
#include <algorithm>

int get_score(int x, int y) {
  return std::abs(x - y);
}

int main(void) {
  int N, Z, W;
  std::cin >> N >> Z >> W;
  std::vector<int> deck(N);
  for (int i = 0; i < N; i++) {
    std::cin >> deck[N - i - 1];
  }
  
  int score = (W - deck[0]);
  if(score < 0) score *= -1;

  if(N > 1) score = std::max(score , get_score(deck[0], deck[1]));


  std::cout << score << std::endl;
  /*
  std::reverse(deck.begin(), deck.end());

  int X = Z;
  int Y = W;
  int score = get_score(X, Y);

  int turn = 0; //0 == X turn, 1 == Y turn

  int size = deck.size();
  int target_id = 0;
  while(size > 1) {
    for(int i = 0; i < size; i++) {
      int card = deck[i];
      if(turn == 0) {
        //X turn
        
      }
    }
    }*/
  return 0;
}
