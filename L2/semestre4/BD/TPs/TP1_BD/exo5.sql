create table commandes(ncom int primary key check (ncom>0), ncli varchar(10) references clients(ncli) check (ncli > 0), date_commande date);

create table clients(ncli varchar(10) primary key check (ncli > 0), nom varchar(20), adresse varchar(30), localite char(10));

create table produits(npro varchar(10) primary key, libelle varchar(50), prix float check (prix >= 0));

create table details(ncom int references commandes(ncom) check (ncom > 0), npro char(10) references produits(npro), qcom int check (qcom >= 0)); 

insert into clients(ncli,nom,adresse,localite) values ('B512', 'GILLET', '14 r. de l''Eté','Toulouse'),('C400','FERARD','63, r. du Tertre','Poitiers');

insert into commandes(ncom, ncli, date_commande) values(30188,'B512','2016-01-02'),(30179,'C400','2015-12-22');

insert into produits(npro,libelle,prix) values ('CS464', 'Chev. sapin 400x6x4', 220.00),('PA45','Pointe acier 45 (20K)',105.00),('PA60','Pointe acier 60 (10K)',95.00),('PH222','Pl. hetre 200x20x2',230.00),('CS262','Chev. sapin 200x6x2',75.00);

insert into details(ncom,npro,qcom) values (30188,'CS464',180),(30188,'PA45',22),(30188,'PA60',70),(30188,'PH222',92),(30179,'CS262',60),(30179,'PA60',20);

