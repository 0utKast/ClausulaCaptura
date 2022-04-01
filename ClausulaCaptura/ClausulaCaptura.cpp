
#if 0
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "amarillo", "naranja", "verde", "rojo" };

    // Definimos la función justo donde la usamos.
    const auto encontrado{ std::find_if(arr.begin(), arr.end(),
                             [](std::string_view str) // esta es nuestra lambda, sin cláusula de captura
                             {
                               return (str.find("ver") != std::string_view::npos);
                             }) };

    if (encontrado == arr.end())
    {
        std::cout << "No se encontró ver\n";
    }
    else
    {
        std::cout << "Encontrado en:  " << *encontrado << '\n';
    }

    return 0;
}



#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main()
{
    std::array<std::string_view, 4> arr{ "amarillo", "naranja", "verde", "rojo" };

    // Pedir al usuario qué buscar.
    std::cout << "buscar por: ";

    std::string buscar{};
    std::cin >> buscar;

    auto encontrado{ std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
        // Buscar por @buscar en lugar de por "ver".
        return (str.find(buscar) != std::string_view::npos); // Error: buscar no accesibe en este alcance
      }) };

    if (encontrado == arr.end())
    {
        std::cout << "No encontrado\n";
    }
    else
    {
        std::cout << "Encontrado " << *encontrado << '\n';
    }

    return 0;
}








#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main()
{
    std::array<std::string_view, 4> arr{ "amarillo", "naranja", "verde", "rojo" };

    // Pedir al usuario qué buscar.
    std::cout << "buscar por: ";

    std::string buscar{};
    std::cin >> buscar;

    auto encontrado{ std::find_if(arr.begin(), arr.end(), [buscar](std::string_view str) {
        // Buscar por @buscar en lugar de por "ver".
        return (str.find(buscar) != std::string_view::npos); // Error: buscar no accesibe en este alcance
      }) };

    if (encontrado == arr.end())
    {
        std::cout << "No encontrado\n";
    }
    else
    {
        std::cout << "Encontrado " << *encontrado << '\n';
    }

    return 0;
}


#include <iostream>

int main()
{
    int balas { 10 };

    // Define una lambda y la  almacena en una variable llamada "disparar".
    auto disparar{
      [balas]() {
            // Ilegal, balas fue capturada como un copia const.
            --balas;

            std::cout << "bang, quedan " << balas << " disparos.\n";
          }
    };

    // Llamar a la lambda
    disparar();

    std::cout << "quedan" << balas << " disparos\n";

    return 0;
}




#include <iostream>

int main()
{
    int balas{ 10 };

    auto disparar{
        // Añadimos a la definición de la lambda "mutable" después de paréntesis parámetros.
        [balas]() mutable {
            // Ahora ya podemos modificar balas (pero modificará el clon, no aceptará al original)
            --balas;

            std::cout << "Bang, quedan " << balas << " disparos.\n";
          }
    };

    disparar();
    disparar();

    std::cout << "quedan " << balas << " disparos\n";

    return 0;
}



#include <iostream>

int main()
{
    int balas{ 10 };

    auto disparar{
        // Ya no necesitamos mutable
        [&balas]() { // &balas significa que balas es capturado por referencia
          // Cambios en balas afectarán también al balas original
          --balas;

          std::cout << "Bang, quedan " << balas << " disparos.\n";
        }
    };

    disparar();

    std::cout << "Quedan " << balas << " disparos\n";

    return 0;
}


#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Coche
{
    std::string marca{};
    std::string modelo{};
};

int main()
{
    std::array<Coche, 3> coches{ { { "Seat", "Arona" },
                               { "Renault", "Arkana" },
                               { "Honda", "jazz" } } };

    int comparaciones{ 0 };

    std::sort(coches.begin(), coches.end(),
        // Captura @comparaciones por referencia.
        [&comparaciones](const auto& a, const auto& b) {
            // Al capturar comparaciones por referencia. Podemos modificarlo sin "mutable".
            ++comparaciones;

            // Ordenamos los coches por su marca.
            return (a.marca < b.marca);
        });

    std::cout << "Comparaciones: " << comparaciones << '\n';

    for (const auto& coche : coches)
    {
        std::cout << coche.marca << ' ' << coche.modelo << '\n';
    }

    return 0;
}



#include <vector>
int main()
{
int salud{ 33 };
int armadura{ 100 };
std::vector<int> enemigos{};

    // Captura salud y armadura por valor, y enemigos por referencia.
    [salud, armadura, &enemigos]() {};
}

#endif

#include <array>
#include <iostream>

int main()
{
    std::array areas{ 100, 25, 121, 40, 56 };

    int ancho{};
    int alto{};

    std::cout << "Escribe ancho y alto: ";
    std::cin >> ancho >> alto;

    auto encontrado{ std::find_if(areas.begin(), areas.end(),
                             [alto, &ancho](int conocerArea) { // capturará alto por valor y ancho por referencia
                               return (ancho * alto == conocerArea); // porque se mencionan aquí
                             }) };

    if (encontrado == areas.end())
    {
        std::cout << "No conozco esta area :(\n";
    }
    else
    {
        std::cout << "Area encontrada :)\n";
    }

    return 0;
}






#if 0
#endif