/*QUESTTION 1-2*/
function Joujou(nom='', poids=0, prix=0, volume=0, dest='', estEmballe=false) {
    this.nom = nom;
    this.poids = poids;
    this.prix = prix;
    this.volume = volume;
    this.estEmballe = estEmballe;
    this.dest = dest;
}

Joujou.prototype.toString = function(){
    var res = "";
    res += "Nom :" + this.nom + '\n';
    res += "Poids :" + String(this.poids) + "g" + '\n';
    res += "Prix :" +  String(this.prix) + "€" + '\n';
    res += "Volume :" + String(this.volume) + "m3" + '\n';
    res += "Destinataire :" + this.dest + '\n';
    if (this.estEmballe){
        res += "Le joujou est emballé";
    } else {
        res += "Le joujou n'est pas emballé";
    }
    return res;
}

Joujou.prototype.emballe = function(){
    this.estEmballe = true;
}

/*QUESTION 3-4*/
function Hotte(joujoux = [], poidsMax=0, volMax=0) {
    this.joujoux = joujoux;
    this.poidsMax = poidsMax; //poid max de la hotte
    this.volMax = volMax; //volume max de la hottee
}

/*toString(): renvoie une chaine de caractère représentant la hotte.*/
Hotte.prototype.toString = function(){
    var res = "";
    res += "Poids Max de la Hotte : " + String(this.poidsMax) + " g" + '\n';
    res += "Volume Max de la Hotte : " + String(this.volMax) + " m3" + '\n';
    
    if (this.joujoux.length == 0){
       res += "Liste des jouets est vide:" + '\n';     
    } else {
        res += "Liste des jouets :" + '\n' + '\n'; 
        this.joujoux.forEach(function(joujou){
            res += joujou + '\n' + '\n';
        });
    }
    return res;
}

/*poidsContenu() : getter renvoyant la poids total du contenu de la hotte*/
Object.defineProperty(Hotte.prototype,"poidsContenu",{
    get : function(){
        var res = 0;
        this.joujoux.forEach(function(joujou){
            res += joujou.poids;
        });
        return res;
    }
});

/*volumeCOntenu() : getter renvoyant le volume total du contenu de la hotte.*/
Object.defineProperty(Hotte.prototype,"volumecontenu",{
    get : function(){
        var res = 0;
        this.joujoux.forEach(function(joujou){
            res += joujou.volume;
        });
        return res;
    }
});

/*sontEmballés() : vrai si tous les joujoux de la hotte sont emballés, faux sinon.*/
Hotte.prototype.sontEmballes = function(){
    var res = true;
    this.joujoux.forEach(function(joujou){
        if (joujou.estEmballe){
            res = false;
        }
    });
    return res;
}
/* VERIFIER AU DESSUS AA, BIZARRE DE TETE*/

/*emballeTout() : fait en sorte que tous les jouxjours soient emballés.*/
Hotte.prototype.emballeTout = function(){
    this.joujoux.forEach(function(joujou){
        joujou.emballe();
    });
}

/*ajoutejoujou(joujou): ajoute le joujou si celui-ci n'excède pas le poids
 * et le volume disponibles de la hotte. Renvoie vrai si le joujou a été ajouté,
 * faux sinon*/
 Hotte.prototype.ajouteJoujou = function(joujou){
	var res = this.poidsContenu;
    if (res - joujou.poids > 0){
        this.joujoux.push(joujou);
        return true;
    }
    return false;
 }
 
 /*cherchejoujoux(dest) : donne la liste des jouxjoux dont le destinaire est dest*/
 Hotte.prototype.chercheJoujoux = function(dest){
    var res = [];
    this.joujoux.forEach(function(joujou){
        if (joujou.dest == dest){
            res.push(joujou);
        }
    });
    return res;
}

/*retirejoujoux(dest) : retire de la hotte l'ensemble des joujoux du dictionnaire 
 * dest*/
Hotte.prototype.retireJoujoux = function(dest){
    var i;
    for (i = 0; i< this.joujoux.length; i++){
        if (this.joujoux[i].dest == dest){
            this.joujoux.splice(i,1);
        }
    }
}

/* Les jouets*/
var jouet1=new Joujou('Un Anthony sauvage', 80000,15, 0.45, 'Faculté Jean-Perrin');
var jouet2=new Joujou('Peluche', 150, 20, 0.2, "Antoine-Alexis Bourdon");
var jouet3=new Joujou("Une licorne", 0,0,0,"Marie");

/* Emballage par les nains */
jouet1.emballe();

var tab=[jouet1,jouet2]; //emballé, non emb.
var hohoho = new Hotte(tab,20000,30); // la petite hotte du papa noël
hohoho.ajouteJoujou(jouet3); //ajoute ma petite licorne
hohoho.retireJoujoux("Faculté Jean-Perrin"); //on retire à la falculté Anthony car c'est mieux pour eux :D
console.log(hohoho.toString()); //affiche :D

/*sortie les joujoux appartenant à Marie*/
var trouver = hohoho.chercheJoujoux("Marie");
for (var i = 0; i < trouver.length; i++){
    console.log(trouver[i].toString());
}

