// 3_SaveGame.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>

#define MAXNAMESIZE 16

enum  EWeapon
{
    none, Sword, Axe ,bow
};

enum EArchetype
{
    Deprived, Warrior, Mage, Cleric
};

enum Especie
{
    Unknow, Human, Dwarf, Elf
};

enum EItem
{
    None, Potion, Map, Relic
};


struct SGameData
{
    char name[MAXNAMESIZE];
    EWeapon currentWeapon;
    EArchetype currentArchetype;
    Especie currentspecie;
    EItem currentItem;
    unsigned int enemysKilled;
};

void Log(const char* msg)
{
    std::cout << msg << "\n";
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
        savefile.read((char*)&data.currentWeapon, 4);

        savefile.read((char*)&data.currentArchetype, 4);
        savefile.read((char*)&data.currentspecie, 4);
        savefile.read((char*)&data.currentItem, 4);




        savefile.read((char*)&data.enemysKilled, 4);

        std::cout << "hola " << data.name<< "\n";
        std::cout << "tienes el roll de " << data.currentArchetype << "\n";
        std::cout << "eres un  " << data.currentspecie << "\n";
        std::cout << "tienes un  " << data.currentItem << "en tu inventario " << "\n";
        
        std::cout << "tienes un arma " << data.currentWeapon << "\n";

        std::cout << " y  has matado a " << data.enemysKilled << "\n";
    }
    else 
    {
        Log("crear savefile vacio e inicial");
        SGameData data;
        Log("Escribe tu nombre aventurero");
        std::cin >> data.name;
        data.currentWeapon = EWeapon::none;

        data.currentArchetype = EArchetype::Deprived;
        data.currentspecie = Especie::Unknow;
        data.currentItem = EItem::None;

        data.enemysKilled = 0;

        savefile.open("data.sav", std::ios::out);
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

