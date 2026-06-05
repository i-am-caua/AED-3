void mesclaFila (Fila *f1, Fila *f2, Fila *f3) {
    int val1 = remover(f1), val2 = remover(f2);
    int flag = 1;
    while (!isEmpty(f1) || !isEmpty(f2) || flag) {
        if (!isEmpty(f1) && !isEmpty(f2) || flag) {
            if (val1 <= val2) {
                inserir (f3, val1);
                val1 = remover (f1);
            }
            else {
                inserir (f3, val2);
               val2 = remover (f2);
            }

        }
         if (isEmpty(f1) && !isEmpty(f2)) {
             inserir (f3, val2);
             val2 = remover (f2);
        }
        if (isEmpty(f2) && !isEmpty(f1)) {
            inserir (f3, val1);
            val1 = remover (f1);
        }
    }

