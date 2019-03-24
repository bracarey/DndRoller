#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

int StrengthMod;
int DexterityMod;
int ConstitutionMod;
int IntelligenceMod;
int WisdomMod;
int CharismaMod;
int Health;
int Strength;
int Dexterity;
int Constitution;
int Intelligence;
int Wisdom;
int Charisma;
int size = 6;
int rolls[6];
string Name;
string PlayerRace;
string PlayerClass;

int race (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma, int Health);
int d12 (int mod);
int d10 (int mod);
int d6 (int mod);
int modifier (double a);
int diceRoll ();
void RaceRoll();
void RaceOut(int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma, int Health, int StrengthMod, int DexterityMod, int ConstitutionMod, int IntelligenceMod, int WisdomMod, int CharismaMod) ;
void barbarian (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void bard (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void cleric (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void druid (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void fighter (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void monk (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void paladin (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void ranger (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void rogue (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void sorcerer (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void warlock (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);
void wizard (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma);

int main (){
srand ((int) time (NULL));
    int playerClass;
    cout << "Hello, and thank you for choosing my 5th Edition Dungeons and Dragons Character Generator. Lets start by having you name your new character. \n";
    cin>> Name;
    cout << "Now, Lets choose your class. You can choose from: 1 for Barbarian, 2 for Bard, 3 for Cleric, 4 for Druid, 5 for Fighter, 6 for Monk, "<<
        "7 for Paladin, 8 for Ranger, 9 for Rogue, 10 for Sorcerer, 11 for Warlock, 12 for Wizard.\n";
    cin >> playerClass;
    if (playerClass == 1)
    {
        PlayerClass = "Barbarian";
        barbarian (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 2)
    {
        PlayerClass = "Bard";
        bard (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 3)
    {
        PlayerClass = "Cleric";
        cleric (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 4)
    {
        PlayerClass = "Druid";
        druid (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 5)
    {
        PlayerClass = "Fighter";
        fighter (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 6)
    {
        PlayerClass = "Monk";
        monk (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 7)
    {
        PlayerClass = "Paladin";
        paladin (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 8)
    {
        PlayerClass = "Ranger";
        ranger (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 9)
    {
        PlayerClass = "Rogue";
        rogue (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 10)
    {
        PlayerClass = "Sorcerer";
        sorcerer (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else if (playerClass == 11)
    {
        PlayerClass = "Warlock";
        warlock (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    else
    {
        PlayerClass = "Wizard";
        wizard (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma);
    }
    return 0;
}

int d12 (int mod){
    int Health = 12 + mod;	//((rand() % 12) + 1) + mod; Left in for the future expansion of this project.
    return Health;
}

int d10 (int mod){
  int Health = 10 + mod;	//((rand() % 10) + 1) + mod; Left in for the future expansion of this project.
  return Health;
}

int d8 (int mod){
  int Health = 8 + mod;		//((rand() % 8) + 1) + mod; Left in for the future expansion of this project.
  return Health;
}

int d6 (int mod){
  int Health = 6 + mod;		//((rand() % 6) + 1) + mod; Left in for the future expansion of this project.
  return Health;
}

int modifier (double a) { //Figures out the ability score modifier
  return floor ((a - 10) / 2);
}

int diceRoll (){
    int psize = 4;
    int stat = 6;
    int i, j, temp;
    int dice[4];
    int sum;
    int rolls[6];
    dice[0] = ((rand () % 6) + 1);
    dice[1] = ((rand () % 6) + 1);
    dice[2] = ((rand () % 6) + 1);
    dice[3] = ((rand () % 6) + 1);
    for (i = 0; i < psize; i++)
    {
        for (j = i + 1; j < psize; j++)
        {
            if (dice[j] < dice[i])
            {
                temp = dice[i];
                dice[i] = dice[j];
                dice[j] = temp;
            }
        }
    }
    sum = dice[1] + dice[2] + dice[3];
    cout << "The sum for your roll, dropping the lowest is : " << sum << "\n" ;
    return sum;
}

void RaceRoll(){
    int stats[6];
    int temp1;
    for (int i = 0; i < size; i++)
    {
      rolls[i] = diceRoll ();
    }
    cout << "Your stat poll is: " << rolls[0] << ", " << rolls[1] << ", " << rolls[2] << ", " << rolls[3] << ", " << rolls[4] << ", " << rolls[5] << "\n \n";
    for (int a = 0; a < size; a++)
    {
        for (int b = a + 1; b < size; b++)
        {
            if (rolls[b] < rolls[a])
            {
                temp1 = rolls[a];
                rolls[a] = rolls[b];
                rolls[b] = temp1;
            }
        }
    }
    cout << "Your sorted stat pool is :" << rolls[0] << ", " << rolls[1] << ", " << rolls[2] << ", " << rolls[3] << ", " << rolls[4] << ", " << rolls[5] << "\n \n";
}

void RaceOut(int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma, int Health, int StrengthMod, int DexterityMod, int ConstitutionMod, int IntelligenceMod, int WisdomMod, int CharismaMod) {
    cout << "Before racial bonuses your stats are: \n" <<
    "    Your Strength is " << Strength << ", with a modifier of " <<StrengthMod << ".\n" <<
    "    Your Dexterity is " << Dexterity << ", with a modifier of " << DexterityMod << ".\n" <<
    "    Your Constitution is " << Constitution << ", with a modifier of " << ConstitutionMod << ".\n" <<
    "    Your Intelligence is " << Intelligence << ", with a modifier of " << IntelligenceMod << ".\n" <<
    "    Your Wisdom is " << Wisdom << ", with a modifier of " << WisdomMod << ".\n" <<
    "    Your Charisma is " << Charisma << ", with a modifier of " <<CharismaMod << ".\n" <<
    "    You start with " << Health <<" max hit-points. \n";
    race (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health);
    }

void barbarian (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[5];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[0];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[2];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[1];
    CharismaMod = modifier (Charisma);
    Health = d12 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void bard (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[2];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[1];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[5];
    CharismaMod = modifier (Charisma);
    Health = d8 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void cleric (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[1];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[5];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[2];
    CharismaMod = modifier (Charisma);
    Health = d8 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void druid (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[2];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[5];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[1];
    CharismaMod = modifier (Charisma);
    Health = d8 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void fighter (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[5];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[2];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[0];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[3];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[1];
    CharismaMod = modifier (Charisma);
    Health = d10 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void monk (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[2];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[5];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[0];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[3];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[1];
    CharismaMod = modifier (Charisma);
    Health = d8 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void paladin (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[5];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[1];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[3];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[0];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[2];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[4];
    CharismaMod = modifier (Charisma);
    Health = d10 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void ranger (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[5];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[2];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[3];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[1];
    CharismaMod = modifier (Charisma);
    Health = d10 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void rogue (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[5];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[1];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[2];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[3];
    CharismaMod = modifier (Charisma);
    Health = d8 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void sorcerer (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[1];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[2];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[5];
    CharismaMod = modifier (Charisma);
    Health = d6 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void warlock (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[2];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[1];
    WisdomMod = modifier (Wisdom);Charisma = rolls[5];
    CharismaMod = modifier (Charisma);
    Health = d8 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}

void wizard (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma){
    RaceRoll();
    Strength = rolls[0];
    StrengthMod = modifier (Strength);
    Dexterity = rolls[3];
    DexterityMod = modifier (Dexterity);
    Constitution = rolls[4];
    ConstitutionMod = modifier (Constitution);
    Intelligence = rolls[5];
    IntelligenceMod = modifier (Intelligence);
    Wisdom = rolls[2];
    WisdomMod = modifier (Wisdom);
    Charisma = rolls[1];
    CharismaMod = modifier (Charisma);
    Health = d6 (ConstitutionMod);
    RaceOut(Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, Health, StrengthMod, DexterityMod, ConstitutionMod, IntelligenceMod, WisdomMod, CharismaMod);
}
int race (int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma, int Health){
    int playerRace;
    int subRace;
    cout << "Now, lets choose your race. You can choose from the following: 1 for Human, 2 for Elf, 3 for Dwarf, 4 for Halfling, 5 for Gnome, 6 for Half-Orc, 7 for Dragonborn, or 8 for Tiefling.\n";
    cin >> playerRace;
    if (playerRace == 1)		//Human
    {
        PlayerRace = "Human";
        Strength++;
        Dexterity++;
        Constitution++;
        Intelligence++;
        Wisdom++;
        Charisma++;
    }
    else if (playerRace == 2)	//Elf
    {
        cout << "Which sub race would you like to be: 1 for Drow, 2 for High, or 3 for Wood? \n";
        cin >> subRace;
        if (subRace == 1)		//Drow
        {
            Dexterity = Dexterity + 2;
            PlayerRace = "Drow (Dark Elf)";
            Charisma++;
        }
        else if (subRace == 2)	//high
        {
            Dexterity = Dexterity + 2;
            PlayerRace = "High Elf";
            Intelligence++;
        }
        else			//wood
        {
            Dexterity = Dexterity + 2;
            PlayerRace = "Wood Elf";
            Wisdom++;
        }
    }
    else if (playerRace == 3)
    {
        cout <<"Which sub race would you like to be: 1 for Hill, or 2 for Mountain? \n";
        cin >> subRace;
        if (subRace = 1)
        {
            Constitution = Constitution + 2;
            PlayerRace = "Hill Dwarf";
            Wisdom++;
        }
        else
        {
            Strength = Strength + 2;
            PlayerRace ="Mountain Dwarf";
            Constitution = Constitution + 2;
        }
    }
    else if (playerRace == 4)
    {
        cout << "Which sub race would you like to be: 1 for Lightfoot, or 2 for Stout? \n";
        cin >> subRace;
        if (subRace == 1)
        {
            Dexterity = Dexterity + 2;
            PlayerRace = "Lightfoot Halfling";
            Wisdom++;
        }
        else
        {
            Dexterity = Dexterity + 2;
            PlayerRace = "Stout Halfling";
            Constitution++;
        }
    }
    else if (playerRace == 5)
    {
        Constitution++;
        PlayerRace ="Gnome";
        Intelligence = Intelligence + 2;
    }
    else if (playerRace == 6)
    {
        Strength = Strength + 2;
        PlayerRace ="Half-Orc";
        Constitution++;
    }
    else if (playerRace == 7)
    {
        Strength = Strength + 2;
        PlayerRace ="Dragonborn";
        Charisma++;
    }
    else				//Tiefling
    {
        Intelligence++;
        PlayerRace ="Teifling";
        Charisma = Charisma + 2;
    }
    StrengthMod = modifier (Strength);
    DexterityMod = modifier (Dexterity);
    ConstitutionMod = modifier (Constitution);
    IntelligenceMod = modifier (Intelligence);
    WisdomMod = modifier (Wisdom);
    CharismaMod = modifier (Charisma);

    cout << "You are " << Name << ", the "<< PlayerRace << " "<< PlayerClass << "\n After racial bonuses your stats are: \n" <<
            "    Your Strength is " << Strength << ", with a modifier of " << StrengthMod << ".\n" <<
            "    Your Dexterity is " << Dexterity << ", with a modifier of " << DexterityMod << ".\n" <<
            "    Your Constitution is " << Constitution << ", with a modifier of " << ConstitutionMod << ".\n" <<
            "    Your Intelligence is " << Intelligence << ", with a modifier of " << IntelligenceMod << ".\n" <<
            "    Your Wisdom is " << Wisdom << ", with a modifier of " << WisdomMod << ".\n" <<
            "    Your Charisma is " << Charisma << ", with a modifier of " << CharismaMod << ".\n" <<
            "    Your starting Max Hit-points are " << Health + ConstitutionMod <<". \n \n";

    ofstream myfile;
    myfile.open("Character Rolls.txt", ios::app);
    myfile << "You are " << Name << ", the "<< PlayerRace << " "<< PlayerClass << "\n After racial bonuses your stats are: \n" <<
            "    Your Strength is " << Strength << ", with a modifier of " << StrengthMod << ".\n" <<
            "    Your Dexterity is " << Dexterity << ", with a modifier of " << DexterityMod << ".\n" <<
            "    Your Constitution is " << Constitution << ", with a modifier of " << ConstitutionMod << ".\n" <<
            "    Your Intelligence is " << Intelligence << ", with a modifier of " << IntelligenceMod << ".\n" <<
            "    Your Wisdom is " << Wisdom << ", with a modifier of " << WisdomMod << ".\n" <<
            "    Your Charisma is " << Charisma << ", with a modifier of " << CharismaMod << ".\n" <<
            "    Your starting Max Hit-points are " << Health + ConstitutionMod <<". \n \n";
    myfile.close();
    cout<< "Thank you for using this. I hope you enjoy your new D&D character.";
}

