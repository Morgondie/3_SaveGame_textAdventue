// 3_SaveGame.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

#define MAXNAMESIZE 16

enum  EWeapon
{
    Sword, Axe ,Lance, Fits
};

enum EArchetype
{
     Warrior, Mage, Cleric, Adventure
};



enum EItem
{
    Armor, Potion, Map, Gold
};


struct SGameData
{
    char name[MAXNAMESIZE];
    EWeapon currentWeapon;
    EArchetype currentArchetype;
    
    EItem currentItem;
    unsigned int enemysKilled;
};

void Log(const char* msg)
{
    std::cout << msg << "\n";
}

const char* PickWeapon(EWeapon weapon)
{
    
    switch (weapon)
    {
    case Sword: return "Espada";
    case Axe: return "Hacha";
    case Lance: return "Lanza";
    case Fits: return "Puños";
    default: return "none";
    }
}

const char* PickClases(EArchetype clases)
{

    switch (clases)
    {
    case Warrior: return "Guerrero";
    case Mage: return "Mago";
    case Cleric: return "Curandero";
    case Adventure: return "Adventurero";
    default: return "none";
    }
}


const char* PickItem(EItem objetos)
{

    switch (objetos)
    {
    case Armor: return "Armadura";
    case Potion: return "Posion";
    case Map: return "Mapa";
    case Gold: return "Oro";
    default: return "none";
    }
}

int main()
{
    //std::cout << "Hello World!\n";

    //leer ele archivo de salvagame
    std::fstream savefile("data.sav", std::ios::in | std::ios::out);

    if (savefile.is_open())
    {
        Log("savefile abierto");

        //leer da
        SGameData data;
        savefile.read(data.name, MAXNAMESIZE);
        savefile.read((char*)&data.enemysKilled, 4);
        
        savefile.read((char*)&data.currentWeapon, 4);
        savefile.read((char*)&data.currentArchetype, 4);
        savefile.read((char*)&data.currentItem, 4);

        


        savefile.read((char*)&data.enemysKilled, 4);

        std::cout << "hola " << data.name<< "\n";
        std::cout << "has matado a " << data.enemysKilled << "\n";

        ////////Arma

        if (data.currentWeapon == 0)
        {
            std::cout << "tienes una espada " << data.currentWeapon << "\n";
        }
        else if (data.currentWeapon == 1)
        {
            std::cout << "tienes una Hacha " << data.currentWeapon << "\n";
        }
        else if (data.currentWeapon == 2)
        {
            std::cout << "tienes una Lanza " << data.currentWeapon << "\n";
        }
        else
        {
            std::cout << "Estas armado con solo tus puños " << data.currentWeapon << "\n";
        }
        ///////Clase

        if (data.currentArchetype == 0)
        {
            std::cout << "Eres un guerrero " << data.currentArchetype << "\n";
        }
        else if (data.currentArchetype == 1)
        {
            std::cout << "Eres un mago " << data.currentArchetype << "\n";
        }
        else if (data.currentArchetype == 2)
        {
            std::cout << "Eres un Curandero " << data.currentArchetype << "\n";
        }
        else
        {
            std::cout << "Eres un Aventurero " << data.currentArchetype << "\n";
        }
        /////Inventario
        if (data.currentItem == 0)
        {
            std::cout << "tienes una armadura  " << data.currentItem << " en tu inventario " << "\n";;
        }
        else if (data.currentItem == 1)
        {
            std::cout << "tienes una posion  " << data.currentItem << " en tu inventario " << "\n";
        }
        else if (data.currentItem == 2)
        {
            std::cout << "tienes un Mapa  " << data.currentItem << " en tu inventario " << "\n";
        }
        else
        {
            std::cout << "tienes Oro  " << data.currentItem << " en tu inventario " << "\n";
        }
        
       
       
    }
    else 
    {
        Log("crear savefile vacio e inicial");
        SGameData data;
        Log("Escribe tu nombre aventurero");
        std::cin >> data.name;

        Log("Cual es tu Arma?");
        std::string Answer;

        Log("1. Espada");
        Log("2. Hacha");
        Log("3. Lanza");
        Log("4 Puños");
        std::cin >> Answer;

        if (Answer == "1")
        {
            data.currentWeapon = EWeapon::Sword;
        }
        else if (Answer == "2")
        {
            data.currentWeapon = EWeapon::Axe;
        }
        else if (Answer == "3")
        {
            data.currentWeapon = EWeapon::Lance;
        }
        else
        {
            data.currentWeapon = EWeapon::Fits;
        }

        Log("Cual es tu clase?");
        std::string Answer2;

        Log("1. Guerrero");
        Log("2. Mago");
        Log("3. Curandero");
        Log("4 Aventurero");
        std::cin >> Answer2;

        if (Answer2 == "1")
        {
            data.currentArchetype = EArchetype::Warrior;
        }
        else if (Answer2 == "2")
        {
            data.currentArchetype = EArchetype::Mage;
        }
        else if (Answer2 == "3")
        {
            data.currentArchetype = EArchetype::Cleric;
        }
        else
        {
            data.currentArchetype = EArchetype::Adventure;
        }


        Log("Cual es tu clase?");
        std::string Answer3;

        Log("1. Armadura");
        Log("2. Posion");
        Log("3. Mapa");
        Log("4 Oro");
        std::cin >> Answer3;
        if (Answer3 == "1")
        {
            data.currentItem = EItem::Armor;
        }
        else if (Answer3 == "2")
        {
            data.currentItem = EItem::Potion;
        }
        else if (Answer3 == "3")
        {
            data.currentItem = EItem::Map;
        }
        else
        {
            data.currentItem = EItem::Gold;
        }
        data.enemysKilled = 0;

        savefile.open("data.sav", std::ios::out);

       
        //data.currentItem = EItem::None;

        

        if (savefile.is_open())
        {
            //dumperar la estrcutura data
            savefile.seekp(0, std::ios::beg);
            savefile.write((const char*)& data, sizeof(SGameData));
        }
        else
        {
            Log("no se pudo crear el archivo");
        }

    }

    savefile.close();

    return 0;
}

