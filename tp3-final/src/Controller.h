
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* cadena con el nombre del archivo
 * \param pArrayListEmployee LinkedList*  puntero linkedlist de la lista de empleados
 * \return int 1 si hubo error, 0 si no lo hubo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* cadena con el nombre del archivo
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int 1 si hubo error, 0 si no lo hubo
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* cadena con el nombre del archivo
 * \param pArrayListEmployee LinkedList*, puntero linkedList de la lista de empleados
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* cadena con el nombre del archivo
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief lee el archivo con el proximo id o si todavia no existe empieza lo crea vacio
 *
 * \param id int*, puntero con el id
 * \return 1 si el archivo es NULL, 0 si no lo es
 *
 */
int createFileId(int* id);

/** \brief abre el archivo en modo escritura binaria y le escribe el id incrementado en 1.
 *
 * \param id int, variable con el entero
 * \return 1 si no puedo abrir el archivo, 0 si no hubo errores
 *
 */
int updateId(int id);
