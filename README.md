# Proiect POO - ROCK the SHOP

Proiectul a presupus implementarea unui sistem complet de administrare a unui magazin online de produse rock, incluzând gestiunea angajaților, a stocurilor și procesarea automată a comenzilor, folosind concepte de programare orientată pe obiecte în C++.

## Cum a fost creat?
Aplicatia a fost dezvoltata modular, folosind:
 - clase separate pentru produse
 - clase pentru angajati
 - utilizarea STL (vector, map, queue, algorithm) si functionalitati moderne C++11/14
Validarea datelor (CNP, varsta minima etc.) s-a facut conform specificatiilor. Comenzile au fost procesate automat, tinand cont de incarcarea operatorilor.

Comenzile sunt citite din fisier si validatte conform regulilor impuse. Fiecare comanda valida este asignata automat unui operator disponibil, tinand cont de faptul ca un operator poate gestiona maximum 3 comenzi. Daca toti operatorii sunt ocupati, comenzile sunt plasate intr-o coada de asteptare si repartizate automat atunci cand se elibereaza un operator. Verificarea eliberarii operatorilor se face in timp real.

Rularea se face cu ajutorul fisierului Makefile care compileaza automat toate fisierele .cpp si creeaza executabilul.
