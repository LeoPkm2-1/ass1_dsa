#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

//=================================================== support function ======================================
bool is_String(string );     // this function return true if str is string
bool is_string_helper(string);  // this is supporting function of is_String()
bool is_Num(string );   // is_Num() return true if string is number
int convert_Num(string);

int count_Space(string);    // this fucntion return the number of space in the string


class sperate_command{
public:
    string command;
    string identifier;
    string type;
    

    void sperate(string str);   //this function help to sperate command to command_partion identifier_partion type_partion
    

};










//=========================================== class declare symbol table type================================
class SymbolTable
{
public:
    SymbolTable() {}
    void run(string filename);
};


//=================================== class declare symbol type=========================================
class symbol {
private:
    string identifier;
    string type;
    int level;
public:

    symbol(string, string);

};


//================================= class declare nodesymbol type ==========================================
class nodesymbol{
public:
    symbol node;
    symbol* symbolnext;         // pointer to node symbol after 
    symbol* symbolbefore;       // pointer to the node before
    nodesymbol();
};

//================================== class declare row type ==============================================
class row{
    static int index;   // the number of row in the table
public:
    int indexrow;       // index (position ) of row in table

    row();              //constructor
    
    int numOfrow();     //return sum number of row in table

    bool closed();
    
};

#endif