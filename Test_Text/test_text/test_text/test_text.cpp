
#include <stdio.h>
#include <stdlib.h>

void LoadText()
{
    FILE *fp = nullptr;

    fopen_s(&fp, "test_text.txt", "r");

    if(fp == nullptr)return;

    char buffer[256];
    //memset(buffer, 0, sizeof(char) * 256);
    /*
        %[指定] => fscanfの読み込み方の指定ができる

                    [^文字] => 指定された文字まで読み込む
    */
    fscanf_s(fp, "%[^sf]", buffer, sizeof(char) * 256);
    printf("%f\n", buffer);

    fclose(fp);
}