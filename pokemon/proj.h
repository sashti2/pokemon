//==============================================================
//    proj.h
//==============================================================
// Sasha Ashtiani
// 10/16/2016

#include "Pokemon.h"
#include "MyPokemon.h"
#include <iostream>     /* cout, cin */
#include <vector>       /* vector */
#include <string>       /* string */
#include <fstream>      /* fstream, ifstream, ofstream */
#include <iomanip>      /* setw, setfill, etc */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

//Constants
const int POKECOUNT = 151;
const char POKEDEX[12] = "pokeDex.txt";
const char MYCOLLECTION[18] = "myCollection.txt";

//Loads the complete pokemon list from file & returns a populated pokeDex vector
void getPokeDex(vector <Pokemon> &pokeDex);

//Loads the user's pokemon collection from file & returns a populated myCollection vector
void getMyCollection(vector <MyPokemon> &myCollection);

//Takes in user's collection and the pokeDex vector & tries to find a random pokemon based on that rarity
void catchPokemon(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection);

//Takes in pokeDex vector & prints num and name of each pokemon in vector
void printPokeDex(vector <Pokemon> &pokeDex);

//Takes in myCollection vector & prints num, name, CP, HP, rarity of each pokemon in vector
void printMyCollection(vector <MyPokemon> &myCollection);

//After a pokemon is found, rarity is passed into this
//Randomly selects a pokemon with matching rarity from pokeDex to add into user's collection
void foundPokemon(int rarity, vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection);

//Takes in vector pokeDex and vector myCollection & calls a variety of functions based on user
void mainMenu(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection);

//Takes in both pokeDex and myCollection & randomly chooses an enemy
//Sets enemy CP as random number between minCP and maxCP
//Mentions battle is won or lost & returns to mainMenu
void battlePokemon(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection);

//Takes in both pokeDex and myCollection & calls Train member function that increases CP by 10
//Updates myCollection
void trainPokemon(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection);

//Calls saveMyCollection and exits application
void exitPokemon(vector <MyPokemon> &myCollection);

//Takes in vector of user's pokemon & saves a file with each Pokemon with number, name, CP, HP, rarity
void saveMyCollection(vector <MyPokemon> &myCollection);