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
void battle_sequence();

// Class Definintions
class Templar {
    public:
        string char_class = "Templar";
        int hp = 100;
        int attack = 15;
        int defense = 15;
};
class Assassin {
    public:
        string char_class = "Assassin";
        int hp = 70;
        int attack = 23;
        int defense = 10;
};
class Barbarian {
    public:
        string char_class = "Barbarian";
        int hp = 85;
        int attack = 20;
        int defense = 12;
};
class Character {
    private:
        string username;
        string char_class;
        int level;
        int xp;
        int xp_limit;
        int hp;
        int max_hp;
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
            max_hp = Hp;
            attack = Attack;
            defense = Defense;
        }
        void show_details(){
            cout << "\n|| " << username << " || " << char_class << " || " << "Level " << level << " || " << "XP: " << xp << "/" << xp_limit << " || " <<
            "\n|| Health: " << hp << " / " << max_hp << " || " << "Attack: " << attack << " || " << "Defense: " << defense << " || " << endl; 
        }
        void add_xp(int XP){
            cout << "You got " << XP << " XP!" << endl << endl;
            xp += XP;
            while (xp >= xp_limit){
                xp = xp - xp_limit; // Revert xp
                level += 1; // Level up
                xp_limit = xp_limit * 1.4; // Set XP Limit
                // stat change function over here!
            }
            show_details();
        }
        void hp_reduce(int enemy_atk){
            int actual_attack = (getRNG(5, enemy_atk-5)) - ((getRNG(3, 2) * 0.1) * defense);
            cout << username << " received " << actual_attack << " damage!" << endl;
            hp = hp - actual_attack;
            if (hp < 0){
                hp = 0;
            }
        }
        int get_user_level(){
            return level;
        }
        int get_user_hp(){
            return hp;
        }
        int get_user_attack(){
            return attack;
        }
        int get_user_defense(){
            return defense;
        }
        void death(){
            cout << username << " has been killed!" << endl;
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
        int max_hp;
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
            max_hp = Hp;
            attack = Attack;
            defense = Defense;
            level = getRNG(2, user_level);
            xp = getRNG((10 * (1.3 * level)), (5 * (1.3 * level)));
        }
        void show_details(){
            cout << "\n|| " << enemy_name << " || " << char_class << " || " << "Level " << level << " || " <<
            "\n|| Health: " << hp << " / " << max_hp << " || " << "Attack: " << attack << " || " << "Defense: " << defense << " || " << endl << endl; 
        }
        int get_enemy_hp(){
            return hp;
        }
        int get_enemy_attack(){
            return attack;
        }
        int get_enemy_defense(){
            return defense;
        }
        void hp_reduce(int user_atk){
            int actual_attack = (getRNG(5, user_atk-5)) - ((getRNG(3, 2) * 0.1) * defense);
            cout << enemy_name << " received " << actual_attack << " damage!" << endl;
            hp = hp - actual_attack;
            if (hp < 0){
                hp = 0;
            }
        }
        void death(){
            cout << enemy_name << " has been killed!" << endl;
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
void showBothDetails(Character c, Enemy e){
    c.show_details();
    e.show_details();
}
void battle_sequence(Character c, Enemy e){
    while (c.get_user_hp() > 0 && e.get_enemy_hp() > 0){
        showBothDetails(c, e);
        c.hp_reduce(e.get_enemy_attack());
        e.hp_reduce(c.get_user_attack());
    }
    showBothDetails(c, e);
    if (c.get_user_hp() == 0){
        c.death();
    } else if (e.get_enemy_hp() == 0){
        e.death();
    }
}

// Main Function
int main(){
    srand(time(NULL));
    Character myChar = character_creation_prompt();
    Enemy enemy = enemy_creration(myChar.get_user_level());
    battle_sequence(myChar, enemy);
}