#ifndef PORTE_H_INCLUDED
#define PORTE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <string>


class Porte//declaration du classe porte avec ses attribus et methodes
{     //les methodes sont commentés dans le fichier cpp
public:

bool get_value(std::string v);
void print_info();
void set_input(std::string word , bool val );
void ecrirefichier();
bool calculate_output(std::string typ, bool x);

public:

bool k;
bool s;
bool h;
bool b;
bool y;
bool l;

std::vector<std::string> tab;
std::vector <bool> tob;

std::string sortie;
std::string nomdeporte;
std::string typeduporte;
};



#endif // PORTE_H_INCLUDED
