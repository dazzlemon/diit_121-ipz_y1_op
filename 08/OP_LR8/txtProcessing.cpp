#define _CRT_SECURE_NO_WARNINGS

#include "txtProcessing.h"
#include <string.h>

void copySentenceLines(FILE* txtIn, FILE* txtOut) {
	std::vector<fpos_t> pointers{ 0 };
	int index = 0;
	do {//copy string-sentences to new file
		fsetpos(txtIn, &(pointers[index]));
		char current;
		char sentence[256];
		std::fill_n(sentence, 256, '\0');//set all aray values to '/0'
		int i = 0;//iterator
		do {
			current = fgetc(txtIn);
			if (current != '\n') {
				sentence[i] = current;
				i++;
			}
		} while ((current != '.' && current != '!' && current != '?') || feof(txtIn));//check until the end of file or sentence
		while ((current == '\n' || current == ' ' || current == '.' || current == '!' || current == '?') && !feof(txtIn))//skip dot-space sequence and check if current sentence is last
			current = fgetc(txtIn);
		fpos_t temp;
		if (!feof(txtIn)) {
			ungetc(current, txtIn);//set from 2nd to 1st char of sentence
			fgetpos(txtIn, &temp);//save pointer to start of next sentence
			pointers.push_back(temp);
		}
		fputs(sentence, txtOut);//adding new sentence
		fputc('\n', txtOut);
		index++;
	} while (index < pointers.size());
}

void coutSentence(FILE* txt, std::vector<fpos_t>& pointers, int index) {
	fsetpos(txt, &(pointers[index]));
	char sentence[256];
	std::fill_n(sentence, 256, '\0');//set all aray values to '\0'
	fgets(sentence, 255, txt);
	std::cout << sentence[0];
	for (int i = 1; i < 255 && sentence[i] != '\n' && sentence[i - 1] != '.'; i++)//added check for '.' because else it prints next message on the curent if inserted after last
		std::cout << sentence[i];
	if (index == pointers.size() - 1) {//to prevent adding old indexes to vector
		fpos_t temp;
		char current = fgetc(txt);
		if (!feof(txt)) {
			ungetc(current, txt);//set from 2nd to 1st char of sentence
			fgetpos(txt, &temp);//save pointer to start of next sentence
			pointers.push_back(temp);
		}
	}
}

void insertSentence(FILE* txt, char* sentence, std::vector<fpos_t>& pointers, int index, int sentenceSize) {
	//move anything after index to right N characters
	fseek(txt, 0, SEEK_END);
	fpos_t end = ftell(txt);
	end--;//to avoid EOF
	fpos_t insertPos;
	if (index <= pointers.size() - 1)//fix if after last
		insertPos = pointers[index];
	else
		insertPos = end;
	pointers.push_back(insertPos);
	for (int i = pointers.size() - 1; i > index; i--)
		pointers[i] = pointers[i - 1] + sentenceSize;//updating pointers to sentences

	char currentChar;
	for (end; end >= insertPos; end--) {
		fsetpos(txt, &end);
		currentChar = fgetc(txt);
		end += sentenceSize;
		if (currentChar == '\n')//otherwise overrites previous symbol and writes '\n' twice
			end--;
		fsetpos(txt, &end);
		fputc(currentChar, txt);
		end -= sentenceSize;
	}
	fsetpos(txt, &insertPos);
	fputs(sentence, txt);//??
	if (index < pointers.size() - 1)//weirdo '\n'
		fputc('\n', txt);
}

errno_t deleteSentence(const char* fileName, std::vector<fpos_t>& pointers, int& index) {
	FILE* txt;
	errno_t err = fopen_s(&txt, fileName, "r+");
	if (!err) {
		fseek(txt, 0, SEEK_END);
		fpos_t end = ftell(txt);

		int sentenceSize;
		if (index < (pointers.size() - 1))//if last
			sentenceSize = pointers[index + 1] - pointers[index];
		else
			sentenceSize = end - pointers[index];

		//move anything after index to left N characters
		fsetpos(txt, &pointers[index]);
		fpos_t start = ftell(txt);
		char currentChar;
		for (start; start < end - sentenceSize; start++) {
			start += sentenceSize;
			fsetpos(txt, &start);
			currentChar = fgetc(txt);
			start -= sentenceSize;

			fsetpos(txt, &start);
			fputc(currentChar, txt);
			if (currentChar == '\n')//otherwise overrites previous symbol and writes '\n' twice
				start++;
		}

		for (int i = index; i < pointers.size() - 1; i++)//mb start from index + 1
			pointers[i] = pointers[i + 1] - sentenceSize;//updating pointers to sentences
		pointers.pop_back();
		fclose(txt);
		err = fresize(fileName, end - sentenceSize);
		if (index >= pointers.size())//if deleting last
			index--;
	}
	return err;
}

errno_t fresize(const char* fileName, size_t newSize) {
	FILE* oldFile, * newFile;
	errno_t err = fopen_s(&oldFile, fileName, "r+");

	if (!err && oldFile != NULL) {
		fseek(oldFile, 0, SEEK_END);
		size_t oldSize = ftell(oldFile);
		fseek(oldFile, 0, SEEK_SET);

		if (oldSize > newSize) {
			char tmpFileName[256];
			err = tmpnam_s(tmpFileName, 255);
			if (!err) {
				err = fopen_s(&newFile, tmpFileName, "w+");
				if (!err && newFile != NULL) {
					char currentCh;
					for (newSize; newSize > 0; newSize--) {
						currentCh = fgetc(oldFile);
						fputc(currentCh, newFile);
						if (currentCh == '\n')//weirdo '\n'
							newSize--;
					}
					fclose(oldFile);
					fclose(newFile);
					remove(fileName);
					err = rename(tmpFileName, fileName);
				}
				if (newFile == NULL)
					err = EINVAL;
			}
		}
		else if (oldSize < newSize) {
			newSize -= oldSize;
			for (newSize; newSize > 0; newSize--)
				fputc('\0', oldFile);
		}
	}
	if (oldFile == NULL)
		err = EINVAL;
	return err;
}