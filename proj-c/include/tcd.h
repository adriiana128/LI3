/** @file tcd.h
 *  @brief Protótipos das funções que trabalham com os tcd.
 *
 *  O ficheiro contem os prototipos das funçoes da estrutura tcd.
 *
 *  @author Grupo 19
 */

#ifndef __TCD_H__
#define __TCD_H__

#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <time.h>
#include "date.h"
#include "interface.h"
#include "queriesdata.h"
/**
 * @brief Declaração do tipo TCD_community, um tipo abstrato.
 */
typedef struct TCD_community TCD_community;

/** @brief Inicialização da estrutura.
 *  @return TAD_community.
 */
TAD_community init_tcd();

/** @brief Retorna a hash das tags.
 *  @param TAD_community Estrutura.
 *  @return hash.
 */
GHashTable* get_hash_tags(TAD_community root);
/** @brief Retorna a hash dos users.
 *  @param TAD_community Estrutura.
 *  @return hash.
 */
GHashTable* get_hash_users(TAD_community root);
/** @brief Retorna a hash das quest.
 *  @param TAD_community Estrutura.
 *  @return hash.
 */
GHashTable* get_hash_quest_tcd(TAD_community root);
/** @brief Retorna a hash das answer.
 *  @param TAD_community Estrutura.
 *  @return hash.
 */
GHashTable* get_hash_answer_tcd(TAD_community root);
/** @brief Retorna a tree dos dias.
 *  @param TAD_community Estrutura.
 *  @return tree dos days.
 */
GTree* get_tree_days(TAD_community root);
/** @brief Retorna n posts.
 *  @param TAD_community Estrutura.
 *  @return rank_n_posts.
 */
GSList* get_rank_n_posts(TAD_community root);

GSList* get_best_user_tcd(TAD_community root);

/** @brief Rank n_posts.
 *
 *  @param TAD_community Estrutura.
 *  @param *new apontador para uma nova lista.
 *  @return Void.
 */
void set_rank_n_posts(TAD_community root, GSList *new);

void set_best_user_tcd(TAD_community root, GSList *new);

void load_n_posts_tags_tcd(TAD_community com,int c,query11 aux);

gboolean load_rank_gslist_tcd(gpointer key,gpointer value,gpointer data);

void sort_rank_tcd(TAD_community root);
void sort_best_tcd(TAD_community root);
int isQuest(TAD_community root, long id);
STR_pair get_info_post_tcd(TAD_community root, int x, long id);
LONG_list get_most_active_tcd(TAD_community root, int N);
void query3_tcd(TAD_community root,query3 ld);

void sort_list_tcd(TAD_community root, char c,GCompareFunc func);
void prepend_list_tcd(TAD_community root, char c, void* data);
void foreach_hash_tcd(TAD_community root, char c, GHFunc func, void* data);
void insert_tree_tcd(TAD_community root, void* key, void* value);
void insert_hash_tcd(TAD_community root, char c, void* key, void* value);
/*Liberta a memoria alocada para as estruturas de dados*/
void free_tcd(TAD_community com);


#endif
