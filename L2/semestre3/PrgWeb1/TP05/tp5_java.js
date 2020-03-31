//EXO 1
function infoPopup(){
    ch = ""
    tab = navigator.plugins; 

    ch = "vous utilisez " + navigator.appName + ". \n vous utilisez la version "+ navigator.appVersion + ". \nvous utilisez la plateforme" + navigator.platform + ". \nl'useragent est" + navigator.userAgent + ". \n les plugins installés sont : ";

    for (i=0;i < tab.length;i+= 1) ch =ch + tab[i]; // renvoie la liste des plugins installés
    alert (ch);
};
infoPopup();

//EXO 2

//question 3
function infoTitre(){
	alert(document.title);
}

infoTitre();
//question 4
//document.getElementsByTagName("h1")[0].innerHTML="coucou le test";

function changerTitre(){
    body = document.body; //met dans une variable l'intégralité du texte entre les balises body --> c'est un objet aussi
    for (i = 0; i < body.childNodes.length; i += 1) { //boucle qui parcours les noeuds pour trouver h1
        node = body.childNodes[i];
        if (node.nodeName === "H1") { //compare le nom du noeud
            node.firstChild.nodeValue += " (DOM)"; //prend le premier fils du noeud est ajoute (DOM) à la valeur
        }
    }
};

changerTitre();

//question5
//function to_up(n){
//    if (typeof(node)!=='object')
//        return null;
//    if ( node.nodeType === Node.TEXT_NODE)
        
function nodeMasjuscule(node){
    for (i = 0; i < node.childNodes.length; i += 1) {
        n = node.childNodes[i];
        if (n.nodeType === node.TEXT_NODE) {
            n.nodeValue = n.nodeValue.toUpperCase();
        }
    }
};

nodeMasjuscule(document.body.childNodes[1])

//question6

function h1UpperCase(){
    body = document.body; //met dans une variable l'intégralité du texte entre les balises body --> c'est un objet aussi
    for (i = 0; i < body.childNodes.length; i += 1) { //boucle qui parcours les noeuds pour trouver h1
        node = body.childNodes[i];
        if (node.nodeName === "H1"){ //compare le nom du noeud
            node.firstChild.nodeValue = node.firstChild.nodeValue.toUpperCase(); //prend le premier fils du noeud est met en majuscule
            return None;
        }
    }
};


//question7

/* Version d'avant (mais manque d'explication consignes :'( )
function h1UpperRec (node=document.body.childNodes[0],i=0) {
	if (node === document.body.childNodes[document.body.childNodes.length-1]) {
		return None;
	}
	if ((node.nodeName === "H1") || (node.nodeName ==="H2")) {
		node.firstChild.nodeValue = node.firstChild.nodeValue.toUpperCase();
	}
	h1UpperRec(document.body.childNodes[i+1],i+1);
}*/


function h1UpperRec (node) {
    if (node.nodeType === node.TEXT_CODE) {
        node.nodeValue = node.nodeValue.toUpperCase();
    } else {
        for (i = 0; i < node.childNodes.length; i += 1) {
            h1UpperRec(node.childNodes[i])
            }
        }
};
