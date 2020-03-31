package calculette;

import calculette.ICalculette;
import java.math.BigDecimal;

/**
 * Classe qui implemente de la manière la plus simple possible l'interface ICalculette.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public class MaCalculette implements ICalculette {
	// Initialisation de monAfficheur
	Afficheur monAfficheur = new Afficheur();

	// Initialisation des piles
	Pile<BigDecimal> pileBigDecimal = new Pile<BigDecimal>();
	Pile<Operateur> pileOperateur = new Pile<Operateur>();

	// Initialisation des operateurs
	Operateur monOperateurPlus = new OperateurPlus();
	Operateur monOperateurMoins = new OperateurMoins();
	Operateur monOperateurFois = new OperateurFois();
	Operateur monOperateurDiv = new OperateurDiv();
	Operateur monOperateurPO = new OperateurParO();
	Operateur monOperateurPF = new OperateurParF();
	Operateur monOperateurEgal = new OperateurEgal();
	Operateur monOperateurSqrt = new OperateurSqrt();
	Operateur monOperateurLn = new OperateurLn();
	Operateur monOperateurMod = new OperateurMod();
	//Operateur monOperateurMPlus = new OperateurMPlus(); //sert à rien

	// Initialisation pour les M+, MR, MZ
	BigDecimal saveM = new BigDecimal(0);

	//True si un "resultat" est afficher sinon False
	private boolean result = false;

	//True si une parenthèse fermée est mise sinon False
	private boolean parFer = false;
	private boolean error = false;

	/**
	 * Fonction qui affiche le contenu de l'afficheur.
	 * @return : retourne le contenu de l'afficheur.
	 */
	public String valeur() {
		return monAfficheur.toString();
	}

	/**
	 * Fonction qui execute les différents Opérateur (+,-,*,/,sqrt,Ln,%,...) dans les piles pour le calcul.
	 * @param monOperateur : Operateur.
	 */
	public void executeOperateur(Operateur monOperateur) {
		try {
			if (erreurExOperateurNeg(monOperateur.getValeur())){
				empileMonNombre();
			}else{
				pileBigDecimal.empiler(new BigDecimal(0));
			}
			monOperateur.executer(pileBigDecimal, pileOperateur);
			monAfficheur.changeExpression(monOperateur);
		} catch (ArithException e) {
			monAfficheur.setExpression(e.getMessage());
			error = true;
		} catch (NumberFormatException i) {
			monAfficheur.setExpression("Error Expression");
			error = true;
		}
	}

	/**
	 * Fonction qui permet de savoir si ont peut mettre un -(plus) ou un +(plus) comme premier caractère dans l'afficheur.
	 * @param valeurOperand : correspond à la valeur de l'opérande.
	 * @return : vrai si l'afficheur est de taille 0 et si un la valeur de l'opérande est + ou -.
	 */
	public boolean erreurExOperateurNeg(char valeurOperand){
		return (((monAfficheur.getMonExpression().length() != 0)||(monAfficheur.getMonNombre().length() != 0)) || (valeurOperand != '+')&&(valeurOperand != '-'));
	}

	/**
	 * Fonction qui empile le nombre ecrit par l'utilisateur.
	 */
	public void empileMonNombre() {
		reInitResult();
		if (!parFer) {
			pileBigDecimal.empiler(new BigDecimal(monAfficheur.getMonNombre().toString()));
		} else {
			parFer = false;
		}

	}

	/**
	 * Fonction qui reinitialise tout sauf monNombre de l'afficheur.
	 */
	public void reInitResult() {
		if (result) {
			monAfficheur.setMonNombre(pileBigDecimal.sommet().toString());
			monAfficheur.getMonExpression().setLength(0);
			pileBigDecimal.reInit();
			pileOperateur.reInit();
			parFer = false;
			result = false;
		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche chiffre enfoncé par l'utilisateur.
	 * @param c : le chiffre choisi par l'utilisateur.
	 */
	public void enfoncerChiffre(int c) {
		if (error||result) {
			enfoncerRaz();
			error = false;
			result = false;
		}
		// afficheur s'occupe de cela :D
		if (!result) {
			monAfficheur.ajouteChiffre(c);
		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche . (point) enfoncé par l'utilisateur.
	 */
	public void enfoncerPoint() {
		if (!result) {
			monAfficheur.ajoutePoint();
		}
		else{
			BigDecimal tmp = pileBigDecimal.depiler();
			enfoncerRaz();
			monAfficheur.setMonNombre(tmp.toString());
			monAfficheur.ajoutePoint();
		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche + (plus) enfoncé par l'utilisateur.
	 */
	public void enfoncerPlus() {
		if (error) {
			enfoncerRaz();
			error = false;
		}
		// on evalue l'operateur
		executeOperateur(monOperateurPlus);
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche - (moins) enfoncé par l'utilisateur.
	 */
	public void enfoncerMoins() {
		if (error) {
			enfoncerRaz();
			error = false;
		}
		executeOperateur(monOperateurMoins);
	}

	/**
	 *  Fonction qui envoie à l'afficheur la touche * (multiplication) enfoncé par l'utilisateur.
	 */
	public void enfoncerMult() {
		if (error) {
			enfoncerRaz();
			error = false;
		}
		executeOperateur(monOperateurFois);
	}

	/**
	 *  Fonction qui envoie à l'afficheur la touche / (division) enfoncé par l'utilisateur.
	 */
	public void enfoncerDiv() {
		if (error) {
			enfoncerRaz();
			error = false;
		}
		executeOperateur(monOperateurDiv);
	}

	/**
	 *  Fonction qui envoie à l'afficheur la touche √ (racine carrée) enfoncé par l'utilisateur.
	 */
	public void enfoncerSqrt() {
		if (error||result) {
			enfoncerRaz();
			error = false;
		}
		if (!result) {
			if (monAfficheur.getMonNombre().length() == 0) {
				reInitResult();
				// on empile sqrt et ensuite une parenthèse (évaluation dans '('__')' )
				pileOperateur.empiler(monOperateurSqrt);
				monAfficheur.changeExpression(monOperateurSqrt);
				pileOperateur.empiler(monOperateurPO);
				monAfficheur.changeExpression(monOperateurPO);
			}
		}

	}

	/**
	 * Fonction qui envoie à l'afficheur la touche Ln (Logarithme) enfoncé par l'utilisateur.
	 */
	public void enfoncerLn() {
		if (error||result) {
			enfoncerRaz();
			error = false;
		}
		if (!result) {
			if (monAfficheur.getMonNombre().length() == 0) {
				reInitResult();
				//comme sqrt :D
				pileOperateur.empiler(monOperateurLn);
				monAfficheur.changeExpression(monOperateurLn);
				pileOperateur.empiler(monOperateurPO);
				monAfficheur.changeExpression(monOperateurPO);
			}
		}

	}

	/**
	 * Fonction qui envoie à l'afficheur le resultat si l'utilisateur enfonce la touche = (égal).
	 */
	public void enfoncerEgal() {
		try {
			executeOperateur(monOperateurEgal);
			pileOperateur.depiler();
			monAfficheur.setExpression(pileBigDecimal.sommet().toString());
			monAfficheur.reInitMonNombre();
			result = true;
		} catch (ArrayIndexOutOfBoundsException e) {

		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche ( (parenthèse ouvrante) enfoncé par l'utilisateur.
	 */
	public void enfoncerPO() {
		if ((!pileOperateur.pileVide())	&& (monAfficheur.avantDernierCaractEstOperat())) {
			pileOperateur.empiler(monOperateurPO);
			monAfficheur.changeExpression(monOperateurPO);
		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche ) (parenthèse fermante) enfoncé par l'utilisateur.
	 */
	public void enfoncerPF() {
		try {
			if (!result) {
				if (pileOperateur.sommet() == monOperateurPO) {					
					empileMonNombre();
					pileOperateur.empiler(monOperateurPF);	
					monAfficheur.changeExpression(monOperateurPF);
				} else {
					executeOperateur(monOperateurPF);
				}
				// on depile les parenthèse par paire (une ouvrante et une fermante)
				pileOperateur.depiler();
				pileOperateur.depiler();
				if (pileOperateur.sommet().getPriorite() == 3) { //calcul interne pour Prio 3, sinon bug. (Au moment fermeture :D)
					try {
						pileOperateur.depiler().evaluer(pileBigDecimal);
					} catch (ArithException e) {
						monAfficheur.setExpression(e.getMessage());
						error = true;
					}
				}
			}
			parFer = true;
		} catch (ArrayIndexOutOfBoundsException e) {
			monAfficheur.setMonNombre("");
			monAfficheur.setExpression("Error Expression");
			error = true;
		} catch (NumberFormatException i) {
			monAfficheur.setMonNombre("");
			monAfficheur.setExpression("Error Expression");
			error = true;
		}

	}

	/**
	 * Fonction qui envoie à l'afficheur la touche Corr enfoncé par l'utilisateur. Permet d'effacer le dernier chiffre saisi.
	 */
	public void enfoncerCorr() {
		try {
			monAfficheur.enleveUnChiffre();
		} catch (StringIndexOutOfBoundsException e) {

		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche Raz (remise à zero) enfoncé par l'utilisateur.
	 */
	public void enfoncerRaz() {
		monAfficheur.reInit();
		pileBigDecimal.reInit();
		pileOperateur.reInit();
		result = false;
		parFer = false;
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche % (modulo) enfoncé par l'utilisateur.
	 */
  public void enfoncerMod(){
		if (error) {
			enfoncerRaz();
			error = false;
		}
		executeOperateur(monOperateurMod);
	}

	/**
	 * Fonction qui garde en Mémoire le dernier numéro afficher (si l'utilisateur est entrain d'écrire), ou le resultat d'une opération.
	 */
  public void enfoncerMPlus(){
		//Si l'utilisateur veut le nombre qu'il ecrit
		StringBuffer afficheurNum = monAfficheur.getMonNombre();
		if (afficheurNum.length() > 0){
			saveM = saveM.add(new BigDecimal(afficheurNum.toString()));
		}
		//Si l'utilisateur veut le resultat (donc appui egal de sa part)
		else{
			BigDecimal tmp = pileBigDecimal.depiler();
			saveM = saveM.add(tmp);
			pileBigDecimal.empiler(tmp);
		}
	}

	/**
	 * Fonction qui envoie à l'afficheur un changement de signe quand la touche +/- (plus ou moins) est enfoncé par l'utilisateur.
	 */
  public void enfoncerPlusMoins(){
		Operateur tmp;
		try{
		int taille = pileOperateur.getPosition();
		if (taille <=0 ){
			monAfficheur.reInit();
			BigDecimal valInt = pileBigDecimal.depiler();
			enfoncerRaz();
			String valString;
			if (valInt.intValue()>=0){
				enfoncerPlus();
				valString = valInt.toString();
			}
			else{
				enfoncerMoins();
				valString=valInt.toString().substring(1);
				
			}
			monAfficheur.setMonNombre(valString);
		}
		tmp = pileOperateur.depiler();
		if (tmp.getValeur() == '+'){
			tmp = new OperateurMoins();
			monAfficheur.changePlusMoins(tmp);
		}
		else{
			tmp = new OperateurPlus();
			monAfficheur.changePlusMoins(tmp);
		}
		pileOperateur.empiler(tmp);
		}catch (ArrayIndexOutOfBoundsException e) {
			monAfficheur.setExpression("tu pousses le bouchon un peu trop loin Maurice !!! (ça sert à quoi -0 au demarrage ? :D");
			error = true;
		}
	}

	/**
	 * Fonction qui envoie à l'afficheur la touche MR (MRecup) enfoncé par l'utilisateur. Permet d'afficher le numéro dans la mémoire.
	 */
  public void enfoncerMRecup(){
	  	monAfficheur.setMonNombre(saveM.toString());
	}

	/**
	 * Fonction qui supprime le numéro gardé en Mémoire.
	 */
  public void enfoncerMZero(){
		saveM = new BigDecimal(0);
	}
}
