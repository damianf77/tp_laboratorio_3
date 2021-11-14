#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

#include "validacionesFig.h"





int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int problem = 1;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        FILE* textFile;
        textFile = fopen(path,"r");

        if(textFile != NULL)
        {
            if(!parser_EmployeeFromText(textFile, pArrayListEmployee))
            {
                problem = 0;
            }

            fclose(textFile);
        }
    }

    return problem;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int problem = 1;

    if(path != NULL && pArrayListEmployee != NULL)
    {

        FILE* pFile;

        pFile = fopen(path,"rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                problem = 0;
            }

            fclose(pFile);
        }
    }

    return problem;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    int nameFlag = 0;
    int JobHoursFlag = 0;
    int salaryFlag = 0;
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        Employee* auxiliarEmployee;
        int id;
        char nameForEmployee[128];
        int jobHoursForEmployee;
        int salaryForEmployee;

        char idStr[4096];
        char jobHoursStr[4096];
        char salaryForEmployeeStr[4096];

        createFileId(&id);

        printf("****** Registrar un empleado nuevo ******\n");

        if(utn_getNombre(nameForEmployee,128,"Ingrese el nombre: ","Error, solo se deben digitar letras y sin espacios.\n",3)==0)
        {
            nameFlag = 1;
        }
        if(utn_getNumero(&jobHoursForEmployee,"Ingrese la cantidad de horas: ","Error, solo puede digitar numeros.\n",0,100000,3)==0)
        {
            JobHoursFlag = 1;
        }
        if(utn_getNumero(&salaryForEmployee,"Ingrese el salario: ","Error, solo numeros enteros.\n",0,100000,3)==0)
        {
            salaryFlag = 1;
        }
        if(nameFlag  && JobHoursFlag && salaryFlag)
        {
            itoa(id,idStr,10);
            itoa(jobHoursForEmployee,jobHoursStr,10);
            itoa(salaryForEmployee,salaryForEmployeeStr,10);
            auxiliarEmployee = employee_newParametros(idStr,nameForEmployee,jobHoursStr,salaryForEmployeeStr);
            if(auxiliarEmployee == NULL)
            {
                printf("Error en la carga.\n");
                system("pause");
            }
            else
            {
                ll_add(pArrayListEmployee,auxiliarEmployee);
                updateId(id);
                error = 0;
                system("pause");
            }

        }
        else
        {
            printf("Error, carga de datos fallida.\n");
            system("pause");
        }
    }
    return error;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        Employee* auxiliarEmployee;
        int id;
        int index;
        char newNameForEmployee[100];
        int newHoursForEmployee;
        int newSalaryForEmployee;

        controller_ListEmployee(pArrayListEmployee);
        printf("******* Actualizar Empleado ********\n\n");

        if(utn_getNumero(&id,"Ingrese el id del empleado a modificar: ","Error, solo numeros\n",0,20000,3)==-1)
        {
            printf("Operacion cancelada\n");
            system("pause");
        }
        else
        {
            index = findEmployeeById(pArrayListEmployee,id);

            if(index == -1)
            {
                printf("No hay empleado con ese id\n");
            }
            else
            {
                auxiliarEmployee = (Employee*) ll_get(pArrayListEmployee,index);
                showEmployeeInformation(auxiliarEmployee);

                switch(menuModificar())
                {
                case 1:
                    if(utn_getNombre(newNameForEmployee,100,"Ingrese nuevo nombre: ","\nError, nombre invalido. Debe ser entre 3 y 128 caracteres.\n",3)==-1)
                    {
                        printf("Error, operacion cancelada. No hay mas intentos.\n");
                        system("pause");
                    }
                    else
                    {
                        strcpy(auxiliarEmployee->nombre,newNameForEmployee);
                        printf("Nombre modificado con exito.\n");
                    }
                    break;
                case 2:
                    if(utn_getNumero(&newHoursForEmployee,"Ingrese nueva cantidad de horas trabajadas: ","\nError, solo numeros y que sean enteros.\n",1,100000,3)==-1)
                    {
                        printf("Error, operacion cancelada. No hay mas intentos.\n");
                        system("pause");
                    }
                    else
                    {
                        auxiliarEmployee->horasTrabajadas = newHoursForEmployee;
                        printf("Nueva cantidad de horas trabajadas cargadas con exito.\n");
                    }
                    break;
                case 3:
                    if(utn_getNumero(&newSalaryForEmployee,"Ingrese nuevo sueldo: ","Error, solo numeros.\n",0,100000,3)==-1)
                    {
                        printf("Error, operacion cancelada. No hay mas intentos\n");
                        system("pause");
                    }
                    else
                    {
                        auxiliarEmployee->sueldo = newSalaryForEmployee;
                        printf("Nuevo sueldo puesto\n");
                    }
                }

            }
        }
    }

    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int succes = -1;
    int index = -1;
    int id;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(utn_getNumero(&id,"Ingrese el id a eliminar: ","\nError, por favor ingrese un id valido.\n",0,20000,3) != -1)
        {

            index = findEmployeeById(pArrayListEmployee,id);

            if(index == -1)
            {
                printf("No hay empleados con el id: %d .\n",id);
                system("pause");
            }
            else
            {

                printf("El empleado a eliminar es el siguiente: \n\n");

                printf("ID                       NOMBRE                  HORAS TRABAJADAS       SUELDO\n");

                showEmployeeInformation((Employee*) ll_get(pArrayListEmployee,index));

                ll_remove(pArrayListEmployee, index);
                printf("\nEmpleado eliminado!!\n");
                succes = 0;
            }
        }
        else
        {
            printf("Error. Gastaste los intentos\n");
        }
    }

    return succes;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int flag = 0;
    if(pArrayListEmployee != NULL)
    {
        printf("ID                       NOMBRE                  HORAS TRABAJADAS       SUELDO\n");
        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if( ((Employee*) ll_get(pArrayListEmployee,i)) != NULL) //devuelve puntero a void casteada a puntero empleado
            {
                showEmployeeInformation((Employee*) ll_get(pArrayListEmployee,i));
                flag = 1;
            }

        }
        if(flag==0)
        {
            printf("No hay personas para mostrar\n");
        }
    }
    return flag;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        int orden;
        if(utn_getNumero(&orden,"0-Ascendente\n 1-Descendente\n","Error, opcion invalida\n",0,1,3)!= -1)
        {
            if(orden == 0)
            {
                ll_sort(pArrayListEmployee,cmpEmployeesByName,0);
            }
            if(orden == 1)
            {
                ll_sort(pArrayListEmployee,cmpEmployeesByName,1);
            }
        }
        else
        {
            printf("No te quedan intentos\n");
        }
    }
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        FILE* archivo =  fopen(path,"w");
        Employee* auxEmployee;
        fprintf(archivo, "Id, Nombre, HorasTrabj, Sueldo\n");
        if(archivo!=NULL)
        {
            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
                if(auxEmployee!=NULL)
                {
                    fprintf(archivo,"%d,%s,%d,%d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                    error = 0;
                }
            }
        }
        fclose(archivo);

    }

    return error;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        FILE* archivo =  fopen(path,"wb");
        Employee* auxEmployee;

        if(archivo!=NULL)
        {
            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee,i);
                if(auxEmployee!=NULL)
                {
                    fwrite(auxEmployee,sizeof(Employee),1,archivo);
                    error = 0;
                }
            }
        }
        fclose(archivo);
    }
    return error;
}

int createFileId(int* id)
{
    //Si no sirve el archivo arranca en 1001
    *id = 1001;
    int error = 1;

    FILE* idFile;
    idFile = fopen("proximoid.bin","rb");

    if(idFile != NULL)
    {
        fread(id,sizeof(int),1,idFile);

        fclose(idFile);
        error = 0;
    }

    return error;
}

int updateId(int id)
{
    int proxId = ++id;
    int error  = 1;
    FILE* idFile;
    idFile = fopen("proximoid.bin","wb");

    if(idFile != NULL)
    {
        fwrite(&proxId,sizeof(int),1,idFile);

        fclose(idFile);
        error = 0;
    }

    return error;
}


