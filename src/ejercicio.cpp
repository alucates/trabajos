#include <iostream>
#include <string>
using namespace std;


/*
 *Template de una clase Pila con sus respectivos metodos y su objetos

 */
template<typename T> class Pila {
private:
	/*Variables: La primera variable es un array de tipo int con 10 posiciones, siendo esta una variable privada.
	 *Variables: La segunda variable es un int llamda elementos, siendo esta una variable privada.*/
	int listaElementos[10];
	int elementos;
public:
	/*Constructor clase pila inicializando la variable elementos a 0*/
	Pila() :
			elementos(0) {
	}
	/*
	Metodos: 1º insertNumero de tipo void con un int en el parametro, este metodo verificara si todos los
	 *elementos del array "listaElmentos" estan ocupados, en caso de que no estan el programa asignara el numero
	 *pasado por parametro a la ultima posició de la lista y sumara un elemento mas perteneciente a la lista.
	 *En caso contrario se mostrara por pantalla dicho mensaje "Error: Pilla llena".*/
	void insertNumero(int i) {
		if (elementos < 10) {
			listaElementos[elementos] = i;
			elementos++;
		} else {
			cout << "Error: Pila llena";
		}
	}
	;

	/*
	 * Metodo: 2º definirElementos de tipo int, en este metodo declaramos una variable de tipo int "numero".
 *Habrimos un try catch y pedimos que el usuario pase un numero por teclado asginado a la variable "numero"
 *En caso de que el dato declarado por el usario no sea de tipo int saltara la excepción y se mostrara.
 *Por ultimo dentro del try existe un metodo que verifica si el numero introducido es 0, en caso de que sea 0
 *se mostrara un mensaje por teclado "el numero 0 no se almacenado".
	 */
	int definirElementos() {
		int numero;
		try {
			cout << "introduce un numero" << endl;
			cin >> numero;
			if (std::cin.fail()) {
				throw 1;
			}
			if (numero == 0) {
				cout << "el numero 0 no sera almacenado\n" << endl;
			}
		} catch (int err) {
			cout << "numero no validado\n";
		}
		return numero;

	}

	/*Metodos: 3º metodo de tipo void showNumeros, este metodo comprueba al principio si existen elementos en la lista
	 *en caso de que nunca haya ningún elemento en la lista se mostrara dicho mensaje por pantalla "NO EXISTEN ELEMENTOS
	 *PARA MOSTRAR". En caso contrario el programa recogera la lista mediante un for que tendra como limite establecido
	 *el numero de elementos almacenado en la variable elementos, al recoger el array mostraremos la posición de elemento
	 *y su respectivo valor.*/
	void showNumeros() {
		if (elementos == 0) {
			cout << "NO EXISTEN ELEMENTOS PARA MOSTRAR\n" << endl;

		}else{
		for (int i = 0; i < elementos; i++) {
			cout << "Posición elemento: " << i + 1 << "\n";
			cout << "Nombre del libro: " << listaElementos[i] << "\n";

		}
		}
	}
	/*Metodos: 4º metodo de tipo void eliminar (solo se ejecutara sus funciones si existen elementos en la lista)
	 *Metodos: ,en este metodo creamos una varible de tipo int pos (posición),
	 *pediremos al usuario que introduzca un dato tipo int que verificara el elemento de la posición. Se abrira un try
	 *catch que verificara que el elemento introducido es de tipo número. En caso de que el número se haya introducido
	 *correctamente y de que la posición existe en al pila, se recogera un for con su limite establecido por el número de elementos actuales de la lista.
	 *Con este for recogeremos la lista y eliminaremos el elemento en la posición que hemos introducido por teclado,
	 *asginaremos la lista con la posición borrada a la lista con todas las posiciones, y disminuiremos la variable int elementos por 1 valor.
	 */
	void eliminar() {
		cin.ignore();
		if(elementos != 0){
		int pos;
		try{
			cout << "Introduce la posición del elemento que deseas eliminar\n"
							<< endl;
					cin >> pos;
					if(std::cin.fail()){
						throw 1;
					}else if((pos) <= elementos){
					for (int j = pos; j < elementos; j++) {
						listaElementos[j - 1] = listaElementos[j];

					}
					elementos = elementos - 1;
					}else{
						cout << "La posición indicada no pertenece a la lista\n"<<endl;
					}
		}catch(int err){
			cout << "El dato introducido no es de tipo númerico\n" << endl;

		}
		}else{
			cout << "La lista esta vacia\n"<<endl;
		}

	}
};

/*
 *Metodo main de tipo int, en este metodo determinaremos toda la ejecución del programa.
 */
int main() {
	/*
	 * Variables 1º: variable de tipo int "num" se usara en el caso 1 para verfiicar si el numero obtenido es = 0
	 * Variables 2º: variable de tipo int "caso" se usara para determinar el case ejecutado en el switch
	 * Variables 3º: vairable de tipo boolean "continuar, se usara para controlar el while que determina el tiempo de vida
	 * de programa
	 * Variables 4ª: Variable de tipo Pila, referenciando a clase pila y a sus respectivos metodos/
	 */
	int num;
	int caso;
	bool continuar = true;
	Pila<int> listaElementos;
/*
 * While que detemrinara la vida del programa
 */
	while (continuar) {
		/*
		 * Comentarios con un breve descripción de cada caso del switch
		 */
		cout << "----Introduce la opción que deseas realizar----\n"
				"1- Insertar valores en la Pila\n"
				"2- Ver valores almacenados\n"
				"3- Eliminar elementos\n"
				"4- Salir del bucle\n";
		/*
		 * metodos para borrar la cache de los datos pedidos atraves del metodo cin
		 */
		cin.clear();
		cin.sync();
		/*
		 * pedimos al usuario que introduzca una de las opciones mostradas anteriormente por pantalla y la asginamos a la variable caso
		 */
		cin >> caso;
		/*
		 * Switch que gestionara los 5 posibles casos.
		 */
		switch (caso) {
		/*
		 * Asignaremos la variable num al metodo definirElementos, en caso de que lo que nos retorne el metodo
		 * definirElementos perteneciente a la clase Pila sea distinto de 0, insertaremos dicho elemento en la lista
		 * atraves del metodo insertNumero.
		 */
		case 1:
			num = listaElementos.definirElementos();
			if (num != 0) {
				listaElementos.insertNumero(num);
			}
			break;
			/*
			 * Se iniciara el metodo showNumeros, se mostraran por pantalla todos los elementos pertenecientes a la lista
			 */
		case 2:
			listaElementos.showNumeros();
			break;
/*
 * Se ejectura el metodo para eliminar un número especifico de la lista determinado por su posición.
 */
		case 3:
			listaElementos.eliminar();
			break;
/*
 * En este caso se mostraria una mensage por pantalla "FIN DEL PROGRAMA" y la variable continuar se igualaria a false terminado asi en bucle while y la ejecución del programa
 */
		case 4:
			cout << "FIN DEL PROGRAMA" << "\n";
			continuar = false;
			break;
			/*
			 * Este caso se ejectura si la variable num caso no corresponde a ninguno de los 4 casos disponibles,
			 * se mostrara una mensaje por pantalla "el caso que a seleccionado no existe"
			 */
		default:
			cout << "el caso que a seleccionado no existe\n";
			break;
		}
	};
}
;
