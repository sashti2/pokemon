//==============================================================
//    Pokemon.h
//==============================================================
// Sasha Ashtiani
// 10/16/2016

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Pokemon {
public:
	//Constructors
	Pokemon();
	Pokemon(int num, string name, int cpMin, int cpMax, int rarity);

	//Accessors
	int GetCPMin();
	int GetCPMax();
	int GetRarity();
	string GetName();
	int GetNum();

	//Mutators
	void SetRarity(int newRarity);
	void SetName(string newName);
	void SetCP(int newCP);
	void Train();
private:
	int m_Num;
	string m_Name;
	int m_MinCP;
	int m_MaxCP;
	int m_Rarity;
};

#endif