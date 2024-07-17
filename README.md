
# Taller de Estructuras y Funciones en C++





En este taller es obligatorio el uso de estructuras y funciones. Debe usar headers para evitar que el código se vea muy extenso, y ***no puede usar `cin` o `cout` en ninguna parte del código que no sea el archivo `main.cpp`.***

  
Se recomienda que use la estructura `NumberList` para el desarrollo de este taller.

## **Enunciado**: 
Para implementar la funcionalidad de listas de números en C++, es necesario crear el archivo de encabezado `NumberList.h`. A continuación, se describe cada parte del archivo. Puede ir copiando y pegando cada una de las partes, hasta tener el archivo completado. 

### **Definición de Encabezado**  
```cpp
    #ifndef NUMBERLIST_H 
    #define NUMBERLIST_H
```
 
 Estas líneas garantizan que el contenido del archivo se incluirá solo una vez en el programa, evitando problemas de duplicación durante la compilación.
 
### **Inclusión de Librerías**
```cpp
    #include <string>
```
Se incluye la librería `<string>` para utilizar la clase `string` en la definición de la estructura.

### **Espacio de Nombres**
```cpp
    using namespace std;
```
Se utiliza `using namespace std;` para evitar tener que escribir `std::` antes de cada elemento de la biblioteca estándar.

### **Definición de la Estructura NumberList**
```cpp
    struct NumberList {
    // ...
    };
```    

Se define la estructura `NumberList` que contendrá información sobre el tamaño de la lista y los números almacenados.

### **Miembros de la Estructura**
####  size
El miembro **`size`** representa el tamaño actual de la lista.
```cpp
    int size
```
####  numbers
El array **`numbers`** almacena los números de la lista. En este ejemplo, se ha establecido un límite máximo de *100* elementos.
```cpp
    int numbers[100];
```
Con esto, la estructura completa sería:
```cpp
    struct NumberList {
	    int size;
	    int numbers[100]
    };
```

### Métodos en la Estructura `NumberList`

Las funciones que viven dentro de las estructuras se denominan métodos. Los métodos en la estructura `NumberList` son funciones que realizan operaciones específicas en la lista de números. A continuación, se explica cada método que debe ser agregado a la estructura (justo abajo del array de números):

#### Constructor
El constructor es un método especial que se llama automáticamente cuando se crea un objeto (es decir una nueva variable) de la estructura. En este caso, inicializa el tamaño de la lista a cero al crear una instancia de `NumberList`.  Tiene la particularidad que se llama igual que la estructura
```cpp
    // Constructor
	NumberList() {
      size = 0;
	}
```
Con esto, la estructura sería la siguiente, de momento:
```cpp
    struct NumberList {
	    int size;
	    int numbers[100]
		
		// Constructor
		NumberList() {
		    size = 0;
		}
    };
```


#### Método `add`

```cpp
    // Método: add  
    void add(int number) { 	
		numbers[size] = number; 
		size++; 
    }
```
El método `add` agrega un número al final de la lista.

##### **Ejemplo:**

```cpp
    NumberList lista;
    lista.add(5);
    lista.add(8);
    lista.add(3);
    // Ahora, la lista contiene: [5, 8, 3]
```

#### Método `remove`
```cpp
    // Método: remove  
    void remove(int index) { 
	    for (int i = index; i < size - 1; i++) { 
			numbers[i] = numbers[i + 1]; 
		} 
		
		size--; 
    }
```
El método `remove` elimina un elemento en la posición dada por `index`.
##### **Ejemplo**:
```cpp
    NumberList lista;
    lista.add(5);
    lista.add(8);
    lista.add(3);
    lista.remove(1);
    // Ahora, la lista contiene: [5, 3]
```
### Método: `get`
```cpp
    // Método: get  
    int get(int index) { 
	    return numbers[index]; 
	} 
```
El método `get` devuelve el número en la posición indicada por `index`.

##### **Ejemplo:**
```cpp
    NumberList lista;
    lista.add(5);
    lista.add(8);
    lista.add(3);
    int valor = lista.get(1);
    // 'valor' ahora es 8 
```
### Método: `set`
```cpp
    // Método: set  
    bool set(int index, int number) { 
	    if (index < 0 || index >= size) { 
		    return  false; 
		} 
		numbers[index] = number; 
		return  true; 
    } 
```
El método `set` establece el valor de la lista en la posición `index` con el número dado. Retorna verdadero si el valor fue cambiado. 

##### **Ejemplo:**

```cpp

NumberList lista;
lista.add(5);
lista.add(8);
lista.add(3);
lista.set(1, 10);
// Ahora, la lista contiene: [5, 10, 3]
```
### Método: `contains`
```cpp
    // Método: contains  
    bool contains(int number) { 
	    for (int i = 0; i < size; i++) { 
		    if (numbers[i] == number) { 
			    return  true; 
			} 
		} 
		return  false;
	}
```
El método `contains` verifica si la lista contiene un número específico.

##### **Ejemplo:**
```cpp
    NumberList lista;
    lista.add(5);
    lista.add(8);
    lista.add(3);
    bool resultado = lista.contains(8);
    // 'resultado' ahora es true
```
 

