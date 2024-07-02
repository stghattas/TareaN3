#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Dot {
    float x;
    float y;
    float z;

    Dot(float x, float y, float z) : x(x), y(y), z(z) {}
};

float distance(const Dot& a, const Dot& b, bool is3D = true) {
    if (is3D) {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
    } else {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }
}

Dot sum(const Dot& a, const Dot& b, bool is3D = true) {
    if (is3D) {
        return Dot(a.x + b.x, a.y + b.y, a.z + b.z);
    } else {
        return Dot(a.x + b.x, a.y + b.y, 0);
    }
}

Dot sumArray(Dot dots[], int n, bool is3D = true) {
    Dot result(0, 0, 0);
    for (int i = 0; i < n; i++) {
        result = sum(result, dots[i], is3D);
    }
    return result;
}

float dotProduct(const Dot& a, const Dot& b, bool is3D = true) {
    if (is3D) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    } else {
        return a.x * b.x + a.y * b.y;
    }
}

Dot crossProduct(const Dot& a, const Dot& b) {
    return Dot(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

void printVector(const Dot& v) {
    cout << "u = " << fixed << setprecision(2) << v.x << "i + " 
         << fixed << setprecision(2) << v.y << "j + " 
         << fixed << setprecision(2) << v.z << "k\n";

    if (v.x != 0 && v.y != 0 && v.z != 0) {
        cout << "Plano XYZ\n";
    } else if (v.x != 0 && v.y != 0) {
        cout << "Plano XY\n";
    } else if (v.x != 0 && v.z != 0) {
        cout << "Plano XZ\n";
    } else if (v.y != 0 && v.z != 0) {
        cout << "Plano YZ\n";
    } else if (v.x != 0) {
        cout << "Eje X\n";
    } else if (v.y != 0) {
        cout << "Eje Y\n";
    } else if (v.z != 0) {
        cout << "Eje Z\n";
    }
}

void solveForces(Dot forces[], int n) {
    Dot resultant = sumArray(forces, n);
    printVector(resultant);
}

int main() {
    Dot a(1, 2, 3);
    Dot b(4, 5, 6);
    
    cout << "Distancia 2D: " << distance(a, b, false) << "\n";
    cout << "Distancia 3D: " << distance(a, b) << "\n";

    Dot sumResult = sum(a, b);
    cout << "Suma de vectores: ";
    printVector(sumResult);

    Dot vectors[] = {a, b, Dot(7, 8, 9)};
    int n = sizeof(vectors) / sizeof(vectors[0]);
    Dot sumArrayResult = sumArray(vectors, n);
    cout << "Suma de arreglo de vectores: ";
    printVector(sumArrayResult);

    cout << "Producto escalar 2D: " << dotProduct(a, b, false) << "\n";
    cout << "Producto escalar 3D: " << dotProduct(a, b) << "\n";

    Dot crossResult = crossProduct(a, b);
    cout << "Producto cruz: ";
    printVector(crossResult);

    cout << "Resolviendo sistema de fuerzas:\n";
    solveForces(vectors, n);

    return 0;
}
