#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <vector>
#include <algorithm>

using namespace std;


// computadora.h
class Civilizacion 
{
    string nombre;
    float ubicacion_x;
    float ubicacion_y;
    float puntuacion;
    

public:
    Civilizacion ();
    Civilizacion (const string &nombre, float ubicacion_x, float ubicacion_y, float puntuacion);
    void setNombre (const string &v);
    string getNombre ();
    void setUbicacion_x (float v);
    float getUbicacion_x ();
    void setUbicacion_y (float v);
    float getUbicacion_y ();
    void setPuntuacion (float v);
    float getPuntuacion ();


// Sobrecarga del operador 
    friend ostream& operator<<(ostream&out, const Civilizacion &p)
    {
        // Imprimir cada atributo con out          
            out << left ; // Para que todo este  alineado          
            out << setw(20) << p.nombre;
            out << setw(20) << p.ubicacion_x;
            out << setw(10) << p.ubicacion_y;
            out << setw(18) << p.puntuacion;
            out << endl;
// En out estara toda la informacion
            return out;
    }
// Sobrecargar el operador de entrada
    friend istream& operator>>(istream&in, Civilizacion &p)
    {
            cout << "Nombre: ";
            getline (cin, p.nombre);

            cout << "Ubicacion en X: ";
            cin >> p.ubicacion_x;

            cout << "Ubicacion en Y: ";
            cin >> p.ubicacion_y;

            cout << "Puntuacion: ";
            cin >> p.puntuacion;

            return in;
    }
    bool operator==(const Civilizacion& p)
    {
        return nombre == p.nombre;
    }
    bool operator==(const Civilizacion& p) const
    {
        return nombre == p.nombre;
    }

    bool operator<(const Civilizacion& p)
    {
        return 2;
    }
    bool operator<(const Civilizacion& p) const
    {
        return nombre < p.nombre;
    }

};





//computadora.cpp
Civilizacion :: Civilizacion ()
{
}

Civilizacion::Civilizacion(const string &nombre, float ubicacion_x, float ubicacion_y, float puntuacion)
{
    this -> nombre = nombre;
    this -> ubicacion_x = ubicacion_x;
    this -> ubicacion_y = ubicacion_y;
    this -> puntuacion = puntuacion;
}
//          nombre
void Civilizacion::setNombre(const string &v)
    {
        nombre = v;
    }
    string Civilizacion :: getNombre()
{
    return nombre;
}
//          ubicacion x
void Civilizacion::setUbicacion_x(float v)
    {
        ubicacion_x = v;
    }
    float Civilizacion :: getUbicacion_x()
{
    return ubicacion_x;
}
//          ubicacion y
void Civilizacion::setUbicacion_y(float v)
    {
        ubicacion_y = v;
    }
    float Civilizacion :: getUbicacion_y()
{
    return ubicacion_y;
}
//          puntuacion
void Civilizacion::setPuntuacion(float v)
    {
        puntuacion = v;
    }
    float Civilizacion :: getPuntuacion()
{
    return puntuacion;
}









//  Clase Administradora.h
class VideoGame
{

    string nombre_videogame;
    vector<Civilizacion> civilizaciones;

public:
    VideoGame ();

    void agregarcivilizacion (const Civilizacion &p);
    void mostrar ();
    void insertar(const Civilizacion &p, size_t pos);
    size_t size();
    void inicializar(const Civilizacion &p, size_t n);
    void eliminar(size_t pos);
    void ordenarNombre ();
    void ordenarUbicacion_x ();
    void ordenarUbicacion_y ();
    void ordenarPuntuacion ();
    void primera();
    void ultimo();
    void setNombre_Videogame (const string &nombre_videogame);
    string getNombre_Videogame();

    Civilizacion* buscar(const Civilizacion &p);
    Civilizacion* modificar(Civilizacion &p);
    friend VideoGame& operator<< (VideoGame&v, const Civilizacion &p)
    {
        v.agregarcivilizacion (p);
        return v;
    }

};










//  Clase Administradora.cpp

VideoGame::VideoGame ()
    {

    }

void VideoGame::agregarcivilizacion (const Civilizacion &p)
    {
        civilizaciones.push_back(p);
    }

//Imprimira los datos que hayas ingresado, no necesariamente los 5 elementos.
void VideoGame::mostrar ()
    {   
        cout << left ;
        cout << endl;
        cout << setw (20) << "Nombre- ";
        cout << setw (20) << "Ubicacion X- ";
        cout << setw (10) << "Ubicacion Y- ";
        cout << setw (18) << "Puntuacion- ";
        cout << endl;

        for (size_t i = 0; i < civilizaciones.size(); i++)
        {   
            Civilizacion &p = civilizaciones [i];
            cout << p;
        }
    }   

