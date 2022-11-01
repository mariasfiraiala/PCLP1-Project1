Copyright 2021 Maria Sfiraiala (maria.sfiraiala@stud.acs.upb.ro)

## Problema 1

- Rezolvam gasirea in vectorul dat a elementelor care satisfac cerinta astfel:
	1. vom citi intr-o prima faza doar primele doua valori
	2. daca exista mai mult de doua valori, vom continua sa le citim una cate una, de interes fiind doar valoarea x2, adica cea marginita de alte 2 valori
	3. in cazul in care aceasta este valida, adica mai mare decat ambii sai vecini, crestem contorul referitor la valorile valide, dar si adaugam elementul respectiv la suma
	4. urmatorul pas este acela al determinarii pozitiei elementului valid si deciderea daca valoarea poate fi candidata pentru un maxim sau minim, in functie de ce indica paritatea pozitiei
	5. pasul final din cadrul blocului repetitiv este interschimbarea
		  valorilor, astfel incat sa fim pregatiti pentru citirea unui nou element
- Incheierea exercitiului este adusa de calcularea mediei, printr-o impartire reala la contorul folosit a sumii memorate pe parcurs
- O ultima observatie legata de cazurile speciale seteaza valorile lui xmin_par si xmax_par in mod corespunzator
- Afisarea mediei aritmetice se face cu 7 zecimale, asadar vom folosi specificatorul %.7lf


## Problema 2

- Exercitiul ne cere sa aflam o perioada a unei proprietati matematice data de diferenta dintre cifrele sortate descrescator ale unui numar si cifrele sortate crescator, asadar vom calcula in mod repetitiv aceasta diferenta, dupa cum urmeaza:
	1. citim numarul initial
	2. cream prima diferenta
	3. in cadrul acestei diferente este nevoie de doua functii complementare: una ce calculeaza numarul cu cifrele sortate descrescator, si una ce calculeaza numarul cu cifrele sortate crescator
	4. cele doua functii sunt asemanatoare: prin utilizarea unui vector de frecventa sunt ordonate cifrele, singura problema aparand in cadrul functiei ce ordoneaza crescator cifrele: toate cifrele de 0 sunt ignorate, dupa cum sugereaza enuntul; altfel, proprietatea matematica nu se mai indeplineste
- O alta functie necesara in cadrul structurii repetitive este una de cautare a unui element intr-un vector nesortat
- Vectorul in cauza este unul pe care il folosim pentru a memora toat elementele perioadei
- In mod succesiv cream noi diferente, pe care le cautam in vectorul de perioada; daca ele nu se afla in vector, inseamna ca perioda nu se incheie si atuncim repetam procesul, punandu-le la randul lor in vectorul de perioada
- In momentul in care structura repetitiva se incheie putem fi siguri ca perioada a fost inregistrata in vectorul aferent si, deci, putem afisa numarul de pasi necesari pentru a o incepe, valoare data de pozitia in vector care a generat iesirea din while
- Tot de la pozitia respectiva incepe perioada, si deci o vom afisa pana la finalul vectorului, dat de variabila k, care a fost folosita pentru a retine dimensiunea acestuia.


## Problema 3

- Rezolvarea problemei se bazeaza pe o abordare greedy a analizei materiilor la care elevul ar fi trebuit sa ia nota maxima:
	1. primul aspect este dat de punctajul pe care acesta il are la momentul curent
	2. in acesta idee vom citi notele si creditele in doi vectori diferiti
	3. urmatoarea etapa este data de integrarea intr-un vector a punctajelor la materiile la care nu a luat 10, calculand in acelasi timp punctajul real
	4. la finalul acestui pas avem "nota" curenta si mai trebuie doar determinat numarul de materii la care ar fi trebuit sa invete mai mult
	5. aici intervine abordarea greedy, intrucat vom sorta vectorul punctajelor si il vom parcurge in ordine inversa pentru a fi cat mai eficienti in alegerea punctajelor
	6. sortarea aleasa este una eficienta, mai exact, un quicksort implementat printr-o modifiare structurata a algoritmului lui Hoare de pivotare, mult mai optima fata de echivalenta lui Lomuto
- Sfarsitul exercitiului este adus de afisarea numarului materiilor sau -1 in cazul in care indiferent de nota, punctajul minim citit initial nu poate fi atins

## Problema 4

- Algoritmul se bazeaza pe memorarea restrictiilor atat pe linie, cat si pe coloana in doi vectori intr-un mod similar
- Intrucat verificarea corectitudinii nomogramei este asemanatoare pentru linii si coloane, vom explica procesul doar pentru linii
- Un prim pas ar fi abstractizarea problemei si rezolvarea acesteia pe un caz minimal, fie acesta o singura linie a matricei:
	1. vom parcurge coloanele acesteia pana cand ajungem la prima valoare de 1
	2. vom seta un indice suplimentar pentru a calcula dimensiunea grupului de 1, fie acesta i
	3. daca i este diferit de c, indicele coloanei de la care am plecat cu contorizarea, inseamna ca am gasit un grup de valori 1 si vom verifica daca dimensiunea acestuia este identica cu cea din matricea de restrictii
	4. acest lucru este realizat prin setarea unei alte variabile, nr1, care memoreaza numarul de pachete de 1 de pe fiecare linie
	5. daca numarul de pachete este diferit de numarul de restrictii de pe linia respectiva (numarul de pe prima coloana a matricei) vom returna 0
- Aceasta modalitatea este repetata pentru fiecare linie in parte
- Un algoritm similar este implementat pentru restrictiile pe coloane, cand vom parcurge grid - ul pe coloane
- In main este suficient sa citim t si sa apelam functia de validare pentru fiecare grid in parte, iar mesajul corespunzator este afisat
