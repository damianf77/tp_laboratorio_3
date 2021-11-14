/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*, puntero del archivo
 * \param pArrayListEmployee LinkedList*, puntero linkedlist de la lista de empleados
 * \return int 1, si el archivo o la lista son NULL, 0 si no hubo errores.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*, puntero del archivo
 * \param pArrayListEmployee LinkedList*, puntero linkedlist de la lista de empleados
 * \return int 1, si el archivo o la lista son NULL, 0 si no hubo errores.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
