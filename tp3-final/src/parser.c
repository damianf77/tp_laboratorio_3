#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    int cantOfScan;
    char bufferForTheScan[4][1000];
    Employee* auxiliarEmployee;

    if(pFile !=NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");

        while(!feof(pFile))
        {
            auxiliarEmployee = employee_new();
            cantOfScan = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",bufferForTheScan[0],bufferForTheScan[1],bufferForTheScan[2],bufferForTheScan[3]);
            if(cantOfScan == 4)
            {
                auxiliarEmployee = employee_newParametros(bufferForTheScan[0],bufferForTheScan[1],bufferForTheScan[2],bufferForTheScan[3]);
                ll_add(pArrayListEmployee,auxiliarEmployee);
                error = 0;
            }
            else
            {
                break;
            }
        }

    }
    return error;
}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* auxiliarEmployee;
    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {

        //fscanf(pFile, "%*[^\n]\n"); //salto la primera linea del encabezado.

        while(!feof(pFile))
        {
            auxiliarEmployee=employee_new();
            if(fread(auxiliarEmployee,sizeof(Employee),1,pFile)!=0)
            {
                ll_add(pArrayListEmployee,auxiliarEmployee);
            }
        }
        error = 0;
    }
    return error;
}
