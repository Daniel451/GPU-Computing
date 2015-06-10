// exercise1.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <cmath>

using namespace std;

// schluesseltabelle
int a[26][26];
int pwindex = 0;
string password = "HAMBURG";


int giveback(char c)
{
    if ((int) c > (int) 'Z')
    {
        c = (char) ((int) 'A' + (int) c - (int) 'Z' - 1);
    }
    return c;
}


string getZeile(int zeilennummer)
{
    string zeile = "";

    int i;
    for(i = 0; i < 26; i++)
    {
        zeile.append(string(1, (char) a[zeilennummer][i]));
    }

    return zeile;
}


string nstr2upper(string s)
{
    int z;
    for(z = 0; z < s.size(); z++)
    {
        s[z] = toupper(s[z]);
    }

    return  s;
}


string str2lower(string s)
{
    int z;
    for(z = 0; z < s.size(); z++)
    {
        s[z] = tolower(s[z]);
    }

    return s;
}


int getPwInt()
{
    int ret; // container

    // get current password character for encryption
    // -'A' is needed for normalization purposes (A-Z ASCII ints to [0-25])
    ret = (int) password[pwindex] - (int) 'A';

    pwindex = (pwindex + 1) % password.size();

    return ret;
}


int getCharInt(char input)
{
    int ret; // container

    input = toupper(input);

    ret = (int)input - (int)'A';

    return ret;
}


void createtable()
{
    char cx = 'A';
    char cy = 'A';
    int x = 0;
    int y = 0;

    for (x = 0; x < 26; x++)
    {
        for (y = 0; y < 26; y++)
        {
            a[x][y] = cy;
            cy = (char) giveback(cy + 1); // inneren char inkrementieren
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
    std::regex e = std::regex("[a-z]|[A-Z]");

    if(std::regex_match(s, e))
    {
        cinput = (char) a[getPwInt()][getCharInt(cinput)];
    }

    return cinput;
}


char decryptChar(char cinput)
{
    std::string s = std::string(1, cinput);
    std::regex e = std::regex("[a-z]|[A-Z]");

    if(std::regex_match(s, e))
    {
        int zeilennummer = getPwInt();
        string zeile = getZeile(zeilennummer);
        int suche = zeile.find(cinput);
        cinput = (char) a[0][suche];
    }

    return cinput;
}


void decryptfile()
{
    string decrypt_filename = "";
    string decrypt_password = "";
    string decrypt_string = "";

    std::cout << std::endl;
    std::cout << "Dateipfad angeben:" << std::endl << "> ";
    std::cin >> decrypt_filename;
    std::cout << std::endl;
    std::cout << "Passwort angeben:" << std::endl << "> ";
    std::cin >> decrypt_password;
    std::cout << std::endl;

    decrypt_filename = "/home/daniel/test.txt";

    decrypt_password = str2upper(decrypt_password);

    char decrypt_line[256];
    ifstream decrypt_infile(decrypt_filename, ios::in);


    if (!decrypt_infile)
    {
        std::cout << "Kein File gefunden :(" << std::endl;
    }

    if (decrypt_infile)
    {

        while (decrypt_infile.getline(decrypt_line, 256))
        {
            int i;
            for (i = 0; i < sizeof(decrypt_line); i++)
            {
                if (decrypt_line[i] == '\0') // wenn das Ende des String erreicht wurde
                {
                    break;
                }
                decrypt_string.append(string(1, decryptChar(decrypt_line[i])));
            }

        }

        decrypt_string = str2lower(decrypt_string);

        decrypt_infile.close();

        ofstream outfile(decrypt_filename, ios::out);
        outfile << decrypt_string;
        outfile.close();

        std::cout << "Datei wurde entschluesselt." << std::endl;
    }
}


void encryptfile()
{
    string encrypt_filename = "";
    string encrypt_password = "";
    string encrypt_string = "";

    std::cout << std::endl;
    std::cout << "Dateipfad angeben:" << std::endl << "> ";
    std::cin >> encrypt_filename;
    std::cout << std::endl;
    std::cout << "Passwort angeben:" << std::endl << "> ";
    std::cin >> encrypt_password;
    std::cout << std::endl;

    encrypt_filename = "/home/daniel/test.txt";

    password = str2upper(encrypt_password);


    char encrypt_line[256];
    ifstream encrypt_infile(encrypt_filename, ios::in);


    if (!encrypt_infile)
    {
        std::cout << "Kein File gefunden :(" << std::endl;
    }

    if (encrypt_infile)
    {

        while (encrypt_infile.getline(encrypt_line, 256))
        {
            int i;
            for (i = 0; i < sizeof(encrypt_line); i++)
            {
                if (encrypt_line[i] == '\0') // wenn das Ende des String erreicht wurde
                {
                    break;
                }
                encrypt_string.append(string(1, encryptChar(encrypt_line[i])));
            }

        }

        encrypt_infile.close();

        ofstream encrypt_outfile(encrypt_filename, ios::out);
        encrypt_outfile << encrypt_string;
        encrypt_outfile.close();

        std::cout << "Datei wurde verschluesselt." << std::endl;

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
        decryptfile();
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