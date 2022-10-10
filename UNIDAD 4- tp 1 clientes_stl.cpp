#include <iostream>
#include <queue>

using namespace std;

// mostrar cola
void mostrar_cola(queue<int> q)
{
    queue<int> turno = q;
    cout << "\n  TURNOS (por orden de llegada): \n\n";
    while (!turno.empty()) {
        cout<< "     Proximo Cliente: " << turno.front() << "  Box activo. \n";
        turno.pop();
    }
    cout << '\n';
}

// Driver Code
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);

    mostrar_cola(q1) ;

    return 0;
}