void VideoGame::setNombre_Videogame( const string &n ){
    nombre_videogame = n;
}
string VideoGame::getNombre_Videogame(){
    return nombre_videogame;
}


void VideoGame::primera ()
    {
        if (civilizaciones.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else 
                {
                    cout << civilizaciones.front() << endl;
                }
    }

void VideoGame::ultimo ()
    {
        if (civilizaciones.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else 
                {
                    cout << civilizaciones.back() << endl;
                }
    }

void VideoGame::insertar(const Civilizacion &p, size_t pos)
    {
        civilizaciones.insert(civilizaciones.begin()+pos, p);
    }

size_t VideoGame::size()
    {
        return civilizaciones.size();
    }

void VideoGame::inicializar(const Civilizacion &p, size_t n)
    {
        civilizaciones = vector<Civilizacion>(n, p);
    }

void VideoGame::eliminar(size_t pos)
    {
        civilizaciones.erase(civilizaciones.begin()+pos);
    }

// FUNCION LAMBDA
// ascendente "<" descendente ">".

void VideoGame::ordenarNombre()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getNombre() < p2.getNombre();});
    }
void VideoGame::ordenarUbicacion_x()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getUbicacion_x() < p2.getUbicacion_x();});
    }
void VideoGame::ordenarUbicacion_y()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getUbicacion_y() < p2.getUbicacion_y();});
    }
void VideoGame::ordenarPuntuacion()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getPuntuacion() > p2.getPuntuacion();});
    }


Civilizacion* VideoGame::buscar(const Civilizacion &p)
    {
        // vector<Personaje>::iterator
        auto it = find(civilizaciones.begin(), civilizaciones.end(), p);

        if (it == civilizaciones.end()) {
            return nullptr;
        }
        else {
            return &(*it);
        }
    }



Civilizacion* VideoGame::modificar(Civilizacion &p)
    {
        int op;
        string nuevo_nombre;
        float nuevo_x, nuevo_y, nuevo_puntuacion;
        cout << "=============== Menu de Modificar ===============" << endl;
        cout << "1) Modificar el Nombre" << endl;
        cout << "2) Modificar la Ubicacion en X" << endl;
        cout << "3) Modificar la Ubicacion en Y" << endl;
        cout << "4) Modificar la Puntuacion" << endl;
        cout << "Selecciona el dato que desee modificar: " << endl;
        cin >> op; 
        cin.ignore();

        switch(op)
            {
              case 1:
                    {
                        cout << "Escribe el nuevo nombre" << endl;
                        getline(cin,nuevo_nombre);
                        p.setNombre(nuevo_nombre); 
                        cout << "Nombre actualizado" << endl;     
                        system ("pause");
                        break;
                    }

                case 2:
                    {   
                        cout << "Escribe la nueva Ubicacion x" << endl;
                        cin >> nuevo_x; cin.ignore();
                        p.setUbicacion_x(nuevo_x);
                        cout << "X actualizado" << endl;    
                        system ("pause");
                        break;
                    }

                case 3:
                    {
                        cout << "Escribe la nueva Ubicacion y" << endl;
                        cin >> nuevo_y; cin.ignore();
                        p.setUbicacion_y(nuevo_y);        
                        system ("pause");
                        break;
                    }

                case 4:
                    {
                        cout << "Escribe la nueva Puntuacion" << endl;
                        cin >> nuevo_puntuacion; cin.ignore();
                        p.setPuntuacion(nuevo_puntuacion);                               
                        system ("pause");
                        break;
                    }  
            }
                
    }








