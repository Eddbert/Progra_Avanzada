Problema: Batman empieza en en un array de tamaño [W, H] en la posicion X0 y Y0 y necesita llegar a una posicion [X, Y] Desconocida para la cual solo te dan indicaciones vagas en la forma de (U, UR, R, DR, D, DL, L or UL) para indicar a donde deberia de dirigirse.
Contexto: Batman cuenta con un numero N de movimientos maximos antes de que la bomba truene. 
1 ≤ W ≤ 10000
1 ≤ H ≤ 10000
2 ≤ N ≤ 100
0 ≤ X, X0 < W
0 ≤ Y, Y0 < H
Ejemplo: Digamos Batman esta en un array [10, 10] y tiene 6 turnos para llegar a su destino empezando en [2,5]. Lo primero que llega es UR asi que batman decide brincar a [5, 4], despues llega R asi que batman decide brincar a [7, 4] y el juego termina.
Solucion: Dado el tamaño y el hecho de que no sabemos la posicion exacta de la bomba pero tenemos un indicador vago de a donde dirigirnos por ejemplo si nos dan la indicacion UR podemos descartar todo lo que este abajo de batman y tambien todo lo que este a la izquierda y construir un nuevo array de posible rango de posiciones donde la bomba se encuentra. Para encontrar la mejor posicion para brincar dentro de este nuevo rango lo mejor que podemos usar es una busqueda binaria. Si nuestro rango original es X1 y Y1 en 0 y X2 = W-1 y Y2 = H-1 lo primero que hacemos es el ajuste dado una direccion y despues de esto dado la posicion actual de batman lo ideal es moverse a la mitad de el nuevo rango, esto se repite hasta que eventualmente se llega a la posicion requerida.