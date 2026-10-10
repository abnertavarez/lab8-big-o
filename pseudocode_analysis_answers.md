PROCEDURE FindAndCountActive(sortedIds, isActive, count, targetId)
    first = 0
    last = count - 1
    found = false

    WHILE first <= last AND found is false
        middle = (first + last) / 2

        IF sortedIds[middle] = targetId
            found = true
        ELSE IF sortedIds[middle] < targetId
            first = middle + 1
        ELSE
            last = middle - 1
        END IF
    END WHILE

    activeCount = 0
    FOR index = 0 TO count - 1
        IF isActive[index] is true
            activeCount = activeCount + 1
        END IF
    END FOR

    RETURN found, activeCount
END PROCEDURE


Parte D1
La búsqueda binaria tiene una complejidad de O(log n) porque en cada paso reduce a la mitad los IDs que necesita revisar. En cambio, contar las actividades activas tiene una complejidad de O(n), porque tiene que revisar todas las actividades una por una. La complejidad del procedimiento completo es O(n), ya que primero realiza la búsqueda y después cuenta las actividades activas. Los costos se suman, O(log n) + O(n), pero el resultado sigue siendo O(n) porque contar las actividades requiere más trabajo cuando aumenta la cantidad de datos. Los costos no se multiplican porque las dos operaciones se hacen por separado, una después de la otra.  La búsqueda binaria termina antes de que empiece el ciclo que cuenta las actividades.





PROCEDURE CountPotentialConflicts(startTimes, count)
    conflictCount = 0

    FOR first = 0 TO count - 1
        second = first + 1

        WHILE second < count
            IF startTimes[first] = startTimes[second]
                conflictCount = conflictCount + 1
            END IF

            second = second + 1
        END WHILE
    END FOR

    RETURN conflictCount
END PROCEDURE

Parte D2
La variable second comienza en first + 1 para evitar comparar una actividad consigo misma y para no revisar el mismo par dos veces. De esta manera, cada par distinto se analiza una sola vez.La operación representativa es comparar startTimes (fisrt) con startTimes(second) para verificar si ambas actividades comienzan a la misma hora. En el caso de más trabajo, la complejidad es O(n²), porque hay dos ciclos que recorren los pares de actividades. Si se duplica count, la cantidad de comparaciones aumenta aproximadamente cuatro veces cuando el tamaño de la entrada es grande. Esto sucede porque el número de pares distintos es n(n - 1) / 2. Por ejemplo, con 4 actividades hay 6 pares, mientras que con 8 actividades hay 28. Esto demuestra el crecimiento cuadrático del procedimiento. 