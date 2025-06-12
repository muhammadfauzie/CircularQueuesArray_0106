#include <iostream>
using namespace std;

class Queues
{
    private:
        static const int MAX = 5;
        int FRONT, REAR;
        int queues_array[5];

    public:
        Queues()
        {
            FRONT = -1;
            REAR = -1;
        }

        void insert()
        {
            int num;
            cout << "Enter a number:" ;
            cin >> num;
            cout << endl;

            //1. cek apakah antrian penuh
            if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1))
            {
                cout << "\nQueues overflow\n"; 
                return;
            }

            //2. cek apakah antrian kosong
            if (FRONT == -1)
            {
                FRONT = 0;
                REAR = 0;
            }
            else 
            {
                //jika REAR berada di posisi terakhir array, kembali ke awal array
                if (REAR == MAX - 1)
                    REAR = 0;
                else
                    REAR = REAR + 1;

            }
            queues_array[REAR] = num;

        }
        void remove()
        {
            //cek apakah antrian kosong
            if (FRONT == -1)
            {
                cout << "Queues underflow\n";
                return;
            }
        }};