#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <vector>
#include <algorithm>

using namespace std;


// computadora.h
class computadora 
{
    string sistem_Op;
    string nombre_equipo;
    int ram;
    float almacenamiento;

public:
    computadora ();
    computadora (const string &sistem_Op, const string &nombre_equipo, int ram, float almacenamiento);
    void setSistem_Op (const string &v);
    string getSistem_Op ();
    void setNombre_equipo (const string &v);
    string getNombre_equipo ();
    void setRAM (int v);
    int getRAM ();
    void setAlmacenamiento (float v);
    float getAlmacenamiento ();

// Sobrecarga del operador 
    friend ostream& operator<<(ostream&out, const computadora &p)
    {
        // Imprimir cada atributo con out          
            out << left ; // Para que todo este  alineado          
            out << setw(20) << p.sistem_Op;
            out << setw(20) << p.nombre_equipo;
            out << setw(10) << p.ram;
            out << setw(18) << p.almacenamiento;
            out << endl;
// En out estara toda la informacion
            return out;
    }
// Sobrecargar el operador de entrada
    friend istream& operator>>(istream&in, computadora &p)
    {
            cout << "Sistema Operativo: ";
            getline (cin, p.sistem_Op);

            cout << "Nombre del equipo: ";
            getline (cin, p.nombre_equipo);

            cout << "Ram: ";
            cin >> p.ram;

            cout << "Almacenamiento: ";
            cin >> p.almacenamiento;

            return in;
    }
    bool operator==(const computadora& p)
    {
        return sistem_Op == p.sistem_Op;
    }
    bool operator==(const computadora& p) const
    {
        return sistem_Op == p.sistem_Op;
    }

    bool operator<(const computadora& p)
    {
        return 2;
    }
    bool operator<(const computadora& p) const
    {
        return sistem_Op < p.sistem_Op;
    }

};





//computadora.cpp
computadora :: computadora ()
{
}

computadora::computadora(const string &sistem_Op, const string &nombre_equipo, int ram, float almacenamiento)
{
    this -> sistem_Op = sistem_Op;
    this -> nombre_equipo = nombre_equipo;
    this -> ram = ram;
    this -> almacenamiento = almacenamiento;
}
//          sistema operativo
void computadora::setSistem_Op(const string &v)
    {
        sistem_Op = v;
    }
    string computadora :: getSistem_Op()
{
    return sistem_Op;
}
//          nombre del equipo
void computadora::setNombre_equipo(const string &v)
    {
        nombre_equipo = v;
    }
    string computadora :: getNombre_equipo()
{
    return nombre_equipo;
}
//          Ram
void computadora::setRAM(int v)
    {
        ram = v;
    }
    int computadora :: getRAM()
{
    return ram;
}
//          almacenamiento
void computadora::setAlmacenamiento(float v)
    {
        almacenamiento = v;
    }
    float computadora :: getAlmacenamiento()
{
    return almacenamiento;
}






//  Clase Administradora.h
class Laboratorio
{
   vector<computadora> computadoras;

public:
    Laboratorio ();
    void agregarcompu (const computadora &p);
    void mostrar ();
    void respaldar_tabla ();
    void respaldar ();
    void recuperar ();

