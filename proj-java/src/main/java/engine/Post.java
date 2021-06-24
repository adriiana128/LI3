/** @file Post.java
 *  @brief Funções que trabalham com os Post.
 *
 *  @author Grupo 19
 */

package engine;
import java.time.LocalDate;
import java.lang.StringBuilder;
import java.lang.Object;

public abstract class Post{
    //variaveis de instancia
    private long id; /* Id de um post. */
    private LocalDate creationDate; /* Data de criação de um post. */
    private int score; /* Score de um post. */
    private long ownerUserId; /* Id de um user que elaborou um determinado post. */
    private int comment_c; /* Nº de comentários que um determinado post tem. */

    public Post(long id){
        this.id = id;
        this.creationDate = LocalDate.now();
        this.score = 0;
        this.ownerUserId = -2;
        this.comment_c =0;
    }
    //unico metodo de criação necessario
    public Post(long id,LocalDate creationDate, int score, long ownerUserId, int comment_c){
        this.id = id;
        this.creationDate = creationDate;
        this.score = score;
        this.ownerUserId = ownerUserId;
        this.comment_c = comment_c;
    }
    public Post(Post p){
        this.id = p.getId();
        this.creationDate = p.getDate();
        this.score = p.getScore();
        this.ownerUserId = p.getUser();
        this.comment_c = p.getComment();
    }
    //Setters
    public void setId(long id) {
        this.id = id;
    }
    public void setCreationDate(LocalDate creationDate) {
        this.creationDate = creationDate;
    }
    public void setScore(int score) {
        this.score = score;
    }
    public void setOwnerUserId(long ownerUserId) {
        this.ownerUserId = ownerUserId;
    }
    public void setComment_c(int comment_c) {
        this.comment_c = comment_c;
    }

    //Getters
    public long getId(){
        return id;
    }
    public LocalDate getDate(){
        return creationDate;
    }
    public int getScore(){
        return score;
    }
    public long getUser(){
        return ownerUserId;
    }
    public int getComment(){
        return comment_c;
    }
    //Clone
    public abstract Post clone();

    //Equals
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Post object = (Post) o;

        if (id != object.id) return false;
        if (creationDate != null ? !creationDate.equals(object.creationDate) : object.creationDate != null) return false;
        if (score != object.score) return false;
        if (ownerUserId != object.ownerUserId) return false;
        return !(comment_c != object.comment_c);
    }

    //toString
    public String toString() {
        final StringBuilder sb = new StringBuilder("Post{");
        sb.append("id = ").append(id);
        sb.append(", creationDate = ").append(creationDate);
        sb.append(", score = ").append(score);
        sb.append(", ownerUserId = ").append(ownerUserId);
        sb.append(", comment_c = ").append(comment_c);
        return sb.append("}").toString();
    }

}
