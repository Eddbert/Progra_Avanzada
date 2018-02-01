Problema:
	Queremos una aplicacion que revise la contraseña de el usuario para verificar que esta cumpla con los requisitos minimos de complejidad

Contexto:
	La contraseña tiene almenos 6 carcateres
	Maximo 20 carcateres
	Contiene al menos una mayuscula, una minuscula y un digito
	no deben de repetirse un caracter tres veces de manera consecutiva
	Debe retornar el cambio minimo para convertir una contraseña debil en una fuerte
	Tiene dos estados, fuerte o debil.
	No se aceptan caracteres no alfanumericos

Ejemplo:
	Si el usuario pone de contraseña: Sofi94
	Entonces el programa regresaria un 0 indicando que la contraseña es fuerte
	Si el usuario pone de contraseña: ehhh
	el programa veria que se tienen tres caracteres iguales consecutivos, no tiene el minimo numero de carcateres, le faltan caracteres en mayuscula y un digito entonces se regresaria un numero que indica que necesita borrar (1) insertar tres nuevos (3) estos dos nuevos pueden ser un digito y una mayuscula y el otro es indiferente.
	
Solucion:
	El programa recibe un string (pointer a un arreglo de caracteres) lo primero que hacemos es checar el tamaño de este arreglo para poder confirmar que sea de al menos 6 de lo contrario le resta a 6 el tamaño del arreglo para conseguir el numero de inserciones que se necesitan para llegar a 6; tambien se checa que no se pase de 20, si se pasa de 20 se le resta al tamaño del arreglo 20 y este es el numero de caracteres a borrar; esta informacion se va guardando en una variable que lleva la cuenta de cambios requeridos.
	Despues el programa checa si hay caracteres no alfanumericos y el numero que encuentre se suma al numero de cambios tomando en cuenta si el string sigue cumpliendo el numero minimo o si esto ayuda a que baje de 20.
	Se checa si se contiene un caracter mayuscula otro minuscula y un digito si hace falta alguno de estos entonces se suma al numero de cambios requeridos de nuevo viendo que se siga respetando el minimo y maximo tamaño.
	Por ultimo se checa que ni un caracter exista tres veces seguidas dentro del string y los cambios requeridos de nuevo se verifican que respeten los tamaños minimos y maximos.