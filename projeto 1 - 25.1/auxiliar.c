int divisaoInteira(int dividendo, int divisor, int* quoc, int*resto){
    
    if (divisor==0)
        if (dividendo==0)
            return -1;
        else
            return 0;
    else{
        *quoc= dividendo/divisor;
        *resto=dividendo%divisor;
        return 1;
    }
    
}
void horario(int tempo, int *horas, int *minutos) {
	divisaoInteira(tempo,60, horas,minutos);
	return;
}