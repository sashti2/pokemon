//==============================================================
//    proj2.cpp
//==============================================================
// Sasha Ashtiani
// 10/16/2016

#include "proj.h"
#include "Pokemon.h"
#include "MyPokemon.h"

using namespace std;

int main() {

	//Seed RNG
	srand(time(NULL));

	//Create PokeDex vector
	vector <Pokemon> pokeDex;
	//Create vector for my collection
	vector <MyPokemon> myCollection;

	//Fill pokeDex vector
	getPokeDex(pokeDex);

	//Fill myCollection vector
	getMyCollection(myCollection);

	//Main menu
	mainMenu(pokeDex, myCollection);

	//Save to myCollection
	exitPokemon(myCollection);

	return 0;
}

void getPokeDex(vector <Pokemon> &pokeDex) {

	int num;
	string name;
	int cpMin;
	int cpMax;
	int rarity;

	//Open pokeDex.txt
	ifstream inFile("pokeDex.txt");

	//Loop into vector
	while (inFile >> num >> name >> cpMin >> cpMax >> rarity) {

		Pokemon p(num, name, cpMin, cpMax, rarity);

		pokeDex.push_back(p);
	}

	//Close pokeDex.txt
	inFile.close();
}

void getMyCollection(vector <MyPokemon> &myCollection) {

	int num;
	string name;
	int cp;
	int hp;
	int rarity;

	//Open myCollection.txt
	ifstream inFile("myCollection.txt");

	//Loop into vector
	while (inFile >> num >> name >> cp >> hp >> rarity) {

		MyPokemon p(num, name, cp, hp, rarity);

		myCollection.push_back(p);
	}

	//Close myCollection.txt
	inFile.close();
}

void mainMenu(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection) {

	int ans = 0;

	//Loop until user chooses 6 for 'exit'
	while (ans != 6) {

		cout << endl;
		cout << "What would you like to do?:" << endl;
		cout << "1. See the PokeDex" << endl;
		cout << "2. See your collection" << endl;
		cout << "3. Search for a new Pokemon" << endl;
		cout << "4. Battle your Pokemon" << endl;
		cout << "5. Train your Pokemon" << endl;
		cout << "6. Exit" << endl << endl;
		cin >> ans;

		if (ans == 1) {

			printPokeDex(pokeDex);
			ans = 0;
		}

		else if (ans == 2) {
			printMyCollection(myCollection);
			ans = 0;
		}

		else if (ans == 3) {

			catchPokemon(pokeDex, myCollection);
			ans = 0;
		}

		else if (ans == 4) {

			battlePokemon(pokeDex, myCollection);
			ans = 0;
		}

		else if (ans == 5) {

			trainPokemon(pokeDex, myCollection);
			ans = 0;
		}

		//If invalid choice
		else if (ans != 6) {

			cout << endl;
			cout << "Sorry, please try again." << endl;
			ans = 0;
		}

		else;
	}
}

void printPokeDex(vector <Pokemon> &pokeDex) {

	//Print out pokeDex
	cout << endl;
	for (int i = 0; i < (int)pokeDex.size(); i++) {

		cout << pokeDex[i].GetNum() << " " << pokeDex[i].GetName() << endl;
	}
}

void printMyCollection(vector <MyPokemon> &myCollection) {

	//Print out myCollection
	cout << endl;
	for (int i = 0; i < (int)myCollection.size(); i++) {

		cout << i + 1 << ". " << myCollection[i].GetNum() << " " << myCollection[i].GetName() << " " << myCollection[i].GetCP\
			() << " " << myCollection[i].GetHP() << " " << myCollection[i].GetRarity() << endl;
	}
}

void catchPokemon(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection) {

	int rarity;
	int numR;

	//Menu
	cout << endl;
	cout << "What type of Pokemon would you like to try and catch?:" << endl;
	cout << "1. Very Common (Very High Probability)" << endl;
	cout << "2. Common (High Probability)" << endl;
	cout << "3. Uncommon (Normal Probability)" << endl;
	cout << "4. Rare (Low Probability)" << endl;
	cout << "5. Ultra Rare (Extremely Low Probability)" << endl;
	cin >> rarity;

	cout << endl;
	cout << "You start to search..." << endl;

	//Very common
	if (rarity == 1) {

		numR = rand() % 100 + 1;

		if (numR <= 65) {

			foundPokemon(rarity, pokeDex, myCollection);
		}

		else {

			cout << "There seems to be nothing here." << endl;
		}
	}

	//Common
	else if (rarity == 2) {

		numR = rand() % 100 + 1;

		if (numR <= 45) {

			foundPokemon(rarity, pokeDex, myCollection);
		}

		else {

			cout << "There seems to be nothing here." << endl;
		}
	}

	//Uncommon
	else if (rarity == 3) {

		numR = rand() % 100 + 1;

		if (numR <= 25) {

			foundPokemon(rarity, pokeDex, myCollection);
		}

		else {

			cout << "There seems to be nothing here." << endl;
		}
	}

	//Rare
	else if (rarity == 4) {

		numR = rand() % 100 + 1;

		if (numR <= 10) {

			foundPokemon(rarity, pokeDex, myCollection);
		}

		else {

			cout << "There seems to be nothing here." << endl;
		}
	}

	//Ultra rare
	else if (rarity == 5) {

		numR = rand() % 100 + 1;

		if (numR == 1) {

			foundPokemon(rarity, pokeDex, myCollection);
		}

		else {

			cout << "There seems to be nothing here." << endl;
		}
	}

	else;
}

void foundPokemon(int rarity, vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection) {

	//RNG
	int numR = rand() % POKECOUNT + 1;
	//Loop until Pokemon of same rarity is found
	while (rarity != pokeDex[numR].GetRarity()) {
		numR = rand() % POKECOUNT + 1;
	}

	//When found
	cout << endl;
	cout << "Congrats! You found a " << pokeDex[numR].GetName() << endl;

	//Add to myCollection vector
	//myCollection.push_back(numR);
}

void battlePokemon(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection) {

	cout << "Coming soon." << endl;
}

void trainPokemon(vector <Pokemon> &pokeDex, vector <MyPokemon> &myCollection) {

	//Ask user for which Pokemon to train
	int ans;

	cout << endl;
	cout << "Which of your Pokemon would you like to train?";

	for (int i = 0; i < (int)myCollection.size(); i++) {

		cout << i + 1 << ". " << myCollection[i].GetNum() << " " << myCollection[i].GetName() << " " << myCollection[i].GetCP\
			() << " " << myCollection[i].GetHP() << " " << myCollection[i].GetRarity() << endl;
	}

	cin >> ans;
	ans -= 1;

	//Increase CP by 10
	//myCollection[ans].GetCP() += 10;
}

void exitPokemon(vector <MyPokemon> &myCollection) {

	saveMyCollection(myCollection);
}

void saveMyCollection(vector <MyPokemon> &myCollection) {

	//cout << "Coming soon." << endl;
	ifstream outFile;

	outFile.open("mycollection.txt");

	/*for (int i = 0; i < (int) myCollection.size(); i++) {

	outFile << myCollection[i].GetNum() << " " << myCollection[i].GetName() << " " << myCollection[i].GetCP() << " " <<\
	myCollection[i].GetHP() << " " << myCollection[i].GetRarity() << endl;
	}
	*/
	outFile.close();
	cout << "File saved." << endl;
	cout << "Thank you for playing!" << endl;
}