#ifndef __TXTPROCESSING_H__
#define __TXTPROCESSING_H__

#include <cstdio>
#include <iostream>
#include <vector>

void insertSentence(FILE* txt, char* sentence, std::vector<fpos_t>& pointers, int index, int sentenceSize);
//appends sentence from txtIn to txtOut
void copySentenceLines(FILE* txtIn, FILE* txtOut);
errno_t deleteSentence(const char* fileName, std::vector<fpos_t>& pointers, int& index);
void coutSentence(FILE* txt, std::vector<fpos_t>& pointers, int index);
errno_t fresize(const char* fileName, size_t newSize);

#endif