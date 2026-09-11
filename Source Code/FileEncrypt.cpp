#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdio>
#include <direct.h>

int main()
{
    FILE* file;
    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        std::cout << "could not create test.txt\n";
        return 1;
    }

    fprintf(file, "MJ loves pandas, isn't it ?");
    fclose(file);

    std::cout << "test file created\n";

    std::string plaintext;
    file = fopen("test.txt", "r");
    if (file == NULL)
    {
        std::cout << "could not open test.txt\n";
        return 1;
    }

    char buffer[100];
    fgets(buffer, 100, file);
    fclose(file);
    plaintext = buffer;
    std::cout << "original text: " << plaintext << "\n";

    std::string keyword = "MJisKUCHUPUCHU";
    for (int i = 0; i < plaintext.length(); i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = plaintext[i] - 'A' + 'a';
        }
    }

    for (int i = 0; i < keyword.length(); i++)
    {
        if (keyword[i] >= 'A' && keyword[i] <= 'Z')
        {
            keyword[i] = keyword[i] - 'A' + 'a';
        }
    }

    std::string fullKey = keyword;

    for (int i = 0; fullKey.length() < plaintext.length(); i++)
    {
        fullKey += keyword[i % keyword.length()];
    }

    std::string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            int ptValue = plaintext[i] - 'a';
            int keyValue = fullKey[i] - 'a';
            int cipherValue = (ptValue + keyValue) % 26;
            ciphertext += (cipherValue + 'a');
        }
        else
        {
            ciphertext += plaintext[i];
        }
    }

    std::cout << "encrypted text: " << ciphertext << "\n";

    FILE* encryptedFile;
    encryptedFile = fopen("test.txt.enc", "w");
    if (encryptedFile == NULL)
    {
        std::cout << "Could not create encrypted file\n";
        return 1;
    }

    fputs(ciphertext.c_str(), encryptedFile);
    fclose(encryptedFile);

    std::cout << "encrypted file created\n";
    std::cout << "simulation complete\n";

    return 0;
}
