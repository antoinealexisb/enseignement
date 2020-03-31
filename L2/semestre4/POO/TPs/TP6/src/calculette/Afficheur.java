package calculette;

/**
 * classe qui prend en charge la construction du nombre de chiffre après chiffre.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class Afficheur {

	private StringBuffer monExpression;
	private StringBuffer monNombre;
	private boolean point = false;

	/**
	 * Construit une instance d'Afficheur.
	 */
	public Afficheur() {
		monExpression = new StringBuffer();
		monNombre = new StringBuffer();
	}

	/**
	 * Fonction qui renvoie sous la forme d'un String, l'affichage des nombres et des opérateurs.
	 * @return : l'affichage des nombres et des opérateurs.
	 */
	public String toString() {
		if (monNombre.length() == 0) {
			return monExpression.toString();
		} else {
			return (monExpression.toString() + monNombre.toString());
		}
	}

	/**
	 * Fonction qui renvoie l'expression.
	 * @return : revoie l'expression.
	 */
	public StringBuffer getMonExpression() {
		return monExpression;
	}

	/**
	 * Fonction qui renvoie le nombre qui est entrain d'être saisi.
	 * @return : le nombre saisi.
	 */
	public StringBuffer getMonNombre() {
		return monNombre;
	}

	/**
	 * Fonction qui modifie l'expression.
	 * @param result : Expression à mettre.
	 */
	public void setExpression(String result) {
		monExpression.setLength(0);
		monExpression.append(result);
	}
	
	/**
	 * Fonction qui modifie le nombre.
	 * @param nombre : Le nombre sous la forme d'une chaine de caractère.
	 */
	public void setMonNombre(String nombre) {
		monNombre.setLength(0);
		monNombre.append(nombre);
		point = (nombre.indexOf('.') == -1) ? false : true;
	}

	// methode

	/**
	 * Fonction qui ajoute un chiffre au nombre (ou des chiffres).
	 * @param c : Chiffre.
	 */
	public void ajouteChiffre(int c) {
		monNombre.append(c);
	}

	/**
	 * Fonction qui ajoute un point à monNombre.
	 */
	public void ajoutePoint() {
		if (!point) {
			monNombre.append('.');
			point = true;
		}
	}

	/**
	 * Fonction qui enleve le dernier caractère du nombre (soit un chiffre ou un point uniquement).
	 */
	public void enleveUnChiffre() {
		if (monNombre.charAt(monNombre.length() - 1) == '.') {
			point = false;
		}
		monNombre.deleteCharAt(monNombre.length() - 1);
	}

	/**
	 * Fonction qui renvoie vrai si l'avant dernier caractere de l'expression est un opérateur définie parmit "*\/-+%(".
	 * Permet de faire par exemple 4%(2+1).
	 * @return : vrai si l'avant dernier caractère est un opérateur.
	 */
	public boolean avantDernierCaractEstOperat() {

		if ((monExpression.charAt(monExpression.length() - 2) == ('*'))
				|| (monExpression.charAt(monExpression.length() - 2) == ('/'))
				|| (monExpression.charAt(monExpression.length() - 2) == ('-'))
				|| (monExpression.charAt(monExpression.length() - 2) == ('+'))
				|| (monExpression.charAt(monExpression.length() - 2) == ('('))
				|| (monExpression.charAt(monExpression.length() - 2) == ('%'))) {
			return true;
		} 
		return false;
	}

	/**
	 * Fonction qui remet à zero monNombre.
	 */
	public void reInitMonNombre() {
		point = false;
		monNombre.setLength(0);
	}

	/**
	 * Fonction qui remet à zero le nombre et l'expression.
	 */
	public void reInit() {
		reInitMonNombre();
		monExpression.setLength(0);
	}

	/**
	 * Fonction qui ajoute l'opérateur sqrt ou ln correctement (avec les espaces).
	 */
	public void changeExpression(Operateur operand) {
		if (monNombre.length() != 0) {
			monExpression.append(monNombre);
			monExpression.append(' ');
		}
		if (operand.getValeur() != '\u33D1') { //different de Ln
			monExpression.append(operand.getValeur());//donc racine
		} else {
			monExpression.append("ln");
		}
		
		monExpression.append(' ');
		reInitMonNombre();
	}

	/**
	 * Fonction qui change l'expression pour afficher le +(plus) si un -(moins) est présent et inversement.
	 * @param operand : opérateur qui remplace l'opérateur présent.
	 */
	public void changePlusMoins(Operateur operand){
		monExpression.replace(monExpression.length()-2, monExpression.length()-1, String.valueOf(operand.getValeur()));
	}
}
