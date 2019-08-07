#include <Windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

string Pwd() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    string separator = "/";
    return string( buffer ).substr( 0, pos) + separator;
}

int main (int argc, char* argv[]) {
    printf(Pwd().c_str());
}
