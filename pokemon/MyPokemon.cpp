//==============================================================
//    MyPokemon.cpp
//==============================================================
// Sasha Ashtiani
// 10/16/2016

#include "MyPokemon.h"

//Default Constructor
MyPokemon::MyPokemon() {
	m_Num = 0;
	m_Name = " ";
	m_CP = 0;
	m_HP = 0;
	m_Rarity = 0;
}

//Overload Contructor
MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity) {
	m_Num = num;
	m_Name = name;
	m_CP = cp;
	m_HP = hp;
	m_Rarity = rarity;
}

//Accessors
int MyPokemon::GetCP() {
	return m_CP;
}

int MyPokemon::GetHP() {
	return m_HP;
}

int MyPokemon::GetRarity() {
	return m_Rarity;
}

string MyPokemon::GetName() {
	return m_Name;
}

int MyPokemon::GetNum() {
	return m_Num;
}

//Mutators
void MyPokemon::SetRarity(int newRarity) {
	m_Rarity = newRarity;
}

void MyPokemon::SetName(string newName) {
	m_Name = newName;
}

void MyPokemon::SetCP(int newCP) {
	m_CP = newCP;
}

void MyPokemon::SetHP(int newHP) {
	m_HP = newHP;
}

void MyPokemon::Train() {
	m_CP += 10;
}