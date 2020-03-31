import com.sun.jdi.FloatValue;

/** classe qui modélise la gestion d’un étudiant dans une université.
*/
public class Etudiant {
    public final static int MAXNOTES = 5;
    public final static int MINVALUE = 0;
    public final static int MAXVALUE = 20;
    public final static int MINMOYENNE = 10;

    private String nom;
    private String prenom;

    //private Formation formation;

    private float[] lesNotes = new float[MAXNOTES];
    private int nbNotes; // nombre actuel de notes de l’étudiant

    /** Constructeur d’un étudiant.
    @param nom : le nom de l’étudiant
    @param prenom : le prénom de l’étudiant
    */

    public Etudiant(String nom, String prenom) {
        this.nom = nom;
        this.prenom = prenom;
        }

    /** accesseur pour le nom de l’étudiant
    @return le nom de l’étudiant */
    public String getNom(){
        return nom;
    }

    /** accesseur pour le prénom de l’étudiant
    @return le prénom de l’étudiant */
    public String getPrenom(){
        return prenom;
    }

    /** retourne une présentation textuelle d’un étudiant :
    son nom, son prénom, son nombre de notes */
    public String toString(){
        return prenom+" "+nom+", "+nbNotes+" note(s).";
    }

    /** ajoute une note à un étudiant dans la limite de la capacité de l’étudiant
    @param note : la note qu’on veut ajouter à l’étudiant
    @return vrai si l’ajout a pu être fait */
    public boolean ajouteNote(float note){
        if (nbNotes < lesNotes.length){
            lesNotes[nbNotes] = note;
            nbNotes++;
            return true;
        }
        else if(!valider()){
            int indice = indicePetit();
            return true;
        }
        return false;
    }

    /**
     * Renvoit la moyenne des notes de l'étudiant.
     * @return : Moyenne des notes
     */
    public float moyenne(){
        float sum;
        for (int i=0; i< nbNotes; i++)
        {
            sum += lesNotes[i];
        }
        return sum/nbNotes;
    }

    /** Renvoit un boolean pour savoir si l'étudiant est admis.
     * @return : vrai si l'étudiant à valider est admis. 
     */
    public boolean valider(){
        return ((moyenne()>=10) && (nbNotes==MAXNOTES)) ? True : False;
    }

}
