create table produit (
    fabr char(1),
    modele integer primary key,
    type varchar(10)
);

create table pc (
    modele integer primary key references produit(modele),
    vitesse float check (vitesse > 0),
    ram int check (ram > 0),
    hd int check (hd > 0),
    prix float check (prix > 0)
);

create table portable (
    modele integer primary key references produit(modele),
    vitesse float check (vitesse > 0),
    ram int check (ram > 0),
    hd int check (hd > 0),
    ecran float check (ecran > 0),
    prix float check (prix > 0)
);

create table imprimante (
    modele integer primary key references produit(modele),
    couleur boolean,
    type varchar(10),
    prix float check (prix > 0)
);
