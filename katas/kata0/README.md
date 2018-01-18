Problema:
	Tenemos que poder encontrar en un arreglo de tamaño mayor a dos, dos numeros que sumados den un resultado requerido y regresar su indice en un arreglo.

Contexto:
	No se repiten numeros
	Solo enteros positivos
	El tamaño es ilimitado
	Siempre se requerira una suma positiva
	Siempre habra una respuesta posible
	Solo se requiere la primera respuesta
	
Ejemplo:
	El caso mas sencillo:
		Si te piden un numero t = 3 cuando tu arreglo es de tamaño 2 la solucion siempre sera que te regrese un arreglo de tamaño 2.
		Este arreglo siempre sera [0, 1]
		obviamente en este caso los dos numeros deberan ser cualquier combinacion que de como resultado tamaño
	Caso con arreglo tamaño 3:
		Si nuestro arreglo es de tamaño 3 ya empieza a haber mas casos.
		Buscando 2 numeros que sumados den t tenemos que decidir por donde empezar a buscar.
		Una opcion es empezar en el principio en el siguiente arreglo:
		[2,1,7]
		En i = 0 tenemos un dos, suponiendo que t = 3 entonces nuestra primera opcion seria verificar que el numero no sobrepase 3.
		Ya que 3-2 = 1 sabemos dos cosas el hecho de que sea un entero positivo nos dice que 2 no sobrepasa nuestra t y el resultado nos dice que numero estamos buscando.
		Al avanzar a i = 1 nos damos cuenta que nuestro numero requerido fue encontrado.
		Saber que numero buscamos convierte esto en una tarea de simple busqueda.
		
Solucion:
	Una solucion para el problema seria empezar con i = 0 sacar el complemento con t y buscar el numero, si el numero no se encuentra entonces movemos i a 1 y repetimos.
	La eficiencia de esta solucion es de n pero sabemos que podemos hacerlo mas rapido.
	Una manera de hacer esta busqueda mas eficiente es usando hashtables.
	Usando hashtables solo recorreriamos el arreglo una vez para generar el hash table y una vez mas cuando estemos buscando los dos numeros que resulten en t.
	De la otra manera estariamos recorriendo una vez mientras buscamos los numeros que resulten en t mas todas las veces que sea necesario cuando se este buscando el segundo numero