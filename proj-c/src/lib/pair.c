#include <stdlib.h>
#include <string.h>
#include <common.h>
#include "pair.h"

/* Definição da estrutura das str_pair. */
struct str_pair {
  char* fst; /* Primeiro elemento. */
  char* snd; /* Segundo elemento. */
};

/* Função reponsável pela criação da str_pair. */
STR_pair create_str_pair(char* fst, char* snd) {
  STR_pair p = malloc(sizeof(struct str_pair));
  p->fst = mystrdup(fst);
  p->snd = mystrdup(snd);
  return p;
}

/* Gets (Obter valor das variaveis da estrutura) */
void set_fst_str(STR_pair pair, char* str) {
  free(pair->fst);
  pair->fst = mystrdup(str);
}

void set_snd_str(STR_pair pair, char* str) {
  free(pair->snd);
  pair->snd = mystrdup(str);
}

char* get_fst_str(STR_pair pair) {
  return pair? mystrdup(pair->fst) : NULL;
}

char* get_snd_str(STR_pair pair) {
  return pair? mystrdup(pair->snd) : NULL;
}

/* Apaga a str_pair dando free na memoria alocada. */
void free_str_pair(STR_pair pair) {
  if(pair) {
    free(pair->fst);
    free(pair->snd);
    free(pair);
  }
}

/* Definição da estrutura dos long_pair. */
struct long_pair {
  long fst; /* . */
  long snd; /* . */
};

/* Função reponsável pela criação do long_pair. */
LONG_pair create_long_pair(long fst, long snd) {
  LONG_pair p = malloc(sizeof(struct long_pair));
  p->fst = fst; 
  p->snd = snd;
  return p;
}

/* Gets (Obter valor das variaveis da estrutura) */
void set_fst_long(LONG_pair pair, long l) {
  pair->fst = l;
}

void set_snd_long(LONG_pair pair, long l) {
  pair->snd = l;
}

long get_fst_long(LONG_pair pair) {
  return pair->fst;
}

long get_snd_long(LONG_pair pair) {
  return pair->snd;
}

/* Apaga o long_pair dando free na memoria alocada. */
void free_long_pair(LONG_pair pair) {
    free(pair);
}


