#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Obtiene espacio en memoria dinamica para el puntero del empleado
 *
 * \return NULL si no consigui el espacio sino retora la direccion de memoria
 *
 */
Employee* employee_new();

/** \brief construye al empleado y le pasa los datos recibidos por parametro, tambien verifica que los datos sean correctos a traves de los setter
 *
 * \param idStr char*, cadena con el id
 * \param nombreStr char*, cadena con el nombre
 * \param horasTrabajadasSrt char*, cadena con la cantidad de horas trabajadas
 * \param sueldoStr char*, cadena con el sueldo
 *
 * \return retora NULL sino pudo settear los parametros sino retorna al empleado construido
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr); //modificar lo que ya usamos en la ultima clase.


/** \brief libera el espacio en memoria del elemento que le llega por parametro
 *
 * \param this Employee*, direccion de memoria del empleado
 * \return void
 *
 */
void employee_delete(Employee* this);


/** \brief verifica que el id este en el rango correcto y se lo asigna al empleado
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param id int, variable con el entero
 * \return 1 si el puntero es NULL o si la variable no esta en el rango, 0 si no lo hubo
 *
 */
int employee_setId(Employee* this,int id);


/** \brief verifica que los parametros no sean null y asigna el id del empleado al puntero id que le llega por parametro
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param id int*, puntero del id
 * \return 1 si algun puntero es NULL, 0 si no lo hubo
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief verifica que el nombre este en el rango correcto y se lo asigna al empleado
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param nombre char*, cadena con el nombre
 * \return 1 si el puntero es NULL o el nombre esta fuera del rango, 0 si no lo hubo
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief verifica que los parametros no sean null y asigna el id del empleado al puntero id que le llega por parametro
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param id int*, puntero del id
 * \return 1 si algun puntero es NULL, 0 si no lo hubo
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief verifica que las horas trabajadas este en el rango correcto y se lo asigna al empleado
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param horasTrabajadas int, variable con la cantidad de horas trabajadas
 * \return 1 si el puntero es NULL o la cantidad esta fuera del rango, 0 si no lo hubo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief verifica que los parametros no sean null y asigna la cantidad de horas trabajadas del empleado al puntero horas trabajadas que le llega por parametro
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param horasTrabajadas int*, puntero de las horas trabajadas
 * \return 1 si algun puntero es NULL, 0 si no lo hubo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief verifica que los sueldos esten en el rango correcto y se lo asigna al empleado
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param sueldo int, variable con el sueldo
 * \return 1 si el puntero es NULL o la cantidad esta fuera del rango, 0 si no lo hubo
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief verifica que los parametros no sean null y asigna la cantidad de horas trabajadas del empleado al puntero horas trabajadas que le llega por parametro
 *
 * \param this Employee*, direccion de memoria del empleado
 * \param sueldo int*, puntero del sueldo
 * \return 1 si algun puntero es NULL, 0 si no lo hubo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief muestra los datos del empleado que le llega por parametro
 *
 * \param empleado Employee*, puntero del empleado
 * \return error 1 si el empleado es null, 0 si no hubo error
 *
 */
int showEmployeeInformation(Employee* empleado);

/** \brief castea los empleados a puntero employee y compara sus campos de nombre
 *
 * \param employeeA void*, puntero void
 * \param employeeB void*, puntero void
 * \return retorna 0 si las cadenas son iguales, 1 si la segunda cadena es menor que la primera y -1 si la primera es menos que la segunda.
 */
int cmpEmployeesByName(void* employeeA, void* employeeB);

/** \brief despliega un menu con opciones
 *
 * \return el entero con la opcion elegida
 *
 */
int menu();

/** \brief despliega un menu con opciones de modificacion
 *
 * \return entero con opcion elegida
 *
 */
int menuModificar();

/** \brief encuentra un empleado por ID y devuelve el indice en el array
 *
 * \param pArrayListEmployee LinkedList*, puntero de la lista linkedlist
 * \param id int, variable con el id
 * \return -1 si no existe en la lista, o un entero con el indice donde se encuentra el archivo
 *
 */
int findEmployeeById(LinkedList* pArrayListEmployee, int id);

#endif // employee_H_INCLUDED
