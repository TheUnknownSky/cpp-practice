#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRNG(){
    return rand() % 10 + 5;
}
class Character {
    private:
        string username;
        string char_class;
        int level;
        int xp;
        int xp_limit;
    public:
        Character(string Username = "", string Char_Class = "", int Level = 1, int XP = 1, int XP_Limit = 10){
            username = Username;
            char_class = Char_Class;
            level = Level;
            xp = XP;
            xp_limit = XP_Limit;
        }
        void show_details(){
            cout << "\n|| " << username << " || " << char_class << " || " << "Level " << level << " || " << "XP: " << xp << "/" << xp_limit << " || " << endl << endl;
        }
        void level_up(){
            level += 1;
        }
        void set_xp_limit(){
            xp_limit = xp_limit * 1.4;
        }
        void revert_xp(){
            xp = xp - xp_limit;
        }
        void add_xp(int XP){
            cout << "You got " << XP << " XP!" << endl << endl;
            xp += XP;
            while (xp >= xp_limit){
                revert_xp();
                level_up();
                set_xp_limit();
            }
            show_details();
        }
};
string select_character(){
    int char_class;
    cout << "1 - Templar\n2 - Barbarian\n3 - Assassin\nSelect Class: "; cin >> char_class;
    switch (char_class){
    case 1: 
        return "Templar";
        break;
    case 2: 
        return "Barbarian"; 
        break;
    case 3: 
        return "Assassin"; 
        break;
    default: 
        cout << "\nInvalid input." << endl << endl; 
        return select_character(); 
        break;
    }
}
Character game_prompt(){
    string username, char_class;
    cout << "Enter username: "; cin >> username;
    char_class = select_character();
    Character myCharacter(username, char_class);
    return myCharacter;
}
int main(){
    srand(time(NULL));
    Character myChar = game_prompt();
    myChar.show_details();
}