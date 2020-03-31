package calculette;

/**
 * Interface ICalculette.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public interface ICalculette {

	/**
	 * Fonction qui affiche le contenu de l'afficheur.
	 * @return : retourne le contenu de l'afficheur.
	 */
    public String valeur();

	/**
	 * Fonction qui envoie à l'afficheur la touche chiffre enfoncé par l'utilisateur.
	 * @param c : le chiffre choisi par l'utilisateur.
	 */
    public void enfoncerChiffre(int c);

	/**
	 * Fonction qui envoie à l'afficheur la touche . (point) enfoncé par l'utilisateur.
	 */
    public void enfoncerPoint();

	/**
	 * Fonction qui envoie à l'afficheur la touche ( (parenthèse ouvrante) enfoncé par l'utilisateur.
	 */
    public void enfoncerPO();

	/**
	 * Fonction qui envoie à l'afficheur la touche ) (parenthèse fermante) enfoncé par l'utilisateur.
	 */
    public void enfoncerPF();

	/**
	 * Fonction qui envoie à l'afficheur la touche + (plus) enfoncé par l'utilisateur.
	 */
    public void enfoncerPlus();

	/**
	 * Fonction qui envoie à l'afficheur la touche - (moins) enfoncé par l'utilisateur.
	 */
    public void enfoncerMoins();

	/**
	 *  Fonction qui envoie à l'afficheur la touche * (multiplication) enfoncé par l'utilisateur.
	 */
    public void enfoncerMult();

	/**
	 *  Fonction qui envoie à l'afficheur la touche / (division) enfoncé par l'utilisateur.
	 */
    public void enfoncerDiv();

	/**
	 * Fonction qui envoie à l'afficheur la touche % (modulo) enfoncé par l'utilisateur.
	 */
    public void enfoncerMod();

	/**
	 *  Fonction qui envoie à l'afficheur la touche √ (racine carrée) enfoncé par l'utilisateur.
	 */
    public void enfoncerSqrt();

	/**
	 * Fonction qui envoie à l'afficheur la touche Ln (Logarithme) enfoncé par l'utilisateur.
	 */
    public void enfoncerLn();

	/**
	 * Fonction qui envoie à l'afficheur la touche Corr enfoncé par l'utilisateur. Permet d'effacer le dernier chiffre saisi.
	 */
    public void enfoncerCorr();

	/**
	 * Fonction qui envoie à l'afficheur la touche Raz (remise à zero) enfoncé par l'utilisateur.
	 */
    public void enfoncerRaz();

	/**
	 * Fonction qui envoie à l'afficheur le resultat si l'utilisateur enfonce la touche = (égal).
	 */
    public void enfoncerEgal();

	/**
	 * Fonction qui envoie à l'afficheur un changement de signe quand la touche +/- (plus ou moins) est enfoncé par l'utilisateur.
	 */
    public void enfoncerPlusMoins(); 
    
	/**
	 * Fonction qui garde en Mémoire le dernier numéro afficher (si l'utilisateur est entrain d'écrire), ou le resultat d'une opération.
	 */
    public void enfoncerMPlus();

	/**
	 * Fonction qui envoie à l'afficheur la touche MR (MRecup) enfoncé par l'utilisateur. Permet d'afficher le numéro dans la mémoire.
	 */
    public void enfoncerMRecup();

	/**
	 * Fonction qui supprime le numéro gardé en Mémoire.
	 */
    public void enfoncerMZero();
}
