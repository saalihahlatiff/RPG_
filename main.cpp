#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Character.h"

using namespace std;

ifstream inFS;            //file where game is opened from and saved (input)
string filename = "save.txt";
char userInput;
bool isValid = true; 

Character player;
Character opp;

/*
struct NameAndXP{
    int userXP, oppontXP;
    string name;
};



void actions(){
    Character player;
    Act act;
    NameAndXP effect;

    player.knight.act.attack.effect.name = "Slash!";
    player.knight.act.attack.effect.userXP = -5;
    player.knight.act.attack.effect.oppontXP = -15;

    player.knight.act.defend.effect.name = "Shield!";
    player.knight.act.defend.effect.userXP = 0;
    player.knight.act.defend.effect.oppontXP = -10;


    player.mage.act.attack.name = "Attack Spell!";
    player.mage.act.attack.effect.userXP = -5;
    player.mage.act.attack.effect.oppontXP = -15;

    player.mage.act.defend.effect.name = "Healing Spell!";
    player.mage.act.defend.effect.userXP = +8;
    player.mage.act.defend.effect.oppontXP = 0;


    player.ninja.act.attack.name = "Ninja stars!";
    player.ninja.act.attack.effect.userXP = -2;
    player.ninja.act.attack.effect.oppontXP = -15;

    player.ninja.act.defend.effect.name = "Dodge!";
    player.ninja.act.defend.effect.userXP = +2;
    player.ninja.act.defend.effect.oppontXP = -10;
  
}
*/

//ALL FUNCTIONS
void Error();
char getUserInput();
void MenuInput();
void OpenNewGameSubMenu();
void OpenCharacterPage();
void OpenPlayGuide();
void GetUserAction();
void GetOpponentPlayer();
void GetOpponentAction();

void LoadNewGame();
int LoadSavedGame();
void SaveGame();


//GENERAL FUNCTIONS
void Error(){
  cout << "Incorrect input. Try again" << endl;
  getUserInput();
}

char getUserInput(){
  cin >> userInput; 
  userInput = toupper(userInput);
  return userInput;
}

void PrintOpening(string str){
  cout << "opening... " << str << endl << endl;
  //return 0;
}

void PrintTest(){
  cout << "testing... input: " << userInput << endl << endl; 
  //return 0;
}

//FUNCTIONS FOR MENU
void MenuInput(){
  cout << "(A) New Game, (B) Resume Saved Game, (C) How to Play " << endl;
  getUserInput();
  PrintTest();

  isValid = true;
  while(isValid){
  if(userInput == 'A'){isValid = false; OpenNewGameSubMenu();}
  else if(userInput == 'B'){isValid = false; LoadSavedGame();}
  else if(userInput == 'C'){isValid = false; OpenPlayGuide();}
  else{Error(); }
  }

}

void OpenNewGameSubMenu(){
  cout << " Choose a player: (A) Knight, (B) Mage, (C) Ninja " << endl;

  getUserInput();
  PrintTest();

  isValid = true;
  while(isValid){
    if(userInput == 'A' || userInput == 'B' || userInput == 'C'){ 
      isValid = false;
      PrintOpening("character page");
      OpenCharacterPage();
    }
    else{Error();}
  }

}

void OpenCharacterPage(){

  cout << "You picked character: ";

  if(userInput == 'A'){
    cout << "knight";
    player.SetAttackGraphics("Slash!");
    player.SetAttackXP(-5);
    opp.SetAttackedXP(-15);
    player.SetDefenseGraphics("Shield!");
    player.SetDefenseXP(0);
    opp.SetDefendedXP(-10);
  }  
  else if(userInput == 'B'){
    cout << "mage";
    player.SetAttackGraphics("Attack Spell!");
    player.SetAttackXP(-5);
    opp.SetAttackedXP(-15);
    player.SetDefenseGraphics("Healing Spell!");
    player.SetDefenseXP(8);
    opp.SetDefendedXP(0);
  }
  else if(userInput == 'C'){
    cout << "ninja";
    player.SetAttackGraphics("Ninja stars!");
    player.SetAttackXP(-2);
    opp.SetAttackedXP(-15);
    player.SetDefenseGraphics("Dodge!");
    player.SetDefenseXP(2);
    opp.SetDefendedXP(-10);
  }
  cout << endl;

  cout << "(A) Continue to Game, (B) Go Back" << endl;
  getUserInput();

  isValid = true;
  while(isValid){
    if(userInput == 'A'){isValid = false; cout << endl; LoadNewGame();}
    else if(userInput == 'B'){isValid = false; OpenNewGameSubMenu();}
    else{ Error();}
  }

}

