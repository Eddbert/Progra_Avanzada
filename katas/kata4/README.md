Problema: Queremos validar si un string dado es numerico o no
Contexto: El string dado puede contener solo numeros para regresar true
El string es de maximo 255 caracteres
Se puede usar tanto la coma decimal como el punto decimal
Se puede usar la letra e para exponencial pero solo en minuscula
No puede haber operaciones matematicas
Los numeros fraccionales no necesariamente empiezan en 0
Se puede empezar con un simbolo de signo
El exponente puede ser negativo o positivo
Ejemplo: .5757=>true
45e-2=>true
45E+56=>false
1,000.95=>true
1+1=>false
Solucion: Lo primero que haria seria un for loop que recorra el arreglo buscando primero simbolos invalidos con una funcion "isValid(char)" esta funcion buscaria que el caracter sea solo uno numerico, signo, punto, coma, espacios o letra e minuscula.
isValid solo considera valido el signo si este se encuentra en la primer casilla del arreglo o inmediatamente despues de la letra e asi que considerando que isValid regresa un caracter boleano se puede complementar con un caso if que registre que es valido y que la posicion del signo es correcto.
un segundo caso if es para la coma, la coma no puede estar nunca al principio ni despues de que la letra e ocurra. Tambien se debe tomar en cuenta que la coma solo puede aparecer cada digitos.
El tercer caso de if se da por los espacios, los espacios solo pueden ocurrir al principio o al final asi que se debe de tener una condicion para que si despues de uno o una serie de espacios se encuentra un symbolo que no sea el terminador o que antes de los espacios se encuentre el inicio de el arreglo entonces no es valido.
Como cuarto caso se debe revisar como se encuentra posicionado el punto. El punto solo puede ocurrir una vez por arreglo bajo condiciones especificas como son que este tiene que estar antes de un numero ya que antes de el puede haber espacios, numeros o el inicio del arreglo; el punto no puede aparecer si la letra e ya a ocurrido.
Un ultimo caso es con la letra e minuscula ya que esta solo puede ocurrir despues de algun digito y debe de tener despues de el mas digitos para hacerlo valido o en caso de signo un simbolo de + o -
