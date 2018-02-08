Problema:
	Tenemos un Robot en una posicion inicial (0,0) en un plano. Dada una sequencia de movimientos queremos saber si el robot se movio en circulos, osea que se movio a la posicion original.
Contexto:
	La sequencia a movimientos a realizar seran representados por un string.
	Cada caracter del string es un movimiento.
	Los movimientos validos seran R-Derecha, L-Izquierda, U-Arriba, D-Abajo.
	El output sera solo True o False para reperesentar si se movio en circulos.
Ejemplo:
	Si el input recibido es el string "UD" significa que el robot se movio una vez para arriba y una vez para abajo en dado caso el output se dara como true.
	Si el input recibiro es el string "LL" significa que el robot se movio dos veces para la izquierda y no pudo haber llegado al origen.
Solucion:
	Si tenemos inputs en forma de string y sabemos que un string es solo un arreglo de caracteres lo primero que haria seria pensar en como recorrer este arreglo. La forma mas sencilla seria con un for loop en la que se recorre cada caracter del arreglo. Despues de esto usaria casos con if, else if para analizar los 4 casos posibles mas un else en el que se puede lanzar cualquier caracter invalido. Se tendrian 2 variables, X y Y para ver la posicion del robot en el plano. En X tendriamos los casos de R y L donde R sumaria uno a la variable X y L restaria uno a la variable. En Y tendriamos los casos de U y D donde U suma uno y D resta 1. Al final se debe comprobar que tanto X como Y sean igual a 0 lo cual nos indica que el robot regreso al origen y se regresa true y en otro caso regresamos false.