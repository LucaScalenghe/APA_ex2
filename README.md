# APA_ex2
This was my second exercise for my APA exam at Politecnico di Torino

L’esercizio chiede di scrivere una funzione che, noti r,n,val e disp, calcoli il numero minimo di
monete da restituire affinché si ottenga il resto desiderato e stampi le monete da dare.
Il codice presenta una funzione ricorsiva che si basa sul modello delle combinazioni ripetute
con un pruning.

CONDIZIONE DI TERMINAZIONE
Ad ogni istanza si calcola con un for la somma di tutte le monete nella soluzione corrente.
La condizione di terminazione si ha quando la somma dei valori della soluzione corrente è
uguale al resto. In tal caso si esegue un ulteriore controllo sulla lunghezza di tale soluzione e se
risulta minore allora si procede nella copiatura nella best_sol della soluzione corrente.

PARTE RICORSIVA
Presenta un for che cicla sulle varie monete che si possono selezionare a quel passo.
Basandosi sul modello delle combinazioni ripetute si vincola i con start così da non considerare
soluzioni simmetriche.
Una scelta è valida se la disponibilità è sufficiente e se è promising.

PRUNING
La funzione promising controlla solo che se presa la moneta la somma della soluzione corrente
non risulti maggiore del resto da dare.
Passati questi controlli si inserisce la moneta nella soluzione e si diminuisce la disponibilità. Si
ricorre con pos+1.
In fase di backtrack si riporta la lungsol e la disp ai valori originari, come se non si avesse preso
la moneta e poi si incrementa start.
