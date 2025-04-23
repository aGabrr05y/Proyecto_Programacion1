#include <iostream>
#include <string>
using namespace std;

bool menu(bool flag){
	int eleccion_menu = 0;
	cout << "Continuar? 1.Si 2.No" << endl;
	cin >> eleccion_menu;
	switch (eleccion_menu) {
	case 1:
		cout << "Reiniciando el tablero..." << endl;
		break;
	case 2:
		cout << "Saliendo...";
		flag = false;
		break;
	default:
		cout << "Opcion no valida, por favor elija 1 o 2." << endl;
	}
	return flag;
}
	
	void codigo_principal(
						int turno,string objeto_1 ,string objeto_2 ,string objeto_3 ,string objeto_4 ,
						string objeto_5 ,string objeto_6 ,string objeto_7 ,string objeto_8 ,
						string objeto_9 ,string objeto_10 ,string objeto_11 ,string objeto_12 ,
						string objeto_13 ,string objeto_14 ,string objeto_15
						)
	{
		string jugador_1 = "",jugador_2 = "";
		for (int i=0;i<4;i++){
			int eleccion_objeto = 0,cantidad_objetos = 0;
			int fila = 0;
			int disponibles_fila1 = (objeto_1 != "   ") + (objeto_2 != "   ") + (objeto_3 != "   ");
			int disponibles_fila2 = (objeto_4 != "   ") + (objeto_5 != "   ") + (objeto_6 != "   ") + (objeto_7 != "   ") + (objeto_8 != "   ");
			int disponibles_fila3 = (objeto_9 != "   ") + (objeto_10 != "   ") + (objeto_11 != "   ") + (objeto_12 != "   ") + (objeto_13 != "   ") + (objeto_14 != "   ") + (objeto_15 != "   ");
			
			if(jugador_1 == "" && jugador_2 == ""){
			cout<<"Ingrese nombre para jugadro 1: ";
			cin>>jugador_1;
			cout<<"Ingrese nombre para jugadro 2: ";
			cin>>jugador_2;
			}else{
				if(turno == 1){
				cout << "Turno de " << jugador_1 << endl;
				}else if(turno == 2){
				cout << "Turno de " << jugador_2 << endl;
			}
			}
			
			cout << "Objetos disponibles: " << endl<< endl;
			cout <<"         "<< objeto_1 << objeto_2 << objeto_3 <<"  "<< endl;
			cout <<"      "<<objeto_4<< objeto_5 << objeto_6 << objeto_7 << objeto_8 <<" "<< endl;
			cout << objeto_9 << objeto_10 << objeto_11 << objeto_12 << objeto_13 << objeto_14 << objeto_15 << endl<< endl;
			
			bool seleccion_valida = false;
			while(!seleccion_valida){
				cout << "De que fila quitará objetos? (1: Primera, 2: Segunda, 3: Tercera): ";
				cin >> fila;
				
				if(fila == 1){
					cout << "Cuantos objetos retirara (disponible " << disponibles_fila1 << ")? ";
					cin >> cantidad_objetos;
					if(cantidad_objetos > 0 && cantidad_objetos <= disponibles_fila1){
						seleccion_valida = true;
					}
				}
				else if(fila == 2){
					cout << "Cuantos objetos retirara (disponible " << disponibles_fila2 << ")? ";
					cin >> cantidad_objetos;
					if(cantidad_objetos > 0 && cantidad_objetos <= disponibles_fila2){
						seleccion_valida = true;
					}
				}
				else if(fila == 3){
					cout << "Cuantos objetos retirara (disponible  " << disponibles_fila3 << ")? ";
					cin >> cantidad_objetos;
					if(cantidad_objetos > 0 && cantidad_objetos <= disponibles_fila3){
						seleccion_valida = true;
					}
				}
				
				if(!seleccion_valida){
					cout << "Cantidad no valida o fila incorrecta. Intente de nuevo." << endl;
				}
			}
			
			for (int j=0;j<cantidad_objetos;j++){
				bool objeto_valido = false;
				while(!objeto_valido){
					cout << "Elija un objeto para quitar de la fila " << fila << ": ";
					cin >> eleccion_objeto;
					
					if(fila == 1){
						if(eleccion_objeto == 1 && objeto_1 != "   "){
							objeto_1 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 2 && objeto_2 != "   "){
							objeto_2 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 3 && objeto_3 != "   "){
							objeto_3 = "   "; objeto_valido = true;
						}
					}
					else if(fila == 2){
						if(eleccion_objeto == 4 && objeto_4 != "   "){
							objeto_4 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 5 && objeto_5 != "   "){
							objeto_5 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 6 && objeto_6 != "   "){
							objeto_6 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 7 && objeto_7 != "   "){
							objeto_7 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 8 && objeto_8 != "   "){
							objeto_8 = "   "; objeto_valido = true;
						}
					}
					else if(fila == 3){
						if(eleccion_objeto == 9 && objeto_9 != "   "){
							objeto_9 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 10 && objeto_10 != "   "){
							objeto_10 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 11 && objeto_11 != "   "){
							objeto_11 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 12 && objeto_12 != "   "){
							objeto_12 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 13 && objeto_13 != "   "){
							objeto_13 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 14 && objeto_14 != "   "){
							objeto_14 = "   "; objeto_valido = true;
						}
						else if(eleccion_objeto == 15 && objeto_15 != "   "){
							objeto_15 = "   "; objeto_valido = true;
						}
					}
					
					if(!objeto_valido){
						cout << "Objeto no disponible. Intente de nuevo." << endl;
					}
				}
			}
			turno = (turno == 1) ? 2 : 1;
		}
	}
	
	int main() {
		bool flag = true,controlador_menu;
		int jugador_1=0,jugador_2=0,turno = 1;
		
		string objeto_1 = "[1]", objeto_2 = "[2]", objeto_3 = "[3]", objeto_4 = "[4]";
		string objeto_5 = "[5]", objeto_6 = "[6]", objeto_7 = "[7]", objeto_8 = "[8]";
		string objeto_9 = "[9]", objeto_10 = "[10]", objeto_11 = "[11]", objeto_12 = "[12]";
		string objeto_13 = "[13]", objeto_14 = "[14]", objeto_15 = "[15]";
		cout << "Bienvenido al juego" << endl<< endl;
		
		do {
			codigo_principal(turno,objeto_1,objeto_2,objeto_3,objeto_4,objeto_5,objeto_6,objeto_7,objeto_8,
							objeto_9,objeto_10,objeto_11,objeto_12,objeto_13,objeto_14,objeto_15);
			cout << "Jugador uno = " << jugador_1 << endl;
			cout << "Jugador dos = " << jugador_2 << endl;
			controlador_menu=menu(flag);
		}while (controlador_menu==true);
		
		return 0;
	}
