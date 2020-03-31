/**
 * Classe qui moélise la gestion d'une promotion d'étudiants.
 */
public class Promo{
    public final static int MAXETUDIANTS = 30;
    private Etudiant[] etudiants = new Etudiant[MAXETUDIANTS];
    private int nb_etudiants = 0;


    /**
     * ajoute un etudiant dans la promo dans la limite de la capacité de la promo.
     * @param nom : le nom de l'etudiant
     * @param pernom : le prenom de l'etudiant
     * @return : return l'etudiant créer (permet de faire e1 = AjouteEtudiant('bili','bob'); e1.AjouteNote(10);)
     */
    public Etudiant AjouteEtudiant(String nom, String pernom){
        if (nb_etudiants < MAXETUDIANTS){
            etudiants[nb_etudiants] = Etudiant(nom,prenom);
            nb_etudiants++;
        }
        return etudiants[nb_etudiants-1];
    }

    /**
     * Ajoute une note à l'étudiant ce trouvant à l'indice donné.
     * @param note : La note que reçoit l'étudiant.
     * @param indice : L'indice où se situe l'étudiant.
     * @return : vrai si la note a été ajoutée .
     */
    public boolean AjouteNote(float note, int indice){
        if (indice < nb_etudiants){
            return etudiants[indice].ajouteNote(note);
        }
        return False;
    }


}
