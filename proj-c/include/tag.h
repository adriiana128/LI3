/** @file tag.h
 *  @brief Protótipos das funções que trabalham com as Tag.
 *
 *  O ficheiro contem os prototipos das funçoes da estrutura Tag.
 *
 *  @author Grupo 19
 */

#ifndef __TAG_H__
#define __TAG_H__

#include "common.h"
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Declaração do tipo Tag, um tipo abstrato.
 */
typedef struct tag* Tag;

/** @brief Criação das Tags.
 *  @param id id da tag.
 *  @param tag tag pretendida.
 *  @param t_ctag count tag.
 *  @return Tag.
 */
Tag create_tag(long id,char* tag);

//Setters

/** @brief Id da Tag.
 *
 *  @param t Tag.
 *  @param id_out id tag.
 *  @return Void.
 */
void set_id_tag (Tag t, long id_out);
/** @brief Tag.
 *
 *  @param t Tag.
 *  @param g_tag tag dada.
 *  @return Void.
 */
void set_tag (Tag t, char* g_tag);
/** @brief Nº de vezes que a tag foi usada.
 *
 *  @param t Tag.
 *  @param count_tag nº de vezes que uma tag é usada.
 *  @return Void.
 */
void inc_n_used (Tag t);

//Getters

/** @brief Retorna o id da tag.
 *
 *  @param t Tag.
 *  @return Id da Tag.
 */
long get_id_tag (Tag t);
/** @brief Retorna a tag pretendida.
 *
 *  @param t Tag.
 *  @return Tag.
 */
char* get_tag (Tag t);
/** @brief Retorna o nº de vezes que uma tag é usada.
 *
 *  @param t Tag.
 *  @return Nº de vezes que uma tag é usada.
 */
int get_n_used (Tag t);

//Métodos
int equal_tag(Tag t,char* s);

int comp_n_used_tag(gconstpointer a,gconstpointer b);

void tag_list11(gpointer key,gpointer value,gpointer data);

void load_n_used_tag(gpointer value,gpointer data);

void print_tag(Tag t);

/** @brief Liberta o espaço ocupado pela tag.
 *
 *  @param Tag.
 *  @return Void.
 */
 /** @brief Coloca todos os n_used a 0
  *
  * @param Hash de Tags
  * @return void 
  */
void clean_tags(GHashTable* tags);
void free_tag(Tag t);
void free_g_tag(gpointer g);
#endif
