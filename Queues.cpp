/**
 * @mainpage Dokumentation Circular Queue
 * 
 * @section introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data dengan pendekatan circular arrays.
 * 
 * @section operations
 * project ini memiliki beberapa operasi antrian lain:
 * 1. Insert
 * 2. delete
 * 3. Display
 * 
 * @section Cara penggunaan
 * berikut beberapa menu yang bisa di gunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - nama :muh. fauzie primarka ramdhani
 * - nim : 20240140106
 * - kelas : C
 * 
 * @brief
 * @version 1.0
 * @date 2025-06-24
 * 
 * @copyright muh. fauzie primarka ramdhani@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;
/**
* @class Queues
* @brief class ini untuk operasi lengkap queue
*
*
*/

class Queues
{
    private:
        int FRONT; ///<variabel private front untuk menyimpan posisi depan antrian
        int REAR; ///<variabel private rear untuk menyimpan posisi belakang antrian
        int MAX = 5; ///<variabel private MAX untuk menyimpan ukuran maximum antrian
        int queues_array[5]; ///< variabel private queues_array untuk menyimpan elemen antrian
    public:
        /**
         * @brief Constructor a new Queues object
         * set default queues null
         * with front = -1 and rear = -1
         */
         
        Queues()
        {
            FRONT = -1;
            REAR = -1;
        }

        /**
         * @brief method untuk memasukkan elemen ke dalam antrian
         * data dimasukkan variable queues_array
         */
        void insert()
        {
            int num;///<variable num untuk menyimpan nilai
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
        /**
         * @brief method untuk menghapus data dalam antrian
         * data dihapuskan dari dalam variable queues_array
         */
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
        /**
         * @brief method untuk menampilkan data dalam antrian
         * data ditampilkan yang berada dalam variable queues_array
         */

        void display()
        {
            int FRONT_position = FRONT;///< variable FRONT_position untuk menandakan posisi element pertama pada variable front
            int REAR_position = REAR;///< variable REAR_position untuk menandakan posisi element terakhir pada variable rear

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

/**
 * @brief method utama untuk menjalankan program
 * 
 * @return int
 */

int main()
{
    Queues q;///< object untuk menggunakan member yang ada pada class Queues
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try
        {   
            cout << "Menu" << endl;
            cout << "1.Implement insert operation" << endl;
            cout << "2.Implement delete operation" << endl;
            cout << "3.Display values" << endl;
            cout << "4.Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
}