    void insertar(const computadora &p, size_t pos);
    size_t size();
    void inicializar(const computadora &p, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    computadora* buscar(const computadora &p);
    
    friend Laboratorio& operator<< (Laboratorio&v, const computadora &p)
    {
        v.agregarcompu (p);
        return v;
    }

};




//  Clase Administradora.cpp

Laboratorio::Laboratorio ()
{

}

void Laboratorio::agregarcompu (const computadora &p)
{
    computadoras.push_back(p);
}

//Imprimira los datos que hayas ingresado, no necesariamente los 5 elementos.
void Laboratorio::mostrar ()
{   
    cout << left ;
    cout << endl;
    cout << setw (20) << "Sistema Operativo- ";
    cout << setw (20) << "Nombre del equipo- ";
    cout << setw (10) << "Ram- ";
    cout << setw (18) << "Almacenamiento- ";
    cout << endl;

    for (size_t i = 0; i < computadoras.size(); i++)
    {   
        computadora &p = computadoras [i];
        cout << p;
    //    cout << "Sistema Operativo: " << arreglo[i].getSistem_Op() << endl;
    //    cout << "Nombre del equipo: " << arreglo[i].getNombre_equipo() << endl;
    //    cout << "Ram: " << arreglo[i].getRAM() << "GB" << endl;
    //    cout << "Almacenamiento: " << arreglo[i].getAlmacenamiento() << "GB" << endl;
    //    cout << endl;
    }
}   
    void Laboratorio::respaldar_tabla ()
    {
        ofstream archivo("Computadoras_Tabla.txt");
        if (archivo.is_open())
        {
            archivo << left ;
            archivo << endl;
            archivo << setw (20) << "Sistema Operativo- ";
            archivo << setw (20) << "Nombre del equipo- ";
            archivo << setw (10) << "Ram- ";
            archivo << setw (18) << "Almacenamiento- ";
            archivo << endl;

            for (size_t i = 0; i < computadoras.size(); i++)
            {
                computadora &p = computadoras [i];
                archivo << p;
                // Imprime en nuestro archivo
            }
        }
        archivo.close();
    }

    void Laboratorio::respaldar()
    {
        ofstream archivo("Computadoras.txt");
        if (archivo.is_open())
        {
            for (size_t i = 0; i < computadoras.size(); i++)
            {
                computadora &p = computadoras [i];
                archivo << p.getNombre_equipo () << endl;
                archivo << p.getSistem_Op () << endl;
                archivo << p.getRAM () << endl;
                archivo << p.getAlmacenamiento () << endl;
                // Imprime linea por linea
            }
        }
        archivo.close();
    }
        void Laboratorio::recuperar()
    {
        ifstream archivo ("Computadoras.txt");
        if (archivo.is_open())
        {
            string temp;
            computadora p;
            int ram;
            float almacenamiento;
            
            while (true)
            {
                getline (archivo, temp);
                if (archivo.eof())
                    {
                        break;
                    } // terminar el ciclo
                p.setSistem_Op (temp);

                getline (archivo, temp);
                p.setNombre_equipo (temp);

                getline (archivo, temp);
                ram = stoi (temp); // string to int
                p.setRAM (ram);

                getline (archivo, temp);
                almacenamiento = stof (temp); // string to float
                p.setAlmacenamiento (almacenamiento);

                agregarcompu(p);
            }
        }
        archivo.close();
    }
void Laboratorio::insertar(const computadora &p, size_t pos)
{
    computadoras.insert(computadoras.begin()+pos, p);
}

size_t Laboratorio::size()
{
    return computadoras.size();
}

void Laboratorio::inicializar(const computadora &p, size_t n)
{
    computadoras = vector<computadora>(n, p);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}

computadora* Laboratorio::buscar(const computadora &p)
{
    // vector<Personaje>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), p);

    if (it == computadoras.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}




























//main.cpp
int main () 
{
    Laboratorio v;
    string op;

    while (true)
    {
        cout << "1) Agregar computadora" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Buscar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            computadora p;

            cin >> p;

            v.agregarcompu(p); 
            cin.ignore();
        } 
        else if (op == "2") {
            v.mostrar();
        }
        else if (op == "3") {
            v.respaldar();
        }
        else if (op == "4") {
            v.recuperar();
        }
        else if (op == "5") {
            computadora p;
            cin >> p;

            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.insertar(p, pos);
            }
        }
        else if (op == "6") {
            computadora p;
            cin >> p;

            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();

            v.inicializar(p, n);
        }
        else if (op == "7") {
            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.eliminar(pos);
            }
        }
        else if (op == "8") {
            v.ordenar();
        }
        else if (op == "9") {
            computadora p;
            cin >> p; cin.ignore();

            computadora *ptr = v.buscar(p);

            if (ptr == nullptr) {
                cout << "no encontrado" << endl;
            }
            else {
                cout << *ptr << endl;
            }
        }
        else if (op == "0") {
            break;
        }
    }

    return 0;
} 
