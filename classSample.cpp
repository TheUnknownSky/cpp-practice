#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Class/Function Declarations
int getRNG(int range, int lowest_limit);
class Templar;
class Assassin;
class Barbarian;
class Char_Class;
class Character;
class Enemy;
Char_Class select_character();
Character character_creation_prompt();
Enemy enemy_creration();

// Class Definintions
class Templar {
    public:
        string char_class = "Templar";
        int hp = 100;
        int attack = 10;
        int defense = 20;
};
class Assassin {
    public:
        string char_class = "Assassin";
        int hp = 70;
        int attack = 30;
        int defense = 5;
};
class Barbarian {
    public:
        string char_class = "Barbarian";
        int hp = 85;
        int attack = 20;
        int defense = 10;
};
class Character {
    private:
        string username;
        string char_class;
        int level;
        int xp;
        int xp_limit;
        int hp;
        int attack;
        int defense;
    public:
        Character(string Username = "", string character_class = "", int Hp = 0, int Attack = 0, int Defense = 0, int Level = 1, int XP = 1, int XP_Limit = 10){
            username = Username;
            level = Level;
            xp = XP;
            xp_limit = XP_Limit;
            char_class = character_class;
            hp = Hp;
            attack = Attack;
            defense = Defense;
        }
        void show_details(){
            cout << "\n|| " << username << " || " << char_class << " || " << "Level " << level << " || " << "XP: " << xp << "/" << xp_limit << " || " <<
            "\n|| Health: " << hp << " || " << "Attack: " << attack << " || " << "Defense: " << defense << " || " << endl << endl; 
        }
        void add_xp(int XP){
            cout << "You got " << XP << " XP!" << endl << endl;
            xp += XP;
            while (xp >= xp_limit){
                xp = xp - xp_limit; // Revert xp
                level += 1; // Level up
                xp_limit = xp_limit * 1.4; // Set XP Limit
            }
            show_details();
        }
        int get_user_level(){
            return level;
        }
};
class Char_Class {
    public:
        int hp;
        int attack;
        int defense;
        string char_class;
        Char_Class(int choice = 0){
            if (choice == 1){
                Templar templar;
                hp = templar.hp;
                attack = templar.attack;
                defense = templar.defense;
                char_class = templar.char_class;
            } else if (choice == 2){
                Assassin assassin;
                hp = assassin.hp;
                attack = assassin.attack;
                defense = assassin.defense;
                char_class = assassin.char_class;
            } else if (choice == 3){
                Barbarian barbarian;
                hp = barbarian.hp;
                attack = barbarian.attack;
                defense = barbarian.defense;
                char_class = barbarian.char_class;
            }
        }
};
class Enemy{
    private:
        int hp;
        int attack;
        int defense;
        int level;
        int xp;
        string enemy_name;
        string char_class;
    public:
        Enemy(string EnemyName, string CharacterClass, int Hp, int Attack, int Defense, int user_level){
            enemy_name = EnemyName;
            char_class = CharacterClass;
            hp = Hp;
            attack = Attack;
            defense = Defense;
            level = getRNG(2, user_level);
            xp = getRNG((10 * (1.3 * level)), (5 * (1.3 * level)));
        }
        void show_details(){
            cout << "\n|| " << enemy_name << " || " << char_class << " || " << "Level " << level << " || " <<
            "\n|| Health: " << hp << " || " << "Attack: " << attack << " || " << "Defense: " << defense << " || " << endl << endl; 
        }
};

// Function Definitions
int getRNG(int range, int lowest_limit){
    return rand() % range + lowest_limit;
}
Char_Class select_character(){
    int char_class;
    cout << "1 - Templar\n2 - Assassin\n3 - Barbarian\nSelect Class: "; cin >> char_class;
    Char_Class myCharClass(char_class);
    return myCharClass;
}
Character character_creation_prompt(){
    string username;
    cout << "Enter username: "; cin >> username;
    Char_Class myChar;
    myChar = select_character();
    Character myCharacter(username, myChar.char_class, myChar.hp, myChar.attack, myChar.defense);
    return myCharacter;
}
Enemy enemy_creration(int user_level){
    Char_Class enemyClass(getRNG(3, 1));
    string names[10] = {"Calias", "Fechin", "Broccan", "Achilleus", "Demosthenes", "Menandros", "Publius", "Fiachrae", "Alcibiades", "Caesar"};
    Enemy enemy (names[getRNG(9, 0)], enemyClass.char_class, enemyClass.hp, enemyClass.attack, enemyClass.defense, user_level);
    return enemy;
}

// Main Function
int main(){
    srand(time(NULL));
    Character myChar = character_creation_prompt();
    Enemy enemy = enemy_creration(myChar.get_user_level());
    myChar.show_details();
    enemy.show_details();
}