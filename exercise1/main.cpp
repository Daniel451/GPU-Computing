// exercise1.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

// schluesseltabelle
int a[26][26];


int giveback(char c)
{
    if ((int) c > (int) 'z')
    {
        c = (char) ((int) 'a' + (int) c - (int) 'z' - 1);
    }
    return c;
}


void createtable()
{
    char cx = 'a';
    char cy = 'a';
    int x = 0;
    int y = 0;

    for (x = 0; x < 26; x++)
    {
        for (y = 0; y < 26; y++)
        {
            a[x][y] = cy;
            cy = giveback(cy + 1); // inneren char inkrementieren
        }
        cx++; // �u�eren char inkrementieren
        cy = cx;
    }
}


void viewTable()
{
    int x = 0;
    int y = 0;

    std::cout << std::endl;

    for (x = 0; x < 26; x++)
    {
        for (y = 0; y < 26; y++)
        {
            std::cout << (char) a[x][y];
        }
        std::cout << endl;
    }
}


char encryptChar(char cinput)
{
    std::string s = std::string(1, cinput);
    std::regex e = std::regex("[a-z]");

    if(std::regex_match(s, e))
    {
        //cinput = (char)(a[(int)cinput][0]);
        //cinput = (char)toupper(cinput);
    }

    return cinput;
}


void encryptfile()
{
    string filename = "";

    std::cout << std::endl;
    std::cout << "Dateipfad angeben:" << std::endl << "> ";
    std::cin >> filename;
    std::cout << std::endl;

    filename = "/home/daniel/test.txt";

    char line[256];
    ifstream infile(filename, ios::in);

    if (!infile)
    {
        std::cout << "Kein File gefunden :(" << std::endl;
    }

    if (infile)
    {
        std::cout << "Dateiinhalt:" << std::endl;
        std::cout << ">>";
        while (infile.getline(line, 256))
        {
            std::cout << line << std::endl;

            int i;
            for (i = 0; i < sizeof(line); i++)
            {
                if (line[i] == '\0') // wenn das Ende des String erreicht wurde
                {
                    break;
                }
                std::cout << encryptChar(line[i]);
            }

            if (infile.peek() != EOF)
            {
                std::cout << std::endl;
            }
        }
        std::cout << "<<";

    }
}


void printmenu()
{
    // Container f�r Benutzereingaben
    string eingabe = "";

    std::cout << std::endl;
    std::cout << "Warten auf Benutzereingabe:" << std::endl;
    std::cout << "* (a)nzeigen der Verschluesselungstabelle" << std::endl;
    std::cout << "* (v)erschluesseln" << std::endl;
    std::cout << "* (e)ntschluesseln" << std::endl;
    std::cout << "* (q)uit" << std::endl;
    std::cout << "> ";

    // Benutzereingabe einlesen
    std::cin >> eingabe;

    if (eingabe != "v" && eingabe != "e" && eingabe != "q" && eingabe != "a")
    {
        std::cout << std::endl;
        std::cout << "Bitte v, e, a oder q als Eingaben nutzen." << std::endl;
        printmenu();
    }
    else if (eingabe == "v")
    {
        encryptfile();
    }
    else if (eingabe == "e")
    {
    }
    else if (eingabe == "a")
    {
        viewTable();
        printmenu();
    }
    else if (eingabe == "q")
    {
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    createtable();
    printmenu();

    std::cin.get();
    std::cin.get();
    return 0;
}
