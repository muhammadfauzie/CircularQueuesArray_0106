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

            cout << "\nThe element deleted from the queue is: " << queues_array[FRONT] << "\n";

            //cek jika antrian hanya memiliki satu elemen
            if (FRONT == REAR)
            {
                FRONT = -1;
                REAR = -1;
            }
            else
            {
                //jika element yang dihapus berada di posisi terakhir array, kembali ke awal array
                if (FRONT == MAX - 1)
                    FRONT = 0;
                else
                    FRONT = FRONT + 1;
            }
        }

        void display()
        {
            int FRONT_position = FRONT;
            int REAR_position = REAR;

            //cek apakah antrian kosong
            if (FRONT == -1)
            {
                cout << "Queues is empty\n";
                return;
            }

            cout << "\nElements in the queue are...\n";

            //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
            if (FRONT_position <= REAR_position)
            {
                while (FRONT_position <= REAR_position)
                {
                    cout << queues_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;
            }
            else
            {
                //jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
                while (FRONT_position <= MAX - 1)
                {
                    cout << queues_array[FRONT_position] << " ";
                    FRONT_position++;
                }

                FRONT_position = 0;

                 while (FRONT_position <= REAR_position)
                {
                    cout << queues_array[FRONT_position] << " ";
                    FRONT_position++;
                }
                cout << endl;

            }
        }
};

int main()
{
    Queues q;
    char ch;
}