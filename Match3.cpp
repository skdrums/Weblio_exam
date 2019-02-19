// Match3.cpp
#include "Match2.h"

static int SimpleMatch(const char* src, int nBufSize,
                       int nFirst, const char* pat);

int main()
{
    Match("c.txt", SimpleMatch);
    return 0;
}

// 単純な文字列照合関数です
// src には検索対象を、
// nBufSize には src のサイズを、
// nFirst には開始バイト数を、
// pat には検索文字列を指定します
static int SimpleMatch(const char* src, int nBufSize,
                       int nFirst, const char* pat)
{
    // エラーチェック
    if(pat[0] == 0        ||
       src[nBufSize] != 0 ||
       nFirst > nBufSize)
        return MATCH_NOTFOUND;

    // 開始位置をずらします
    src += nFirst;

    // src[0] から順に照合していきます
    for(int i = 0; src[i] != 0; i++)
    {
        // src と pat の照合
        int j;
        for(j = 0; pat[j] != 0; j++)
            if(src[i + j] != pat[j])
                break;
        // 等しかった場合、見つかった場所を返します
        if(pat[j] == 0)
            return i + nFirst;
    }
    // 最後まで見つかりませんでした
    return MATCH_NOTFOUND;
}