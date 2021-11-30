#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

/*
 ============================================================================
 Author      : Figueroa Damian
 ============================================================================
 */

int main()
{
    setbuf(stdout, NULL);
    LinkedList* listaEmpleados = ll_newLinkedList();
    char salir= 'n';
    int flagTexto=0; //carga no realizada
    int flagBin =0; //carga no realizada
    int opcion;
    int id=1000;
    int flagGuardarBin=0;//no se guardo
    int flagGuardarTexto=0;//no se guardo
    char respuesta[2];
    int guardar;
    do
    {

        switch(menuListaEmpleados())
        {

        case 1:
            if(ll_isEmpty(listaEmpleados)|| (flagBin==0 && flagTexto==0))
            {
                system("cls");
                printf("\n\nEleccion del archivo que se cargara:\n\n");

                utn_getNumero(&opcion,"\n1.Cargar desde la lista original.\n\n2.Cargar lo ultimo guardado.\n\nSeleccione opcion: ","\nError,opcion invalida\n",1,2,3);

                if(opcion==1)
                {
                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        flagTexto=1; //carga realizada
                    }
                    else
                    {
                        printf("\nNo se ha cargado el archivo\n\n");
                    }
                    }else if(opcion==2){

					if(controller_loadFromText("empleados.csv",listaEmpleados))
					{
					flagTexto=1; //carga realizada
					}
					else
					{
					printf("\nNo se ha cargado el archivo\n\n");
					}
                }
            }
            else
            {
                printf("\nNo puedes cargar dos veces el archivo\n\n");
            }
            system("pause");

            break;

        case 2:
            if( ll_isEmpty(listaEmpleados)|| (flagBin==0 && flagTexto==0))
            {
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    flagBin=1; //carga realizada
                }
            }
            else
            {
                printf("\nNo puedes cargar dos veces el archivo\n");
            }
            system("pause");
            break;

        case 3:
            if(controller_addEmployee(listaEmpleados,&id))
            {
                controller_saveAsTextIdEmpleado("idEmpleados.csv",listaEmpleados,id);
            }

            system("pause");
            break;

        case 4:
            if(ll_len(listaEmpleados)>0)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo hay empleados para editar\n\n");
            }
            system("pause");
            break;

        case 5:

            if(ll_len(listaEmpleados)>0)
            {
                controller_removeEmployee(listaEmpleados);

            }
            else
            {
                printf("\nNo hay empleados para realizar una baja\n\n");
            }
            system("pause");
            break;

        case 6:
            if(ll_len(listaEmpleados)>0)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo hay empleados para mostrar\n\n");
            }
            system("pause");
            break;

        case 7:
            if(ll_len(listaEmpleados)>0)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("\nNo hay empleados para ordenar\n\n");
            }
            system("pause");
            break;

        case 8:

            if(ll_len(listaEmpleados)>0)
            {
                controller_saveAsText("empleados.csv",listaEmpleados);
                flagGuardarTexto=1;
            }
            else
            {
                printf("\nNo hay empleados para guardar\n\n");
            }

            system("pause");
            break;

        case 9:
            if(ll_len(listaEmpleados)>0)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
                flagGuardarBin=1;
            }
            else
            {
                printf("\nNo hay empleados para guardar\n\n");
            }
            system("pause");
            break;

        case 10:
            if(flagGuardarBin==0&&flagGuardarTexto==0)
            {
                utn_getChar(respuesta,2,"\nEsta seguro de que desea irse sin guardar? Ingrese s/n: ","\nError, ingrese s/n\n",3);
                if(!strcmp(respuesta,"s"))
                {
                    printf("\nHa abandonado el programa\n");
                    salir = 's';
                }
                else if(!strcmp(respuesta,"n"))
                {
                    utn_getNumero(&guardar,"\nDe que modo desea guardar: \n1.Binario\n2.Texto\n","\nError, ingrese 1 o 2 \n",1,2,3);

                    if(guardar==1)
                    {
                        controller_saveAsBinary("data.bin",listaEmpleados);
                        printf("\nSe han guardado los cambios\n");
                        salir = 's';
                    }
                    else if(guardar==2)
                    {
                        controller_saveAsText("empleados.csv",listaEmpleados);
                        printf("\nSe han guardado los cambios\n");
                        salir = 's';
                    }
                }
            }else{
            	salir = 's';
            }

            system("pause");
            break;
        default:
            printf("Opcion invalida.\n");
            system("pause");
            break;

        }
    }
    while(salir=='n');

	return EXIT_SUCCESS;
}