### Método: `clear`
```cpp

    // Método: clear  
    void clear() { 
	    size = 0; 
	}
```
El método `clear` reinicia el tamaño de la lista a cero, eliminando todos los elementos.

##### **Ejemplo:**
```cpp
    NumberList lista;
    lista.add(5);
    lista.add(8);
    lista.add(3);
    lista.clear();
    // Ahora, la lista está vacía 
```
### Método: `copy`


   
```cpp
     NumberList  copy() {
    
	    NumberList  other;
    
	    for (int  i  =  0; i  <  other.size; i++) {
	    numbers[i] =  other.numbers[i];
	    }
	    size =  other.size;
	    return  other;
    }
```
 

El método `copy` retorna una nueva lista con los elementos de nuestra lista actual.

##### **Ejemplo:**
```cpp

    NumberList original;
    original.add(5);
    original.add(8);
    original.add(3);
    
    NumberList copia = original.copy();
    // 'copia' ahora contiene los mismos elementos que 'original'
```
 

### Método: `toString`
```cpp
    // Método: toString  
    string toString() { 
	    string result = "["; 
	    for (int i = 0; i < size; i++) { 
		    result += to_string(numbers[i]); 
		    if (i < size - 1) { 
			    result += ", "; 
			} 
		} 
		result += "]"; 
		return result; 
	}
```
El método `toString` devuelve una representación en formato de cadena de la lista.

##### **Ejemplo:**
```cpp
    NumberList lista;
    lista.add(5);
    lista.add(8);
    lista.add(3);
    string resultado = lista.toString();
    // 'resultado' ahora es "[5, 8, 3]"
```
### Cierre del encabezado
```cpp
#endif /* NUMBERLIST_H */
```

Estas líneas cierran el bloque de definición del archivo de encabezado.

## Calificación
En este taller es obligatorio el uso de estructuras y funciones.

Debe usar headers para evitar que el código se vea muy extenso, y no puede usar cin o cout en ninguna parte del código que no sea el archivo main.cpp.
  
### Operaciones Disponibles
Su programa debe hacer lo siguiente, a través de un menú:
  

1. **Crear e imprimir una lista de números enteros de 20 elementos.(1.0)**

- Los números deben ser generados de forma aleatoria entre 1 y 10.

- Ejemplo:

    ```cpp

    [4,7,2,1,5,3,2,1,9,10,2,3,4,5,6,7,8,9,10,1]

    ```

  

2. **Crear e imprimir una lista de números sin repetir y en orden de aparición.(1.5)**

- Ejemplo:

    ```cpp

    [4,7,2,1,5,3,9,10,6,8]

    ```

  

3. **Crear e imprimir una lista de la frecuencia de cada número en la lista anterior.(1.0)**

- Ejemplo:

    ```cpp

    [2,2,3,3,2,2,2,2,1,1]

    ```

  

4. **Generar números aleatorios y guardarlos en una matriz de 5x5.(1.5)**

- Haciendo uso de la estructura `NumberMatrix` (Esta estructura está incluída junto con este enunciado).

- Ejemplo:

    ```cpp

    [4,7,2,1,5

    3,2,1,9,10

    2,3,4,5,6

    7,8,9,10,1

    1,2,3,4,5]

    ```

  

5. **Generar una función que imprima los valores mínimos de cada columna.(1.0)**

- Indicando el número de la columna y el valor mínimo.

- Ejemplo:

    ```cpp

    fila columna valor

    0 3 1

    1 2 1

    ```
## Recursos en línea

- [cpp Datatypes](https://www.geeksforgeeks.org/cpp-data-types/) [Artículo]
- [C++ Header Files: A Pillar of Efficient Coding](https://www.simplilearn.com/tutorials/cpp-tutorial/guide-to-understand-cpp-header-files) [Artículo]
- [Structures in cpp](https://www.geeksforgeeks.org/structures-in-cpp/) [Artículo]
- [Functions in cpp](https://www.geeksforgeeks.org/functions-in-cpp/) [Artículo]
- [C++ Structures for beginners (explained in 30 minutes)](https://www.youtube.com/watch?v=9j5KkOC_goQ) [Video]
- [C++ arrays explained 🚗](https://www.youtube.com/watch?v=QFrJQq6Iox8) [Video]
- [DATA STRUCTURES - How to work with arrays? (for beginners)](https://www.youtube.com/watch?v=T76E09hnEuo) [Video]
- [💻MATRICES en PROGRAMACIÓN ¿Qué son y cómo funcionan? 💻 ](https://www.youtube.com/watch?v=twRXsDm2FUo) [Video]
- [35. Programaciòn en C++ || Matrices](https://www.youtube.com/watch?v=7LMAZimcgZ8) [Video]
- [Bot de chatgpt para que hagan preguntas](https://chatgpt.com/share/87f28d74-ffcb-4d9a-b322-94ba4b8c739c) [Herramienta]
- [Slides vistas e  n clase](https://   livejaverianaedu.sharepoint.com/:b:/s/ProgramacinAvanzada2430/Ef0DYdKDijhOsEJifWHcBrIBuyYCDK5Gww12quOkJ8AcdA?e=Jb01RJ) [Slides]
- [Installing C++ in Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp) [Tutorial]