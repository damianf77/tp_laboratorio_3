#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"

#include "validacionesFig.h"

int initPersonas(LinkedList* lista)
{
    int todoOk = 0;
    if (lista != NULL)
    {
        for(int i = 0; i < ll_len(lista); i++)
        {
            lista = NULL;
        }
        todoOk = 1;
    }

    return todoOk;
}

Employee* employee_new()
{
    Employee* auxiliarNewEmployee;
    auxiliarNewEmployee = (Employee*) malloc(sizeof(Employee));

    if(auxiliarNewEmployee != NULL)
    {
        auxiliarNewEmployee->id = 0;
        strcpy(auxiliarNewEmployee->nombre,"");
        auxiliarNewEmployee->horasTrabajadas = 0;
        auxiliarNewEmployee->sueldo = 0;
    }

    return auxiliarNewEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr) //modificar lo que ya usamos en la ultima clase.
{
    Employee* employeeToCreate;

    employeeToCreate = employee_new();

    if(employeeToCreate != NULL)
    {
        if(employee_setId(employeeToCreate,atoi(idStr))
                || employee_setNombre(employeeToCreate,nombreStr)
                || employee_setHorasTrabajadas(employeeToCreate,atoi(horasTrabajadasStr))
                || employee_setSueldo(employeeToCreate,atoi(sueldoStr))
          )
        {
            employee_delete(employeeToCreate);
            employeeToCreate = NULL;
        }

    }
    return employeeToCreate;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
    int error = 1;
    if(this!=NULL && id > 0 && id <= 20000)
    {
        this->id = id;
        error = 0;
    }
    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = 1;
    if(this!=NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && strlen(nombre) >= 3 && strlen(nombre) < 128)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }
    return error;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }
    return error;

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 1;
    if(this!=NULL && horasTrabajadas > 0 && horasTrabajadas <= 100000)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }
    return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 1;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;
    if(this!=NULL && sueldo > 0 && sueldo <= 100000)
    {
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if(this!=NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;
}

int showEmployeeInformation(Employee* empleado)
{
    int error = 1;

    if(empleado != NULL)
    {
        printf("%4d         %20s                %4d                   %d\n",empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
        error = 0;
    }
    return error;
}

int cmpEmployeesByName(void* employeeA, void* employeeB)
{
    int returnedInt;
    Employee* auxiliarEmployeeA = (Employee*) employeeA;
    Employee* auxiliarEmployeeB = (Employee*) employeeB;

    if(strcmp(auxiliarEmployeeA->nombre,auxiliarEmployeeB->nombre)<0)
    {
        returnedInt = -1;
    }
    else if(strcmp(auxiliarEmployeeA->nombre,auxiliarEmployeeB->nombre)>0)
    {
        returnedInt = 1;
    }
    else
    {
        returnedInt = 0;
    }
    return returnedInt;
}

int findEmployeeById(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    int auxiliarId;
    Employee* auxiliarEmployee;

    int listLenght = ll_len(pArrayListEmployee);

    for(int i = 0; i< listLenght; i++)
    {
        auxiliarEmployee = ll_get(pArrayListEmployee, i);
        if(employee_getId(auxiliarEmployee, &auxiliarId) == 0 &&
           auxiliarId == id)
        {
            indice = i;
        }
    }
    return indice;
}

int menu()
{
    int option;
    printf("1- Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2- Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3- Alta de empleado.\n");
    printf("4- Modificar datos de empleado.\n");
    printf("5- Baja de empleado.\n");
    printf("6- Listar empleados.\n");
    printf("7- Ordenar empleados.\n");
    printf("8- Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9- Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10- Salir.\n");
    utn_getNumero(&option,"Elija una opcion: ","Error, opcion incorrecta.\n",1,10,3);
    return option;
}


int menuModificar()
{
    int rta;
    printf("1-Nuevo nombre\n");
    printf("2-Nuevo horas trabajadas\n");
    printf("3-Nuevo sueldo\n");
    utn_getNumero(&rta,"Ingrese una opcion\n","Error, opcion invalida",1,3,3);
    return rta;
}