//main.cpp
int main () 
{
    vector <string> cadenas;
    VideoGame v;
    string op, nuevo_nombre;


    while (true)
    {   
        system ("cls");
        cout << "               Usuario:" << endl;
        cout << " " << v.getNombre_Videogame() << endl;        
        cout << "=============== M E N U ===============" << endl;
        cout << "1) Nombre de Usuario" << endl;
        cout << "2) Agregar Civilizacion" << endl;
        cout << "3) Insertar Civilizacion" << endl;
        cout << "4) Crear Civilizaciones" << endl;
        cout << "5) Primera Civilizacion" << endl;
        cout << "6) Ultima Civilizacion" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar Civilizacion" << endl;
        cout << "9) Buscar" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Salir" << endl;
        cout << "Opcion: ";
        getline(cin, op);
        

        if (op == "1") 
            {   
                string nombre_videogame;
                cout << "Dame el nombre de usuario" << endl;
                getline(cin, nombre_videogame);
                v.setNombre_Videogame(nombre_videogame);
                cout << "===  " << v.getNombre_Videogame() << "  ===" << endl;
                system ("pause");
            } 

// Agregar civilizacion
        else if (op == "2") 
            {
                cout << "=========== Agregar civilizacion ===========" << endl;
                Civilizacion p;

                cin >> p;

                v.agregarcivilizacion(p); 
                cin.ignore();
                system ("pause");
            } 

// Insertar civilizacion
        else if (op == "3") 
            {
                cout << "=========== Insertar civilizacion ===========" << endl;
                Civilizacion p;
                cin >> p;

                size_t pos;
                cout << "Posición: ";
                cin >> pos; cin.ignore();

                if (pos >= v.size()) 
                    {
                        cout << "Posicion no válida" << endl;
                        system ("pause");
                    }
                else 
                    {
                        v.insertar(p, pos);
                        system ("pause");
                    }
            } 

// Inicializar
        else if (op == "4") 
            {
                cout << "=========== Inicializar ===========" << endl;
                Civilizacion p;
                cin >> p;

                size_t n;
                cout << "Numero de veces a inicializar: ";
                cin >> n; cin.ignore();

                v.inicializar(p, n);
                system ("pause");
            }

// Primera civilizacion
         else if (op == "5")
            {
                cout << "=========== Primera Civilizacion ===========" << endl;
                v.primera ();
                system ("pause");
            }

// Ultima civilizacion 
        else if (op == "6")
            {
                cout << "=========== Ultima Civilizacion ===========" << endl;
                v.ultimo ();
                system ("pause");
            }

// Ordenar
        else if (op == "7") 
        {  
                while (true)
                {
                    cout << "=============== Menu de Ordenar ===============" << endl;
                    cout << "1) Ordenar por Nombre" << endl;
                    cout << "2) Ordenar por Ubicacion en X" << endl;
                    cout << "3) Ordenar por Ubicacion en Y" << endl;
                    cout << "4) Ordenar por Puntuacion - Descendente" << endl;
                    getline(cin, op);

                    if (op == "1")
                    {
                        v.ordenarNombre();
                        system ("pause");
                        break;
                    }

                    if (op == "2")
                    {
                        v.ordenarUbicacion_x ();
                        system ("pause");
                        break;
                    }

                    if (op == "3")
                    {
                        v.ordenarUbicacion_y ();
                        system ("pause");
                        break;
                    }

                    if (op == "4")
                    {
                        v.ordenarPuntuacion();
                        system ("pause");
                        break;
                    }
                }     
            }

// Eliminar
        else if (op == "8") 
            {
                cout << "=========== Eliminar ===========" << endl;
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; cin.ignore();

                if (pos >= v.size()) 
                {
                 cout << "Posicion no válida" << endl;
                 system ("pause");
                }
                else 
                {
                 v.eliminar(pos);
                 system ("pause");
                }
            }

// Buscar
        else if (op == "9") 
            {
                cout << "=========== Buscar ===========" << endl;
                Civilizacion p;
                cin >> p; cin.ignore();

                Civilizacion *ptr = v.buscar(p);

                if (ptr == nullptr) {
                    cout << "no encontrado" << endl;
                    system ("pause");
                }
                else {
                    cout << "Civilizacion encontrada: " << endl;
                    cout << *ptr << endl;
                    system ("pause");
                }
            }

// Modificar
        else if (op == "10")
            {
                cout << "=========== Modificar ===========" << endl;
                Civilizacion p;

                cout << "Inserte los datos de la Civilizacion a modificar: " << endl;
                cin >> p; cin.ignore();

                Civilizacion *ptr = v.buscar(p);

                if (ptr == nullptr) 
                    {
                        cout << "Civilizacion no encontrada" << endl;
                        system ("pause");
                    }
                else 
                    {
                        cout << "Civilizacion encontrada: " << endl;
                        cout << *ptr << endl;
                        v.modificar(*ptr);
                    }
            }

// Resumen / mostrar
        else if (op == "11")
            {
                cout << "=========== Resumen ===========" << endl;
                v.mostrar();
                system ("pause");
            }
        
// Salir 
        else if (op == "12") 
            {
                cout << "Usted ha salido del programa" << endl;
                system ("pause");
                break;
            }

// opcion invalida
        else if (op < "1"||op > "12")
            {
                cout << "Opcion Invalida, intentelo de nuevo..." << endl;
                system ("pause");
            }
        
    } 
    return 0;
}