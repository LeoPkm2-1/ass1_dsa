#include "SymbolTable.h"

//=================================================== support function ======================================

bool is_String(string str){     // this function return true if str is string
    if(str.front()=='\'')
        if(str.back()=='\'') return is_string_helper(str.substr(1,str.length()-2));
    return false;
    
}

bool is_string_helper(string str){      // this is supporting function of is_String()
    char front=str.front();
    if(str.length()==1 && (front==' ' || (front>64 && front<91) || (front>96 && front<123) || (front>47 && front<58 ) ))
        return true;
    else if(!(front==' ' || (front>64 && front<91) || (front>96 && front<123) || (front>47 && front<58 )))
            return false;
    return is_string_helper(str.substr(1,str.length()-1));
}

bool is_Num(string str){     // is_Num() return true if string is number
    for (int i = 0; i < str.length(); i++)
    {
       if(str[i]<48 || str[i]>57)
        return false;
    }
    return true;    
}

int convert_Num(string str){
    if(str.length()==1) return int(str.front())-48;
    else 
        return int(str.back())-48 + 10*(convert_Num(str.substr(0,str.length()-1)));
}

int count_Space(string str){    // this fucntion return the number of space in the string
    int numOfspace =0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ') numOfspace+=1;
    }
}

void sperate_command:: sperate(string str){    //this function help to sperate command to command_partion identifier_partion type_partion
        int numofspace= count_Space(str);
        int lengthofstr=str.length();
        if(numofspace==0){
            command=str;
        }
        else if(numofspace==1) {
            int positionOfspace=0;
            for (int i = 0; i < lengthofstr; i++)
            {
                if(str[i]!=' ') positionOfspace +=1;
                else break;                
            }
            command=str.substr(0,positionOfspace);
            identifier=str.substr(positionOfspace+1,lengthofstr-positionOfspace);
            
            
        }
        else{
            int positionOfspace=0;
            for (int i = 0; i < lengthofstr; i++)
            {
                if(str[i]!=' ') positionOfspace +=1;
                else break;                
            }
            command=str.substr(0,positionOfspace);
            int temp=(++positionOfspace);
            for (int i = temp; i < lengthofstr; i++)
            {
                if(str[i]!=' ') positionOfspace +=1;
                else break;
            }
            identifier=str.substr(temp,positionOfspace-temp);
            type=str.substr(positionOfspace+1,lengthofstr-positionOfspace-1);
            
        }
}


//===========================================  define symbol table type================================
void SymbolTable::run(string filename)
{
    cout << "success";
}


//===================================  define symbol type=========================================




//================================= define nodesymbol type ==========================================






//=====================================define row =================================================
int row::index=0;   //numberOFrow in the table at now
int row::numOfrow(){        // return number of row in table
    return index+1;
}
row::row(){                 // automatic set number for row
        indexrow=index++;
}