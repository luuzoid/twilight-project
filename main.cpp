#include <iostream>
using namespace std;

void perkalian(int N, int M, int P, int A[100][100], int B[100][100], int C[100][100])
{
    cout << "> Elemen A: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "  ";
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "> Elemen B: " << endl;
    for (int i = 0; i < M; i++)
    {
        cout << "  ";
        for (int j = 0; j < P; j++)
        {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < P; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < M; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void penambahan(int W, int X, int A[100][100], int B[100][100], int C[100][100])
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < X; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void pengurangan(int W, int X, int A[100][100], int B[100][100], int C[100][100])
{
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < X; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main()
{
    while (true)
    {
        cout << endl
             << "\033[32m" << "-=[ Program Matriks ]=-" << "\033[0m" << endl;

        char O;
        cout << "> Operasi [+/-/x]? ";
        cin >> O;

        if (O == 'x')
        {
            cout << "\033[31m" << "[*]" << " Syarat: Ordo kolom A harus sama dengan ordo baris B!" << "\033[0m" << endl;
            cout << "\033[33m" << "[*] Ordo .. (Baris x Kolom)" << "\033[0m" << endl;
            int N, M, M2, P;
            int A[100][100], B[100][100], C[100][100];

            cout << "> Ordo A (B*K): ";
            cin >> N >> M;
            cout << "> Ordo B (B*K): ";
            cin >> M2 >> P;

            if (M != M2)
            {
                cout << "\033[31m" << "[!] Ordo matriks tidak sesuai!" << "\033[0m" << endl;
                continue;
            }
            M = M2;

            perkalian(N, M, P, A, B, C);

            cout << "> Hasil AxB: " << endl;
            for (int i = 0; i < N; i++)
            {
                cout << "  ";
                for (int j = 0; j < P; j++)
                {
                    cout << C[i][j] << " ";
                }
                cout << endl;
            }

            // cout << "Output: " << endl;
            // cout << N << " " << M << endl;
            // cout << M << " " << P << endl;
        }
        else if (O == '+' || O == '-')
        {
            cout << "\033[31m" << "[*]" << " Syarat: Ordo kedua matriks harus sama!" << "\033[0m" << endl;
            cout << "\033[33m" << "[*] Ordo .. (Baris " << O << " Kolom)" << "\033[0m" << endl;
            int W, X, Y, Z;
            int A[100][100], B[100][100], C[100][100];

            cout << "> Ordo A (B" << O << "K): ";
            cin >> W >> X;
            cout << "> Ordo B (B" << O << "K): ";
            cin >> Y >> Z;

            if (W != Y || X != Z)
            {
                cout << "\033[31m" << "[!] Ordo matriks tidak sesuai!" << "\033[0m" << endl;
                continue;
            }

            cout << "> Elemen A: " << endl;
            for (int i = 0; i < W; i++)
            {
                cout << "  ";
                for (int j = 0; j < X; j++)
                {
                    cin >> A[i][j];
                }
            }

            cout << "> Elemen B: " << endl;
            for (int i = 0; i < Y; i++)
            {
                cout << "  ";
                for (int j = 0; j < Z; j++)
                {
                    cin >> B[i][j];
                }
            }

            if (O == '+')
            {
                penambahan(W, X, A, B, C);
                cout << "> Hasil A+B: " << endl;
                for (int i = 0; i < W; i++)
                {
                    cout << "  ";
                    for (int j = 0; j < X; j++)
                    {
                        cout << C[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            else
            {
                pengurangan(W, X, A, B, C);
                cout << "> Hasil A-B: " << endl;
                for (int i = 0; i < W; i++)
                {
                    cout << "  ";
                    for (int j = 0; j < X; j++)
                    {
                        cout << C[i][j] << " ";
                    }
                    cout << endl;
                }
            }

            // cout << "Output: " << endl;
            // cout << W << " " << X << endl;
            // cout << Y << " " << Z << endl;
        }
        else
        {
            cout << "\033[31m" << "[!] Operasi tidak dikenali!" << "\033[0m" << endl;
        }
    }
    return 0;
}