#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

/* 到目前為止都只使用一個函式（Function），也就是 main() 主函式，，若某些程式碼經常使用，
   可以抽出成為新函式以便重覆呼叫，函式用來將程式組織為一個小的、獨立的運行單元，一個函式
   可以接受資料，並運行其中的算法，最後將結果傳回。

   函式的組成主要包括四個部份：返回值、函式名稱、參數列與函式主體。前三者稱為函式宣告或函
   式原型（Function prototype），C 語言規定，如果函式是在 main 之後實作，必須在 main 之
   前進行宣告，否則會出現編譯錯誤。

   函式原型定義了函式的外觀，通常定義在獨立的標頭檔，而被含入每個想呼叫函式的檔案中，以下
   是一個函式宣告的範例：
   */

int power2(int);
int power(int, int);

#endif // MATH_H_INCLUDED
