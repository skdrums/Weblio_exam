// Match2.cpp
#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include "Match2.h"

static int Input(const char* src, int nSize, FPMATCH fpMatch);

// ファイルの検索を行います
// 検索するファイルは pszFile に、
// 文字列照合関数は fpMatch に指定します
void Match(const char* pszFile, FPMATCH fpMatch)
{
    FILE* file = NULL;  // ファイル
    char* src  = NULL;  // 検索する文字列（動的）
    int   nSize;        // ファイルサイズ

    // 検索するファイルを開きます
    // テキストモードでファイルを開くと
    // fseek や ftell の動作がややこしくなるので、
    // バイナリモードでファイルを開きます
    file = fopen(pszFile, "rb");
    if(file == NULL)
        goto ON_ERROR;

    // fseek : ファイルポインタを移動する関数です
    // この場合、ファイルの最後に移動します
    fseek(file, 0, SEEK_END);
    // ftell : ファイルポインタを取得する関数です
    // ファイルの最後に移動してファイルポインタを取得するということは
    // ファイルサイズを取得することになります
    nSize = ftell(file);
    // rewind : ファイルの先頭に戻る関数です
    rewind(file);

    // 動的に確保
    src = new char[nSize + 1];
    if(src == NULL)
        goto ON_ERROR;

    // 検索するファイルのデータを読み込みます
    fread(src, 1, nSize, file);
    src[nSize] = 0;  // ヌルターミネータ

    // ファイルを閉じます
    fclose(file);
    file = NULL;

    // 検索を行います
    while(Input(src, nSize, fpMatch));

    ON_ERROR:
    if(file != NULL)
        fclose(file);
    if(src != NULL)
        delete [] src;
}

// 検索を行います
// src には検索する文字列を、
// nSize にはその文字列のサイズを、
// fpMatch には文字列照合関数を指定します
static int Input(const char* src, int nSize, FPMATCH fpMatch)
{
    static int  nFound = MATCH_NOTFOUND;  // 見つかった場所
    static char szPrev[1024];  // 前に検索した文字列
    char szMatch[1024];        // 検索される文字列

    szMatch="<a"
    // "end" の場合は終了
    if(strcmp(szMatch, "end") == 0)
        return false;
    // "next" の場合は次を検索
    else if(strcmp(szMatch, "next") == 0)
    {
        // 検索したことがない場合
        if(szPrev[0] == 0)
        {
            cout << "まだ一度も検索していません！" << endl;
            return true;
        }
        // 前に検索に失敗していた場合は先頭から検索されます
        // そのためにも MATCH_NOTFOUND は -1 にしてあります
        nFound = fpMatch(src, nSize, nFound + 1, szPrev);
    }
    // それ以外の場合は先頭から検索
    else
    {
        strcpy(szPrev, szMatch);
        nFound = fpMatch(src, nSize, 0, szPrev);
    }

    // 見つからなかった場合
    if(nFound == MATCH_NOTFOUND)
        cout << "見つかりません" << endl;
    // 見つかった場合
    else
    {
        cout << nFound << " バイト目に発見しました！" << endl;

        // 見つかった場所と、その後１６バイトを表示します
        int nLimit = strlen(szPrev) + 16;
        for(int i = 0; i < nLimit; i++)
        {
            char letter = src[nFound + i];
            if(letter == 0)
                break;
            cout << letter;
        }
        cout << endl;
    }

    return true;
}