void OpenPlayGuide(){
    cout << "How to Play" << endl
         << "(A) Go Back" << endl;
  
  getUserInput();
  isValid = true;
  while(isValid){
    if(userInput == 'A'){isValid = false; PrintOpening("menu"); MenuInput();}
    else{Error();}
  }
}

//FUNCTIONS FOR GAME ACTIONS
void GetUserAction(){
  cout << "Choose your action: (A) Attack, (B) Defend" << endl;
  getUserInput();
  
  isValid = true;
  while(isValid){
    if(userInput == 'A'){
      isValid = false; 
      cout << "You chose attack" << endl << player.GetAttackGraphics() << endl
           << "  -" << player.GetAttackXP() << "             "
           << "-" << opp.GotAttacked() << endl;
    }
    else if(userInput == 'B'){
      isValid = false; 
      cout << "You chose defend" << endl << player.GetDefenseGraphics() << endl
           << "  -" << player.GetDefenseXP() << "             "
           << "-" << opp.DefendedXP() << endl;
    }
    else{Error();}
  }
}

void GetOpponentPlayer(){
  srand(time(0));
  int num = rand() % 3;
  
  if(num == 0){ 
    opp.SetName("The Goblin");
    opp.SetAttackGraphics("Swing!");
    opp.SetAttackXP(-3);
    player.SetAttackedXP(-10);
    opp.SetDefenseGraphics("Run away!");
    opp.SetDefenseXP(-8);
    player.SetDefendedXP(0);
  }
  else if(num == 1){
    opp.SetName("The Evil Wizard");
    opp.SetAttackGraphics("Mind control!");
    opp.SetAttackXP(-5);
    player.SetAttackedXP(-20);
    opp.SetDefenseGraphics("Invisiblity cloak!");
    opp.SetDefenseXP(-10);
    player.SetDefendedXP(-15);
  }
  else if(num == 2){
    opp.SetName("Boxer");
    opp.SetAttackGraphics("Jab!");
    opp.SetAttackXP(-4);
    player.SetAttackedXP(-10);
    opp.SetDefenseGraphics("Block!");
    opp.SetDefenseXP(0);
    player.SetDefendedXP(-7);
  }
  cout << "Your opponent, " << opp.GetName() << ", has appeared!"<< endl;
}

void GetOpponentAction(){
  srand(time(0));
  int num = rand() % 2;

  cout << opp.GetName();
  if(num == 0){
    cout << " attacked you" << endl << opp.GetAttackGraphics() << endl
         << "  -" << player.GotAttacked() << "             "
         << "-" << opp.GetAttackXP() << endl;
  }
  else if(num == 1){
    cout << " defended" << endl << opp.GetDefenseGraphics() << endl
         << "  -" << player.DefendedXP() << "             "
         << "-" << opp.GetDefenseXP() << endl;
  }
  else{ cout << "Error:" << num; }
}

void PrintTotalXPs(){
  cout << "Your XP: " << player.ReturnTotalXP() << "             " 
       << opp.GetName() << " XP: " << opp.ReturnTotalXP() << endl;
}

void GamePlay(){
  while(player.ReturnTotalXP() > 0 && opp.ReturnTotalXP() > 0){
    PrintTotalXPs();
    cout << endl;
    GetUserAction();
    cout << endl;
    PrintTotalXPs();
    cout << endl;
    GetOpponentAction();
    cout << endl;
  }
  PrintTotalXPs();
}

//FUNCTIONS FOR I/O

void LoadNewGame(){
  //cout << "this is the start new game" << endl
  //     << "loading opponent.." << endl;
  GetOpponentPlayer();
  cout << endl;
  GamePlay();
}

int LoadSavedGame(){
    cout << "Opening list of saved games..." << endl;

    inFS.open("save.txt");
    if (!(inFS.is_open())){ cout << "ERROR: Could not open file" << endl; 
      return 1;
    }

    if(inFS.peek() == std::ifstream::traits_type::eof()){ cout << "No saved games" << endl; return 0;}
    else{
        //output usernames of the files saved then allow the user to pick a file;
      cout << "File is NOT empty";
      return 0;
    }
  
//return 0;
};

void SaveGame(){
    //save username, character type and xp;
    //fin << c;
    cout << "Closing file " << endl;
    inFS.close(); // Done with file, so close it
  //return 0;
}


int main(){
  string username;
  cout << "Enter Username: " << endl;
  cin >> username;

  cout << "Hi " << username << "!" << endl << endl;

  int xp;
  MenuInput(); //function that gets username, character option, etc.

  cout << "WE'RE BACK IN INT MAIN ";


  
  if(userInput == 'Q'){
    cout << " Would you like to save the game? " << endl
         << "(A) Yes, (B) No" << endl;
    cin >> userInput;
    if(userInput == 'A'){SaveGame();}
    //else if(userInput == 'B'){break;}
    else{Error();}
  }

  inFS.close();

  return 0;
}