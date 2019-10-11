#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

//PREGUNTA 1
template <typename T>
auto absolute(T& n){
    if(n < 0){
        return n*-1;
    } else
        return n;
}

//PREGUNTA 2
template <typename Container, typename T>
auto split_range(Container& cnt, T n) {
    //auto it = cnt.begin();
    vector<vector<int>> resultado;
    int contador = 0;
    int cociente = cnt.size() / n;
    int residuo = cnt.size() % n;

    for (int i = 0; i < cociente; i++) {
        vector<int> tmp;

        for (int j = i * cociente; j < (cociente + i * cociente); j++) {
            tmp.push_back(cnt[j]);
            contador = j;
        }

        resultado.push_back(tmp);
        tmp.clear();
    }
    if (residuo != 0) {
        vector<int> tmp;

        for (int k = contador + 1; k < cnt.size(); k++) {
            tmp.push_back(cnt[k]);
        }
        resultado.push_back(tmp);
    }

    for (int i = 0; i < resultado.size(); i++)
    {
        cout << "resultado["<<i<<"] = {";

        for (int j = 0; j < resultado[i].size(); j++)
        {
            cout<<" "<<resultado[i][j]<<" ";
        }
        cout <<"};";
        cout << endl;
    }

    return resultado;
}



//PREGUNTA 3
template <typename Container>
auto sumar_rango(Container &cnt1, Container &cnt2){
    auto it_cnt1 = cnt1.begin();
    auto it_cnt2 = cnt2.begin();
    auto a = cnt2.begin();
    auto b = cnt1.begin();
    Container tmp;

    if(cnt1.size() == cnt2.size()){
        for( ;it_cnt1 != cnt1.end();advance(it_cnt1,1)) {
            tmp.push_back(*it_cnt1 + *it_cnt2);
            it_cnt2++;
        }
    }
    if(cnt1.size() < cnt2.size()){
        for( ;it_cnt2 != cnt2.end();advance(it_cnt2,1)) {

            if (it_cnt1 != cnt1.end()){
                tmp.push_back(*it_cnt1 + *it_cnt2);
                it_cnt1++;
            }else{
                tmp.push_back(*it_cnt2 + *b);
                advance(b,1);
                if(b == cnt1.end()){
                    b = cnt1.begin();
                }
            }
        }

    }
    if(cnt1.size() > cnt2.size()){

        for( ;it_cnt1 != cnt1.end();advance(it_cnt1,1)) {

            if (it_cnt2 != cnt2.end()){
                tmp.push_back(*it_cnt1 + *it_cnt2);
                it_cnt2++;
            }else{
                tmp.push_back(*it_cnt1 + *a);
                advance(a,1);
                if(a == cnt2.end()){
                    a = cnt2.begin();
                }
            }
        }

    }
    for(auto &v:tmp){
        cout<<v<<" ";
    }
    cout<<endl;
    return tmp;

}



//PREGUNTA 4 A FALTA SOBRECARGA DE {}
template<typename Container, typename T>
auto delete_items(Container &cnt, T n){
    auto it = cnt.begin();
    Container tmp;
    for (; it != cnt.end(); it++) {
        if (*it == n) {

            cnt.erase(it);

        }
        tmp.push_back(*it);
    }
    for(auto &v:tmp){
        cout<<v<<" ";
    }
    cout<<endl;
    return tmp;
}



//PREGUNTA 5 A MEDIAS
template <typename Container>
auto delete_duplicated(Container & cnt){
    auto it = cnt.begin();
    Container tmp;
    for(;it != cnt.end(); advance(it,1)){
        for (auto it2 = cnt.begin(); it2 !=cnt.end();advance(it2,1)){
                if(*it==*it2){
                    cnt.erase(it);
                }

        }
        tmp.push_back(*it);
    }
    for(auto &v:tmp){
        cout<<v<<" ";
    }
    cout<<endl;
    return tmp;
}


