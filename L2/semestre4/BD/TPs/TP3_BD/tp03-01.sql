drop table if exists achat;
drop table if exists client;
drop table if exists produit;

create table client
       (numcl 	integer ,
        nomcl 	varchar(15),
        codepostal numeric(5),
	constraint pk_client primary key(numcl));
   
create table produit
	(nprod 	integer ,
 	 libprod 	varchar(20),
 	 coulprod 	varchar(10),
 	 qstock 	integer ,
	 constraint pk_produit primary key(nprod)); 

create table achat
	(numcl 	integer ,
	 nprod 	integer ,
	 date_cmd date,
	 qcmd	integer,
	 constraint pk_achat primary key (numcl,nprod, date_cmd));


insert into client values(101,'DEFRERE', 56800);
insert into client values(102,'JACOB', 62000);
insert into client values(103,'JAMAR', 13080);
insert into client values(104,'DELVENNE', 93000);
insert into client values(105,'RAMJOIE', 75000);
insert into client values(106,'RIFFLET',59700);
insert into client values(107,'STOECKEL',61200);
insert into client values(108,'ANGELL', 22200);
insert into client values(109,'SMINE',10120);
insert into client values(110,'ANGELLA', 22200);
insert into client values(111,'SMINETTE',10120);
insert into client values(112,'SMINETA',10120);
insert into client values(113,'JAMARIO',61200);
insert into client values(114,'JACOBIN', 59700);
insert into client values(115,'JACKPOT', 13080);

insert into produit values(1,'AGRAFEUSE','ROUGE',150);
insert into produit values (2,'CALCULATRICE','NOIR',200);
insert into produit values (3,'CACHET-DATEUR','BLANC',21);
insert into produit values (4,'LAMPE','ROUGE',105);
insert into produit values (5,'LAMPE','BLANC',100);
insert into produit values (6,'LAMPE','BLEU',0);
insert into produit values (7,'LAMPE','VERT',105);
insert into produit values (8,'PESE-LETTRE',NULL,120);
insert into produit values (10,'CRAYON','ROUGE',10);
insert into produit values (11,'CRAYON','BLEU',30);
insert into produit values (12,'CRAYON LUXE','ROUGE',30);
insert into produit values (13,'CRAYON LUXE','VERT',35);
insert into produit values (14,'CRAYON LUXE','BLEU',40);
insert into produit values (15,'CRAYON LUXE','NOIR',0);
insert into produit values (16,'AGENDA','ROUGE',100);
insert into produit values (17,'CLASSEUR SOUPLE','VERT',135);
insert into produit values (18,'CLASSEUR RIGIDE',NULL,40);
insert into produit values (19,'STYLO CORRECTEUR','NOIR',50);
insert into produit values (20,'GOMME','JAUNE',105);
insert into produit values (21,'AGRAFE',NULL,120);
insert into produit values (22,'TROUSSE','ROUGE',10);
insert into produit values (23,'CISEAUX',NULL,30);

insert into achat values (101,1,'2010-11-12',13);
insert into achat values (101,2,'2010-09-18',2);
insert into achat values (101,3,'2010-12-02',12);
insert into achat values (101,4,'2010-09-18',12);
insert into achat values (101,5,'2011-01-13',12);
insert into achat values (101,6,'2011-02-23',12);
insert into achat values (101,7,'2009-09-30',12);
insert into achat values (101,8,'2008-05-29',12);
insert into achat values (101,10,'2011-02-19',12);
insert into achat values (101,11,'2010-09-03',12);
insert into achat values (101,12,'2009-09-08',12);
insert into achat values (101,13,'2010-09-12',12);
insert into achat values (101,14,'2008-09-04',12);
insert into achat values (101,15,'2009-09-11',12);
insert into achat values (103,1,'2010-09-27',4);
insert into achat values (103,4,'2009-09-22',3);
insert into achat values (103,7,'2010-09-02',6);
insert into achat values (103,8,'2009-08-12',9);
insert into achat values (104,11,'2010-09-17',1);
insert into achat values (104,14,'2010-08-31',10);
insert into achat values (105,4,'2010-10-05',4);
insert into achat values (106,10,'2010-12-16',3);
insert into achat values (106,12,'2010-01-11',15);
insert into achat values (107,3,'2010-01-07',10);
insert into achat values (107,6,'2010-04-11',11);
insert into achat values (107,8,'2008-12-26',14);
insert into achat values (108,11,'2009-06-19',18);
insert into achat values (108,14,'2010-02-27',10);
insert into achat values (101,16,'2009-09-08',12);
insert into achat values (101,17,'2010-09-12',20);
insert into achat values (101,18,'2008-09-04',120);
insert into achat values (101,18,'2009-09-11',10);
insert into achat values (102,19,'2009-09-08',2);
insert into achat values (102,21,'2010-09-12',40);
insert into achat values (103,22,'2008-09-04',12);
insert into achat values (103,23,'2009-09-11',20);