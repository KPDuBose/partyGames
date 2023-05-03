#include <RcppArmadillo.h>
#include <random>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

//'Play a game of Monopoly under specific circumstances
//'
//'This function allows you to look at and emulate playing a game of Monopoly
//'with a single player.
//'
//'There are a few assumptions that will be made during this simulation of Monopoly.
//'First, the purpose of this function is to see which spaces are landed on more
//'consistently than others, as such, we assume there is only one player. We won't
//'worry about money or bankruptcy rules.
//'
//'Additionally, whenever the player gets sent to jail, we assume that the player
//'doesn't roll doubles and stays in jail until his third turn.
//'
//'Also note that though the function allows you to throw more than two dice, doubles
//'will only compare the first two dice thrown to see if they are the same.
//'
//'The Chance and Community Chest cards are based on the 2008 Classic version of
//'the game. The board is also based on the US 2008 Classic board, with the fist
//'integer in the vector representing how many times the "Go" space was landed on,
//'the second integer representing how many times "Mediterranean Avenue" was
//'landed on, and so forth until the last integer, which represents "Boardwalk."
//'
//'
//'@name monopoly
//'
//'@usage monopoly(maxTurns, sides, numDice)
//'
//'@param maxTurns An integer representing the max number of turns to be played
//'@param sides An integer representing the size of dice to be rolled. Default is a six sided dice
//'@param numDice The number of dice of size 'sides' to be rolled. Default is two dice
//'
//'@return A matrix representing the number of times
//'@examples
//'#Default Function
//'monopoly()
//'
//'#Play with two 20-sided dice
//'monopoly(500, 20, 2)
//'
//'@seealso
//'References for the \href{https://monopoly.fandom.com/wiki/Monopoly_Board}{board}
//'and for the \href{https://www.monopolyland.com/list-monopoly-chance-community-chest-cards/}{Chance and Community Chest Cards}
//'
//'@export
std::vector<int> diceRoll(int sides, int numDice);

std::vector<int> cards(int numCards){
  std::random_device rd;
  std::mt19937 gen(rd());

  std::vector<int> results(numCards);

  std::uniform_int_distribution<> deck(1, numCards);

  for (int i = 0; i < numCards; i++){
    results[i] = i + 1;
  }

  std::shuffle(results.begin(), results.end(), gen);

  return results;
}

std::vector<int> communityDraw(
  int token,
  int card,
  int count
){
  std::vector<int> result;

  //Cards that change position on the board
  //Move to Go
  if (card == 1){
    return result = {1, count, 0};
  }
  //Go to Jail
  if (card == 6){
    count += 2;
    return result = {11, count, 1};
  }

  //Cards that don't change position on the board
  return result = {token, count, 0};
}

std::vector<int> chanceDraw(
  int token,
  int card,
  int count
){
  std::vector<int> result = {token, count, 0};

  //Set locations of the utility spaces and railroad spaces
  std::vector<int> utility = {13,29};
  std::vector<int> railroads = {6, 16, 26, 36};
  // std::vector<int> closeRail;
  // std::vector<int> closeUtil;

  //Cards that change position

  //Boardwalk
  if (card == 1){
    result[0] = 40;
    return result;
  }

  //Go
  if (card == 2){
    result[0] = 1;
    return result;
  }

  //Illinois Ave
  if (card == 3){
    result[0] = 25;
    return result;
  }

  //St. Charles
  if (card == 4){
    result[0] = 12;
    return result;
  }

  //Nearest Railroads
  if (card == 5 || card == 6){
    //Based on position of chance spaces and position of RailRoads
    if (token == 8){
      result[0] = 16;
      return result;
    }

    if (token == 23){
      result[0] = 26;
      return result;
    }

    if (token == 37){
      result[0] = 6;
      return result;
    }
  }

  //Utilities
  if (card == 7){
    if (token == 8 || token == 37){
      result[0] = utility[0];
      return result;
    }
    else {
      result[0] = utility[1];
      return result;
    }
  }

  //Go back three spaces
  if (card == 10){
    result[0] = token - 3;
    return result;
  }

  //Go to jail
  if (card == 11){
    result[0] = 11;
    result[1] = count + 2;
    result[2] = 1;
    return result;
  }

  //Go to Reading Railroad
  if (card == 14){
    result[0] = 6;
    return result;
  }

  //Cards that don't change position
  return result = {token, count, 0};
}

