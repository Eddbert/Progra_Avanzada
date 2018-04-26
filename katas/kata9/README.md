Problema: Nos esta llegando un array de entros en los que que cada byte representa una parte de un caracter en formato UTF-8 y queremos saber si estan codificados de manera correcta o no
Contexto: dentro de la codificacion de UTF-8 los caracteres pueden ser entre 1 y 4 bytes cada uno.
El primer byte nos indica cuantos bytes tendra el caracter y esto lo indica de la siguiente manera
0XXXXXXX - 1 byte
110XXXXX - 2 bytes
1110XXXX - 3 bytes
11110XXX - 4 bytes
todos los bytes siguientes contienen informacion pero deben empezar con 10 para quedar 10XXXXXX
Ejemplo: 
data = [197, 130, 1] -->11000101 10000010 00000001.    Return true.  Es valido ya que empieza con 110 representando dos bytes y el siguiente empezo con 10 y el ultimo empieza con 0 representando 1 byte
data = [235, 140, 4] -->11101011 10001100 00000100.    Return false. La primera parte es valida ya que representa 3 bytes pero la ultima parte deberia empezar con 10 ya que se espcifico que son 3 bytes lo cual hace este ultimo parte del caracter de otra forma es incorrecta la representacion
Solucion: Lo primero que se tiene que hacer es ver los primeros bits hasta el primer 0 en el primer byte, esto representa el numero de bytes que se estan esperando. Despues de esto se debe mantener un contador que lleve cuenta del numero de bytes que han pasado y si esto coincide con el numero de bytes esperados (si se vio un 110 al principio se esperan 2 bytes). Si se esperan dos bytes en el siguiente byte se verifica que el byte empieze con 10 siginificando que aun es parte del caracter codificado y de otra manera se regresa un false, esto se debe ejecutar dentro de un for que recorra el arreglo entero de enteros para verificar que todos los caracteres UTF-8 sean correctos.