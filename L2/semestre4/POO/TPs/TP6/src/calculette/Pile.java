/**
 * Classe de gestion d'une pile
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */

package calculette;

/**
 * Classe créant une pile d'élèments.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class Pile<type> {
	/** Tableau de double */
	private type[] mesElements;
	/** Position du dernier element dans la pile */
	private int position;

	/**
	 * Fonction qui renvoie la position du dernier element.
	 * @return : la position du dernier element.
	 */
	public int getPosition() {
		return position;
	}

	/**
	 * Constructeur de la pile.
	 */
	@SuppressWarnings(value = "unchecked")
	public Pile() {
		this.mesElements = (type[]) new Object[10];
		this.position = 0;
	}

	/**
	 * Fonction qui enleve l'element aux sommet de la pile et renvoie cet element. 
	 * @return : l'element aux sommet de la pile
	 */
	public type depiler() {
		return mesElements[--position];
	}

	/**
	 * Fonction qui ajoute un element a la pile. 
	 * @param element : un element à ajouter.
	 */
	public void empiler(type element) {
		if (position == mesElements.length) {
			// Pour enlever le warning.
			@SuppressWarnings(value = "unchecked")
			type[] tmp = (type[]) new Object[mesElements.length + 10];
			for (int i = 0; i < mesElements.length; i++) {
				tmp[i] = mesElements[i];
			}
			mesElements = tmp;
		}
		mesElements[position++] = element;
	}

	/**
	 * Fonction qui vérifie si une pile est vide.
	 * @return return vrai si la pile est vide.
	 */
	public boolean pileVide() {
		return position == 0;
	}

	/**
	 * Fonction qui initialise la pile avec une position à 0.
	 */
	public void reInit() {
		position = 0;
	}


	/**
	 * Fonction qui retourne l'element au sommet de la pile sans l'enlever.
	 * @return : le dernier element de la pile.
	 */
	public type sommet() {
		return mesElements[position - 1];
	}

}
