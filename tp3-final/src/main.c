#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesFig.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). //OK
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario). //OK
     3. Alta de empleado (como obtener el ultimo id)
     4. Modificar datos de empleado //OK
     5. Baja de empleado //Preguntar pero parece OK (la primera borra bien, despues se rompe)
     6. Listar empleados //OK
     7. Ordenar empleados // En binario anda bien en csv no
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto). //OK
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario). //OK
    10. Salir
*****************************************************/





int main()
{
    char continuar = 's';
    LinkedList* employeeList = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",employeeList))
            {
                printf("Problemas para cargar los empleados.\n");
            }
            else
            {
                printf("Empleados cargados con exito.\n");
            }
            break;
        case 2:
            if(controller_loadFromBinary("data.bin",employeeList))
            {
                printf("Problemas para cargar los empleados.\n");
            }
            else
            {
                printf("Empleados cargados con exito.\n");
            }
            break;
        case 3:
            controller_addEmployee(employeeList);
            break;
        case 4:
            if(ll_isEmpty(employeeList)!=1)
            {
                controller_editEmployee(employeeList);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 5:
            if(ll_isEmpty(employeeList)!=1)
            {
                controller_removeEmployee(employeeList);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 6:
            if(ll_isEmpty(employeeList)!=1)
            {
                controller_ListEmployee(employeeList);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 7:
            if(ll_isEmpty(employeeList)!=1)
            {
                controller_sortEmployee(employeeList);
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 8:
            if(ll_isEmpty(employeeList)!=1)
            {
                if((!controller_saveAsText("data.csv",employeeList)))
                {
                    printf("Empleados guardados con exito!\n");
                }
                else
                {
                    printf("Error guardando datos.\n");
                }
            }
            else
            {
                printf("No hay datos cargados aun.\n");
            }
            break;
        case 9:
            if(ll_isEmpty(employeeList)!=1)
            {
                if((!controller_saveAsBinary("data.bin",employeeList)))
                    {
                        printf("Empelados guardados con exito!\n");
                    }
                    else
                    {
                        printf("Error guardando datos.\n");
                    }
            }
            else
            {
                printf("No hay datos cargados aun\n");
            }
            break;
        case 10:
            continuar = 'n';
            printf("Hasta luego.\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(continuar == 's');

    ll_deleteLinkedList(employeeList);

    return 0;
}