// [[Rcpp::export]]
std::vector<int> monopoly(
  int maxTurns = 500,
  int sides = 6,
  int numDice = 2
){
  //Initialize and shuffle the Chance and Community decks
  std::vector<int> chance = cards(16);
  std::vector<int> community = cards(16);
  int topChance = 0;
  int topCommunity = 0;
  std::vector<int> communityRes;
  std::vector<int> chanceRes;

  //Track Community Chest and Chance card draws
  std::vector<int> chanceTrack;
  std::vector<int> communityTrack;

  //Set up spaces tracker vector
  std::vector<int> spaceTracker;

  //Turn counter
  int count = 0;
  std::vector<int> countTrack;

  //Double tracker
  int dTrack = 0;
  std::vector<int> dTracker;

  //Token movement
  int token = 1;

  //Dice vector set up
  std::vector<int> dice;
  int roll;

  //final matrix
  arma::mat final(2, 40);

  //Set up turn
  while (count < maxTurns){
    count += 1;
    dTrack = 0;
    // countTrack.push_back(count);

    //Roll the dice
    roll = 0;
    dice = diceRoll(sides, numDice);
    for (int i = 0; i < numDice; i++){
      roll += dice[i];
    }

    token += roll;

    //Check if over 40
    while (token > 40){
      token -= 40;
    }

    //Append to spaceTracker
    spaceTracker.push_back(token);
    // dTracker.push_back(dTrack);

    //Draw a Community Chest card
    if (token == 3 || token == 18 || token == 34){
      if (topCommunity == 16){
        topCommunity -= 16;
      }

      // communityTrack.push_back(community[topCommunity]);

      communityRes = communityDraw(
        token,
        community[topCommunity],
        count);

      token = communityRes[0];
      count = communityRes[1];

      topCommunity += 1;

      if (communityRes[2] == 1){
        //Append to spaceTracker
        spaceTracker.push_back(token);
        continue;
      }
    }

    //Draw a Chance card
    if (token == 8 || token == 23 || token == 37){
      if (topChance == 16){
        topChance -= 16;
      }

      // chanceTrack.push_back(chance[topChance]);

      chanceRes = chanceDraw(
        token,
        chance[topChance],
        count
      );

      token = chanceRes[0];
      count = chanceRes[1];

      topChance += 1;

      if (chanceRes[2] == 1){
        //Append to spaceTracker
        spaceTracker.push_back(token);
        continue;
      }
    }

    //Check if rolled doubles
    while (dice[0] == dice[1] && dTrack != 3){
      dTrack += 1;
      // dTracker.push_back(dTrack);

      //Check if third double rolled
      if (dTrack == 3){
        token = 11;
        spaceTracker.push_back(token);
        count += 2; //Misses turns due to being in jail
        break;
      }

      //Roll the dice
      roll = 0;
      dice = diceRoll(sides, numDice);
      for (int i = 0; i < numDice; i++){
        roll += dice[i];
      }

      token += roll;

      //Check if over 40
      while (token > 40){
        token -= 40;
      }

      //Append to spaceTracker
      spaceTracker.push_back(token);

      //Draw a Community Chest card (For Doubles)
      if (token == 3 || token == 18 || token == 34){
        if (topCommunity == 14){
          topCommunity -= 14;
        }

        // communityTrack.push_back(community[topCommunity]);

        communityRes = communityDraw(
          token,
          community[topCommunity],
                   count);

        token = communityRes[0];
        count = communityRes[1];

        topCommunity += 1;

        if (communityRes[2] == 1) {
          //Append to spaceTracker
          spaceTracker.push_back(token);
          break;
        }

      }

      //Draw a Chance card
      if (token == 8 || token == 23 || token == 37){
        if (topChance == 16){
          topChance -= 16;
        }

        // chanceTrack.push_back(chance[topChance]);

        chanceRes = chanceDraw(
          token,
          chance[topChance],
                count
        );

        token = chanceRes[0];
        count = chanceRes[1];

        topChance += 1;

        if (chanceRes[2] == 1){
          //Append to spaceTracker
          spaceTracker.push_back(token);
          break;
        }
      }
    }
  }

  int n = spaceTracker.size();

  // std::vector<int> spaceTrackVec = as<arma::vec>(wrap(spaceTracker));

  std::vector<int> spaces(40);
  for (int j = 0; j < 40; j++){
    for (int k = 0; k < n; k++){
      if (spaceTracker[k] == j + 1){
        spaces[j] += 1;
      }
    }
  }


  // for (int i = 0; i < 40; i++){
  //   final(0, i) = i + 1;
  //
  // }
  //
  // for (int j = 0; j < 40; j++){
  //   final(1, j) = spaces(j);
  // }
  //
  // std::vector<int> actfinal(40);
  //
  // for (int i = 0; i < 40; i++){
  //   actfinal[i] = final.row(1)[i];
  // }

  // int doubles = sum(dTracker);

  return spaces;
}







