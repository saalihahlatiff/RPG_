#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character{
private:
  int totalXP, attackXP, attackedXP, defenseXP, defendedXP;
  string attackGraphics, defenseGraphics, name;
public:
  Character(); 
  void SetAttackGraphics(string);
  string GetAttackGraphics(); //prints "Slash! (0-0)/"

  void SetAttackXP(int);
  int GetAttackXP();     

  void SetAttackedXP(int);
  int GotAttacked();    //prints  "Ow" and XP lost. Also subtracts XP from total

  void SetDefenseGraphics(string);
  string GetDefenseGraphics();    

  void SetDefenseXP(int);
  int GetDefenseXP();

  void SetDefendedXP(int i);
  int DefendedXP();

  void UpdateXP(int i);
  int ReturnTotalXP();

  void SetName(string);
  string GetName();
};

#endif