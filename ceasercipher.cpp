#include <iostream>
#include <string>
using namespace std;

string encrypt(const string t, int shift)
{
    char c;
    string encryptedText = "";

    for (size_t i = 0; i < t.size(); i++)
    {
        c = t[i];
        if (c >= 'A' && c <= 'Z')
        {
            encryptedText += char((c - 'A' + shift) % 26 + 'A');
        }
        else if (c >= 'a' && c <= 'z')
        {
            encryptedText += char((c - 'a' + shift) % 26 + 'a');
        }
        else
        {
            encryptedText += c;
        }
    }

    return encryptedText;
}
string decrypt(const string t, int shift)
{
    char c;
    string decryptedText = "";

    for (size_t i = 0; i < t.size(); i++)
    {
        c = t[i];
        if (c >= 'A' && c <= 'Z')
        {
            decryptedText += char((c - 'A' - shift + 26) % 26 + 'A');
        }
        else if (c >= 'a' && c <= 'z')
        {
            decryptedText += char((c - 'a' - shift + 26) % 26 + 'a');
        }
        else
        {
            decryptedText += c;
        }
    }

    return decryptedText;
}

int main()
{
    int shift, passkey;
    string encryp;

    cout << " Enter the text you want to encrypt: ";
    getline(cin, encryp);
    cout << " Enter the shift key: ";
    cin >> shift;
    string encryptedText = encrypt(encryp, shift);
    cout << " Encrypted Text: " << encryptedText << endl;
    string decryptedtext = decrypt(encryptedText, shift);
    do
    {
        cout << " Enter passkey to decrypt this text ";
        cin >> passkey;

        if (passkey == shift)
        {
            cout << " Your key is correct :)" << endl;
            cout << " Decrypted Text : " << decryptedtext << endl;
        }
        else
        {
            cout << " Your key is not correct :( " << endl;
        }

    } while (passkey != shift);

    return 0;
}
