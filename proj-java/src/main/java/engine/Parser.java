/** @file Parser.java
 *  @brief Funções que trabalham com o Parser.
 *
 *  @author Grupo 19
 */

package engine;

import javax.xml.stream.XMLStreamException;
import java.io.FileNotFoundException;

import java.time.LocalDate;
import java.util.HashMap;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.File;
import java.lang.Number;
import java.util.Iterator;
import javax.xml.stream.*;
import javax.xml.namespace.QName;
import javax.xml.stream.events.XMLEvent;

public class Parser{
//Cria uma tag e insere-a na estrutura das tags.
    public void parseTags(TCD data,String file) {
        int ev;
        String text,TagName;
        long Id;
        int Count;
        try{
            XMLInputFactory xmlif = XMLInputFactory.newInstance();
            xmlif.setProperty(XMLInputFactory.IS_COALESCING,true);
            XMLStreamReader xmlr = xmlif.createXMLStreamReader(new FileInputStream(new File(file)));
            while(xmlr.hasNext()) {
				ev = xmlr.next();
				if(ev == XMLStreamConstants.START_ELEMENT) {
					text = xmlr.getLocalName();
					if (text.equals("row")) {
						Id = Long.parseLong(xmlr.getAttributeValue(null, "Id"),10);               
						TagName = xmlr.getAttributeValue(null, "TagName");  
                        Count = Integer.parseInt(xmlr.getAttributeValue(null, "Count"));
                        Tag t = new Tag(Id,TagName,Count);
                        data.addTag(t);
                    }
				}
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
   }

//Cria um novo user e insere-o na estrutura dos users.
   public void parseUsers(TCD data,String file) {
        int ev;
        long id = -2,reputation;
        String name, aboutMe, text;
        try{
            XMLInputFactory xmlif = XMLInputFactory.newInstance();
            xmlif.setProperty(XMLInputFactory.IS_COALESCING,true);
            XMLStreamReader xmlr = xmlif.createXMLStreamReader(new FileInputStream(new File(file)));
            while(xmlr.hasNext()) {
				ev = xmlr.next();
				if(ev == XMLStreamConstants.START_ELEMENT) {
					text = xmlr.getLocalName();
					if (text.equals("row")) {
						id = Long.parseLong(xmlr.getAttributeValue(null, "Id"));
						reputation = Long.parseLong(xmlr.getAttributeValue(null, "Reputation"));
						name = xmlr.getAttributeValue(null, "DisplayName");  
						aboutMe = xmlr.getAttributeValue(null, "AboutMe");  
                        if(id!=-1 && id!=-2){
                            User u = new User(id,name,aboutMe,reputation,0,new HashMap<Long,Post>());
                            data.addUser(u);
                        }
                    }
				}
            }
        } catch (FileNotFoundException eis) {
            eis.printStackTrace();
        } catch (XMLStreamException eis) {
            eis.printStackTrace();
        }
    }

//Cria um novo post e insere-o na estrutura dos posts.
    public void parsePosts(TCD data,String file) {
        int ev, score, nComment, nAnswer;
        long id = -2, pId, userId;
        LocalDate date;
        String text, title, tags;
        try{
            XMLInputFactory xmlif = XMLInputFactory.newInstance();
            xmlif.setProperty(XMLInputFactory.IS_COALESCING,true);
            XMLStreamReader xmlr = xmlif.createXMLStreamReader(new FileInputStream(new File(file)));
            while(xmlr.hasNext()) {
				ev = xmlr.next();
				if(ev == XMLStreamConstants.START_ELEMENT) {
					text = xmlr.getLocalName();
					if (text.equals("row")) {
                        id = Long.parseLong(xmlr.getAttributeValue(null, "Id"));
                        date = LocalDate.parse(xmlr.getAttributeValue(null, "CreationDate").substring(0,10));               
                        score = Integer.parseInt(xmlr.getAttributeValue(null, "Score"));
                        if(xmlr.getAttributeValue(null, "OwnerUserId") != null)
                        userId = Long.parseLong(xmlr.getAttributeValue(null, "OwnerUserId"));
                        else userId = 0;
                        nComment = Integer.parseInt(xmlr.getAttributeValue(null, "CommentCount"));
                        if(id != -1 && id != -2)
                            if(xmlr.getAttributeValue(null,"PostTypeId").equals("1")){
                                title = xmlr.getAttributeValue(null, "Title");
                                tags = xmlr.getAttributeValue(null, "Tags");
                                nAnswer = Integer.parseInt(xmlr.getAttributeValue(null, "AnswerCount"));
                                Quest q = new Quest(id, date, score, userId, nComment, title, tags, nAnswer);
                                data.addPost(q);
                            } else if(xmlr.getAttributeValue(null,"PostTypeId").equals("2")){
                                pId = Long.parseLong(xmlr.getAttributeValue(null,"ParentId"));
                                Answer a = new Answer(id, date, score, userId,nComment,pId);
                                data.addPost(a);
                                data.addToQuest(a);
                            }
                    }
				}
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
    }
}