//PREGUNTA 6
template <typename V_entero, typename Container>
auto rotate_range(Container & cnt, V_entero valor){
    auto it = cnt.begin();
    auto it_2 = cnt.end();
    auto tamano = distance(it,it_2);
    int i = 0, j = 0, aux = 0;

    if(valor > 0){

        for(; it < (it_2 + valor); it++) {
           aux = cnt[tamano-1];
            for(i = tamano; i > 0; i--)
                cnt[i] = cnt[i - 1];
                cnt[0] = aux;


        }

        for(auto &v:cnt){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    if (valor < 0) {

        for(; j > valor; j-- ) {
           aux = cnt[0];
            for(int i = 0; i < tamano; i++)
                cnt[i] = cnt[i + 1];
                cnt[tamano - 1] = aux;

        }
        for(auto &v:cnt){
            cout<<v<<" ";
        }
        cout<<endl;
    }


}
//PREGUNTA 7
template<typename First_value, typename Second_value, typename Container>
auto unpack(First_value & v1, Second_value & v2, Container & cnt){
    v1=cnt.first;
    v2=cnt.second;
    cout << "El primer parametro es: " << v1 << ", " << "el segundo parametor es: "<< v2 << endl;
}

//PREGUNTA 8
template <typename First_value, typename Second_value, typename Third_Value, typename Forth_value, typename Container>
auto unpack(First_value& v1, Second_value& v2, Third_Value& v3, Forth_value& v4, Container& cnt) {
    v1 = get<0>(cnt);
    v2 = get<1>(cnt);
    v3 = get<2>(cnt);
    v4 = get<3>(cnt);
    cout <<"KEY: "<<v1<<" | "<<"FIRST_NAME: "<<v2<<" | "<<"LAST_NAME: "<<v3<<" | "<<"HEIGHT: "<<v4<<endl;
}

//PREGUNTA 9 SOLO PARA VECTORES
template < typename ...args>
auto generar_contenedor(args ...argumentos){
    vector<int> tmp;
    for(auto &v:{argumentos ...}){
        tmp.push_back(v);
    }
    for(auto &v:tmp){
        cout<<v<<" ";
    }
    cout<<endl;
    return tmp;
}

//PREGUNTA 10
template <typename ...args>
auto min_size(args ...argumentos){
    int tamano;
    int minimo = 100000;// se le da ese valor para hacer la primera consulta de tamano < minimo;

    for (auto &v : {argumentos ...})
    {
        tamano = v.size();
        if (tamano < minimo)
        {
            minimo = v.size();
        }
    }
    return minimo;
}

//PREGUNTA 11
template <typename ...args>
auto zip(args ...argumentos){

    vector <vector<int>> resultado;
    vector <int> temporal;

    int longitud = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    for (auto &v: {argumentos ...}) {
        //Se obtiene un iterador al inicio de la lista
        list<int> temp = v;
        auto it = temp.begin();
        longitud = v.size();

        while (it != temp.end()) {
            temporal.push_back(*it++);
        }
    }
    for (i = 0; i < longitud; i++)
    {
        vector<int> temporal2;
        k = 0;
        j = i;
        while (k <longitud)
        {
            temporal2.push_back(temporal[j]);
            j = j+longitud;
            k++;
        }
        resultado.push_back(temporal2);
        temporal2.clear();
    }
    for (i = 0; i<resultado.size(); i++)
    {
        for (j = 0; j<resultado[i].size(); j++)
        {
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
    return resultado;

}

//PREGUNTA 12
template <typename Container, typename T>
auto busqueda_binaria(Container& cnt, T n){
    sort(cnt.begin(),cnt.end());
    int arriba = cnt.size()-1;
    int abajo = 0;
    int centro;

    while(abajo <= arriba){

        centro = (arriba + abajo)/2;

        if(cnt[centro]  == n){
            cout << "El valor: "<<n<<" fue encontrado en la posicion: "<<centro<<endl;
            return true;
            break;
        } else
            if(n < cnt[centro]){
                arriba = centro - 1;
            } else
                abajo = centro + 1;

    }
    cout << "El valor: "<<n<<" no fue encontrado"<<endl;
    return false;

}
//PREGUNTA 14
template<typename ...args>
auto sum_product(args ...argumentos){

    int resultado = 0;
    vector<int> datos;
    vector<int> temp;

    for (auto &v:{argumentos ...})
    {
        datos.push_back(v);
    }


    temp = datos;


    for (int i = 0; i < datos.size(); i++){


        if (datos [i] % 2 == 0){

            for (int j = 0; j < temp.size(); j++) {

                if (temp[j] % 2 != 0){

                    resultado = resultado + (datos [i] * temp[j]);
                }
            }
        }
    }
    cout<<resultado<<endl;
    return resultado;
}
//CLASS TEMPLATES NUMERO 2
template <typename T>
struct max_heap{

                 T info;
                 auto find_max(){
                     int maximo = 0;
                     for(int i = 0; i < info.size(); i++){
                            if(info[i]>maximo){
                                maximo = info[i];
                            }
                     }
                     cout<<"El maximo es: " <<maximo<<endl;
                 }

                 void insert( int item){
                        info.push_back(item);
                 }
                 int delete_(){
                        int valor = info[info.size() - 1];
                        info.pop_back();
                        return valor;
                 }
                 void print(){
                     for( auto &v:info){
                         cout<<v<<" ";
                     }
                 }
                    };
int main() {
   //PREGUNTA 1
    int x = -3;
    float k = 5;
    std::cout<<absolute(x)<<std::endl;
    std::cout<<absolute(k)<<std::endl;


    //PREGUNTA 2
    vector<int> n = {1,2,3,4,5,6,7};
    split_range(n,3);

    //PREGUNTA 3
    vector<int> b ={1, 2, 3, 4, 5};
    vector<int> a ={10,20};
    auto v3 = sumar_rango(a,b);

    //PREGUNTA 4
    vector<int> v1 = {1, 3, 4, 1, 3, 2, 3, 4, 6, 5};
    auto v4 = delete_items(v1, 1);

    //PREGUNTA 6
    vector<int> v0 = {1,2,3,4,5,6};
    rotate_range(v0,2);

    //PREGUNTA 7
    int key; string name;
    pair<int, string> p1 = {1321, "Jose Perez"};
    unpack(key,name,p1);

    //PREGUNTA 8
    int key1; string first_name; string last_name; double height;
    tuple<int,string,string,double> p2 = {1321, "Jose", "Perez", 1.68};
    unpack(key1, first_name, last_name, height,p2);

    //PREGUNTA 9 SOLO PARA VECTORES
    auto c1 = generar_contenedor(1, 2, 3, 4);
    auto c2 = generar_contenedor(10, 20, 30, 40);

    //PREGUNTA 10
    vector<int> v10 = { 11 };
    vector<int> v20 = { 21, 22, 23, 1, 2 };
    vector<int> v30 = { 31, 32, 33, 4 };
    cout << min_size(v20, v30) << endl;
    cout << min_size(v10, v20, v30) << endl;

    //PREGUNTA 11
    list<int> v100 = {11, 12, 13};
    list<int> v200 = {21, 22, 23};
    list<int> v300 = {31, 32, 33};

    auto resultado = zip (v100,v200,v300);

    //PREGUNTA 12
    vector<int> v12 = {1,2,3,4,5,6,7};
    busqueda_binaria(v12,1);

    //PREGUNTA 14
    auto c = sum_product(1,2,3,4,5);

    //CLASS TEMPLATES NUMERO 2
    max_heap <vector<int>> pila;
    pila.insert(1);
    pila.insert(2);
    pila.insert(3);
    pila.insert(4);
    pila.insert(5);
    pila.find_max();
    pila.delete_();
    pila.print();

    return 0;
}