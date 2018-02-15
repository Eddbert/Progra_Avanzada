Problema:
    Dado un numero queremos encontrar el numero mas chico cuyo producto de sus digitos sea igual al numero que se le dio.
Contexto:
    Los numeros seran solo enteros
    Son positivos
    El rango es de 0 hasta 10^9
    Si no existe un numero regresar -1
Ejemplo:
    Dado el numero 10 queremos obtener el producto de numeros que dan como resultado debemos de regresar el numero 25 ya que 2*5 es igual a 10.
    Sabemos que 52 tambien es un numero que produce 10 pero debemos de siempre regresar el numero mas chico posible
Solucion:
    La manera de solucionarlo es primero hacer un while en el que checamos si N es mayor 9 esto porque como estamos buscando digitos si el numero fuera algun numero unitario la division seria 1.
    dentro de este loop recorremos us numeros empezando del 9 hasta el 2 viendo si hay algun numero por el que pueda ser divisible N si encontramos un numero asi entonces este numero es uno de los factores de N.
    En N guardamos esta division y volvemos a recorrer numeros de 9 a 2 la razon para esto es porque si siguieramos el loop en el numero que vallamos podriamos encontrar un numero chico que tambien puede ser un factor pero obtendriamos un numero equivocado al final.
    Una vez que la division de N resulte en un numero unitario entonces este junto con el numero de la division son guardados como los ultimos factores de N.
    SI en este loop se detecta que N no esta cambiando entonces Q se cambia a -1 ya que no tiene resultado.
    una vez que Q esta completa esta se tiene que ordenar de manera que sus digitos vallan de menor a mayor para poder obtener el menor numero posible y esto se logra separando el numero en un arreglo y haciendo un sort y luego pasando el numero ordenado a Q.