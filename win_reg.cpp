#include <Windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

HKEY OpenKey(HKEY hRootKey, LPCTSTR strKey){
    HKEY hKey;
    LONG nError = RegOpenKeyEx(hRootKey, strKey, NULL, KEY_ALL_ACCESS, &hKey);
    if (nError == ERROR_FILE_NOT_FOUND) 
        nError = RegCreateKeyEx(hRootKey, strKey, NULL, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL, &hKey, NULL);
    if (nError) cout << "Error: " << endl;
    return hKey;
}

void SetCharKey(HKEY hKey, LPCTSTR lpValue, char* data){
  LONG nError = RegSetValueEx(hKey, lpValue, 0, REG_SZ, (LPBYTE)data, strlen(data)+1);
  if (nError)  cout << "Error: " << endl;
}

void Registry(){
    //LPCTSTR strKey = TEXT("Software\\X\\X\\X\\X"); :D
    LPCTSTR strKey = TEXT("");
    LPCTSTR subKey = TEXT("Key");
    char * subVal = "Val";
    HKEY hk = OpenKey(HKEY_CURRENT_USER, strKey);
    SetCharKey(hk, subKey, subVal);
}

int main (int argc, char* argv[]) {
    //remember advapi32.lib
    Registry();
}
