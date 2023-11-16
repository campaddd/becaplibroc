# Note es 2_5

- in printf se ho %d%d ma al primo gli passo un float lui ignora il float, mi stampa come primo il secondo e come secondo un garbage value
- non posso usare sizeof su un array passato come argomento di una funzione, perchè è passato per riferimento ossia come _puntatore_, e usando sizeof su di un puntatore mi restituisce la dimensione del tipo del puntatore, quindi su un puntatore int mi da 8 anche se l'array int è di dimensione *MAX_LENGHT*
