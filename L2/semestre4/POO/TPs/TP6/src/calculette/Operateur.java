package calculette;
import java.math.BigDecimal;

/**
 * Classe abstraite Operateur.
 *
 * @author BOURDON Antoine-Alexis
 * @version 1.0
 */
public abstract class Operateur {
	public abstract void evaluer(Pile<BigDecimal> lesOperandes) throws ArithException;
	public abstract int getPriorite();
	public abstract char getValeur();
	
	/**
	 * Fonction qui se charge d'évaluer les opérateurs présent sur la pile qui ont une priorité plus grande ou égale à l'opérateur courant.
	 * @param lesOperandes: la pile des operandes.
	 * @param lesOperateurs: la pile des operateurs.
	 */
	public void executer(Pile<BigDecimal> lesOperandes, Pile<Operateur> lesOperateurs) throws ArithException {
		while ((!lesOperateurs.pileVide())&&(lesOperateurs.sommet().getPriorite() >= this.getPriorite())) {		
			lesOperateurs.depiler().evaluer(lesOperandes);
			if (this.getPriorite() == 0) {
				break;
			}
		}
		lesOperateurs.empiler(this);
	}
}
