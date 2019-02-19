// Match2.h
#ifndef __MATCH2_H__010414_2259_57951860__INCLUDED__
#define __MATCH2_H__010414_2259_57951860__INCLUDED__

// 文字列照合関数の型
// 関数ポインタ（第９章参照）ですね
typedef int (*FPMATCH)(const char* src, int nBufSize,
                       int nFirst, const char* pat);

// 「見つかりませんでした」を表す値
const int MATCH_NOTFOUND = -1;

void Match(const char* pszFile, FPMATCH fpMatch);

#endif // #ifndef __MATCH2_H__010414_2259_57951860__INCLUDED__
