--TD1
--Question 1 :
select modele from PC where vitesse >= 3.00;

--Question 2:
select distinct fabr from portable natural join produit where hd >= 100

--Question 3:

select portable.modele, portable.prix
from produit natual join portable 
where produit.fabr =='B'
UNION
select imprimante.modele, imprimante.prix
FROM produit natural join imprimante
where produit.fabr == 'B'
union
select pc.modele, pc.prix
from produit natural join pc
where produit.fabr == 'B';


--Question 4:
select modele from Imprimante where couleur = 1 and type='laser';

--Question 5:
select fabr from produit where type = 'portable' except select fabr from produit where type = 'pc';

--Question 6:
select distinct p1.hd from pc p1, pc p2 where p1.hd = p2.hd and p1.modele < p2.modele;

--Question 7:
select distinct p1.modele, p2.modele from pc p1, pc p2 where p1.vitesse = p2.vitesse and p1.ram = p2.ram and p1.modele < p2.modele;


--Question 8:
select fabr from pc natural join produit where vitesse >= 2.8 union select fabr from portable natural join produit where vitesse >= 2.8 group by fabr having count(modele) >= 2;

--Question 9:
select distinct p1.fabr from produit p1, produit p2, produit p3 natural join pc p4, pc p5, pc p6 where p1.modele != p2.modele and p2.modele != p3.modele and p3.modele != p1.modele and p4.vitesse != p5.vitesse and p5.vitesse != p6.vitesse and p6.vitesse != p4.vitesse and p1.fabr = p2.fabr and p2.fabr = p3.fabr and p3.fabr = p1.fabr;  --Y'a une erreur mais c'est ce principe là

--Question 10:
select fabr from produit natural join pc group by fabr having count(modele) = 3;

--Question 11:
select fabr from pc natural join produit where vitesse = (select max(vitesse) from pc) union select fabr from portable natural join produit where vitesse = (select max(vitesse) from portable);


