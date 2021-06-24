#include "quest.h"
#include <string.h>
/* Definição da estrutura das perguntas (quest). */
struct quest{
    long id; /* Id da quest. */
    Date creationDate; /* Data de criação da quest. */
    int score; /* Pontuação da quest. */
    long ownerUserId; /* Id do user que elaborou a quest. */
    char* title; /* Título da pergunta. */
    char* tags; /* Tag da pergunta. */
    int answer_c; /* Nº de answer. */
    int comment_c; /* Nº de comentários que a quest obteve. */
    int favorite_c; /* Nº de votos favoritos. */
    GSList* answerList; /* Lista das answer de uma quest. */
};

/* Função que inicia a estrutura quest. */
Quest init_quest(long id, Date cd, int s,long ouid, char* ti, char* ta, int ac,
        int cc){
    Quest q = malloc(sizeof(struct quest));
    q -> id = id;
    q -> creationDate = cd;
    q -> score = s;
    q -> ownerUserId = ouid;
    q -> title = mystrdup(ti);
    q -> tags = mystrdup(ta);
    q -> answer_c = ac;
    q -> comment_c = cc;
    q -> answerList = NULL;
    return q;
}

/* Gets (Obter valor das variaveis da estrutura) */
long get_id_quest(Quest q){
    return q->id;
}
Date get_date_quest(Quest q){
    Date d = q->creationDate;
    return createDate(get_day(d),get_month(d),get_year(d));
}
int get_score_quest(Quest q){
    return q->score;
}
long get_owner_id_quest(Quest q){
    return q->ownerUserId;
}
char* get_title_quest(Quest q){
    return mystrdup(q->title);
}
char* get_tags_quest(Quest q){
    return mystrdup(q->tags);
}
int get_answer_c_quest(Quest q){
    return q->answer_c;
}
int get_comment_c_quest(Quest q){
    return q->comment_c;
}
int get_favorite_c_quest(Quest q){
    return q->favorite_c;
}
GSList* get_answer_list_quest(Quest q){
    if(q)
        return q->answerList;
    return NULL;
}

void set_answer_list_quest(Quest q,GSList* l){
    if(q)
        q->answerList = l;
}

void set_tags_quest(Quest q,char* t){
    if(q)
        q->tags = mystrdup(t);
    free(t);
}

static int id_compare_quest(long a,long b){
    if(a>b)
        return -1;
    else
        return 1;
    return 0;
}

int compare_quest(gconstpointer t1, gconstpointer t2){
    Date d1 = get_date_quest((Quest)GPOINTER_TO_SIZE(t1));
    Date d2 = get_date_quest((Quest)GPOINTER_TO_SIZE(t2));
    long id1 = get_id_quest((Quest)GPOINTER_TO_SIZE(t1));
    long id2 = get_id_quest((Quest)GPOINTER_TO_SIZE(t2));
    int c = 0;
    c = (-1)*date_compare(d1,d2);
    if(!c)
       c = id_compare_quest(id1,id2);
    return c;
}

//Funcao de comparação de score para ordenar uma lista ligada.
gint  answer_c_compare_quest(gconstpointer a,gconstpointer b){
    int f = get_answer_c_quest((Quest)a);
    int s = get_answer_c_quest((Quest)b);
    if(f<s) return 1;
    else if(f>s) return -1;
    else return compare_quest(a,b);
}

void comp_tags_quest(gpointer key,gpointer value,gpointer data){
    query4 ld = (query4)GPOINTER_TO_SIZE(data);
    char* t = get_tag_4(ld);
    GSList* l = get_list_4(ld);

    if (strstr(get_tags_quest(value),t)){
        set_list_4(ld,g_slist_prepend(l,value));
    }

}

void comp_words_quest(gpointer key, gpointer value, gpointer data){
    query8  aux = (query8) GPOINTER_TO_SIZE(data);
    char* w = get_word_8(aux);
    char* t = get_title_quest((Quest)value);
    if(strstr(t,w)){
        set_list_8(aux,g_slist_prepend(get_list_8(aux),value));
    }
    free(t);
}

/*adiciona o id da quest na hash*/
void iter_quest9(gpointer data, gpointer user_data){
    if(data != NULL){
        GHashTable* h = (GHashTable*)GPOINTER_TO_SIZE(user_data);
        Quest q = (Quest)GPOINTER_TO_SIZE(data);
        g_hash_table_add(h,GSIZE_TO_POINTER(get_id_quest(q)));
    }
}

//Imprimir o conteudo da pergunta.
void print_quest(Quest q){
    if(q != NULL){
    print_date(q->creationDate);
    printf("Quest:\n\n\t Id: %ld\n\tScore: %d\n\tOwnerUserID: %ld\n\tTitle: %s\n\tI Tags: %s\n\t Answer_c: %d\n\tComment_c: %d\n\tFavorite_c: %d\n\t",
            q->id,q->score,
            q->ownerUserId,q->title,q->tags,q->answer_c,q->comment_c,q->favorite_c);
    printf("\n\n");
    }
}

/* Função resposável por adicionar as answers às quests. */
void add_answer_quest(Quest q, Answer a){
    GSList* l = q->answerList;
    q->answerList = g_slist_prepend(l,a);
}

void free_quest(Quest q){
    if(q){
        free_date(q->creationDate);
        free(q -> title);
        free(q -> tags);
        g_slist_free(q->answerList);
        free(q);
    }
}
void free_g_quest(gpointer g){
    Quest q = (Quest)GPOINTER_TO_SIZE(g);
    free_quest(q);
}
