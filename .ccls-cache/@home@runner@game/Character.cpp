#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(){
  totalXP = 50;
}

void Character::SetAttackGraphics(string s){
  attackGraphics = s;
} 
string Character::GetAttackGraphics(){
  return attackGraphics;
}

void Character::SetAttackXP(int i){
  attackXP = i;
}
int Character::GetAttackXP(){
  UpdateXP(attackedXP);
  return attackedXP;
}       

void Character::SetAttackedXP(int i){
  attackedXP = i;
}
int Character::GotAttacked(){ //says "got attacked" & updates totalXP
  UpdateXP(attackedXP);
  return attackedXP;
}

void Character::SetDefenseGraphics(string s){
  defenseGraphics = s;
}
string Character::GetDefenseGraphics(){
  return defenseGraphics;
}

void Character::SetDefenseXP(int i){
  defenseXP = i;
}
int Character::GetDefenseXP(){
  UpdateXP(defenseXP);
  return defenseXP;
}

void Character::SetDefendedXP(int i){
  defendedXP = i;
}
int Character::DefendedXP(){
  UpdateXP(defendedXP);
  return defendedXP;
}

void Character::UpdateXP(int i){
  totalXP += i;
}
int Character::ReturnTotalXP(){
  return totalXP;
}

void Character::SetName(string s){
  name = s;
}
string Character::GetName(){
  return name;
}