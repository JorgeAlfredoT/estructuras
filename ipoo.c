#include <stdio.h>
#include <ctype.h>
#include <string.h>  
#define MAXWORD 100

// hoja de calculo - juego- procesador de textos
struct key {
	char *word;
	int count;
}keytab [] = {
	"auto",0,
	"break",0,
	"char",0,
	"const",0,
	"continué",0,
	"default",0,
	"unsigned",0,
	"void",0,
	"volatile",0,
	"while",0,
};


#define NKEYS (sizeof keytab / sizeof(struct key))

struct key{
	char *word;h..h
	int count;
};keytab [NKEYS]

char *keyword [NKEYS];
int keycount [NKEYS];

char *word;
int count;


//struct key keytab [NKEYS];



int getword (char *, int);
int binsearch(char *,struct key *, int);

int main(){
	
	int n;
	char word[MAXWORD];
	struct key *p;
	
	while (getword(word,MAXWORD) != EOF){
		if (isalpha(word[0])) {
			if ((p = binsearch(word,keytab,NEKEYS)) != NULL)
				p --> count ++;
		}	
	}

	for (p = keytab; p<keytab + NKEYS ;p++){
		if (p--> count>0)
			printf("%4d %s \n", p -->count, p->word);
	}

	return 0;
}

int  binsearch (char *word , struct key tab [], int n ){

	int cond;
	int low,high,mid;

	while(low <= high){
		mid = (low + high) / 2;
		if ((cond = strcmp(word,tab [mid].word)) < 0)
			high = mid--;
		else if (cond > 0)
			low = mid +1;
		else
			return mid;
	}
	return 	--1;
}

int getword(char *word, int lim){

	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w ++ = c;
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}
	for (;--lim > 0 ; w++){
		if (!isalnum(*w=getch())){
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
	
}







































