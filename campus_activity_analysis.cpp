/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: [Date]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}
/*

* Analysis Answers
*
* C1 — Acceso directo
* Respuesta:
* La complejidad es O(1), o tiempo constante. Esto se debe a que la
* función busca el elemento directamente usando su índice. No importa
* si el arreglo tiene pocos o muchos elementos, solo accede a una
* posición, como cuando obtiene el valor 108 del índice 2.
*
* C2 — Contar actividades activas
* Respuesta:
* La complejidad es O(n), o tiempo lineal, porque el ciclo revisa
* cada actividad del arreglo una por una. En este caso, revisa las
* 8 actividades y encuentra que 4 están activas. Si hubiera más
* actividades, tendría que revisar más elementos.
*
* C3 — Búsqueda binaria
* Respuesta:
* La complejidad es O(log n), o tiempo logarítmico, porque en cada
* comparación se descarta aproximadamente la mitad de los elementos
* que quedan por revisar. Para que funcione correctamente, los IDs
* deben estar ordenados de menor a mayor. Si están desordenados,
* la función podría descartar la parte donde se encuentra el ID
* que está buscando. En el programa, encuentra el 140 en 3 comparaciones.
*
* C4 — Pasos de división a la mitad
* Respuesta:
* Si itemCount comienza en 16, los valores van cambiando así:
* 16, 8, 4, 2 y 1. En cada paso, el valor se divide entre 2.
* Para llegar a 1 desde 16 se necesitan 4 pasos, mientras que desde
* 32 se necesitan 5. Aunque el número inicial se duplica, solo hace
* falta un paso adicional. Por eso, la complejidad es O(log n).
*
* C5 — Pares distintos
* Respuesta:
* El segundo ciclo comienza en first + 1 para evitar comparar una
* actividad consigo misma y contar el mismo par dos veces. Si comenzara
* en 0, se repetirían pares y también se incluirían comparaciones de
* una actividad consigo misma. La complejidad es O(n²) porque los dos
* ciclos recorren las combinaciones de actividades. Con 4 actividades
* hay 6 pares, y con 8 actividades hay 28.
*
* C6 — Comparar los patrones observados
* Respuesta:
* Cada función muestra un comportamiento diferente. El acceso directo
* es O(1) porque accede a una sola posición y devuelve 108. El conteo
* de actividades es O(n) porque revisa las 8 actividades y encuentra
* 4 activas. La reducción a la mitad es O(log n): necesita 3 pasos
* para 8, 4 para 16 y 5 para 32. Por último, los pares son O(n²):
* aumentan de 6 con 4 actividades a 28 con 8. Esto muestra cómo cada
* tipo de algoritmo crece de manera diferente cuando aumenta la entrada.
*
* C7 — Decisión sobre ordenar
* Respuesta:
* Si necesito buscar un ID solo unas pocas veces y los datos están
* desordenados, usaría una búsqueda lineal para evitar el trabajo
* adicional de ordenar. Esta búsqueda tiene un costo de O(n) en el
* peor caso. En cambio, si voy a buscar muchos IDs en el mismo arreglo,
* podría ordenarlo una sola vez y después usar búsqueda binaria.
* Un algoritmo eficiente como Merge Sort tarda O(n log n) en ordenar,
* mientras que cada búsqueda binaria tarda O(log n). Así, ordenar
* puede valer la pena cuando se necesitan muchas búsquedas.
*

*/
